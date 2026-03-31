# CTP Mini Java SDK

上海期货信息技术有限公司 **CTP Mini V1.7.5** 交易系统 Java SDK。

对应 C++ API 版本：
- Linux：`CTPMini_V1.7.5_linux64_api_20260115`
- Windows：`CTPMini_V1.7.5_win_api_20260115`（含 win32 / win64）

---

## 项目结构

```
ctpjava/
├── pom.xml
├── README.md
├── jni/                                  # JNI C++ 桥接层
│   ├── CMakeLists.txt                    # 统一构建脚本（Windows / Linux）
│   ├── include/
│   │   └── jni_utils.h                  # JNI 工具宏与函数声明
│   └── src/
│       ├── jni_utils.cpp                # JavaVM 管理、字符串转换、平台适配
│       ├── struct_convert.cpp           # CTP struct <-> Java POJO 转换
│       ├── MdApi_jni.cpp                # 行情 API JNI 实现
│       └── TraderApi_jni.cpp            # 交易 API JNI 实现
└── src/main/java/com/ctpmini/
    ├── api/
    │   ├── CThostFtdcMdApi.java          # 行情API（抽象类）
    │   ├── CThostFtdcMdSpi.java          # 行情回调SPI
    │   ├── CThostFtdcTraderApi.java      # 交易API（抽象类）
    │   └── CThostFtdcTraderSpi.java      # 交易回调SPI
    ├── constants/
    │   └── ThostFtdcUserApiDataType.java # 所有常量定义
    └── struct/
        ├── CThostFtdcReqUserLoginField.java
        ├── CThostFtdcRspUserLoginField.java
        ├── CThostFtdcDepthMarketDataField.java
        ├── CThostFtdcInputOrderField.java
        ├── CThostFtdcOrderField.java
        ├── CThostFtdcTradeField.java
        ├── CThostFtdcInvestorPositionField.java
        ├── CThostFtdcTradingAccountField.java
        └── ... (所有请求/响应/查询结构体)
```

---

## 包说明

| 包 | 说明 |
|---|---|
| `com.ctpmini.api` | API接口和SPI回调，对应 `ThostFtdcMdApi.h` / `ThostFtdcTraderApi.h` |
| `com.ctpmini.constants` | 所有常量定义，对应 `ThostFtdcUserApiDataType.h` |
| `com.ctpmini.struct` | 所有数据结构，对应 `ThostFtdcUserApiStruct.h` |

---

## JNI 桥接层编译教程

> Java 端通过 JNI 桥接层调用 CTP C++ 原生库。需先编译 `jni/` 目录下的 C++ 代码，生成动态库后再启动 Java 程序。
>
> **Windows 和 Linux 共用同一个 `jni/CMakeLists.txt`，无需切换文件。**

### 前置依赖

| 依赖 | Linux | Windows |
|---|---|---|
| C++ 编译器 | GCC 7+ 或 Clang 6+ | Visual Studio 2017+ (MSVC) |
| CMake | 3.14+ | 3.14+ |
| JDK | 8+ | 8+ |
| 环境变量 | `JAVA_HOME` 指向 JDK 根目录 | `JAVA_HOME` 指向 JDK 根目录 |

---

### Linux 编译

#### 1. 确认目录结构

编译前确认以下文件存在：

```
CTPMini_V1.7.5_20260115/
├── ctpjava/jni/                             ← 本项目 JNI 源码（CMakeLists.txt 在此）
└── CTPMini_V1.7.5_linux64_api_20260115/
    ├── traderapi/
    │   ├── ThostFtdcTraderApi.h
    │   ├── ThostFtdcUserApiStruct.h
    │   ├── ThostFtdcUserApiDataType.h
    │   └── libthosttraderapi.so
    └── mdapi/
        ├── ThostFtdcMdApi.h
        ├── ThostFtdcUserApiStruct.h
        ├── ThostFtdcUserApiDataType.h
        └── libthostmduserapi.so
```

#### 2. 设置 JAVA_HOME

```bash
export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64
# 根据实际 JDK 路径调整，例如：
# export JAVA_HOME=/opt/jdk-11
```

#### 3. 配置并编译

```bash
cd ctpjava/jni

cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -- -j$(nproc)
```

如果 CMake 找不到 JNI，可手动传入 `JAVA_HOME`：

