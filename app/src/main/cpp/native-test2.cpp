#include <jni.h>
#include <string>
#include <android/log.h>

#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

// 修改java中的int值
extern "C"
JNIEXPORT void JNICALL
Java_com_dengzi_jnitest_test2_Test2_changeAge(JNIEnv *env, jobject jobj) {
    jclass clazz = env->GetObjectClass(jobj);
    jfieldID ageField = env->GetFieldID(clazz, "age", "I");
    jint iage = env->GetIntField(jobj, ageField);
    LOGD("age = %d", iage);
    iage = 30;
    env->SetIntField(jobj, ageField, iage);
}

// 修改java中的静态String的值
extern "C"
JNIEXPORT void JNICALL
Java_com_dengzi_jnitest_test2_Test2_changeName(JNIEnv *env, jobject jobj) {
    jclass clazz = env->GetObjectClass(jobj);
    jfieldID nameField = env->GetStaticFieldID(clazz, "name", "Ljava/lang/String;");
    jstring nameJobj = (jstring)env->GetStaticObjectField(clazz, nameField);
    const char *userName = env->GetStringUTFChars(nameJobj, 0);
    LOGD("name = %s", userName);
    char *newName = "dengzi";
    env->SetStaticObjectField(clazz, nameField, env->NewStringUTF(newName));
}


// 调用java中的add方法
extern "C"
JNIEXPORT void JNICALL
Java_com_dengzi_jnitest_test2_Test2_callAdd(JNIEnv *env, jobject jobj) {
    jclass clazz = env->GetObjectClass(jobj);
    jmethodID addMethodId = env->GetMethodID(clazz, "add", "(II)I");
    int a = 1;
    int b = 2;
    int sum = env->CallIntMethod(jobj, addMethodId, a, b);
    LOGD("sum = %d", sum);
}


// 获取java中的uuid
extern "C"
JNIEXPORT void JNICALL
Java_com_dengzi_jnitest_test2_Test2_getUUID(JNIEnv *env, jobject jobj) {
    jclass clazz = env->GetObjectClass(jobj);
    jmethodID uuidMethodId = env->GetMethodID(clazz, "getUuid", "()Ljava/lang/String;");
    jstring uuidStr = (jstring)env->CallObjectMethod(jobj, uuidMethodId);
    const char *uuidc = env->GetStringUTFChars(uuidStr, 0);
    LOGD("uuid = %s", uuidc);
}


// c调用java传进来的回调接口
extern "C"
JNIEXPORT void JNICALL
Java_com_dengzi_jnitest_test2_Test2_setCallbackListener(JNIEnv *env, jobject jobj, jobject callback) {
    jclass callbackClazz = env->GetObjectClass(callback);
    jmethodID resultMethodId = env->GetMethodID(callbackClazz, "onResult", "(ILjava/lang/String;)V");
    for (int i = 0; i < 5; i++) {
        const char *result = "callback from C ...";
        env->CallObjectMethod(callback, resultMethodId, i, env->NewStringUTF(result));
    }
}