package com.jauntvr.androidPlugin;
 
import android.content.Context;
import android.widget.Toast;
import android.util.Log;

public class ToastExample {
    private static final String TAG = "ToastExample";
    private Context context;
    private static ToastExample instance;
 
    public ToastExample() {
        Log.d(TAG, "ToastExample");
        this.instance = this;
    }
 
    public static ToastExample instance() {
        Log.d(TAG, "ToastExample::instance");
        if(instance == null) {
            instance = new ToastExample();
        }
        return instance;
    }
 
    public void setContext(Context context) {
        Log.d(TAG, "ToastExample::setContext");
        this.context = context;
    }
 
    public void showMessage(String message) {
        Log.d(TAG, "ToastExample::showMessage");
        Toast.makeText(this.context, message, Toast.LENGTH_SHORT).show();
    }
 
}