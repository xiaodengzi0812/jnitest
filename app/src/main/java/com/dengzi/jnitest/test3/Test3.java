package com.dengzi.jnitest.test3;

public class Test3 {

    static {
        System.loadLibrary("native-test3");
    }


    public native UserBean createUserBean();

}
