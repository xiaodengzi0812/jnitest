package com.dengzi.jnitest.test1;

public class Test1 {
    static {
        System.loadLibrary("native-test1");
    }

    // 加法运算
    public native int add(int a, int b);

    public native void sort(int[] arr);

    public native String getPwd(String userName);

}
