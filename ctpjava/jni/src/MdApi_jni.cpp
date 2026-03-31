/**
 * MdApi_jni.cpp
 * 行情 API JNI 桥接
 *
 * Java 类:  com.ctpmini.api.CThostFtdcMdApi   (abstract)
 *            com.ctpmini.api.CThostFtdcMdSpi   (concrete callbacks)
 *
 * 本文件实现：
 *   1. JavaMdSpiImpl  —— C++ SPI，将 CTP 回调转发给 Java SPI 对象
 *   2. JavaMdApiImpl  —— 继承 Java 抽象类，持有 CThostFtdcMdApi* 指针
 *   3. JNI 函数       —— 对应 CThostFtdcMdApi 中的 native / abstract 方法
 */

#include "jni_utils.h"
#include "ThostFtdcMdApi.h"
#include <string>
#include <cstring>
#include <vector>
#include <cstdint>

/* ────────────────────────────────────────────────────────────
 *  辅助：从 JNI 层调用 Java SPI 的通用宏
 * ──────────────────────────────────────────────────────────── */

// 调用 Java SPI void 方法（无参）
#define CALL_SPI_VOID0(methodName) \
    JNIEnv* env; bool detach = GetEnv(&env); \
    if (!env) return; \
    jclass cls = env->GetObjectClass(jSpi_); \
    jmethodID mid = env->GetMethodID(cls, methodName, "()V"); \
    if (mid) env->CallVoidMethod(jSpi_, mid); \
    env->DeleteLocalRef(cls); \
    if (detach) g_jvm->DetachCurrentThread();

// 调用 Java SPI void 方法（int 参数）
#define CALL_SPI_VOID1I(methodName, arg) \
    JNIEnv* env; bool detach = GetEnv(&env); \
    if (!env) return; \
    jclass cls = env->GetObjectClass(jSpi_); \
    jmethodID mid = env->GetMethodID(cls, methodName, "(I)V"); \
    if (mid) env->CallVoidMethod(jSpi_, mid, (jint)(arg)); \
    env->DeleteLocalRef(cls); \
    if (detach) g_jvm->DetachCurrentThread();

/* ────────────────────────────────────────────────────────────
 *  抑制 -Wdelete-non-virtual-dtor 警告
 *  CTP SDK 基类 CThostFtdcMdSpi 是多态类但未声明 virtual 析构函数，
 *  属于 SDK 设计缺陷，我们无法修改。此处所有 delete 均通过子类指针执行，
 *  子类析构函数会被正确调用，行为安全。
 * ──────────────────────────────────────────────────────────── */
#if defined(__GNUC__) || defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
#elif defined(_MSC_VER)
    #pragma warning(push)
    #pragma warning(disable: 4265)  // class has virtual functions, but destructor is not virtual
#endif

/* ────────────────────────────────────────────────────────────
 *  C++ SPI 实现（转发所有回调到 Java SPI 对象）
 * ──────────────────────────────────────────────────────────── */
class JavaMdSpiImpl : public CThostFtdcMdSpi {
public:
    explicit JavaMdSpiImpl(JNIEnv* env, jobject jSpi)
        : jSpi_(env->NewGlobalRef(jSpi)) {}

    ~JavaMdSpiImpl() {
        JNIEnv* env; bool detach = GetEnv(&env);
        if (env) { env->DeleteGlobalRef(jSpi_); }
        if (detach) g_jvm->DetachCurrentThread();
    }

    void OnFrontConnected() override {
        CALL_SPI_VOID0("OnFrontConnected")
    }

    void OnFrontDisconnected(int nReason) override {
        CALL_SPI_VOID1I("OnFrontDisconnected", nReason)
    }

    void OnHeartBeatWarning(int nTimeLapse) override {
        CALL_SPI_VOID1I("OnHeartBeatWarning", nTimeLapse)
    }

    void OnRspUserLogin(CThostFtdcRspUserLoginField* p,
                        CThostFtdcRspInfoField* rsp,
                        int reqId, bool isLast) override {
        InvokeRsp4("OnRspUserLogin",
            "Lcom/ctpmini/struct/CThostFtdcRspUserLoginField;",
            ToJava_RspUserLogin, p, rsp, reqId, isLast);
    }

