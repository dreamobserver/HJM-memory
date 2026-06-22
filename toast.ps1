param($Title, $Message)

[void] [System.Reflection.Assembly]::LoadWithPartialName("System.Windows.Forms")
[void] [System.Reflection.Assembly]::LoadWithPartialName("System.Drawing")
$icon = [System.Drawing.SystemIcons]::Information
$notify = New-Object System.Windows.Forms.NotifyIcon
$notify.Icon = $icon
$notify.BalloonTipIcon = 'Info'
$notify.BalloonTipTitle = $Title
$notify.BalloonTipText = $Message
$notify.Visible = $true
$notify.ShowBalloonTip(10000)
Start-Sleep -Seconds 11
$notify.Visible = $false
$notify.Dispose()
