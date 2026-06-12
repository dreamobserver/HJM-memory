# inc就是include文件夹是吗？所以我该选择D:\Daheng Imaging\GalaxySDK\Development\C++ SDK\inc文件夹？

**分类**: 编程与技术排错
**来源**: DeepSeek Chat 导出
**来源平台**: DeepSeek

---

# 用户：

inc就是include文件夹是吗？所以我该选择D:\Daheng Imaging\GalaxySDK\Development\C++ SDK\inc文件夹？

# DeepSeek：

**原始回答**

对的！**`inc` 就是 `include` 文件夹的常见缩写**，在软件开发中经常这样命名。所以：

## 正确路径确认

你应该选择：  
**`D:\Daheng Imaging\GalaxySDK\Development\C++ SDK\inc`**

---

## 在 Visual Studio 中的配置方法

### 步骤 1：打开项目属性
- 右键点击项目 → 选择 **属性**

### 步骤 2：配置附加包含目录
- 进入 **C/C++** → **常规** → **附加包含目录**
- 点击下拉箭头 → 选择 **编辑**

### 步骤 3：添加路径
```
D:\Daheng Imaging\GalaxySDK\Development\C++ SDK\inc
```

或者使用宏（更灵活）：
```
$(Drive_D)\Daheng Imaging\GalaxySDK\Development\C++ SDK\inc
```

---

## 验证建议

1. **双击打开该路径**，确认里面确实有 `.h` 或 `.hpp` 头文件
2. **检查是否有多个 inc 文件夹**，比如在 `VC SDK` 下可能也有：
   - `D:\Daheng Imaging\GalaxySDK\Development\VC SDK\inc`
3. **如果需要多个路径**，用分号分隔：
   ```
   D:\Daheng Imaging\GalaxySDK\Development\C++ SDK\inc;
   D:\Daheng Imaging\GalaxySDK\Development\VC SDK\inc
   ```

---

## 如果还有问题

检查大恒图像的官方文档，或者查看 `Doc` 文件夹中的说明文件，确认正确的包含路径。通常 SDK 文档会明确指定需要包含的目录路径。
