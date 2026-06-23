# Cherry Studio 一键恢复（在新电脑上运行）
# 使用方式: .\restore-from-server.ps1
# 前提: 已配置 SSH 密钥到云服务器（否则每次都要输密码）
param(
    $Server = "root@154.7.177.216",
    $HjmTarget = "F:\HJM-memory",
    $CsTarget = "$env:APPDATA\CherryStudio\Data"
)

# 禁止 SSH 交互式提示（host key + 密码）
$SSH_OPTS = "-o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null -o BatchMode=yes -o ConnectTimeout=10"

Write-Host "=== Cherry Studio 一键恢复 ===" -ForegroundColor Cyan
Write-Host "服务器 : $Server"
Write-Host "CS 数据 : $CsTarget"
Write-Host "记忆库  : $HjmTarget"
Write-Host "当前账户: $env:USERNAME"
Write-Host ""

# 检查 SSH 密钥
$sshKey = "$env:USERPROFILE\.ssh\id_rsa"
if (-not (Test-Path $sshKey)) {
    Write-Host "⚠ 未检测到 SSH 密钥，你需要先配置免密登录：" -ForegroundColor Yellow
    Write-Host ""
    Write-Host "  1. 生成密钥（如已有则跳过）:" -ForegroundColor White
    Write-Host "     ssh-keygen -t rsa -b 4096 -f `"$sshKey`" -N `"`"" -ForegroundColor Gray
    Write-Host ""
    Write-Host "  2. 复制公钥到云服务器:" -ForegroundColor White
    Write-Host "     type `"$sshKey.pub`" | ssh root@154.7.177.216 `"mkdir -p ~/.ssh && cat >> ~/.ssh/authorized_keys`"" -ForegroundColor Gray
    Write-Host "     （这一步需要输入一次服务器密码）"
    Write-Host ""
    Write-Host "  3. 测试免密登录:" -ForegroundColor White
    Write-Host "     ssh -o StrictHostKeyChecking=no root@154.7.177.216 echo OK" -ForegroundColor Gray
    Write-Host ""
    $choice = Read-Host "是否现在继续（将输入密码）？[y/N]"
    if ($choice -notmatch '^[yY]') { exit 1 }
    # 去掉 BatchMode 允许密码输入
    $SSH_OPTS = "-o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null -o ConnectTimeout=10"
}

# 测试连接
Write-Host ">>> 测试服务器连接..." -ForegroundColor Yellow
$testConn = ssh $SSH_OPTS $Server "echo CONNECTED" 2>&1
if ($LASTEXITCODE -ne 0 -or $testConn -notmatch "CONNECTED") {
    Write-Host "❌ 无法连接到服务器！请检查：" -ForegroundColor Red
    Write-Host "   1. 服务器是否在线 (154.7.177.216)"
    Write-Host "   2. SSH 密钥是否已配置"
    Write-Host "   3. 网络是否正常"
    exit 1
}
Write-Host "   连接成功" -ForegroundColor Green

# 检查服务器上是否有备份
Write-Host ">>> 检查服务器备份..." -ForegroundColor Yellow
$hasCS = ssh $SSH_OPTS $Server "test -f /home/backup/cs-backup.tar.gz && echo YES || echo NO"
$hasHJM = ssh $SSH_OPTS $Server "test -f /home/backup/hjm-backup.tar.gz && echo YES || echo NO"
if ($hasCS -match "NO") { Write-Host "  ⚠ 服务器无 CS 备份" -ForegroundColor Yellow }
if ($hasHJM -match "NO") { Write-Host "  ⚠ 服务器无 HJM 备份" -ForegroundColor Yellow }
if ($hasCS -match "NO" -and $hasHJM -match "NO") {
    Write-Host "❌ 服务器上没有任何备份！" -ForegroundColor Red
    exit 1
}

# 1. 恢复 Cherry Studio Data
if ($hasCS -match "YES") {
    Write-Host ""
    Write-Host "[1/2] 恢复 Cherry Studio Data..." -ForegroundColor Yellow

    if (-not (Test-Path "$CsTarget")) {
        Write-Host "  ⚠ Cherry Studio Data 目录不存在，请先安装 Cherry Studio！" -ForegroundColor Red
        Write-Host "  下载: https://cherrystudio.ai/"
    } else {
        $csTmp = "$env:TEMP\cs-restore.tar.gz"
        Write-Host "  下载中..."
        scp $SSH_OPTS "${Server}:/home/backup/cs-backup.tar.gz" $csTmp
        if ($LASTEXITCODE -ne 0) {
            Write-Host "  ❌ 下载失败！" -ForegroundColor Red
        } else {
            $csSizeMB = [math]::Round((Get-Item $csTmp).Length / 1MB, 1)
            Write-Host "  下载完成 ($csSizeMB MB)，解压中..."
            # 备份当前配置（安全起见）
            $csBackupDir = "$env:TEMP\cs-old-$(Get-Date -Format 'yyyyMMdd-HHmmss')"
            Write-Host "  备份当前 CS 配置到 $csBackupDir ..."
            Copy-Item -Recurse "$CsTarget" $csBackupDir -ErrorAction SilentlyContinue

            tar -xzf $csTmp -C "$CsTarget"
            Write-Host "  ✅ Cherry Studio Data 恢复完成" -ForegroundColor Green
            Remove-Item $csTmp -Force
        }
    }
}

# 2. 恢复 HJM-memory
if ($hasHJM -match "YES") {
    Write-Host ""
    Write-Host "[2/2] 恢复 HJM-memory..." -ForegroundColor Yellow

    $hjmTmp = "$env:TEMP\hjm-restore.tar.gz"
    Write-Host "  下载中..."
    scp $SSH_OPTS "${Server}:/home/backup/hjm-backup.tar.gz" $hjmTmp
    if ($LASTEXITCODE -ne 0) {
        Write-Host "  ❌ 下载失败！" -ForegroundColor Red
    } else {
        $hjmSizeMB = [math]::Round((Get-Item $hjmTmp).Length / 1MB, 1)
        Write-Host "  下载完成 ($hjmSizeMB MB)，解压中..."

        New-Item -ItemType Directory -Force -Path $HjmTarget | Out-Null
        tar -xzf $hjmTmp -C "$HjmTarget"
        Write-Host "  ✅ HJM-memory 恢复完成 → $HjmTarget" -ForegroundColor Green
        Remove-Item $hjmTmp -Force
    }
}

Write-Host ""
Write-Host "=== 恢复完成 ===" -ForegroundColor Green
Write-Host "重启 Cherry Studio 即可使用恢复的配置。" -ForegroundColor Cyan
