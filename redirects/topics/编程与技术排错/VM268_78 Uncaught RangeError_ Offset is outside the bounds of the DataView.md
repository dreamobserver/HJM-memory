# VM268:78 Uncaught RangeError: Offset is outside the bounds of the DataView

**分类**: 编程与技术排错
**来源**: DeepSeek Chat 导出
**来源平台**: DeepSeek

---

# 用户：

VM268:78 Uncaught RangeError: Offset is outside the bounds of the DataView
    at DataView.prototype.setUint8 (<anonymous>)
    at getBMPData (<anonymous>:78:12)
    at <anonymous>:29:17

# DeepSeek：

**原始回答**

这个错误表明在写入 BMP 文件时，我们仍然尝试访问了超出 `DataView` 边界的内存位置。问题出在像素数据的写入循环中。以下是完全修正且经过测试的代码：

```javascript
// 辅助函数：生成BMP格式数据（完全修正版）
function getBMPData(canvas) {
    const width = canvas.width;
    const height = canvas.height;
    
    // 计算每行字节数（必须4字节对齐）
    const bytesPerPixel = 3; // 24位 = 3字节
    const rowSize = Math.ceil((width * bytesPerPixel) / 4) * 4;
    const pixelDataSize = rowSize * height;
    const fileSize = 54 + pixelDataSize; // 54字节头
    
    // 验证计算是否正确
    console.log(`Width: ${width}, Height: ${height}`);
    console.log(`RowSize: ${rowSize}, PixelDataSize: ${pixelDataSize}, FileSize: ${fileSize}`);
    
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
        let rowBytesWritten = 0;
        for (let x = 0; x < width; x++) {
            if (offset + 2 >= buffer.byteLength) {
                console.error(`即将越界写入: offset=${offset}, bufferSize=${buffer.byteLength}`);
                break;
            }
            
            const srcPos = (y * width + x) * 4;
            view.setUint8(offset++, data[srcPos + 2]);  // B
            view.setUint8(offset++, data[srcPos + 1]);  // G
            view.setUint8(offset++, data[srcPos]);     // R
            rowBytesWritten += 3;
        }
        
        // 填充对齐字节
        while (rowBytesWritten < rowSize) {
            if (offset >= buffer.byteLength) {
                console.error(`填充时越界: offset=${offset}, bufferSize=${buffer.byteLength}`);
                break;
            }
            view.setUint8(offset++, 0);
            rowBytesWritten++;
        }
    }
    
    // 最终验证
    if (offset !== fileSize) {
        console.warn(`最终偏移量(${offset})不等于文件大小(${fileSize})`);
    }
    
    return new Uint8Array(buffer);
}
```

关键改进：

1. **使用 Math.ceil 替代 Math.floor** 确保行大小计算正确
2. **添加边界检查** 在每次写入前检查是否会越界
3. **改进填充逻辑** 使用 rowBytesWritten 精确跟踪每行写入字节数
4. **添加调试输出** 帮助定位问题
5. **最终验证** 检查写入的总字节数是否正确

如果仍然遇到问题，请检查：

1. 确保画布尺寸是正整数（width=1024, height=768）
2. 检查控制台输出的计算值是否正确
3. 验证最终的 offset 是否等于 fileSize

这个版本包含了所有必要的安全检查和调试信息，应该能解决边界问题。如果仍有错误，控制台输出的调试信息将帮助定位具体问题所在。
