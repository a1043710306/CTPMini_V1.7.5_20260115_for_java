/* ThostFtdcTraderApi.i - SWIG interface for CTP Mini Trader API
 * Generates Java bindings for CThostFtdcTraderApi and CThostFtdcTraderSpi
 */

%module(directors="1") CTPMiniTraderApi

%{
#include "ThostFtdcTraderApi.h"
%}

/* Enable director feature for SPI callbacks (Java -> C++) */
%feature("director") CThostFtdcTraderSpi;

/* ===== Java package and class settings ===== */
%pragma(java) jniclasscode=%{
  static {
    try {
      System.loadLibrary("CTPMiniTraderApi");
    } catch (UnsatisfiedLinkError e) {
      System.err.println("Failed to load CTPMiniTraderApi native library: " + e.getMessage());
      throw e;
    }
  }
%}

/* ===== Type mappings ===== */
%include "arrays_java.i"
%include "carrays.i"
%include "typemaps.i"

/* Map const char* return values to Java String */
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

/* Map char* parameters to Java String */
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

/* Handle char** array for SubscribeFlowCtrlWarning / UnSubscribeFlowCtrlWarning */
%typemap(jni)    char **ppTraderID "jobjectArray"
%typemap(jtype)  char **ppTraderID "String[]"
%typemap(jstype) char **ppTraderID "String[]"
%typemap(javain) char **ppTraderID "$javainput"
%typemap(in) (char **ppTraderID, int nCount) {
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
%typemap(freearg) (char **ppTraderID, int nCount) {
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

/* Header declares this as char *ppTraderID[]; map it directly as one Java String[] input */
%typemap(jni)    (char *ppTraderID[], int nCount) "jobjectArray"
%typemap(jtype)  (char *ppTraderID[], int nCount) "String[]"
%typemap(jstype) (char *ppTraderID[], int nCount) "String[]"
%typemap(javain) (char *ppTraderID[], int nCount) "$javainput"
%typemap(in,numinputs=1) (char *ppTraderID[], int nCount) {
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
%typemap(freearg) (char *ppTraderID[], int nCount) {
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

/* ===== Ignore internal/protected destructor ===== */
%ignore CThostFtdcTraderApi::~CThostFtdcTraderApi;

/* ===== Include the struct/type definitions ===== */
%include "ThostFtdcUserApiDataType.h"
%include "ThostFtdcUserApiStruct.h"
%include "ThostFtdcTraderApi.h"
