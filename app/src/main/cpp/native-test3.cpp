#include <jni.h>
#include <string>
#include <android/log.h>

#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)


// C中创建java对象并返还到java
extern "C"
JNIEXPORT jobject JNICALL
Java_com_dengzi_jnitest_test3_Test3_createUserBean(JNIEnv *env, jobject instance) {
    jclass userClass = env->FindClass("com/dengzi/jnitest/test3/UserBean");
    int age = 30;
    char *name = "dengzi";
    // 构造方法创建类
    //  jmethodID userMethodId = env->GetMethodID(userClass, "<init>", "(ILjava/lang/String;)V");
    //  jobject userBeanObj = env->NewObject(userClass, userMethodId, age, env->NewStringUTF(name));

    // 非构造方法创建类
    jobject userBeanObj = env->AllocObject(userClass);
    jmethodID setAgeMethod = env->GetMethodID(userClass, "setAge", "(I)V");
    env->CallVoidMethod(userBeanObj, setAgeMethod, age);
    jmethodID setUserNameMethod = env->GetMethodID(userClass, "setUserName",
                                                   "(Ljava/lang/String;)V");
    env->CallVoidMethod(userBeanObj, setUserNameMethod, env->NewStringUTF(name));
    return userBeanObj;
}