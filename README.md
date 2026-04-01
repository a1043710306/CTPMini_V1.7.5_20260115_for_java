# CTPMini V1.7.5 (20260115)

本目录包含 CTPMini 原生 C++ SDK（Windows/Linux）以及基于 SWIG 的 Java JNI 绑定工程。

## 目录说明

```text
CTPMini_V1.7.5_20260115/
├── CTPMini_V1.7.5_win_api_20260115/      # Windows C++ SDK（win32/win64）
├── CTPMini_V1.7.5_linux64_api_20260115/  # Linux C++ SDK（linux64）
└── swig_java/                             # SWIG + CMake Java 绑定工程
```

## Java 绑定输出约定

Java 自动生成源码按 API 类型分目录输出：

- `mdapi`：行情接口
- `tradeapi`：交易接口

示例（Windows 构建目录）：

```text
swig_java/build_win64/java/
├── mdapi/
└── tradeapi/
```

安装后输出（示例）：

```text
swig_java/install_win64/
├── bin/       # JNI DLL + C++ SDK 运行时 DLL
└── java/src/
    ├── mdapi/
    └── tradeapi/
```

## 环境依赖

### 必需依赖

| 组件 | 最低版本 | 说明 |
|---|---:|---|
| CMake | 3.14+ | 用于配置/构建 JNI 工程 |
| SWIG | 3.0+ | 生成 Java/JNI 包装代码 |
| JDK | 8+ | 需要 `javac`，建议 JDK 17 |
| C++ 编译器 | - | Windows: Visual Studio C++ 工具链；Linux: g++/clang++ |

### Windows 额外要求

- Visual Studio 2015/2017/2019/2022/2026（安装 `Desktop development with C++`）
- 推荐 x64 构建（脚本默认 `-A x64`）

### Linux 额外要求

- 构建工具：`make` 或 `ninja`
- 运行期若加载 JNI 动态库，需保证 `LD_LIBRARY_PATH` 包含 `install_linux64/lib`

### 当前已验证环境（示例）

根据当前构建日志，以下组合可正常进入配置阶段：

- CMake `4.3.1`
- SWIG `4.4.0`
- JDK `graalvm-jdk-17`（`JAVA_HOME=D:\jdk\graalvm-jdk-17`）
- Generator `Visual Studio 18 2026`（x64）

## 快速构建

### Windows

```bat
cd swig_java
build_windows.bat
```

### Linux

```bash
cd swig_java
chmod +x build_linux.sh
./build_linux.sh
```

## 关键映射说明

在 SWIG 接口中，以下 C++ 参数已映射为 Java `String[]`：

- `SubscribeMarketData(char *ppInstrumentID[], int nCount)`
- `UnSubscribeMarketData(char *ppInstrumentID[], int nCount)`
- `SubscribeFlowCtrlWarning(char *ppTraderID[], int nCount)`
- `UnSubscribeFlowCtrlWarning(char *ppTraderID[], int nCount)`

## 详细文档

请查看：`swig_java/README.md`
