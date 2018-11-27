package com.dengzi.jnitest;

import android.util.Log;

import com.dengzi.jnitest.test3.Test3;
import com.dengzi.jnitest.test3.UserBean;

import org.junit.Test;

public class JniTest3 {
    Test3 test3 = new Test3();


    @Test
    public void createUserBean() {
        UserBean userBean = test3.createUserBean();
        Log.e("dengzi", "age = " + userBean.getAge() + ", name = " + userBean.getUserName());
    }
}
