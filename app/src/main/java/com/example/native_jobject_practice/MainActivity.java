package com.example.native_jobject_practice;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;


public class MainActivity extends AppCompatActivity {

    private TextView t1,t2,t3,t4,t5,t6,t7,t8;

    private native void CallAVoidWithInt(int num);
    private native void CallAVoidWithString(String text);
    private native void CallAVoidWithBoolean(boolean b);
    private native void CallAVoidWithChar(char c);
    private native void CallAVoidWithShort(short s);
    private native void CallAVoidWithLong(long l);
    private native void CallAVoidWithFloat(float f);
    private native void CallAVoidWithDouble(Double d);
    private native void CallAVoid();
    private native void native_findViewById_setText(int id_value);
    private native void native_Toast();
    private native void native_System_exit();
    private native void native_log_debug();
    private native int get_a_integer_from_caller_class();
    private native String get_a_string_from_caller_class();
    private native float get_a_flaot_from_caller_class();



    static {
        System.loadLibrary("native");
    }


    private void get_ui_elements(){

        t1=findViewById(R.id.a1);
        t2=findViewById(R.id.a2);
        t3=findViewById(R.id.a3);
        t4=findViewById(R.id.a4);
        t5=findViewById(R.id.a5);
        t6=findViewById(R.id.a6);
        t7=findViewById(R.id.a7);
        t8=findViewById(R.id.a8);

    }

    public int a_int_in_java = 432;
    public String a_string_in_java = "Hello Java!";
    public float a_float_in_java = 32.2f;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        get_ui_elements();

        CallAVoidWithInt(2); //t1
        CallAVoidWithString("Hello"); //t2
        CallAVoidWithBoolean(true); //t3
        CallAVoidWithChar('A'); //t4
        CallAVoidWithShort((short)2); //t5
        CallAVoidWithLong(43453234); //t6
        CallAVoidWithFloat((float)223.21); //t7
        CallAVoidWithDouble(43.3); //t8

        CallAVoid();

        native_findViewById_setText(R.id.a9);
        native_Toast();
        native_log_debug();
        System.out.println(get_a_string_from_caller_class());
        System.out.println(get_a_flaot_from_caller_class());
        System.out.println(get_a_integer_from_caller_class());


    }

    public void exit_click(View v){
        native_System_exit();
    }

    public void cppIntCall(int number){
        t1.setText("Integer from native: "+number);
    }
    public void cppStringCall(String text){
        t2.setText("String from native: "+text);
    }
    public void cppBooleanCall(boolean cppb){
        t3.setText("Boolean from native: "+cppb);
    }
    public void cppCharCall(char c){
        t4.setText("Char from native: "+c);
    }
    public void cppShortCall(short s){t5.setText("Short from native: "+s);}
    public void cppLongCall(long l){t6.setText("Long from native: "+l);}
    public void cppFloatCall(float f){t7.setText("Float from native: "+f);}
    public void cppDoubleCall(Double d){t8.setText("Double from native: "+d);}

    public void cppCall(){Toast.makeText(getApplicationContext(),"Native Calls. Toast from Java", Toast.LENGTH_LONG).show();}

}