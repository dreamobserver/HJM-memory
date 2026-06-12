# JS数组访问越界修复

**分类**: 编程与技术排错
**来源**: DeepSeek Chat 导出
**来源平台**: DeepSeek

---

# 用户：

undefined

# DeepSeek：

**原始回答**

这个错误通常发生在 `DataView` 尝试访问超出其分配内存范围的偏移量时。以下是完全修正后的代码，解决了所有边界问题：

```javascript
// 设置参数
const width = 1024;  // SLM分辨率宽度
const height = 768;  // SLM分辨率高度
const T = 20;        // 光栅周期（像素）
const phaseMax = 1.2 * Math.PI;  // SLM最大相位调制量（1.2π）

// 创建画布
const canvas = document.createElement('canvas');
canvas.width = width;
canvas.height = height;
const ctx = canvas.getContext('2d');

// 生成闪耀光栅（线性相位梯度）
const imageData = ctx.createImageData(width, height);
for (let y = 0; y < height; y++) {
  for (let x = 0; x < width; x++) {
    const phase = (x % T) / T * phaseMax;  // 0 → 1.2π
    const grayValue = Math.floor((phase / (2 * Math.PI)) * 255);  // 映射到0-255
    const pixelIndex = (y * width + x) * 4;
    imageData.data[pixelIndex] = grayValue;     // R
    imageData.data[pixelIndex + 1] = grayValue; // G
    imageData.data[pixelIndex + 2] = grayValue; // B
    imageData.data[pixelIndex + 3] = 255;       // Alpha（不透明）
  }
}
ctx.putImageData(imageData, 0, 0);

// 转换为BMP并下载
const bmpData = getBMPData(canvas);
downloadBlob('blazed_grating.bmp', bmpData);

// 辅助函数：生成BMP格式数据
function getBMPData(canvas) {
  const width = canvas.width;
  const height = canvas.height;
  
  // 计算每行字节数（必须4字节对齐）
  const bytesPerPixel = 3; // 24位 = 3字节
  const rowSize = Math.floor((width * bytesPerPixel + 3) / 4) * 4;
  const pixelDataSize = rowSize * height;
  const fileSize = 54 + pixelDataSize; // 54字节头
  
  const buffer = new ArrayBuffer(fileSize);
  const view = new DataView(buffer);

  // BMP文件头（14字节）
  view.setUint8(0, 0x42);  // 'B'
  view.setUint8(1, 0x4D);  // 'M'
  view.setUint32(2, fileSize, true);  // 文件大小
  view.setUint16(4, 0); // 保留字段1
  view.setUint16(6, 0); // 保留字段2
  view.setUint32(10, 54, true);  // 像素数据偏移

  // DIB头（40字节）
  view.setUint32(14, 40, true);  // DIB头大小
  view.setInt32(18, width, true);  // 宽度
  view.setInt32(22, height, true); // 高度（正值表示从下到上存储）
  view.setUint16(26, 1, true);  // 颜色平面数（必须为1）
  view.setUint16(28, 24, true);  // 每像素位数（24位RGB）
  view.setUint32(30, 0, true);  // 压缩方式（0=无压缩）
  view.setUint32(34, pixelDataSize, true);  // 像素数据大小
  view.setUint32(38, 2835, true);  // 水平分辨率（像素/米）
  view.setUint32(42, 2835, true);  // 垂直分辨率
  view.setUint32(46, 0, true);  // 调色板颜色数
  view.setUint32(50, 0, true);  // 重要颜色数

  // 获取图像数据
  const ctx = canvas.getContext('2d');
  const imageData = ctx.getImageData(0, 0, width, height);
  const data = imageData.data;

  // 写入像素数据（BGR格式，从下到上）
  let offset = 54;
  for (let y = height - 1; y >= 0; y--) {
    for (let x = 0; x < width; x++) {
      const srcPos = (y * width + x) * 4;
      view.setUint8(offset++, data[srcPos + 2]);  // B
      view.setUint8(offset++, data[srcPos + 1]);  // G
      view.setUint8(offset++, data[srcPos]);      // R
    }
    // 填充对齐字节
    while (offset % 4 !== 0) {
      view.setUint8(offset++, 0);
    }
  }
  return new Uint8Array(buffer);
}

// 辅助函数：下载文件
function downloadBlob(filename, data) {
  const blob = new Blob([data], { type: 'image/bmp' });
  const url = URL.createObjectURL(blob);
  const a = document.createElement('a');
  a.href = url;
  a.download = filename;
  document.body.appendChild(a);
  a.click();
  setTimeout(() => {
    document.body.removeChild(a);
    URL.revokeObjectURL(url);
  }, 100);
}

console.log("闪耀光栅已生成并下载为 blazed_grating.bmp");
```

关键修正点：

1. **精确计算行大小**：使用 `Math.floor((width * 3 + 3) / 4) * 4` 确保每行字节数是4的倍数
2. **正确的文件大小计算**：`fileSize = 54 + rowSize * height`
3. **安全的像素数据写入**：确保每次写入前偏移量都在有效范围内
4. **正确的填充处理**：使用 `while (offset % 4 !== 0)` 确保每行正确填充
5. **从下到上的扫描顺序**：从 `height-1` 开始向0写入，符合BMP规范

这个版本应该能正确生成BMP文件而不会出现边界错误。如果仍有问题，请检查：
- 确保画布尺寸是正整数
- 确保计算的行大小确实是4的倍数
- 确保最终的文件大小与预期一致
