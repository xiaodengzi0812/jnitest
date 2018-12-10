#include <jni.h>
#include <string>
#include <android/log.h>

#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

// 共享内存
class Parcel {
    char *mData;
    int mDataPos = 0;

public:
    Parcel() {
        mData = (char *) (malloc(1024));
    }

    void writeInt(jint value) {
        *reinterpret_cast<int *>(mData + mDataPos) = value;
        mDataPos += sizeof(int);
    }

    void writeChar(char* value, int size) {
        for (int i = 0; i < size; i++) {
            *(mData + mDataPos) = *(value+i);
            mDataPos += 1;
        }
        *(mData + mDataPos) = '\0';
        mDataPos += 1;
    }

    char *readChar() {
        char *value = (char *) (malloc(1024));
        int size = 0;
        while (*(mData + mDataPos) != '\0') {
            *(value + size) = *(mData + mDataPos);
            mDataPos += 1;
            size++;
        }
        mDataPos += 1;
        char * temp = value;
        free(value);
        return temp;
    }

    void setDataPosition(jint position) {
        mDataPos = position;
    }

    jint readInt() {
        int result = *reinterpret_cast<int *>(mData + mDataPos);
        mDataPos += sizeof(int);
        return result;
    }

};

extern "C"
JNIEXPORT jlong JNICALL
Java_com_dengzi_jnitest_test4_DzParcel_nativeCreate(JNIEnv *env, jobject instance) {
    Parcel *parcel = new Parcel();
    return (jlong) parcel;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_dengzi_jnitest_test4_DzParcel_nativeWriteInt(JNIEnv *env, jobject instance,
                                                      jlong nativePtr, jint val) {
    Parcel *parcel = (Parcel *) nativePtr;
    parcel->writeInt(val);
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dengzi_jnitest_test4_DzParcel_nativeReadInt(JNIEnv *env, jobject instance,
                                                     jlong nativePtr) {
    Parcel *parcel = (Parcel *) nativePtr;
    return parcel->readInt();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_dengzi_jnitest_test4_DzParcel_nativeWriteString(JNIEnv *env, jobject instance,
                                                         jlong nativePtr, jstring str_) {
    const char *str = env->GetStringUTFChars(str_, 0);
    int size = env->GetStringUTFLength(str_);
    Parcel *parcel = (Parcel *) nativePtr;
    parcel->writeChar((char *)str, size);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dengzi_jnitest_test4_DzParcel_nativeReadString(JNIEnv *env, jobject instance,
                                                        jlong nativePtr) {
    Parcel *parcel = (Parcel *) nativePtr;
    char *value = parcel->readChar();
    return env->NewStringUTF(value);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_dengzi_jnitest_test4_DzParcel_nativeSetDataPosition(JNIEnv *env, jobject instance,
                                                             jlong nativePtr, jint val) {
    Parcel *parcel = (Parcel *) nativePtr;
    parcel->setDataPosition(val);
}