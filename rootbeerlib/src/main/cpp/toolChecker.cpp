/****************************************************************************
 * File:   toolChecker.cpp
 * Author: laxmikant
 * Date:   16/10/2024
 *
 * Description : Root checking JNI NDK code
 *
 ****************************************************************************/

/****************************************************************************
 *>>>>>>>>>>>>>>>>>>>>>>>>> System Includes <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*
 ****************************************************************************/

// Android headers
#include <jni.h>
#include <android/log.h>
#include <exception>

// String / file headers
#include <string.h>
#include <stdio.h>

/****************************************************************************
 *>>>>>>>>>>>>>>>>>>>>>>>>>> User Includes <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*
 ****************************************************************************/
#include "toolChecker.h"
#include "EmulatorDetection.h"

/****************************************************************************
 *>>>>>>>>>>>>>>>>>>>>>>>>>> Constant Macros <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*
 ****************************************************************************/

// LOGCAT
#define  LOG_TAG    "laxmi"
#define  LOGD(...)  if (DEBUG) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__);
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__);

static bool loggingEnabled = true; // Global flag to control logging

// This macro ensures that logs are only enabled in debug builds.
#ifdef NDEBUG  // This is usually defined in release builds
#define LOGGING_ENABLED false
#else
#define LOGGING_ENABLED loggingEnabled
#endif


/* Set to 1 to enable debug log traces. */
static int DEBUG = 1;

/*****************************************************************************
 * Description: Sets if we should log debug messages
 *
 * Parameters: env - Java environment pointer
 *      thiz - javaobject
 * 	bool - true to log debug messages
 *
 *****************************************************************************/
void Java_com_rootchecker_service_RootBeerNative_setLogDebugMessages( JNIEnv* env, jobject thiz, jboolean debug)
{
  if (debug){
    DEBUG = 1;
  }
  else{
    DEBUG = 0;
  }
}


extern "C"
JNIEXPORT void JNICALL
Java_com_rootchecker_service_RootBeerNative_setLoggingEnabled(JNIEnv *env, jobject /* this */, jboolean enable) {
    LOGGING_ENABLED = (enable == JNI_TRUE);
    if (LOGGING_ENABLED) {
        __android_log_print(ANDROID_LOG_INFO, LOG_TAG, "Logging enabled: %d", LOGGING_ENABLED);

    }
    else {
        __android_log_print(ANDROID_LOG_INFO, LOG_TAG, "Logging disabled.");
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_rootchecker_service_RootBeerNative_removeLogs(JNIEnv *env, jobject /* this */, jstring message) {
    const char *nativeMessage = env->GetStringUTFChars(message, 0);

    // Only log if logging is enabled
    if (LOGGING_ENABLED) {
        __android_log_write(ANDROID_LOG_INFO, LOG_TAG, nativeMessage);
    }
    env->ReleaseStringUTFChars(message, nativeMessage);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_rootchecker_service_RootBeerNative_logMessage(JNIEnv *env, jobject /* this */, jstring message) {
    if (!LOGGING_ENABLED) return;// exit if logs are disable
    const char *nativeMessage = env->GetStringUTFChars(message, 0);

    // Only log if logging is enabled
    if (LOGGING_ENABLED) {
        __android_log_write(ANDROID_LOG_INFO, LOG_TAG, nativeMessage);
    }

    env->ReleaseStringUTFChars(message, nativeMessage);
}

//#ifdef RELEASE_BUILD
extern "C"
JNIEXPORT void JNICALL
Java_com_rootchecker_service_RootBeerNative_clearLogs(JNIEnv *env, jobject /* this */) {
    // This function could be used to disable logging or clear any stored logs.
    // Note: Clearing system logs directly is not possible via JNI.

    // Disable logging completely
    LOGGING_ENABLED = false;

    // Optionally notify that logs have been cleared (for internal purposes)
    __android_log_write(ANDROID_LOG_INFO, LOG_TAG, "All logs have been cleared.");
}
//#endif

extern "C" {
JNIEXPORT jboolean JNICALL
Java_com_rootchecker_service_RootBeerNative_isDetected(JNIEnv *env, jobject clazz) {
    (void)env;
    (void)clazz;

    return EmulatorDetection::isDetected();
}

JNIEXPORT jstring JNICALL
Java_com_rootchecker_service_RootBeerNative_getResult(JNIEnv *env, jobject clazz) {
    (void)clazz;

    return env->NewStringUTF(EmulatorDetection::getResult().c_str());
}
}
/*****************************************************************************
 * Description: Checks if a file exists
 *
 * Parameters: fname - filename to check
 *
 * Return value: 0 - non-existant / not visible, 1 - exists
 *
 *****************************************************************************/
int exists(const char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        LOGD("LOOKING FOR BINARY: %s PRESENT!!!",fname);
        fclose(file);
        return 1;
    }
    LOGD("LOOKING FOR BINARY: %s Absent :(",fname);
    return 0;
}




/*****************************************************************************
 * Description: Checks for root binaries
 *
 * Parameters: env - Java environment pointer
 *      thiz - javaobject
 *
 * Return value: int number of su binaries found
 *
 *****************************************************************************/
int Java_com_rootchecker_service_RootBeerNative_checkForRoot( JNIEnv* env, jobject thiz, jobjectArray pathsArray )
{

    int binariesFound = 0;

    int stringCount = (env)->GetArrayLength(pathsArray);

    for (int i=0; i<stringCount; i++) {
        jstring string = (jstring) (env)->GetObjectArrayElement(pathsArray, i);
        const char *pathString = (env)->GetStringUTFChars(string, 0);

	binariesFound+=exists(pathString);

	(env)->ReleaseStringUTFChars(string, pathString);
    }

    return binariesFound>0;
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_rootchecker_service_RootBeerNative_isLoggingEnabled(JNIEnv *env, jobject /* this */) {
    return loggingEnabled ? JNI_TRUE : JNI_FALSE;
}
