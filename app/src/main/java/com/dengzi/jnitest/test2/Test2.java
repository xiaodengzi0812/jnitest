package com.dengzi.jnitest.test2;

public class Test2 {
    private int age = 15;
    private static String name = "feifei";

    public int getAge() {
        return age;
    }

    public String getName() {
        return name;
    }

    static {
        System.loadLibrary("native-test2");
    }

    public native void changeAge();

    public native void changeName();


    public native void callAdd();

    private int add(int a, int b) {
        return a + b;
    }


    public native void getUUID();

    private String getUuid() {
        return "this is uuid from java ... ";
    }


    public native void setCallbackListener(Callback callback);

}
