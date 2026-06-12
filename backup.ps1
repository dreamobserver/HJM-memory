# HJM-Memory GitHub Backup Script
# 系统级定时备份，不依赖 Cherry Studio 是否在线
# 使用: powershell -ExecutionPolicy Bypass -File backup.ps1

$ErrorActionPreference = "Continue"
$repoPath = "F:\HJM-memory"
$remote = "origin"
$branch = "main"

# 全局异常兜底 —— 确保窗口不会闪退
trap {
    Write-Host ""
    Write-Host "╔══════════════════════════════════════╗" -ForegroundColor Red
    Write-Host "║  ✗ 脚本异常终止!                    ║" -ForegroundColor Red
    Write-Host "║  $_" -ForegroundColor Red
    Write-Host "╚══════════════════════════════════════╝" -ForegroundColor Red
    Read-Host "按 Enter 关闭窗口"
    exit 1
}

# ═══════════════════════════════════════
#  终端美化
# ═══════════════════════════════════════
$host.UI.RawUI.WindowTitle = "HJM-Memory GitHub Backup"
Write-Host "╔══════════════════════════════════════╗" -ForegroundColor Cyan
Write-Host "║   HJM-Memory → GitHub 备份中...     ║" -ForegroundColor Cyan
Write-Host "╚══════════════════════════════════════╝" -ForegroundColor Cyan
Write-Host ""

# ═══════════════════════════════════════
#  第1步: 检测 Cherry Studio 冲突
# ═══════════════════════════════════════
Write-Host "[1/4] 检测 Cherry Studio 运行状态..." -ForegroundColor Yellow
$csProcess = Get-Process -Name "CherryStudio" -ErrorAction SilentlyContinue

if ($csProcess) {
    Write-Host "  ⚠ Cherry Studio 正在运行 (PID: $($csProcess.Id))" -ForegroundColor Magenta
    Write-Host "  ⏳ 等待 60 秒确保无并发写入..." -ForegroundColor Magenta

    # 等待 Cherry Studio 的 cron 任务完成（cron 每30分钟触发，给它宽限期）
    Start-Sleep -Seconds 60

    # 二次确认 — 检查 sesssions/ 目录最近30秒是否有写入
    $sessionDir = Join-Path $repoPath "sessions"
    if (Test-Path $sessionDir) {
        $recentWrites = Get-ChildItem $sessionDir -File -ErrorAction SilentlyContinue |
            Where-Object { $_.LastWriteTime -gt (Get-Date).AddSeconds(-30) }
        if ($recentWrites) {
            Write-Host "  ⚠ 检测到最近30秒有文件写入，再等 30 秒..." -ForegroundColor Magenta
            Start-Sleep -Seconds 30
        }
    }
    Write-Host "  ✓ 等待完毕，继续备份" -ForegroundColor Green
} else {
    Write-Host "  ✓ Cherry Studio 未运行，安全" -ForegroundColor Green
}
Write-Host ""

# ═══════════════════════════════════════
#  第2步: 切换到仓库目录
# ═══════════════════════════════════════
Write-Host "[2/4] 进入仓库目录..." -ForegroundColor Yellow
Set-Location $repoPath
Write-Host "  ✓ 当前路径: $repoPath" -ForegroundColor Green
Write-Host ""

# ═══════════════════════════════════════
#  第3步: git add + commit
# ═══════════════════════════════════════
Write-Host "[3/4] 暂存并提交变更..." -ForegroundColor Yellow

git add -A 2>&1 | ForEach-Object { Write-Host "  $_" -ForegroundColor Gray }

# 检查是否有待提交的变更
$diffOutput = git diff --cached --stat 2>&1
if ($LASTEXITCODE -ne 0 -or [string]::IsNullOrWhiteSpace($diffOutput)) {
    Write-Host "  ℹ 没有需要提交的变更" -ForegroundColor DarkYellow
    $hasChanges = $false
} else {
    Write-Host "  ── 待提交文件 ──" -ForegroundColor Gray
    Write-Host $diffOutput -ForegroundColor White
    Write-Host ""

    $timestamp = Get-Date -Format "yyyy-MM-dd HH:mm"
    $commitMsg = "backup: $timestamp auto-sync"
    Write-Host "  📦 提交中: $commitMsg" -ForegroundColor Yellow

    git commit -m $commitMsg 2>&1 | ForEach-Object { Write-Host "  $_" -ForegroundColor Gray }

    if ($LASTEXITCODE -ne 0) {
        Write-Host "  ✗ 提交失败!" -ForegroundColor Red
        Read-Host "按 Enter 退出"
        exit 1
    }
    Write-Host "  ✓ 提交成功" -ForegroundColor Green
    $hasChanges = $true
}
Write-Host ""

# ═══════════════════════════════════════
#  第4步: git push
# ═══════════════════════════════════════
Write-Host "[4/4] 推送到 GitHub..." -ForegroundColor Yellow

if ($hasChanges) {
    Write-Host "  🚀 正在上传到 dreamobserver/HJM-memory..." -ForegroundColor Cyan

    # 先 pull 以防远程有更新（fast-forward only，不会产生 merge commit）
    Write-Host "  ↓ 先同步远程更新..." -ForegroundColor Gray
    git pull $remote $branch --ff-only 2>&1 | ForEach-Object { Write-Host "    $_" -ForegroundColor Gray }

    # push
    Write-Host "  ↑ 推送中..." -ForegroundColor Gray
    $pushOutput = git push $remote $branch 2>&1
    $pushOutput | ForEach-Object { Write-Host "    $_" -ForegroundColor Gray }

    if ($LASTEXITCODE -eq 0) {
        Write-Host ""
        Write-Host "╔══════════════════════════════════════╗" -ForegroundColor Green
        Write-Host "║  ✓ 备份完成! 已推送至 GitHub       ║" -ForegroundColor Green
        Write-Host "╚══════════════════════════════════════╝" -ForegroundColor Green
        Write-Host ""
        Write-Host "  仓库: https://github.com/dreamobserver/HJM-memory" -ForegroundColor Cyan
    } else {
        Write-Host ""
        Write-Host "╔══════════════════════════════════════╗" -ForegroundColor Red
        Write-Host "║  ✗ 推送失败! 请检查网络/GitHub认证  ║" -ForegroundColor Red
        Write-Host "╚══════════════════════════════════════╝" -ForegroundColor Red
        Read-Host "按 Enter 退出"
        exit 1
    }
} else {
    Write-Host "  ✓ 无需推送 (无变更)" -ForegroundColor Green
}

Write-Host ""
Read-Host "按 Enter 关闭窗口"