```bash
cmake -S . -B build \
    -DCMAKE_BUILD_TYPE=Release \
    -DJAVA_HOME=$JAVA_HOME
cmake --build build -- -j$(nproc)
```

编译成功后在 `build/` 目录下生成：

```
libctpjni.so
```

#### 4. 验证

```bash
# 检查编译产物
ls -la build/libctpjni.so

# 确认动态库依赖
ldd build/libctpjni.so
```

#### 5. 部署

将以下三个文件放到同一目录（或加入 `LD_LIBRARY_PATH`）：

```
libctpjni.so
libthosttraderapi.so
libthostmduserapi.so
```

运行 Java 程序时指定库路径：

```bash
java -Djava.library.path=./libs -jar your-app.jar
```

---

### Windows 编译

#### 1. 确认目录结构

编译前确认以下文件存在：

```
CTPMini_V1.7.5_20260115\
├── ctpjava\jni\                             ← 本项目 JNI 源码（CMakeLists.txt 在此）
└── CTPMini_V1.7.5_win_api_20260115\
    ├── win64\
    │   ├── traderapi\
    │   │   ├── ThostFtdcTraderApi.h
    │   │   ├── thosttraderapi.lib           ← 导入库
    │   │   └── thosttraderapi.dll           ← 运行时库
    │   └── mdapi\
    │       ├── ThostFtdcMdApi.h
    │       ├── thostmduserapi.lib
    │       └── thostmduserapi.dll
    └── win32\
        ├── traderapi\ ...
        └── mdapi\ ...
```

#### 2. 设置 JAVA_HOME

在 PowerShell 中：

```powershell
$env:JAVA_HOME = "C:\Program Files\Java\jdk1.8.0_xxx"
# 或永久设置：
[System.Environment]::SetEnvironmentVariable("JAVA_HOME", "C:\Program Files\Java\jdk1.8.0_xxx", "User")
```

#### 3. 配置并编译

**x64（推荐，与 64 位 JDK 对应）：**

```powershell
cd ctpjava\jni

cmake -S . -B build_win64 -G "Visual Studio 17 2022" -A x64
cmake --build build_win64 --config Release
```

**x86（与 32 位 JDK 对应）：**

```powershell
cd ctpjava\jni

cmake -S . -B build_win32 -G "Visual Studio 17 2022" -A Win32
cmake --build build_win32 --config Release
```

> 其他 Visual Studio 版本的生成器写法：
> - VS 2022：`-G "Visual Studio 17 2022"`（当前版本）
> - VS 2019：`-G "Visual Studio 16 2019"`
> - VS 2017：`-G "Visual Studio 15 2017"`

如果 CMake 找不到 JNI，可手动传入 `JAVA_HOME`：

```powershell
cmake -S . -B build_win64 -G "Visual Studio 17 2022" -A x64 `
    -DJAVA_HOME="$env:JAVA_HOME"
```

编译成功后在 `build_win64\Release\` 目录下生成：

```
ctpjni.dll            ← JNI 桥接库（Java System.loadLibrary("ctpjni") 加载）
ctpjni.lib            ← 导入库（可选）
thosttraderapi.dll    ← 构建后自动复制
thostmduserapi.dll    ← 构建后自动复制
```

#### 4. 验证

```powershell
# 检查编译产物
dir build_win64\Release\ctpjni.dll

# 确认 CTP DLL 已自动复制
dir build_win64\Release\thosttraderapi.dll
dir build_win64\Release\thostmduserapi.dll
```

#### 5. 部署

将以下三个文件放到同一目录，或加入系统 `PATH`：

```
ctpjni.dll
thosttraderapi.dll
thostmduserapi.dll
```

运行 Java 程序时指定库路径：

```powershell
java -Djava.library.path=.\libs -jar your-app.jar
```

---

### 常见问题

#### Q：CMake 报错 `JNI_INCLUDE_DIRS not found`

确认 `JAVA_HOME` 已正确设置，且路径下存在 `include/` 目录：

```bash
# Linux
ls $JAVA_HOME/include/jni.h

# Windows PowerShell
Test-Path "$env:JAVA_HOME\include\jni.h"
```

#### Q：Linux 运行时报 `java.lang.UnsatisfiedLinkError`

检查三个 `.so` 文件是否在同一目录，且 `LD_LIBRARY_PATH` 包含该目录：

```bash
export LD_LIBRARY_PATH=/path/to/libs:$LD_LIBRARY_PATH
```

#### Q：Windows 运行时报 `UnsatisfiedLinkError: Can't find dependent libraries`

