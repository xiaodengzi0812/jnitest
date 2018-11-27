package com.dengzi.jnitest;

import android.os.SystemClock;
import android.provider.ContactsContract;
import android.support.test.runner.AndroidJUnit4;
import android.util.Log;

import com.dengzi.jnitest.test2.Callback;
import com.dengzi.jnitest.test2.Test2;

import org.junit.Test;
import org.junit.runner.RunWith;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;

/**
 * Instrumented test, which will execute on an Android device.
 *
 * @see <a href="http://d.android.com/tools/testing">Testing documentation</a>
 */
@RunWith(AndroidJUnit4.class)
public class JniTest2 {
    Test2 test2 = new Test2();

    @Test
    public void changeAge() {
        test2.changeAge();
        Log.e("dengzi", "age = " + test2.getAge());
    }

    @Test
    public void changeName() {
        test2.changeName();
        Log.e("dengzi", "name = " + test2.getName());
    }

    @Test
    public void callAdd() {
        test2.callAdd();
    }

    @Test
    public void callUuid() {
        test2.getUUID();
    }

    @Test
    public void testCallback() {
        test2.setCallbackListener(new Callback() {
            @Override
            public void onResult(int position, String result) {
                Log.e("dengzi", "position = " + position + ", result = " + result);
            }
        });

        try {
            CountDownLatch latch = new CountDownLatch(1);
            latch.await(2, TimeUnit.SECONDS);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

}
