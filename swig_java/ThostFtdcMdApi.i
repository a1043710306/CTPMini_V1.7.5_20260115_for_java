/* ThostFtdcMdApi.i - SWIG interface for CTP Mini Market Data API
 * Generates Java bindings for CThostFtdcMdApi and CThostFtdcMdSpi
 */

%module(directors="1") CTPMiniMdApi

%{
#include "ThostFtdcMdApi.h"
%}

/* Enable director feature for SPI callbacks (Java -> C++) */
%feature("director") CThostFtdcMdSpi;

/* ===== Java package and class settings ===== */
%pragma(java) jniclasscode=%{
  static {
    try {
      System.loadLibrary("CTPMiniMdApi");
    } catch (UnsatisfiedLinkError e) {
      System.err.println("Failed to load CTPMiniMdApi native library: " + e.getMessage());
      throw e;
    }
  }
%}

/* ===== Type mappings ===== */

/* Map C char arrays to Java String */
%include "arrays_java.i"
%include "carrays.i"
%include "typemaps.i"

/* Handle char* return values as Java String */
%typemap(jni)    const char* "jstring"
%typemap(jtype)  const char* "String"
%typemap(jstype) const char* "String"
%typemap(javain) const char* "$javainput"
%typemap(javaout) const char* {
    return $jnicall;
}
%typemap(out) const char* {
    $result = $1 ? JCALL1(NewStringUTF, jenv, $1) : NULL;
}
%typemap(in) const char* {
    $1 = $input ? (char*)JCALL2(GetStringUTFChars, jenv, $input, 0) : NULL;
}
%typemap(freearg) const char* {
    if ($1) JCALL2(ReleaseStringUTFChars, jenv, $input, $1);
}

/* Handle char* (non-const) parameters */
%typemap(jni)    char* "jstring"
%typemap(jtype)  char* "String"
%typemap(jstype) char* "String"
%typemap(javain) char* "$javainput"
%typemap(javaout) char* {
    return $jnicall;
}
%typemap(in) char* {
    $1 = $input ? (char*)JCALL2(GetStringUTFChars, jenv, $input, 0) : NULL;
}
%typemap(freearg) char* {
    if ($1) JCALL2(ReleaseStringUTFChars, jenv, $input, $1);
}

/* Handle char** (array of strings for SubscribeMarketData etc.) */
%typemap(jni)    char **ppInstrumentID "jobjectArray"
%typemap(jtype)  char **ppInstrumentID "String[]"
%typemap(jstype) char **ppInstrumentID "String[]"
%typemap(javain) char **ppInstrumentID "$javainput"
%typemap(in) (char **ppInstrumentID, int nCount) {
    if ($input == NULL) {
        $1 = NULL;
        $2 = 0;
    } else {
        $2 = (int)JCALL1(GetArrayLength, jenv, $input);
        $1 = (char **)malloc(($2 + 1) * sizeof(char *));
        int i;
        for (i = 0; i < $2; i++) {
            jstring js = (jstring)JCALL2(GetObjectArrayElement, jenv, $input, i);
            $1[i] = js ? (char *)JCALL2(GetStringUTFChars, jenv, js, 0) : NULL;
        }
        $1[$2] = NULL;
    }
}
%typemap(freearg) (char **ppInstrumentID, int nCount) {
    if ($1) {
        int i;
        for (i = 0; i < $2; i++) {
            if ($1[i]) {
                jstring js = (jstring)JCALL2(GetObjectArrayElement, jenv, $input, i);
                if (js) JCALL2(ReleaseStringUTFChars, jenv, js, $1[i]);
            }
        }
        free($1);
    }
}

/* Header declares this as char *ppInstrumentID[]; map it directly as one Java String[] input */
%typemap(jni)    (char *ppInstrumentID[], int nCount) "jobjectArray"
%typemap(jtype)  (char *ppInstrumentID[], int nCount) "String[]"
%typemap(jstype) (char *ppInstrumentID[], int nCount) "String[]"
%typemap(javain) (char *ppInstrumentID[], int nCount) "$javainput"
%typemap(in,numinputs=1) (char *ppInstrumentID[], int nCount) {
    if ($input == NULL) {
        $1 = NULL;
        $2 = 0;
    } else {
        $2 = (int)JCALL1(GetArrayLength, jenv, $input);
        $1 = (char **)malloc(($2 + 1) * sizeof(char *));
        int i;
        for (i = 0; i < $2; i++) {
            jstring js = (jstring)JCALL2(GetObjectArrayElement, jenv, $input, i);
            $1[i] = js ? (char *)JCALL2(GetStringUTFChars, jenv, js, 0) : NULL;
        }
        $1[$2] = NULL;
    }
}
%typemap(freearg) (char *ppInstrumentID[], int nCount) {
    if ($1) {
        int i;
        for (i = 0; i < $2; i++) {
            if ($1[i]) {
                jstring js = (jstring)JCALL2(GetObjectArrayElement, jenv, $input, i);
                if (js) JCALL2(ReleaseStringUTFChars, jenv, js, $1[i]);
            }
        }
        free($1);
    }
}

/* Handle SubscribeForQuoteRsp char** */
%typemap(jni)    char **ppInstrumentID2 "jobjectArray"
%typemap(jtype)  char **ppInstrumentID2 "String[]"
%typemap(jstype) char **ppInstrumentID2 "String[]"
%typemap(javain) char **ppInstrumentID2 "$javainput"

/* ===== Ignore problematic or internal methods ===== */
%ignore CThostFtdcMdApi::~CThostFtdcMdApi;

/* ===== Include the struct/type definitions ===== */
%include "ThostFtdcUserApiDataType.h"
%include "ThostFtdcUserApiStruct.h"
%include "ThostFtdcMdApi.h"