确认 `thosttraderapi.dll` 和 `thostmduserapi.dll` 与 `ctpjni.dll` 在同一目录，或已加入系统 `PATH`。

#### Q：编译报 `C2001 常量中有换行符` 或乱码警告（Windows）

CTP 头文件原始编码为 GBK。CMakeLists.txt 已加入 `/utf-8` 选项处理此问题，若仍有乱码警告，可改为：

```cmake
target_compile_options(ctpjni PRIVATE /source-charset:gbk /execution-charset:utf-8)
```

#### Q：Linux 链接报 `undefined reference to CThostFtdcTraderApi::...`

确认 `libthosttraderapi.so` 路径正确，且文件未损坏：

```bash
file /path/to/libthosttraderapi.so
nm /path/to/libthosttraderapi.so | grep CreateFtdcTraderApi
```

---

## 使用说明

### 一、行情 API 使用示例

```java
import com.ctpmini.api.*;
import com.ctpmini.struct.*;
import com.ctpmini.constants.ThostFtdcUserApiDataType;

// 1. 实现SPI回调
public class MyMdSpi extends CThostFtdcMdSpi {

    private final CThostFtdcMdApi mdApi;

    public MyMdSpi(CThostFtdcMdApi mdApi) {
        this.mdApi = mdApi;
    }

    @Override
    public void OnFrontConnected() {
        System.out.println("行情前置已连接，开始登录...");
        CThostFtdcReqUserLoginField req = new CThostFtdcReqUserLoginField();
        req.BrokerID = "9999";
        req.UserID   = "your_user_id";
        req.Password = "your_password";
        mdApi.ReqUserLogin(req, 1);
    }

    @Override
    public void OnRspUserLogin(CThostFtdcRspUserLoginField pRspUserLogin,
                               CThostFtdcRspInfoField pRspInfo,
                               int nRequestID, boolean bIsLast) {
        if (pRspInfo == null || pRspInfo.ErrorID == 0) {
            System.out.println("行情登录成功，交易日: " + pRspUserLogin.TradingDay);
            // 订阅行情
            mdApi.SubscribeMarketData(new String[]{"IF2506", "cu2506"}, 2);
        } else {
            System.err.println("行情登录失败: " + pRspInfo.ErrorMsg);
        }
    }

    @Override
    public void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField pDepthMarketData) {
        System.out.printf("[%s] 合约=%s 最新价=%.2f 买一=%.2f 卖一=%.2f%n",
            pDepthMarketData.UpdateTime,
            pDepthMarketData.InstrumentID,
            pDepthMarketData.LastPrice,
            pDepthMarketData.BidPrice1,
            pDepthMarketData.AskPrice1);
    }
}

// 2. 启动行情
public class MdMain {
    public static void main(String[] args) throws Exception {
        // 加载JNI桥接库（对应 libctpjni.so / ctpjni.dll）
        System.loadLibrary("ctpjni");

        CThostFtdcMdApi mdApi = CThostFtdcMdApi.CreateFtdcMdApi("./flow_md/");
        mdApi.RegisterSpi(new MyMdSpi(mdApi));
        mdApi.RegisterFront("tcp://180.168.146.187:10131"); // 上期模拟行情地址
        mdApi.Init();
        mdApi.Join();
    }
}
```

---

### 二、交易 API 使用示例

