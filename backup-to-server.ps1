# Cherry Studio 全量备份到云服务器
# 使用方式: .\backup-to-server.ps1
param(
    $Server = "root@154.7.177.216",
    $CsSource = "$env:APPDATA\CherryStudio\Data",
    $HjmSource = "F:\HJM-memory"
)

$SSH_OPTS = "-o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null -o ConnectTimeout=10"

Write-Host "=== Cherry Studio 全量备份 -> $Server ===" -ForegroundColor Cyan
Write-Host "当前账户: $env:USERNAME"
Write-Host ""

# 测试连接
Write-Host ">>> 测试连接..." -ForegroundColor Yellow
ssh $SSH_OPTS $Server "echo CONNECTED" 2>&1 | Out-Null
if ($LASTEXITCODE -ne 0) {
    Write-Host "❌ 无法连接服务器！请检查 SSH 密钥和网络" -ForegroundColor Red
    exit 1
}
Write-Host "   连接成功" -ForegroundColor Green

# 1. 打包 Cherry Studio Data
Write-Host ""
Write-Host "[1/3] 打包 Cherry Studio Data..." -ForegroundColor Yellow
$csTar = "$env:TEMP\cs-backup.tar.gz"
if (Test-Path $CsSource) {
    Push-Location $CsSource
    tar -czf $csTar .
    Pop-Location
    $csSizeMB = [math]::Round((Get-Item $csTar).Length / 1MB, 1)
    Write-Host "  CS Data: $csSizeMB MB"
} else {
    Write-Host "  ⚠ Cherry Studio Data 目录不存在，跳过" -ForegroundColor Yellow
    $csTar = $null
}

# 2. 打包 HJM-memory
Write-Host "[2/3] 打包 HJM-memory..." -ForegroundColor Yellow
$hjmTar = "$env:TEMP\hjm-backup.tar.gz"
if (Test-Path $HjmSource) {
    Push-Location $HjmSource
    tar -czf $hjmTar --exclude .git --exclude analysis --exclude dist --exclude "DSPI.Improved" --exclude other-memory --exclude "*.zip" .
    Pop-Location
    $hjmSizeMB = [math]::Round((Get-Item $hjmTar).Length / 1MB, 1)
    Write-Host "  HJM-memory: $hjmSizeMB MB"
} else {
    Write-Host "  ⚠ HJM-memory 目录不存在 ($HjmSource)，跳过" -ForegroundColor Yellow
    $hjmTar = $null
}

# 3. 上传
Write-Host "[3/3] 上传并解压..." -ForegroundColor Yellow

$ok = $true

if ($csTar -and (Test-Path $csTar)) {
    Write-Host "  上传 CS 备份..."
    scp $SSH_OPTS $csTar "${Server}:/home/backup/cs-backup.tar.gz"
    if ($LASTEXITCODE -ne 0) { Write-Host "  ❌ CS 上传失败" -ForegroundColor Red; $ok = $false }
}

if ($hjmTar -and (Test-Path $hjmTar)) {
    Write-Host "  上传 HJM 备份..."
    scp $SSH_OPTS $hjmTar "${Server}:/home/backup/hjm-backup.tar.gz"
    if ($LASTEXITCODE -ne 0) { Write-Host "  ❌ HJM 上传失败" -ForegroundColor Red; $ok = $false }
}

if ($ok) {
    # 服务器端解压
    Write-Host "  服务器端解压中..."
    $remoteCmd = @(
        'mkdir -p /home/backup/cherry-studio/Data /home/backup/hjm-memory',
        'tar -xzf /home/backup/cs-backup.tar.gz -C /home/backup/cherry-studio/Data/',
        'tar -xzf /home/backup/hjm-backup.tar.gz -C /home/backup/hjm-memory/',
        'echo DONE'
    ) -join ' && '
    $result = ssh $SSH_OPTS $Server $remoteCmd
    if ($result -match "DONE") {
        Write-Host "  ✅ 服务器端解压完成" -ForegroundColor Green
    } else {
        Write-Host "  ⚠ 服务器端解压可能失败" -ForegroundColor Yellow
    }
}

# 清理本地临时文件
Remove-Item $csTar, $hjmTar -Force -ErrorAction SilentlyContinue

Write-Host ""
Write-Host "=== 备份完成 ===" -ForegroundColor Green
