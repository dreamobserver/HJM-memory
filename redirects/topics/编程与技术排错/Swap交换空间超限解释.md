# Swap交换空间超限解释

**分类**：编程与技术排错
**来源**：DeepSeek Chat 导出
**来源平台**：DeepSeek
**原始文件**：PowerShell配置文件创建与编辑指南.md
**包含轮次**：31 - 31

---

# 用户：
fastfetch的参数怎么可以超过100%？   Memory: 15.22 GiB / 15.75 GiB (97%)
                                        Swap: 1.41 GiB / 1.00 GiB (141%)

# DeepSeek：

**原始回答**
您观察到的现象非常有趣，也确实可能会发生！让我解释一下为什么交换空间（Swap）的使用率会显示超过 100%，以及这背后的原因。

## 为什么交换空间使用率会超过 100%？

### 1. **交换空间与提交内存的区别**

在 Windows 中，有一个重要的概念叫做"提交内存"（Committed Memory），它与交换空间（页面文件）的使用有关：

- **提交内存** = 物理内存中已使用的部分 + 页面文件中预留的空间
- 系统会为应用程序分配比实际物理内存更多的"承诺"内存
- 当应用程序请求内存时，系统会承诺提供这些内存，但不一定立即分配物理内存

### 2. **内存过量使用（Overcommit）**

Windows 内存管理系统允许一定程度的"过量使用"：
- 系统可能承诺提供比实际可用物理内存+页面文件更多的内存
- 这是基于大多数程序不会同时使用所有已分配内存的假设
- 当实际需要的内存超过物理容量时，系统会积极地将内存页面交换到磁盘

### 3. **Fastfetch 的计算方式**

Fastfetch 可能使用以下公式计算交换空间使用率：
```
交换使用率 = (已提交内存 - 物理内存) / 页面文件大小 × 100%
```

如果已提交内存 > (物理内存 + 页面文件大小)，这个比率就会超过 100%。

## 如何验证和查看真实内存使用情况

您可以使用以下 PowerShell 命令来获取更准确的内存信息：

### 查看详细内存信息
```powershell
Get-WmiObject -Class Win32_OperatingSystem | Select-Object @{
    Name = "TotalPhysicalMemory(GB)"; Expression = {[math]::Round($_.TotalVisibleMemorySize/1MB, 2)}
}, @{
    Name = "FreePhysicalMemory(GB)"; Expression = {[math]::Round($_.FreePhysicalMemory/1MB, 2)}
}, @{
    Name = "TotalVirtualMemory(GB)"; Expression = {[math]::Round($_.TotalVirtualMemorySize/1MB, 2)}
}, @{
    Name = "FreeVirtualMemory(GB)"; Expression = {[math]::Round($_.FreeVirtualMemory/1MB, 2)}
}
```

### 查看页面文件信息
```powershell
Get-WmiObject -Class Win32_PageFileUsage | Select-Object @{
    Name = "PageFile(GB)"; Expression = {[math]::Round($_.AllocatedBaseSize/1KB, 2)}
}, @{
    Name = "CurrentUsage(GB)"; Expression = {[math]::Round($_.CurrentUsage/1KB, 2)}
}, @{
    Name = "UsagePercentage"; Expression = {[math]::Round(($_.CurrentUsage/$_.AllocatedBaseSize)*100, 2)}
}
```

### 使用系统自带工具
1. 按 `Ctrl+Shift+Esc` 打开任务管理器
2. 切换到"性能"选项卡
3. 点击"内存"查看详细信息
4. 注意"已提交"部分的数值

## 这种情况是否正常？

**是的，这种情况是正常的**，特别是在以下情况下：

1. **运行内存密集型应用程序**：如虚拟机、视频编辑软件、大型游戏等
2. **系统内存压力大**：当物理内存不足时，系统会更多地依赖页面文件
3. **内存泄漏**：某个应用程序可能正在不断请求内存但不释放

## 如何优化内存使用？

如果您发现交换空间使用率经常超过 100%，可以考虑：

1. **增加物理内存**：这是最直接的解决方案
2. **增加页面文件大小**：
   - 按 `Win+R`，输入 `sysdm.cpl`
   - 高级 → 性能 → 设置 → 高级 → 虚拟内存 → 更改
3. **关闭不必要的应用程序**：减少内存需求
4. **检查内存泄漏**：使用任务管理器识别占用大量内存的进程

## Fastfetch 的替代显示方式

如果您觉得超过 100% 的显示方式令人困惑，可以考虑使用其他工具或修改 Fastfetch 的配置：

### 使用 SystemInfo 命令
```powershell
systeminfo | findstr /C:"Total Physical Memory" /C:"Available Physical Memory" /C:"Virtual Memory"
```

### 修改 Fastfetch 配置
生成配置文件并调整内存显示方式：
```powershell
fastfetch --gen-config
# 然后编辑生成的配置文件，调整内存显示模块的设置
```

## 总结

您看到的交换空间使用率超过 100% 的情况是正常的 Windows 内存管理行为，反映了系统承诺的内存超过了物理内存和页面文件的实际容量。这并不一定表示有问题，但如果频繁发生且系统变得缓慢，可能表明需要增加物理内存或优化应用程序的内存使用。

如果您对内存使用有更多疑问或需要进一步的优化建议，请随时告诉我！

