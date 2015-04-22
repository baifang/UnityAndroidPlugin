#include <jni.h>
#include <android/log.h>
extern "C"
{
JavaVM* java_vm;
JNIEnv* jni_env = 0;

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	__android_log_print(ANDROID_LOG_INFO, "JniPlugin", "JNI_OnLoad");
	java_vm = vm;
	java_vm->AttachCurrentThread(&jni_env, 0);
	return JNI_VERSION_1_6;		// minimum JNI version
}

int JniAdd(int a, int b)
{
	//__android_log_print(ANDROID_LOG_INFO, "JniPlugin", "Result from JniAdd %d\n", a + b);
    return a + b; 
}	
}
