#include <jni.h>
#include "main.h"

bool InitGameLibrary();

jint JNI_OnLoad(JavaVM *vm, void* reserved)
{
	if(InitGameLibrary())
		LOGI("libGTAVC.so is detected. Address: 0x%X", g_libGTAVC);
	else
		LOGI("Error: libGTAVC.so not found.");

	return JNI_VERSION_1_4;
}