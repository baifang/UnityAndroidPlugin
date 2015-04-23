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
	
	jclass mediaCodecListClass = jni_env->FindClass("android/media/MediaCodecList");         // find class definition
	__android_log_print(ANDROID_LOG_INFO, "JniPlugin", "FindClass - MediaCodecList %p\n", mediaCodecListClass);

	jmethodID methodId_getCodecCount = jni_env->GetStaticMethodID(mediaCodecListClass, "getCodecCount", "()I");
	__android_log_print(ANDROID_LOG_INFO, "JniPlugin", "GetStaticMethodID %s - %p\n", "getCodecCount", methodId_getCodecCount);

	int nCount = jni_env->CallStaticIntMethod(mediaCodecListClass, methodId_getCodecCount);
	__android_log_print(ANDROID_LOG_INFO, "JniPlugin", "Total codec %d\n", nCount);

	jclass mediaCodecClass = jni_env->FindClass("android/media/MediaCodec");         // find class definition
	__android_log_print(ANDROID_LOG_INFO, "JniPlugin", "FindClass - MediaCodec %p\n", mediaCodecClass);

	jmethodID methodId_createByCodecName = jni_env->GetStaticMethodID(mediaCodecClass, "createByCodecName", "(Ljava/lang/String;)Landroid/media/MediaCodec;");
	__android_log_print(ANDROID_LOG_INFO, "JniPlugin", "GetStaticMethodID %s - %p\n", "createByCodecName", methodId_createByCodecName);

	jmethodID methodId_getName = jni_env->GetMethodID(mediaCodecClass, "getName", "()Ljava/lang/String;");         // find class definition
	__android_log_print(ANDROID_LOG_INFO, "JniPlugin", "GetMethodID %p\n", methodId_getName);
	// jobject returnObject = jni_env->CallObjectMethod(mediaCodecClass, methodId_getName);
	// __android_log_print(ANDROID_LOG_INFO, "JniPlugin", "CallObjectMethod %p\n", returnObject);
	// const jclass analyticsTrackerClass = jni_env->FindClass("com/jauntvr/app/AnalyticsTracker");
	// __android_log_print(ANDROID_LOG_INFO, "JniPlugin", "FindClass - FindClass %p\n", analyticsTrackerClass);
	// const jmethodID sendMethod = jni_env->GetStaticMethodID(analyticsTrackerClass, "sendEvent", "(Ljava/lang/String;Ljava/lang/String;)V");
	// __android_log_print(ANDROID_LOG_INFO, "JniPlugin", "GetStaticMethodID - sendEvent %p\n", sendMethod);
	//jni->CallStaticVoidMethod(analyticsTrackerClass, sendMethod, jcategory, jaction);


	// jmethodID methodId_createByCodecName = jni_env->GetStaticMethodID(mediaCodecClass, "createByCodecName", "(Ljava/lang/String;)Landroid/media/MediaCodec;");
	// __android_log_print(ANDROID_LOG_INFO, "JniPlugin", "GetStaticMethodID %s - %p\n", "createByCodecName", methodId_createByCodecName);
	// if (jni_env->ExceptionCheck()) {
	// 	__android_log_print(ANDROID_LOG_INFO, "JniPlugin", "NoSuchMethodError %s\n", "createByCodecName");
	// 	return -1;
	// }	
	// jobject returnObject = jni_env->CallObjectMethod(cls_JavaClass, methodId_createByCodecName, "test.mp4");
	// __android_log_print(ANDROID_LOG_INFO, "JniPlugin", "CallObjectMethod %p\n", returnObject);

	return JNI_VERSION_1_6;		// minimum JNI version
}

int JniAdd(int a, int b)
{
	//__android_log_print(ANDROID_LOG_INFO, "JniPlugin", "Result from JniAdd %d\n", a + b);
    return a + b; 
}	
}
