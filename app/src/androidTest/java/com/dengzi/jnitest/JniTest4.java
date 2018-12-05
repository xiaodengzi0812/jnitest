package com.dengzi.jnitest;

import android.util.Log;

import com.dengzi.jnitest.test3.Test3;
import com.dengzi.jnitest.test3.UserBean;
import com.dengzi.jnitest.test4.DzParcel;

import org.junit.Test;

public class JniTest4 {

    @Test
    public void createUserBean() {
        DzParcel parcel = new DzParcel();
        parcel.writeString("dengzi and feifei");
        parcel.writeInt(16);
        parcel.writeInt(30);

        parcel.setDataPos(0);

        String val3 = parcel.readString();
        int val = parcel.readInt();
        int val2 = parcel.readInt();
        Log.e("dengzi", "val = " + val);
        Log.e("dengzi", "val2 = " + val2);
        Log.e("dengzi", "val3 = " + val3);
    }
}
