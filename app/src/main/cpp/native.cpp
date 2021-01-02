#include <jni.h>
#include <string>

using namespace std;

extern "C"
JNIEXPORT void JNICALL
Java_com_example_native_1jobject_1practice_MainActivity_CallAVoidWithInt(JNIEnv *env, jobject thiz, jint javaint) {

    jclass native_callers_class = env->GetObjectClass(thiz);
    jmethodID method = env->GetMethodID(native_callers_class, "cppIntCall", "(I)V");
    env->CallVoidMethod(thiz, method, javaint*29);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_native_1jobject_1practice_MainActivity_CallAVoidWithString(JNIEnv *env, jobject thiz, jstring text) {

    string cpp_s = env->GetStringUTFChars(text,0);
    cpp_s+=" World from C++!";
    jclass native_callers_class = env->GetObjectClass(thiz);
    jmethodID method = env->GetMethodID(native_callers_class, "cppStringCall", "(Ljava/lang/String;)V");
    env->CallVoidMethod(thiz, method, env->NewStringUTF(cpp_s.c_str()));

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_native_1jobject_1practice_MainActivity_CallAVoidWithBoolean(JNIEnv *env, jobject thiz, jboolean b) {

    jclass native_callers_class = env->GetObjectClass(thiz);
    jmethodID method = env->GetMethodID(native_callers_class, "cppBooleanCall", "(Z)V");
    env->CallVoidMethod(thiz, method, 1); //1=true,0=false

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_native_1jobject_1practice_MainActivity_CallAVoidWithChar(JNIEnv *env, jobject thiz, jchar c) {

    jclass native_callers_class = env->GetObjectClass(thiz);
    jmethodID method = env->GetMethodID(native_callers_class,"cppCharCall","(C)V");
    env->CallVoidMethod(thiz, method, c);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_native_1jobject_1practice_MainActivity_CallAVoidWithShort(JNIEnv *env, jobject thiz, jshort s) {

    jclass native_callers_class = env->GetObjectClass(thiz);
    jmethodID method = env->GetMethodID(native_callers_class,"cppShortCall","(S)V");
    env->CallVoidMethod(thiz, method, s);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_native_1jobject_1practice_MainActivity_CallAVoidWithLong(JNIEnv *env, jobject thiz, jlong l) {

    jclass native_callers_class = env->GetObjectClass(thiz);
    jmethodID method = env->GetMethodID(native_callers_class,"cppLongCall","(J)V");
    env->CallVoidMethod(thiz, method, l);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_native_1jobject_1practice_MainActivity_CallAVoidWithFloat(JNIEnv *env, jobject thiz, jfloat f) {

    jclass native_callers_class = env->GetObjectClass(thiz);
    jmethodID method = env->GetMethodID(native_callers_class,"cppFloatCall","(F)V");
    env->CallVoidMethod(thiz, method, f);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_native_1jobject_1practice_MainActivity_CallAVoidWithDouble(JNIEnv *env, jobject thiz, jobject d) {

    jclass native_callers_class = env->GetObjectClass(thiz);
    jmethodID method = env->GetMethodID(native_callers_class,"cppDoubleCall","(Ljava/lang/Double;)V");
    env->CallVoidMethod(thiz, method, d);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_native_1jobject_1practice_MainActivity_CallAVoid(JNIEnv *env, jobject thiz) {

    jclass native_callers_class = env->GetObjectClass(thiz);
    jmethodID method = env->GetMethodID(native_callers_class,"cppCall","()V");
    env->CallVoidMethod(thiz,method);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_native_1jobject_1practice_MainActivity_native_1findViewById_1setText(JNIEnv *env, jobject thiz, jint id_value) {

    jclass findviewbyid_class = env->FindClass("androidx/appcompat/app/AppCompatActivity");
    jmethodID jfindViewById = env->GetMethodID(findviewbyid_class,"findViewById", "(I)Landroid/view/View;");

    jobject view = env->CallObjectMethod(thiz,jfindViewById,id_value);

    jstring data = env->NewStringUTF("Call setText from C++");

    jclass setText_class = env->FindClass("android/widget/TextView");
    jmethodID integer_setText_method = env->GetMethodID(setText_class,"setText","(Ljava/lang/CharSequence;)V");
    env->CallVoidMethod(view, integer_setText_method, data);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_native_1jobject_1practice_MainActivity_native_1Toast(JNIEnv *env, jobject thiz) {

    jclass application_context_class = env->FindClass("android/content/Context");
    jmethodID jgetApplicationContext = env->GetMethodID(application_context_class,"getApplicationContext","()Landroid/content/Context;");
    jobject context = env->CallObjectMethod(thiz,jgetApplicationContext);

    jstring data = env->NewStringUTF("Toast from C++");

    jclass toast_class = env->FindClass("android/widget/Toast");
    jmethodID makeText = env->GetStaticMethodID(toast_class,"makeText","(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;");
    jobject toast_init = env->CallStaticObjectMethod(toast_class,makeText,context,data,1);
    jmethodID show = env->GetMethodID(toast_class,"show", "()V");
    env->CallVoidMethod(toast_init,show);


}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_native_1jobject_1practice_MainActivity_native_1System_1exit(JNIEnv *env, jobject thiz) {

    jclass System_class = env->FindClass("java/lang/System");
    jmethodID exit = env->GetStaticMethodID(System_class,"exit", "(I)V");
    env->CallStaticVoidMethod(System_class,exit,0);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_native_1jobject_1practice_MainActivity_native_1log_1debug(JNIEnv *env, jobject thiz) {

    jstring title = env->NewStringUTF("C++ Log");
    jstring content = env->NewStringUTF("Hello World!");

    jclass log_class = env->FindClass("android/util/Log");
    jmethodID print = env->GetStaticMethodID(log_class,"v","(Ljava/lang/String;Ljava/lang/String;)I");
    env->CallStaticIntMethod(log_class,print,title,content);

}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_native_1jobject_1practice_MainActivity_get_1a_1integer_1from_1caller_1class(JNIEnv *env, jobject thiz) {

    jclass mainactivity = env->GetObjectClass(thiz);
    jfieldID a_int_in_java_cpp = env->GetFieldID(mainactivity,"a_int_in_java", "I");
    jint data = env->GetIntField(thiz,a_int_in_java_cpp);

    return data;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_native_1jobject_1practice_MainActivity_get_1a_1string_1from_1caller_1class(JNIEnv *env, jobject thiz) {

    jclass mainactivity = env->GetObjectClass(thiz); //com/example/native_jobject_practice/MainActivity
    jfieldID a_string_in_java_cpp = env->GetFieldID(mainactivity,"a_string_in_java", "Ljava/lang/String;");
    jstring data =(jstring)env->GetObjectField(thiz,a_string_in_java_cpp);

    return data;
}

extern "C"
JNIEXPORT jfloat JNICALL
Java_com_example_native_1jobject_1practice_MainActivity_get_1a_1flaot_1from_1caller_1class(JNIEnv *env, jobject thiz) {

    jclass mainactivity = env->GetObjectClass(thiz);
    jfieldID a_float_in_java_cpp = env->GetFieldID(mainactivity,"a_float_in_java", "F");
    jfloat data = env->GetFloatField(thiz,a_float_in_java_cpp);

    return data;
}