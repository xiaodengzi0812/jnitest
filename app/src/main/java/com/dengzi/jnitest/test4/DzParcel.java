package com.dengzi.jnitest.test4;

public class DzParcel {
    private long mNativePtr; // C中返回的地址

    static {
        System.loadLibrary("native-test4");
    }

    public DzParcel() {
        this.mNativePtr = nativeCreate();
    }

    // 写入int数据
    public final void writeInt(int val) {
        nativeWriteInt(mNativePtr, val);
    }

    // 读取int数据
    public final int readInt() {
        return nativeReadInt(mNativePtr);
    }

    // 写入String数据
    public final void writeString(String str) {
        nativeWriteString(mNativePtr, str);
    }

    // 读取String数据
    public final String readString() {
        return nativeReadString(mNativePtr);
    }

    // 设置当前位置
    public final void setDataPos(int val) {
        nativeSetDataPosition(mNativePtr, val);
    }

    private native long nativeCreate();// 创建C对象

    private native void nativeWriteInt(long nativePtr, int val);// C中存储

    private native int nativeReadInt(long nativePtr);// C中读取

    private native void nativeWriteString(long nativePtr, String str);

    private native String nativeReadString(long nativePtr);

    private native void nativeSetDataPosition(long nativePtr, int val);// 设置当前C指针的位置

}
