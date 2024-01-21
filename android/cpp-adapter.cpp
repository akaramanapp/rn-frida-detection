#include <jni.h>
#include "rn-frida-detection.h"
#include <iostream>
#include <chrono>
#include <thread>

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_rnfridadetection_RnFridaDetectionModule_nativeMultiply(JNIEnv *env, jclass type, jdouble a, jdouble b) {
    return rnfridadetection::multiply(a, b);
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_rnfridadetection_RnFridaDetectionModule_nativeBol(JNIEnv *env, jclass type, jdouble a, jdouble b) {
    return rnfridadetection::bol(a, b);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_rnfridadetection_RnFridaDetectionModule_nativeDetect(JNIEnv *env, jclass type) {
    std::thread asyncThread(rnfridadetection::detect);
    asyncThread.join();
}