```java
import com.ctpmini.api.*;
import com.ctpmini.struct.*;
import com.ctpmini.constants.ThostFtdcUserApiDataType;

public class MyTraderSpi extends CThostFtdcTraderSpi {

    private final CThostFtdcTraderApi traderApi;
    private int requestId = 0;

    public MyTraderSpi(CThostFtdcTraderApi traderApi) {
        this.traderApi = traderApi;
    }

    @Override
    public void OnFrontConnected() {
        System.out.println("交易前置已连接，开始认证...");
        CThostFtdcReqAuthenticateField req = new CThostFtdcReqAuthenticateField();
        req.BrokerID        = "9999";
        req.UserID          = "your_user_id";
        req.UserProductInfo = "Java_SDK";
        req.AuthCode        = "your_auth_code";
        req.AppID           = "your_app_id";
        traderApi.ReqAuthenticate(req, ++requestId);
    }

    @Override
    public void OnRspAuthenticate(CThostFtdcRspAuthenticateField pRspAuthenticateField,
                                   CThostFtdcRspInfoField pRspInfo,
                                   int nRequestID, boolean bIsLast) {
        if (pRspInfo == null || pRspInfo.ErrorID == 0) {
            System.out.println("认证成功，开始登录...");
            CThostFtdcReqUserLoginField req = new CThostFtdcReqUserLoginField();
            req.BrokerID = "9999";
            req.UserID   = "your_user_id";
            req.Password = "your_password";
            traderApi.ReqUserLogin(req, ++requestId);
        }
    }

    @Override
    public void OnRspUserLogin(CThostFtdcRspUserLoginField pRspUserLogin,
                               CThostFtdcRspInfoField pRspInfo,
                               int nRequestID, boolean bIsLast) {
        if (pRspInfo == null || pRspInfo.ErrorID == 0) {
            System.out.println("交易登录成功! FrontID=" + pRspUserLogin.FrontID
                + " SessionID=" + pRspUserLogin.SessionID);
            // 查询持仓
            CThostFtdcQryInvestorPositionField qry = new CThostFtdcQryInvestorPositionField();
            qry.BrokerID = "9999";
            qry.InvestorID = "your_user_id";
            traderApi.ReqQryInvestorPosition(qry, ++requestId);
        }
    }

    @Override
    public void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField pInvestorPosition,
                                          CThostFtdcRspInfoField pRspInfo,
                                          int nRequestID, boolean bIsLast) {
        if (pInvestorPosition != null) {
            System.out.printf("持仓: 合约=%s 方向=%c 持仓=%d%n",
                pInvestorPosition.InstrumentID,
                pInvestorPosition.PosiDirection,
                pInvestorPosition.Position);
        }
    }

    @Override
    public void OnRtnOrder(CThostFtdcOrderField pOrder) {
        System.out.printf("报单回报: 合约=%s 状态=%c 已成=%d 剩余=%d%n",
            pOrder.InstrumentID,
            pOrder.OrderStatus,
            pOrder.VolumeTraded,
            pOrder.VolumeTotal);
    }

    @Override
    public void OnRtnTrade(CThostFtdcTradeField pTrade) {
        System.out.printf("成交回报: 合约=%s 价格=%.2f 数量=%d%n",
            pTrade.InstrumentID,
            pTrade.Price,
            pTrade.Volume);
    }

    /**
     * 发送限价买入报单示例
     */
    public void sendBuyOrder(String instrumentId, double price, int volume,
                              int frontId, int sessionId, int maxOrderRef) {
        CThostFtdcInputOrderField order = new CThostFtdcInputOrderField();
        order.BrokerID              = "9999";
        order.InvestorID            = "your_user_id";
        order.InstrumentID          = instrumentId;
        order.OrderRef              = String.format("%012d", maxOrderRef + 1);
        order.Direction             = ThostFtdcUserApiDataType.THOST_FTDC_D_Buy;
        order.CombOffsetFlag        = String.valueOf(ThostFtdcUserApiDataType.THOST_FTDC_OF_Open);
        order.CombHedgeFlag         = String.valueOf(ThostFtdcUserApiDataType.THOST_FTDC_HF_Speculation);
        order.LimitPrice            = price;
        order.VolumeTotalOriginal   = volume;
        order.OrderPriceType        = ThostFtdcUserApiDataType.THOST_FTDC_OPT_LimitPrice;
        order.TimeCondition         = ThostFtdcUserApiDataType.THOST_FTDC_TC_GFD;
        order.VolumeCondition       = ThostFtdcUserApiDataType.THOST_FTDC_VC_AV;
        order.ContingentCondition   = ThostFtdcUserApiDataType.THOST_FTDC_CC_Immediately;
        order.ForceCloseReason      = ThostFtdcUserApiDataType.THOST_FTDC_FCC_NotForceClose;
        order.IsAutoSuspend         = 0;
        order.UserForceClose        = 0;

        traderApi.ReqOrderInsert(order, ++requestId);
    }
}

public class TraderMain {
    public static void main(String[] args) throws Exception {
        System.loadLibrary("ctpjni");

        CThostFtdcTraderApi traderApi = CThostFtdcTraderApi.CreateFtdcTraderApi("./flow_td/");
        traderApi.RegisterSpi(new MyTraderSpi(traderApi));
        // 订阅私有流（只传登录后的内容）
        traderApi.SubscribePrivateTopic(ThostFtdcUserApiDataType.THOST_TERT_QUICK);
        // 订阅公共流（只传登录后的内容）
        traderApi.SubscribePublicTopic(ThostFtdcUserApiDataType.THOST_TERT_QUICK);
        traderApi.RegisterFront("tcp://180.168.146.187:10130"); // 上期模拟交易地址
        traderApi.Init();
        traderApi.Join();
    }
}
```

