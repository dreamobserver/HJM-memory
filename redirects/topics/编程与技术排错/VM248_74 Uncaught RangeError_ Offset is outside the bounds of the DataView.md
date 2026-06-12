# VM248:74 Uncaught RangeError: Offset is outside the bounds of the DataView

**分类**: 编程与技术排错
**来源**: DeepSeek Chat 导出
**来源平台**: DeepSeek

---

# 用户：

VM248:74 Uncaught RangeError: Offset is outside the bounds of the DataView
    at DataView.prototype.setUint8 (<anonymous>)
    at getBMPData (<anonymous>:74:12)
    at <anonymous>:29:17

# DeepSeek：

**原始回答**

这个错误表明在写入BMP文件时，尝试访问了超出 `DataView` 范围的偏移量。问题出在 `getBMPData` 函数中，特别是在计算像素数据偏移和填充时。以下是修正后的代码：

```javascript
// 辅助函数：生成BMP格式数据
function getBMPData(canvas) {
  const ctx = canvas.getContext('2d');
  const imageData = ctx.getImageData(0, 0, canvas.width, canvas.height);
  const data = imageData.data;
  const width = canvas.width;
  const height = canvas.height;
  
  // 计算每行字节数（必须4字节对齐）
  const bytesPerRow = Math.floor((width * 3 + 3) / 4) * 4;
  const pixelDataSize = bytesPerRow * height;
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

  // 写入像素数据（BGR格式，从下到上）
  let offset = 54;
  for (let y = height - 1; y >= 0; y--) {
    let rowOffset = 0;
    for (let x = 0; x < width; x++) {
      const pixelIndex = (y * width + x) * 4;
      view.setUint8(offset + rowOffset, data[pixelIndex + 2]);  // B
      view.setUint8(offset + rowOffset + 1, data[pixelIndex + 1]);  // G
      view.setUint8(offset + rowOffset + 2, data[pixelIndex]);      // R
      rowOffset += 3;
    }
    // 填充对齐字节
    while (rowOffset < bytesPerRow) {
      view.setUint8(offset + rowOffset, 0);
      rowOffset++;
    }
    offset += bytesPerRow;
  }
  return new Uint8Array(buffer);
}
```

主要修改点：

1. 修正了保留字段的设置（4-7字节）
2. 改进了像素数据的写入方式，使用单独的 `rowOffset` 来跟踪每行的偏移
3. 确保每行填充到正确的字节数（`bytesPerRow`）
4. 使用更安全的方式处理行填充，避免超出边界

这个版本应该不会再出现 `RangeError`，并且能正确生成BMP文件。如果仍然遇到问题，可能需要检查：
- 确保 `width` 和 `height` 是正整数
- 确保 `bytesPerRow` 计算正确（应该是 `Math.floor((width * 3 + 3) / 4) * 4`）
- 确保 `fileSize` 计算正确（应该是 `54 + bytesPerRow * height`）
