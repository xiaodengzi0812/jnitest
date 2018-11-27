package com.dengzi.jnitest;

import android.support.test.runner.AndroidJUnit4;
import android.util.Log;

import com.dengzi.jnitest.test1.Test1;

import org.junit.Test;
import org.junit.runner.RunWith;

/**
 * Instrumented test, which will execute on an Android device.
 *
 * @see <a href="http://d.android.com/tools/testing">Testing documentation</a>
 */
@RunWith(AndroidJUnit4.class)
public class JniTest1 {
    Test1 test1 = new Test1();

    @Test
    public void doAdd() {
        int sum = test1.add(1,2);
        Log.e("dengzi", "sum = " + sum);
    }

    @Test
    public void doSort() {
        int[] arr = new int[]{12, 4, 45, 22, 1, 3, 66};
        for (int anArr : arr) {
            Log.e("dengzi", "before = " + anArr);
        }
        test1.sort(arr);
        for (int anArr : arr) {
            Log.e("dengzi", "after = " + anArr);
        }
    }

    @Test
    public void getPwd() {
        String userName = "dengzi";
        String pwd = test1.getPwd(userName);
        Log.e("dengzi", "pwd = " + pwd);

    }
}
