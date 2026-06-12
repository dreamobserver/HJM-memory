# OpenCV相机标定代码

**分类**: 编程与技术排错
**来源**: DeepSeek Chat 导出
**来源平台**: DeepSeek

---

# 用户：

import cv2
import numpy as np
import glob
 
# 设置棋盘格参数
chessboard_size = (11, 8)  # 棋盘格的内角点个数
square_size = 1.0  # 棋盘格每个方格的实际大小，单位可以是毫米、厘米或米
 
# 准备棋盘格的世界坐标系坐标（假设z=0）
objp = np.zeros((chessboard_size[0] * chessboard_size[1], 3), np.float32)
objp[:, :2] = np.mgrid[0:chessboard_size[0], 0:chessboard_size[1]].T.reshape(-1, 2)
objp *= square_size
 
# 用于存储所有图像的世界坐标系点和图像坐标系点
objpoints = []  # 世界坐标系中的点
imgpoints = []  # 图像坐标系中的点
 
# 获取所有棋盘格图像的路径
images = glob.glob('board_image/*.png')
 
for image_path in images:
    img = cv2.imread(image_path)
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
 
    # 检测棋盘格角点
    ret, corners = cv2.findChessboardCorners(gray, chessboard_size, None)
 
    if ret:
        objpoints.append(objp)
        imgpoints.append(corners)
 
        # 绘制角点以进行可视化
        img = cv2.drawChessboardCorners(img, chessboard_size, corners, ret)
        cv2.imshow('Chessboard Corners', img)
        cv2.waitKey(0)
 
cv2.destroyAllWindows()
 
# 执行相机标定
ret, mtx, dist, rvecs, tvecs = cv2.calibrateCamera(objpoints, imgpoints, gray.shape[::-1], None, None)
 
# 输出相机的内参和畸变系数
print("Camera matrix:\n", mtx)
print("Distortion coefficients:\n", dist)
 
# 保存内参和畸变系数到文件
np.savez('camera_calibration.npz', mtx=mtx, dist=dist, rvecs=rvecs, tvecs=tvecs)
 
# 可选：验证标定结果
for image_path in images:
    img = cv2.imread(image_path)
    h, w = img.shape[:2]
 
    # 计算新的相机矩阵和有效像素区域
    # newcameramtx: 新的相机矩阵
    # roi: 有效像素区域（区域内的像素可以保证无畸变）
    newcameramtx, roi = cv2.getOptimalNewCameraMatrix(mtx, dist, (w, h), 1, (w, h))
 
    # 使用新的相机矩阵 undistort 方法校正畸变图像
    # mtx: 原始相机矩阵
    # dist: 畸变系数
    # newcameramtx: 新的相机矩阵
    dst = cv2.undistort(img, mtx, dist, None, newcameramtx)
 
    #  # 获取有效像素区域
    x, y, w, h = roi
    # 裁剪图像，只保留有效像素区域
    dst = dst[y:y + h, x:x + w]
 
    cv2.imshow('Undistorted Image', dst)
    cv2.waitKey(0)
 
cv2.destroyAllWindows()
 
# 加载 .npz 文件
data = np.load('camera_calibration.npz')
print('测试')
print(data['mtx'])
print(data['dist'])

# DeepSeek：

**原始回答**

这段代码是一个完整的 **相机标定（Camera Calibration）** 程序，使用 OpenCV 和 NumPy 实现。它的主要功能是通过拍摄多张棋盘格标定板的图像，计算相机的**内参（Camera Matrix）** 和 **畸变系数（Distortion Coefficients）**，并保存标定结果。最后，它还演示了如何用标定结果去矫正图像的畸变。  

---

## **代码分步解析**
### **1. 设置棋盘格参数**
```python
chessboard_size = (11, 8)  # 棋盘格的内角点个数（11列 x 8行）
square_size = 1.0  # 棋盘格每个方格的实际大小（单位：毫米/厘米/米）
```
- **`chessboard_size`**：棋盘格的角点数量（`(列数+1) x (行数+1)`），例如：
  - 如果棋盘格有 **10x7 个方格**，则角点数为 **11x8**。
- **`square_size`**：棋盘格每个方格的物理尺寸（单位可以是毫米、厘米或米），这里设为 `1.0`，但实际应用时需要根据真实尺寸调整。

---

### **2. 准备世界坐标系坐标**
```python
objp = np.zeros((chessboard_size[0] * chessboard_size[1], 3), np.float32)
objp[:, :2] = np.mgrid[0:chessboard_size[0], 0:chessboard_size[1]].T.reshape(-1, 2)
objp *= square_size
```
- **`objp`**：存储棋盘格角点的 **3D 世界坐标**（假设 `z=0`）。
- **`np.mgrid`** 生成网格坐标，例如：
  - `(0,0), (1,0), (2,0), ..., (10,0)`  
  - `(0,1), (1,1), (2,1), ..., (10,1)`  
  - ...  
  - `(0,7), (1,7), (2,7), ..., (10,7)`
- **`objp *= square_size`**：将坐标乘以实际尺寸（例如，如果 `square_size=2.5`，则每个方格边长 2.5cm）。

---

