/**
 * jni_utils.cpp
 * JNI 通用工具函数实现：JavaVM 管理、字符串编码转换、Java POJO 创建
 */

#include "jni_utils.h"
#include <stdexcept>

// ─────────────────────────────────────────────
//  全局 JavaVM
// ─────────────────────────────────────────────
JavaVM* g_jvm = nullptr;

/**
 * JNI_OnLoad：JVM 加载本库时自动调用，保存全局 JavaVM 指针。
 */
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* /*reserved*/)
{
    g_jvm = vm;
    return JNI_VERSION_1_6;
}

// ─────────────────────────────────────────────
//  GetEnv：获取当前线程 JNIEnv，必要时 Attach
// ─────────────────────────────────────────────
bool GetEnv(JNIEnv** env)
{
    if (!g_jvm) {
        *env = nullptr;
        return false;
    }
    jint ret = g_jvm->GetEnv(reinterpret_cast<void**>(env), JNI_VERSION_1_6);
    if (ret == JNI_OK) {
        return false;   // 线程已 Attach，无需 Detach
    }
    if (ret == JNI_EDETACHED) {
        if (g_jvm->AttachCurrentThread(reinterpret_cast<void**>(env), nullptr) == JNI_OK) {
            return true;    // 本次 Attach，调用方需 Detach
        }
    }
    *env = nullptr;
    return false;
}

// ─────────────────────────────────────────────
//  字符串转换
// ─────────────────────────────────────────────

/**
 * Java jstring（Modified UTF-8）→ std::string（UTF-8）
 */
std::string jstr2str(JNIEnv* env, jstring js)
{
    if (!js) return "";
    const char* chars = env->GetStringUTFChars(js, nullptr);
    if (!chars) return "";
    std::string s(chars);
    env->ReleaseStringUTFChars(js, chars);
    return s;
}

/**
 * const char* (UTF-8) → jstring
 * 若 s 为 nullptr 或空，返回空字符串 jstring（不返回 null）。
 */
jstring str2jstr(JNIEnv* env, const char* s)
{
    if (!s) return env->NewStringUTF("");
    return env->NewStringUTF(s);
}

// ─────────────────────────────────────────────
//  NewJavaObject：无参构造创建 Java 实例
// ─────────────────────────────────────────────
jobject NewJavaObject(JNIEnv* env, const char* className)
{
    jclass cls = env->FindClass(className);
    if (!cls) {
        // FindClass 已抛出 NoClassDefFoundError
        return nullptr;
    }
    jmethodID ctor = env->GetMethodID(cls, "<init>", "()V");
    if (!ctor) {
        env->DeleteLocalRef(cls);
        return nullptr;
    }
    jobject obj = env->NewObject(cls, ctor);
    env->DeleteLocalRef(cls);
    return obj;
}
