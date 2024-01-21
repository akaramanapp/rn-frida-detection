package com.rnfridadetection;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.module.annotations.ReactModule;

@ReactModule(name = RnFridaDetectionModule.NAME)
public class RnFridaDetectionModule extends ReactContextBaseJavaModule {
  public static final String NAME = "RnFridaDetection";

  public RnFridaDetectionModule(ReactApplicationContext reactContext) {
    super(reactContext);
  }

  @Override
  @NonNull
  public String getName() {
    return NAME;
  }

  static {
    System.loadLibrary("rn-frida-detection");
  }

  private static native double nativeMultiply(double a, double b);

  private static native double nativeBol(double a, double b);

  private static native void nativeDetect();

  // Example method
  // See https://reactnative.dev/docs/native-modules-android
  @ReactMethod
  public void multiply(double a, double b, Promise promise) {
    promise.resolve(nativeMultiply(a, b));
  }

  @ReactMethod
  public void bol(double a, double b, Promise promise) {
    promise.resolve(nativeBol(a, b));
  }

  @ReactMethod
  public void detect(Promise promise) {
    nativeDetect();
  }
}
