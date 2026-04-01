# CTP Mini Java SDK (SWIG)

使用 SWIG 将 CTP Mini C++ SDK 翻译为 Java SDK，通过 CMake 编译 JNI 动态库，支持 Windows x64 和 Linux x64。

---

## 目录结构

```
swig_java/
├── ThostFtdcMdApi.i       # 行情 API SWIG 接口文件
├── ThostFtdcTraderApi.i   # 交易 API SWIG 接口文件
├── CMakeLists.txt         # CMake 构建脚本（Windows/Linux 通用）
├── build_windows.bat      # Windows 一键构建脚本
├── build_linux.sh         # Linux 一键构建脚本
└── README.md              # 本说明文件
```

构建完成后，输出目录结构：
```
install_*/
├── bin/                   # Windows: JNI DLL + CTP vendor DLL
├── lib/                   # Linux:   JNI .so + CTP vendor .so
│   └── java/
│       └── ctpmini-java.jar
└── java/src/
    ├── mdapi/             # 行情 API 自动生成的 Java 源码
    └── tradeapi/          # 交易 API 自动生成的 Java 源码
```

---

## 前置依赖

| 工具      | 版本要求   | Windows 安装              | Linux 安装                          |
|-----------|-----------|---------------------------|-------------------------------------|
| CMake     | >= 3.14   | https://cmake.org         | `apt install cmake`                 |
| SWIG      | >= 3.0    | https://www.swig.org      | `apt install swig`                  |
| JDK       | >= 8      | https://adoptium.net      | `apt install default-jdk`           |
| C++ 编译器| -         | Visual Studio 2019/2022   | `apt install g++`                   |

---

## 快速构建

### Windows x64

```bat
cd swig_java
build_windows.bat
```

默认使用 **Visual Studio 17 2022 x64** 生成器。  
如需使用 MinGW，手动修改 `build_windows.bat` 中的 `-G` 参数：
```bat
cmake ... -G "MinGW Makefiles"
```

### Linux x64

```bash
cd swig_java
chmod +x build_linux.sh
./build_linux.sh
```

---

## 手动 CMake 构建

```bash
# 进入 swig_java 目录
cd swig_java
mkdir build && cd build

# Linux
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=../install

# Windows (VS)
cmake .. -G "Visual Studio 17 2022" -A x64 -DCMAKE_INSTALL_PREFIX=../install

cmake --build . --config Release
cmake --install . --config Release
```

---

## Java 调用示例

### 行情 API

```java
import com.ctpmini.mdapi.*;

public class MdDemo {

    // 继承 SPI 实现回调
    static class MySpi extends CThostFtdcMdSpi {

        @Override
        public void OnFrontConnected() {
            System.out.println("行情前置连接成功");
            // 登录
            CThostFtdcReqUserLoginField req = new CThostFtdcReqUserLoginField();
            req.setBrokerID("9999");
            req.setUserID("your_user_id");
            req.setPassword("your_password");
            mdApi.ReqUserLogin(req, 1);
        }

        @Override
        public void OnRspUserLogin(CThostFtdcRspUserLoginField pRspUserLogin,
                                   CThostFtdcRspInfoField pRspInfo,
                                   int nRequestID, boolean bIsLast) {
            if (pRspInfo == null || pRspInfo.getErrorID() == 0) {
                System.out.println("行情登录成功");
                // 订阅行情
                String[] instruments = {"rb2510", "au2506"};
                mdApi.SubscribeMarketData(instruments, instruments.length);
            }
        }

        @Override
        public void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField pData) {
            System.out.printf("合约=%s 最新价=%.2f 成交量=%d%n",
                pData.getInstrumentID(),
                pData.getLastPrice(),
                pData.getVolume());
        }
    }

    static CThostFtdcMdApi mdApi;

    public static void main(String[] args) throws InterruptedException {
        // 加载 JNI 库（也可通过 -Djava.library.path 指定路径）
        System.loadLibrary("CTPMiniMdApi");

        mdApi = CThostFtdcMdApi.CreateFtdcMdApi("./md_flow/", false, false);
        MySpi spi = new MySpi();
        mdApi.RegisterSpi(spi);
        mdApi.RegisterFront("tcp://180.168.146.187:10131");
        mdApi.Init();
        mdApi.Join();
    }
}
```

### 交易 API