    void OnRspUserLogout(CThostFtdcUserLogoutField* p,
                         CThostFtdcRspInfoField* rsp,
                         int reqId, bool isLast) override {
        InvokeRsp4("OnRspUserLogout",
            "Lcom/ctpmini/struct/CThostFtdcUserLogoutField;",
            ToJava_UserLogout, p, rsp, reqId, isLast);
    }

    void OnRspError(CThostFtdcRspInfoField* rsp, int reqId, bool isLast) override {
        JNIEnv* env; bool detach = GetEnv(&env);
        if (!env) return;
        jobject jRsp = ToJava_RspInfo(env, rsp);
        jclass cls = env->GetObjectClass(jSpi_);
        jmethodID mid = env->GetMethodID(cls,
            "OnRspError",
            "(Lcom/ctpmini/struct/CThostFtdcRspInfoField;IZ)V");
        if (mid) env->CallVoidMethod(jSpi_, mid, jRsp, (jint)reqId, (jboolean)isLast);
        if (jRsp) env->DeleteLocalRef(jRsp);
        env->DeleteLocalRef(cls);
        if (detach) g_jvm->DetachCurrentThread();
    }

    void OnRspSubMarketData(CThostFtdcSpecificInstrumentField* p,
                            CThostFtdcRspInfoField* rsp,
                            int reqId, bool isLast) override {
        InvokeRsp4("OnRspSubMarketData",
            "Lcom/ctpmini/struct/CThostFtdcSpecificInstrumentField;",
            ToJava_SpecificInstrument, p, rsp, reqId, isLast);
    }

    void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField* p,
                              CThostFtdcRspInfoField* rsp,
                              int reqId, bool isLast) override {
        InvokeRsp4("OnRspUnSubMarketData",
            "Lcom/ctpmini/struct/CThostFtdcSpecificInstrumentField;",
            ToJava_SpecificInstrument, p, rsp, reqId, isLast);
    }

    void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField* p,
                             CThostFtdcRspInfoField* rsp,
                             int reqId, bool isLast) override {
        InvokeRsp4("OnRspSubForQuoteRsp",
            "Lcom/ctpmini/struct/CThostFtdcSpecificInstrumentField;",
            ToJava_SpecificInstrument, p, rsp, reqId, isLast);
    }

    void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField* p,
                               CThostFtdcRspInfoField* rsp,
                               int reqId, bool isLast) override {
        InvokeRsp4("OnRspUnSubForQuoteRsp",
            "Lcom/ctpmini/struct/CThostFtdcSpecificInstrumentField;",
            ToJava_SpecificInstrument, p, rsp, reqId, isLast);
    }

    void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField* p) override {
        InvokeRtn1("OnRtnDepthMarketData",
            "Lcom/ctpmini/struct/CThostFtdcDepthMarketDataField;",
            ToJava_DepthMarketData, p);
    }

    void OnRtnMBLMarketData(CThostFtdcMBLMarketDataField* p) override {
        InvokeRtn1("OnRtnMBLMarketData",
            "Lcom/ctpmini/struct/CThostFtdcMBLMarketDataField;",
            ToJava_MBLMarketData, p);
    }

    void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* p) override {
        InvokeRtn1("OnRtnForQuoteRsp",
            "Lcom/ctpmini/struct/CThostFtdcForQuoteRspField;",
            ToJava_ForQuoteRsp, p);
    }

