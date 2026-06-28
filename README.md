# 国密本地授权管理器

## 🎯 项目定位

一个**轻量级、纯文件管理**的本地授权工具，专为**没有HSM硬件设备**的场景设计。

通过SM2/SM3/SM4国密算法，实现授权文件的生成与验证，所有操作基于文件系统，无需部署复杂的授权服务器。

## 👥 适用人群

- 软件开发商：需要为软件添加授权验证功能
- 企业内部IT：需要管理内部软件的授权分发
- 独立开发者：需要简单可靠的授权方案
- **特别适合**：没有HSM服务、不想搭建授权服务器的场景

## 🔐 核心功能

### 1. 密钥管理（纯文件）
- 生成SM2密钥对（私钥/公钥）
- 生成SM4对称密钥
- 密钥文件以PEM/Base64格式保存
- 私钥支持密码加密保护

### 2. 授权生成
- 输入：版本号、MAC地址(硬件指纹)、有效期
- 处理：SM3哈希 → SM2签名 → SM4加密
- 输出：`.lic`授权文件

### 3. 授权验证
- 验证签名完整性
- 检查MAC地址（硬件指纹）匹配
- 检查有效期
- 显示授权详情

## 💻 技术规格

| 项目 | 说明 |
|------|------|
| 加密库 | GMSSL（国密算法） |
| 开发框架 | Qt Widgets |
| 语言标准 | C++11 |
| Qt版本 | 5.15.2 (MinGW 64-bit) |
| 支持平台 | Windows / Linux |

## 📦 编译说明

### 环境要求
- Qt 5.15.2+ (MinGW 64-bit)
- GMSSL源码库
- 支持C++11的编译器

### 编译步骤

```bash
# 1. 下载GMSSL源码
git clone https://github.com/guanzhi/GmSSL
cd GmSSL

# 2. 编译GMSSL（根据您的平台）
# Windows (MinGW)
./config --prefix=/usr/local
make
make install

# Linux
./config
make
sudo make install

# 3. 替换项目中的库文件
# 将编译生成的 libgmssl.so / libgmssl.a 放到项目lib目录

# 4. 使用Qt Creator打开项目
# 打开 GMSSL-Local-License-Manager.pro

# 5. 构建并运行
# 选择 Qt_5_15_2_MinGW_64 套件，点击构建运行

#6.安装包后期我上传
