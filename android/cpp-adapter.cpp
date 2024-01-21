#include <jni.h>
#include "rn-frida-detection.h"

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_rnfridadetection_RnFridaDetectionModule_nativeMultiply(JNIEnv *env, jclass type, jdouble a, jdouble b) {
    return rnfridadetection::multiply(a, b);
}
