# Cherry Studio 全量备份到云服务器
$Server = "root@154.7.177.216"

Write-Host "=== Cherry Studio 全量备份 -> $Server ===" -ForegroundColor Cyan

# 1. 打包 Cherry Studio Data
Write-Host "[1/3] 打包 Cherry Studio Data..." -ForegroundColor Yellow
$csTar = "$env:TEMP\cs-backup.tar.gz"
Set-Location "$env:APPDATA\CherryStudio\Data"
tar -czf $csTar .
$csSize = (Get-Item $csTar).Length / 1MB
Write-Host "  CS Data: $($csSize.ToString('0.0')) MB"

# 2. 打包 HJM-memory
Write-Host "[2/3] 打包 HJM-memory..." -ForegroundColor Yellow
$hjmTar = "$env:TEMP\hjm-backup.tar.gz"
Set-Location F:\HJM-memory
# Windows tar: --exclude 后接 = 号
cmd /c "tar -czf $hjmTar --exclude=.git --exclude=analysis --exclude=dist --exclude=DSPI.Improved ."
$hjmSize = (Get-Item $hjmTar).Length / 1MB
Write-Host "  HJM-memory: $($hjmSize.ToString('0.0')) MB"

# 3. 上传
Write-Host "[3/3] 上传并解压..." -ForegroundColor Yellow
scp "$csTar" "$Server`:/home/backup/cs-backup.tar.gz"
scp "$hjmTar" "$Server`:/home/backup/hjm-backup.tar.gz"

# 服务器端解压
ssh $Server 'mkdir -p /home/backup/cherry-studio/Data /home/backup/hjm-memory && tar -xzf /home/backup/cs-backup.tar.gz -C /home/backup/cherry-studio/Data/ && tar -xzf /home/backup/hjm-backup.tar.gz -C /home/backup/hjm-memory/ && echo DONE'

# 清理
Remove-Item $csTar, $hjmTar -Force -ErrorAction SilentlyContinue
Write-Host "=== 备份完成 ===" -ForegroundColor Green
