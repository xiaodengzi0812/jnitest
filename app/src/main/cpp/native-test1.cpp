#include <jni.h>
#include <string>
#include <android/log.h>
#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

// add方法
extern "C"
JNIEXPORT jint JNICALL
Java_com_dengzi_jnitest_test1_Test1_add(JNIEnv *env, jobject instance, jint a, jint b) {
    int sum = a + b;
    return sum;
}


// 排序
extern "C"
JNIEXPORT void JNICALL
Java_com_dengzi_jnitest_test1_Test1_sort(JNIEnv *env, jobject instance, jintArray arr_) {
    jint *arr = env->GetIntArrayElements(arr_, NULL);
    int size = env->GetArrayLength(arr_);
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    env->ReleaseIntArrayElements(arr_, arr, 0);
}


// 通过用户名获取密码
extern "C"
JNIEXPORT jstring JNICALL
Java_com_dengzi_jnitest_test1_Test1_getPwd(JNIEnv *env, jobject instance, jstring userName_) {
    const char *userName = env->GetStringUTFChars(userName_, 0);
    LOGD("userName = %s", userName);
    const char *rightName = "dengzi";
    if (strcmp(userName, rightName) == 0) {
        const char *pwd = "feifei";
        return env->NewStringUTF(pwd);
    } else {
        return env->NewStringUTF("error");
    }
}