private:
    jobject jSpi_;  // global ref

    /* 四参回调：(StructField, RspInfo, int, boolean) */
    template<typename CStruct, typename ConvertFn>
    void InvokeRsp4(const char* method, const char* structSig,
                    ConvertFn cvt, CStruct* p,
                    CThostFtdcRspInfoField* rsp,
                    int reqId, bool isLast)
    {
        JNIEnv* env; bool detach = GetEnv(&env);
        if (!env) return;
        jobject jObj = cvt(env, p);
        jobject jRsp = ToJava_RspInfo(env, rsp);
        jclass cls = env->GetObjectClass(jSpi_);
        std::string sig = std::string("(") + structSig
            + "Lcom/ctpmini/struct/CThostFtdcRspInfoField;IZ)V";
        jmethodID mid = env->GetMethodID(cls, method, sig.c_str());
        if (mid) env->CallVoidMethod(jSpi_, mid, jObj, jRsp,
                                     (jint)reqId, (jboolean)isLast);
        if (jObj) env->DeleteLocalRef(jObj);
        if (jRsp) env->DeleteLocalRef(jRsp);
        env->DeleteLocalRef(cls);
        if (detach) g_jvm->DetachCurrentThread();
    }

    /* 单参推送：(StructField) */
    template<typename CStruct, typename ConvertFn>
    void InvokeRtn1(const char* method, const char* structSig,
                    ConvertFn cvt, CStruct* p)
    {
        JNIEnv* env; bool detach = GetEnv(&env);
        if (!env) return;
        jobject jObj = cvt(env, p);
        jclass cls = env->GetObjectClass(jSpi_);
        std::string sig = std::string("(") + structSig + ")V";
        jmethodID mid = env->GetMethodID(cls, method, sig.c_str());
        if (mid) env->CallVoidMethod(jSpi_, mid, jObj);
        if (jObj) env->DeleteLocalRef(jObj);
        env->DeleteLocalRef(cls);
        if (detach) g_jvm->DetachCurrentThread();
    }
};

/* ────────────────────────────────────────────────────────────
 *  辅助：从 Java MdApi 对象中取 native 指针
 * ──────────────────────────────────────────────────────────── */
static CThostFtdcMdApi* getMdApi(JNIEnv* env, jobject jApi) {
    jclass cls = env->GetObjectClass(jApi);
    jfieldID fid = env->GetFieldID(cls, "nativeHandle", "J");
    env->DeleteLocalRef(cls);
    if (!fid) return nullptr;
    return reinterpret_cast<CThostFtdcMdApi*>(env->GetLongField(jApi, fid));
}

static void setMdApi(JNIEnv* env, jobject jApi, CThostFtdcMdApi* ptr) {
    jclass cls = env->GetObjectClass(jApi);
    jfieldID fid = env->GetFieldID(cls, "nativeHandle", "J");
    env->DeleteLocalRef(cls);
    if (fid) env->SetLongField(jApi, fid, (jlong)(intptr_t)ptr);
}

static JavaMdSpiImpl* getMdSpi(JNIEnv* env, jobject jApi) {
    jclass cls = env->GetObjectClass(jApi);
    jfieldID fid = env->GetFieldID(cls, "nativeSpiHandle", "J");
    env->DeleteLocalRef(cls);
    if (!fid) return nullptr;
    return reinterpret_cast<JavaMdSpiImpl*>(env->GetLongField(jApi, fid));
}

static void setMdSpi(JNIEnv* env, jobject jApi, JavaMdSpiImpl* ptr) {
    jclass cls = env->GetObjectClass(jApi);
    jfieldID fid = env->GetFieldID(cls, "nativeSpiHandle", "J");
    env->DeleteLocalRef(cls);
    if (fid) env->SetLongField(jApi, fid, (jlong)(intptr_t)ptr);
}

/* ────────────────────────────────────────────────────────────
 *  JNI 函数实现
 * ──────────────────────────────────────────────────────────── */