```java
import com.ctpmini.tradeapi.*;

public class TraderDemo {

    static class MySpi extends CThostFtdcTraderSpi {

        @Override
        public void OnFrontConnected() {
            System.out.println("交易前置连接成功，开始认证...");
            CThostFtdcReqAuthenticateField req = new CThostFtdcReqAuthenticateField();
            req.setBrokerID("9999");
            req.setUserID("your_user_id");
            req.setAppID("your_app_id");
            req.setAuthCode("your_auth_code");
            traderApi.ReqAuthenticate(req, 1);
        }

        @Override
        public void OnRspAuthenticate(CThostFtdcRspAuthenticateField pRspAuthenticateField,
                                      CThostFtdcRspInfoField pRspInfo,
                                      int nRequestID, boolean bIsLast) {
            if (pRspInfo == null || pRspInfo.getErrorID() == 0) {
                CThostFtdcReqUserLoginField req = new CThostFtdcReqUserLoginField();
                req.setBrokerID("9999");
                req.setUserID("your_user_id");
                req.setPassword("your_password");
                traderApi.ReqUserLogin(req, 2);
            }
        }

        @Override
        public void OnRspUserLogin(CThostFtdcRspUserLoginField pRspUserLogin,
                                   CThostFtdcRspInfoField pRspInfo,
                                   int nRequestID, boolean bIsLast) {
            System.out.println("交易登录成功，交易日=" + pRspUserLogin.getTradingDay());
        }

        @Override
        public void OnRtnOrder(CThostFtdcOrderField pOrder) {
            System.out.printf("报单回报: 合约=%s 状态=%c%n",
                pOrder.getInstrumentID(), pOrder.getOrderStatus());
        }

        @Override
        public void OnRtnTrade(CThostFtdcTradeField pTrade) {
            System.out.printf("成交回报: 合约=%s 价格=%.2f 数量=%d%n",
                pTrade.getInstrumentID(), pTrade.getPrice(), pTrade.getVolume());
        }
    }

    static CThostFtdcTraderApi traderApi;

    public static void main(String[] args) throws InterruptedException {
        System.loadLibrary("CTPMiniTraderApi");

        traderApi = CThostFtdcTraderApi.CreateFtdcTraderApi("./trader_flow/");
        MySpi spi = new MySpi();
        traderApi.RegisterSpi(spi);
        traderApi.SubscribePrivateTopic(THOST_TE_RESUME_TYPE.THOST_TERT_QUICK);
        traderApi.SubscribePublicTopic(THOST_TE_RESUME_TYPE.THOST_TERT_QUICK);
        traderApi.RegisterFront("tcp://180.168.146.187:10130");
        traderApi.Init();
        traderApi.Join();
    }
}
```

---

## 运行时库路径配置

### Windows

将以下 DLL 放在同一目录（或系统 PATH）：
- `CTPMiniMdApi.dll` / `CTPMiniTraderApi.dll`（JNI 包装库）
- `thostmduserapi.dll` / `thosttraderapi.dll`（CTP 原始库）

启动 JVM 时指定路径：
```bat
java -Djava.library.path=.\install_win64\bin -cp ctpmini-java.jar MdDemo
```

### Linux

```bash
export LD_LIBRARY_PATH=./install_linux64/lib:$LD_LIBRARY_PATH
java -Djava.library.path=./install_linux64/lib \
     -cp ctpmini-java.jar MdDemo
```

---

## SWIG 接口设计说明

| 特性             | 说明                                                               |
|------------------|--------------------------------------------------------------------|
| `directors`      | 开启 director 模式，使 Java 子类可覆写 C++ 虚函数（SPI 回调）     |
| `char*` 映射     | 所有 `char*` / `const char*` 参数和返回值自动映射为 Java `String` |
| `char**` 映射    | `SubscribeMarketData` 等函数的 `char**` 参数映射为 `String[]`     |
| struct 字段      | C++ struct 成员通过 SWIG 自动生成 getter/setter 方法              |
| enum 映射        | `THOST_TE_RESUME_TYPE` 等枚举映射为 Java enum / 常量类            |
| 内存安全         | `freearg` typemap 确保 GetStringUTFChars / malloc 对应释放        |

---

## 常见问题

**Q: SWIG 报错 `Identifier 'XXX' not defined`**  
A: 检查 `.i` 文件中 `%include` 顺序，先 include DataType 再 include Struct，最后 include Api。

**Q: Windows 编译报 LNK2019**  
A: 确认 `find_library` 找到了正确的 `.lib` 文件。CTP Mini win64 目录下应有 `thostmduserapi.lib`。

**Q: Linux 运行时 `Cannot open shared object file`**  
A: 确认 `LD_LIBRARY_PATH` 包含 `.so` 所在目录，或通过 `rpath` 已内嵌（构建脚本已配置 `$ORIGIN`）。

**Q: Java 端字符串乱码**  
A: CTP 部分字段使用 GBK 编码。需在 Java 端做编码转换：
```java
String utf8 = new String(gbkStr.getBytes("ISO-8859-1"), "GBK");
```