### **3. 存储世界坐标和图像坐标**
```python
objpoints = []  # 存储世界坐标系坐标（3D点）
imgpoints = []  # 存储图像坐标系坐标（2D点）
```
- **`objpoints`**：所有棋盘格图像的 **世界坐标**（相同，因为棋盘格在 3D 空间是固定的）。
- **`imgpoints`**：所有棋盘格图像的 **检测到的角点**（2D 像素坐标）。

---

### **4. 检测棋盘格角点**
```python
images = glob.glob('board_image/*.png')  # 读取所有标定板图片

for image_path in images:
    img = cv2.imread(image_path)
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)  # 转为灰度图

    # 检测棋盘格角点
    ret, corners = cv2.findChessboardCorners(gray, chessboard_size, None)

    if ret:  # 如果检测到角点
        objpoints.append(objp)  # 存储世界坐标
        imgpoints.append(corners)  # 存储图像坐标

        # 绘制角点并显示
        img = cv2.drawChessboardCorners(img, chessboard_size, corners, ret)
        cv2.imshow('Chessboard Corners', img)
        cv2.waitKey(0)
```
- **`cv2.findChessboardCorners()`**：检测棋盘格角点。
- **`cv2.drawChessboardCorners()`**：在图像上绘制检测到的角点（可视化）。

---

### **5. 相机标定**
```python
ret, mtx, dist, rvecs, tvecs = cv2.calibrateCamera(objpoints, imgpoints, gray.shape[::-1], None, None)
```
- **`ret`**：标定是否成功的标志（`True`/`False`）。
- **`mtx`**：相机内参矩阵（`3x3`）：
  \[
  \begin{bmatrix}
  f_x & 0 & c_x \\
  0 & f_y & c_y \\
  0 & 0 & 1
  \end{bmatrix}
  \]
  - `f_x, f_y`：焦距（像素单位）。
  - `c_x, c_y`：主点（图像中心）。
- **`dist`**：畸变系数（`k1, k2, p1, p2, k3`）。
- **`rvecs, tvecs`**：每张图像的旋转向量和平移向量（外参）。

---

### **6. 保存标定结果**
```python
np.savez('camera_calibration.npz', mtx=mtx, dist=dist, rvecs=rvecs, tvecs=tvecs)
```
- 将标定结果保存到 **`camera_calibration.npz`** 文件，方便后续使用。

---

### **7. 验证标定结果（去畸变）**
```python
for image_path in images:
    img = cv2.imread(image_path)
    h, w = img.shape[:2]

    # 计算新的相机矩阵（去除无效像素）
    newcameramtx, roi = cv2.getOptimalNewCameraMatrix(mtx, dist, (w, h), 1, (w, h))

    # 去畸变
    dst = cv2.undistort(img, mtx, dist, None, newcameramtx)

    # 裁剪图像（仅保留有效区域）
    x, y, w, h = roi
    dst = dst[y:y + h, x:x + w]

    cv2.imshow('Undistorted Image', dst)
    cv2.waitKey(0)
```
- **`cv2.getOptimalNewCameraMatrix()`**：计算去畸变后的新相机矩阵。
- **`cv2.undistort()`**：矫正图像畸变。
- **`roi`**：有效像素区域（裁剪掉黑边）。

---

### **8. 加载标定数据**
```python
data = np.load('camera_calibration.npz')
print('测试')
print(data['mtx'])  # 相机内参
print(data['dist']) # 畸变系数
```
- 从 `.npz` 文件加载标定数据，方便后续使用（如 3D 重建、AR 等）。

---

## **关键点总结**
1. **棋盘格角点检测**：`cv2.findChessboardCorners()` 是关键。
2. **相机标定**：`cv2.calibrateCamera()` 计算内参和畸变系数。
3. **去畸变**：`cv2.undistort()` 或 `cv2.getOptimalNewCameraMatrix()` + `cv2.undistort()`。
4. **保存/加载标定数据**：`np.savez()` 和 `np.load()`。

---

## **改进建议**
1. **优化角点检测**：
   - 使用 `cv2.cornerSubPix()` 提高角点检测精度：
     ```python
     if ret:
         # 亚像素级优化
         criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001)
         corners = cv2.cornerSubPix(gray, corners, (11,11), (-1,-1), criteria)
     ```
2. **使用更多标定图像**（至少 10-15 张不同角度）。
3. **检查标定误差**：
   ```python
   mean_error = 0
   for i in range(len(objpoints)):
       imgpoints2, _ = cv2.projectPoints(objpoints[i], rvecs[i], tvecs[i], mtx, dist)
       error = cv2.norm(imgpoints[i], imgpoints2, cv2.NORM_L2) / len(imgpoints2)
       mean_error += error
   print("Mean reprojection error: ", mean_error/len(objpoints))
   ```
   - **重投影误差（Reprojection Error）** 应 `< 0.5` 像素，否则标定可能不准确。

---

## **应用场景**
- **增强现实（AR）**：矫正相机畸变，提高 3D 物体叠加的准确性。
- **三维重建**：用于立体匹配、深度计算。
- **机器人视觉**：精确的物体定位。

希望这个解析对你有帮助！如果有问题，欢迎讨论。 🚀
