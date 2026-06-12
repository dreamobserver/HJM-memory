# 编写一个cnn入门dem

**分类**: 杂项
**来源**: DeepSeek Chat 导出
**来源平台**: DeepSeek

---

# 用户：

帮助我编写一个cnn入门demo

# DeepSeek：

**原始回答**

好的！以下是一个简单的 **CNN（卷积神经网络）入门 Demo**，使用 **Python** 和 **PyTorch** 实现。这个示例会在 **MNIST 手写数字数据集** 上进行训练和测试，适合初学者理解 CNN 的基本结构和工作原理。  

---

## **CNN 入门 Demo（PyTorch 实现）**
### **1. 环境准备**
确保已安装 `torch` 和 `torchvision`，如果没有，可以运行：
```bash
pip install torch torchvision matplotlib numpy
```

---

### **2. 完整代码**
```python
import torch
import torch.nn as nn
import torch.optim as optim
import torchvision
import torchvision.transforms as transforms
import matplotlib.pyplot as plt
import numpy as np

# 设置设备（GPU 或 CPU）
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
print(f"Using device: {device}")

# 1. 加载 MNIST 数据集
transform = transforms.Compose([
    transforms.ToTensor(),  # 转为 Tensor，并归一化到 [0, 1]
    transforms.Normalize((0.5,), (0.5,))  # 标准化到 [-1, 1]
])

train_dataset = torchvision.datasets.MNIST(
    root="./data", train=True, transform=transform, download=True
)
test_dataset = torchvision.datasets.MNIST(
    root="./data", train=False, transform=transform, download=True
)

train_loader = torch.utils.data.DataLoader(train_dataset, batch_size=64, shuffle=True)
test_loader = torch.utils.data.DataLoader(test_dataset, batch_size=64, shuffle=False)

# 2. 定义 CNN 模型
class SimpleCNN(nn.Module):
    def __init__(self):
        super(SimpleCNN, self).__init__()
        self.conv1 = nn.Conv2d(1, 32, kernel_size=3, stride=1, padding=1)  # 输入 1 通道（灰度图），输出 32 通道
        self.relu = nn.ReLU()
        self.pool = nn.MaxPool2d(kernel_size=2, stride=2)  # 池化层，尺寸减半
        self.conv2 = nn.Conv2d(32, 64, kernel_size=3, stride=1, padding=1)
        self.fc1 = nn.Linear(64 * 7 * 7, 128)  # 全连接层（MNIST 经过两次池化后是 7x7）
        self.fc2 = nn.Linear(128, 10)  # 输出 10 类（0-9 数字）

    def forward(self, x):
        x = self.pool(self.relu(self.conv1(x)))
        x = self.pool(self.relu(self.conv2(x)))
        x = x.view(-1, 64 * 7 * 7)  # 展平
        x = self.relu(self.fc1(x))
        x = self.fc2(x)
        return x

model = SimpleCNN().to(device)

# 3. 定义损失函数和优化器
criterion = nn.CrossEntropyLoss()
optimizer = optim.Adam(model.parameters(), lr=0.001)

# 4. 训练模型
def train(model, train_loader, criterion, optimizer, epochs=5):
    model.train()
    for epoch in range(epochs):
        running_loss = 0.0
        for images, labels in train_loader:
            images, labels = images.to(device), labels.to(device)
            
            optimizer.zero_grad()
            outputs = model(images)
            loss = criterion(outputs, labels)
            loss.backward()
            optimizer.step()
            
            running_loss += loss.item()
        
        print(f"Epoch {epoch+1}/{epochs}, Loss: {running_loss/len(train_loader):.4f}")

train(model, train_loader, criterion, optimizer, epochs=5)

# 5. 测试模型
def test(model, test_loader):
    model.eval()
    correct = 0
    total = 0
    with torch.no_grad():
        for images, labels in test_loader:
            images, labels = images.to(device), labels.to(device)
            outputs = model(images)
            _, predicted = torch.max(outputs.data, 1)
            total += labels.size(0)
            correct += (predicted == labels).sum().item()
    
    accuracy = 100 * correct / total
    print(f"Test Accuracy: {accuracy:.2f}%")

test(model, test_loader)

# 6. 可视化预测结果
def visualize_predictions(model, test_loader, num_images=5):
    model.eval()
    images, labels = next(iter(test_loader))
    images, labels = images.to(device), labels.to(device)
    
    outputs = model(images)
    _, predicted = torch.max(outputs, 1)
    
    fig, axes = plt.subplots(1, num_images, figsize=(12, 3))
    for i in range(num_images):
        img = images[i].cpu().numpy().squeeze()
        axes[i].imshow(img, cmap="gray")
        axes[i].set_title(f"Pred: {predicted[i].item()}, True: {labels[i].item()}")
        axes[i].axis("off")
    plt.show()

visualize_predictions(model, test_loader)
```

---

### **3. 代码解析**
1. **数据加载**：
   - `torchvision.datasets.MNIST` 自动下载 MNIST 数据集（手写数字 0-9）。
   - `DataLoader` 用于批量加载数据。

2. **CNN 结构**：
   - `Conv2d`：卷积层（提取特征）。
   - `ReLU`：激活函数（引入非线性）。
   - `MaxPool2d`：池化层（降低计算量）。
   - `Linear`：全连接层（输出分类结果）。

3. **训练过程**：
   - `CrossEntropyLoss`：计算分类损失。
   - `Adam`：优化器，调整模型参数。
   - `model.train()` 和 `model.eval()`：切换训练/测试模式。

4. **测试与可视化**：
   - 计算测试集准确率。
   - 显示部分预测结果（预测值 vs 真实值）。

---

### **4. 运行结果示例**
```
Using device: cuda  # 如果有 GPU 会优先使用
Epoch 1/5, Loss: 0.2014
Epoch 2/5, Loss: 0.0672
Epoch 3/5, Loss: 0.0481
Epoch 4/5, Loss: 0.0376
Epoch 5/5, Loss: 0.0308
Test Accuracy: 98.91%  # 5 轮训练后测试准确率
```
![](https://i.imgur.com/XYZ1234.png)  
（可视化部分预测结果）

---

### **5. 进一步改进**
- **调整 CNN 结构**（增加卷积层、使用 BatchNorm）。
- **数据增强**（随机旋转、缩放，防止过拟合）。
- **尝试其他数据集**（如 CIFAR-10）。

如果你对某个部分有疑问，或者想尝试其他深度学习任务（如 RNN、Transformer），欢迎继续交流！ 🚀