extern "C" {

/*
 * CThostFtdcMdApi.CreateFtdcMdApi(String, boolean, boolean)
 * 静态 native 工厂方法：创建 C++ API 实例，包装成 Java 对象
 */
JNIEXPORT jobject JNICALL
Java_com_ctpmini_api_CThostFtdcMdApi_CreateFtdcMdApi(
        JNIEnv* env, jclass /*cls*/,
        jstring jFlowPath, jboolean useUdp, jboolean multicast)
{
    std::string flowPath = jstr2str(env, jFlowPath);
    CThostFtdcMdApi* api = CThostFtdcMdApi::CreateFtdcMdApi(
        flowPath.c_str(), (bool)useUdp, (bool)multicast);
    if (!api) return nullptr;

    // 创建 Java 包装对象（实际运行时用反射创建子类占位）
    jobject jApi = NewJavaObject(env, "com/ctpmini/api/CThostFtdcMdApiImpl");
    if (!jApi) {
        api->Release();
        return nullptr;
    }
    setMdApi(env, jApi, api);
    return jApi;
}

JNIEXPORT jstring JNICALL
Java_com_ctpmini_api_CThostFtdcMdApi_GetApiVersion(JNIEnv* env, jclass /*cls*/)
{
    return str2jstr(env, CThostFtdcMdApi::GetApiVersion());
}

JNIEXPORT void JNICALL
Java_com_ctpmini_api_CThostFtdcMdApiImpl_Release(JNIEnv* env, jobject jApi)
{
    CThostFtdcMdApi* api = getMdApi(env, jApi);
    if (api) {
        api->Release();
        setMdApi(env, jApi, nullptr);
    }
    JavaMdSpiImpl* spi = getMdSpi(env, jApi);
    if (spi) {
        delete spi;
        setMdSpi(env, jApi, nullptr);
    }
}

JNIEXPORT void JNICALL
Java_com_ctpmini_api_CThostFtdcMdApiImpl_Init(JNIEnv* env, jobject jApi, jboolean cont)
{
    CThostFtdcMdApi* api = getMdApi(env, jApi);
    if (api) api->Init((bool)cont);
}

JNIEXPORT jint JNICALL
Java_com_ctpmini_api_CThostFtdcMdApiImpl_Join(JNIEnv* env, jobject jApi)
{
    CThostFtdcMdApi* api = getMdApi(env, jApi);
    return api ? (jint)api->Join() : -1;
}

JNIEXPORT jstring JNICALL
Java_com_ctpmini_api_CThostFtdcMdApiImpl_GetTradingDay(JNIEnv* env, jobject jApi)
{
    CThostFtdcMdApi* api = getMdApi(env, jApi);
    return api ? str2jstr(env, api->GetTradingDay()) : str2jstr(env, "");
}

JNIEXPORT void JNICALL
Java_com_ctpmini_api_CThostFtdcMdApiImpl_RegisterFront(
        JNIEnv* env, jobject jApi, jstring jAddr)
{
    CThostFtdcMdApi* api = getMdApi(env, jApi);
    if (!api) return;
    std::string addr = jstr2str(env, jAddr);
    char buf[256];
    strncpy(buf, addr.c_str(), sizeof(buf)-1);
    buf[sizeof(buf)-1] = '\0';
    api->RegisterFront(buf);
}

JNIEXPORT void JNICALL
Java_com_ctpmini_api_CThostFtdcMdApiImpl_RegisterSpi(
        JNIEnv* env, jobject jApi, jobject jSpi)
{
    CThostFtdcMdApi* api = getMdApi(env, jApi);
    if (!api) return;
    // 删除旧 SPI
    JavaMdSpiImpl* old = getMdSpi(env, jApi);
    if (old) delete old;

    if (!jSpi) {
        api->RegisterSpi(nullptr);
        setMdSpi(env, jApi, nullptr);
        return;
    }
    JavaMdSpiImpl* spi = new JavaMdSpiImpl(env, jSpi);
    setMdSpi(env, jApi, spi);
    api->RegisterSpi(spi);
}

JNIEXPORT jint JNICALL
Java_com_ctpmini_api_CThostFtdcMdApiImpl_SubscribeMarketData(
        JNIEnv* env, jobject jApi, jobjectArray jArr, jint nCount)
{
    CThostFtdcMdApi* api = getMdApi(env, jApi);
    if (!api) return -1;
    int n = (int)nCount;
    std::vector<std::string> strs(n);
    std::vector<char*> ptrs(n);
    for (int i = 0; i < n; i++) {
        jstring js = (jstring)env->GetObjectArrayElement(jArr, i);
        strs[i] = jstr2str(env, js);
        env->DeleteLocalRef(js);
        ptrs[i] = const_cast<char*>(strs[i].c_str());
    }
    return (jint)api->SubscribeMarketData(ptrs.data(), n);
}

JNIEXPORT jint JNICALL
Java_com_ctpmini_api_CThostFtdcMdApiImpl_UnSubscribeMarketData(
        JNIEnv* env, jobject jApi, jobjectArray jArr, jint nCount)
{
    CThostFtdcMdApi* api = getMdApi(env, jApi);
    if (!api) return -1;
    int n = (int)nCount;
    std::vector<std::string> strs(n);
    std::vector<char*> ptrs(n);
    for (int i = 0; i < n; i++) {
        jstring js = (jstring)env->GetObjectArrayElement(jArr, i);
        strs[i] = jstr2str(env, js);
        env->DeleteLocalRef(js);
        ptrs[i] = const_cast<char*>(strs[i].c_str());
    }
    return (jint)api->UnSubscribeMarketData(ptrs.data(), n);
}

JNIEXPORT jint JNICALL
Java_com_ctpmini_api_CThostFtdcMdApiImpl_SubscribeForQuoteRsp(
        JNIEnv* env, jobject jApi, jobjectArray jArr, jint nCount)
{
    CThostFtdcMdApi* api = getMdApi(env, jApi);
    if (!api) return -1;
    int n = (int)nCount;
    std::vector<std::string> strs(n);
    std::vector<char*> ptrs(n);
    for (int i = 0; i < n; i++) {
        jstring js = (jstring)env->GetObjectArrayElement(jArr, i);
        strs[i] = jstr2str(env, js);
        env->DeleteLocalRef(js);
        ptrs[i] = const_cast<char*>(strs[i].c_str());
    }
    return (jint)api->SubscribeForQuoteRsp(ptrs.data(), n);
}

JNIEXPORT jint JNICALL
Java_com_ctpmini_api_CThostFtdcMdApiImpl_UnSubscribeForQuoteRsp(
        JNIEnv* env, jobject jApi, jobjectArray jArr, jint nCount)
{
    CThostFtdcMdApi* api = getMdApi(env, jApi);
    if (!api) return -1;
    int n = (int)nCount;
    std::vector<std::string> strs(n);
    std::vector<char*> ptrs(n);
    for (int i = 0; i < n; i++) {
        jstring js = (jstring)env->GetObjectArrayElement(jArr, i);
        strs[i] = jstr2str(env, js);
        env->DeleteLocalRef(js);
        ptrs[i] = const_cast<char*>(strs[i].c_str());
    }
    return (jint)api->UnSubscribeForQuoteRsp(ptrs.data(), n);
}

JNIEXPORT jint JNICALL
Java_com_ctpmini_api_CThostFtdcMdApiImpl_ReqUserLogin(
        JNIEnv* env, jobject jApi, jobject jField, jint reqId)
{
    CThostFtdcMdApi* api = getMdApi(env, jApi);
    if (!api) return -1;
    CThostFtdcReqUserLoginField f{};
    FromJava_ReqUserLogin(env, jField, f);
    return (jint)api->ReqUserLogin(&f, (int)reqId);
}

JNIEXPORT jint JNICALL
Java_com_ctpmini_api_CThostFtdcMdApiImpl_ReqUserLoginEncrypt(
        JNIEnv* env, jobject jApi, jobject jField, jint reqId)
{
    CThostFtdcMdApi* api = getMdApi(env, jApi);
    if (!api) return -1;
    CThostFtdcReqUserLoginField f{};
    FromJava_ReqUserLogin(env, jField, f);
    return (jint)api->ReqUserLoginEncrypt(&f, (int)reqId);
}

JNIEXPORT jint JNICALL
Java_com_ctpmini_api_CThostFtdcMdApiImpl_ReqUserLogout(
        JNIEnv* env, jobject jApi, jobject jField, jint reqId)
{
    CThostFtdcMdApi* api = getMdApi(env, jApi);
    if (!api) return -1;
    CThostFtdcUserLogoutField f{};
    FromJava_UserLogout(env, jField, f);
    return (jint)api->ReqUserLogout(&f, (int)reqId);
}

} // extern "C"

#if defined(__GNUC__) || defined(__clang__)
    #pragma GCC diagnostic pop
#elif defined(_MSC_VER)
    #pragma warning(pop)
#endif
