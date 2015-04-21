package com.jauntvr.androidPlugin;
 
import android.content.Context;
import android.widget.Toast;
 
public class ToastExample {
    
    private Context context;
    private static ToastExample instance;
 
    public ToastExample() {
        this.instance = this;
    }
 
    public static ToastExample instance() {
        if(instance == null) {
            instance = new ToastExample();
        }
        return instance;
    }
 
    public void setContext(Context context) {
        this.context = context;
    }
 
    public void showMessage(String message) {
        Toast.makeText(this.context, message, Toast.LENGTH_SHORT).show();
    }
 
}