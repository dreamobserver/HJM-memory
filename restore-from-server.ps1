# Cherry Studio 一键恢复（在新电脑上运行）
param(
    $Server = "root@154.7.177.216",
    $HjmTarget = "F:\HJM-memory",
    $CsTarget = "$env:APPDATA\CherryStudio\Data"
)

Write-Host "=== Cherry Studio 一键恢复 ===" -ForegroundColor Cyan
Write-Host "服务器: $Server"
Write-Host "CS数据: $CsTarget"
Write-Host "记忆库: $HjmTarget"
Write-Host ""

# 0. 检查 Cherry Studio 是否已安装
if (-not (Test-Path "$CsTarget")) {
    Write-Host "⚠ Cherry Studio Data 目录不存在，请先安装 Cherry Studio！" -ForegroundColor Red
    Write-Host "下载: https://cherrystudio.ai/"
    exit 1
}

# 1. 恢复 Cherry Studio Data
Write-Host "[1/2] 拉取 Cherry Studio Data..." -ForegroundColor Yellow
ssh $Server "test -d /home/backup/cherry-studio/Data" || {
    Write-Host "❌ 服务器上无备份数据！" -ForegroundColor Red
    exit 1
}
rsync -avz "${Server}:/home/backup/cherry-studio/Data/" "$CsTarget/"

# 2. 恢复 HJM-memory
Write-Host "[2/2] 拉取 HJM-memory..." -ForegroundColor Yellow
New-Item -ItemType Directory -Force -Path $HjmTarget | Out-Null
rsync -avz "${Server}:/home/backup/hjm-memory/" "$HjmTarget/"

Write-Host "=== 恢复完成！重启 Cherry Studio 即可 ===" -ForegroundColor Green
Write-Host "HJM-memory 位于: $HjmTarget"