---

## 常用常量速查

### 买卖方向
| 常量 | 值 | 说明 |
|---|---|---|
| `THOST_FTDC_D_Buy` | `'0'` | 买 |
| `THOST_FTDC_D_Sell` | `'1'` | 卖 |

### 开平标志
| 常量 | 值 | 说明 |
|---|---|---|
| `THOST_FTDC_OF_Open` | `'0'` | 开仓 |
| `THOST_FTDC_OF_Close` | `'1'` | 平仓 |
| `THOST_FTDC_OF_CloseToday` | `'3'` | 平今 |
| `THOST_FTDC_OF_CloseYesterday` | `'4'` | 平昨 |

### 投机套保标志
| 常量 | 值 | 说明 |
|---|---|---|
| `THOST_FTDC_HF_Speculation` | `'1'` | 投机 |
| `THOST_FTDC_HF_Arbitrage` | `'2'` | 套利 |
| `THOST_FTDC_HF_Hedge` | `'3'` | 套保 |

### 报单价格条件
| 常量 | 值 | 说明 |
|---|---|---|
| `THOST_FTDC_OPT_AnyPrice` | `'1'` | 任意价（市价） |
| `THOST_FTDC_OPT_LimitPrice` | `'2'` | 限价 |
| `THOST_FTDC_OPT_BestPrice` | `'3'` | 最优价 |

### 有效期类型
| 常量 | 值 | 说明 |
|---|---|---|
| `THOST_FTDC_TC_IOC` | `'1'` | 立即成交，否则撤销（IOC） |
| `THOST_FTDC_TC_GFD` | `'3'` | 当日有效（GFD） |
| `THOST_FTDC_TC_GTC` | `'5'` | 撤销前有效（GTC） |

### 报单状态
| 常量 | 值 | 说明 |
|---|---|---|
| `THOST_FTDC_OST_AllTraded` | `'0'` | 全部成交 |
| `THOST_FTDC_OST_PartTradedQueueing` | `'1'` | 部分成交，在队列中 |
| `THOST_FTDC_OST_NoTradeQueueing` | `'3'` | 未成交，在队列中 |
| `THOST_FTDC_OST_Canceled` | `'5'` | 已撤单 |

---

## JNI 实现说明

实现 JNI 桥接层时，需要注意：

1. **字符串编码**：CTP C++ API 使用 GBK（Windows）或 UTF-8（Linux）编码，Java 侧使用 UTF-16，需在 JNI 层做转码。
2. **结构体映射**：Java 的 POJO 字段名与 C++ struct 字段名一一对应，在 JNI 中通过 `GetFieldID` / `SetObjectField` 等方法存取。
3. **回调线程**：CTP 的 SPI 回调在 C++ 内部线程中触发，JNI 回调 Java 方法时需 `AttachCurrentThread`。注意该函数在 MSVC 和 GCC 下参数类型不同（`JNIEnv**` vs `void**`），已通过 `#ifdef _WIN32` 做平台适配。
4. **双精度价格**：C++ `double` 对应 Java `double`，无精度损失。
5. **char 类型常量**：C++ 的 `char` 枚举值（如 `'0'`、`'1'`）对应 Java `char` 类型字段。
6. **SDK 基类缺陷**：CTP SDK 的 SPI 基类（`CThostFtdcMdSpi`、`CThostFtdcTraderSpi`）是多态类但未声明 `virtual` 析构函数，已通过 pragma 在 GCC/Clang/MSVC 下统一抑制相关警告。

---

## 版本信息

| 项目 | 内容 |
|---|---|
| SDK 版本 | CTP Mini V1.7.5 |
| API 日期 | 20260115 |
| 支持平台 | Linux x64 / Windows x64 / Windows x86 |
| Java 最低版本 | Java 8 |
