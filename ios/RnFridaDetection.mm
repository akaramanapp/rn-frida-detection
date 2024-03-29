#import "RnFridaDetection.h"

@implementation RnFridaDetection
RCT_EXPORT_MODULE()

// Example method
// See // https://reactnative.dev/docs/native-modules-ios
RCT_EXPORT_METHOD(multiply:(double)a
                  b:(double)b
                  resolve:(RCTPromiseResolveBlock)resolve
                  reject:(RCTPromiseRejectBlock)reject)
{
    NSNumber *result = @(rnfridadetection::multiply(a, b));

    resolve(result);
}

RCT_EXPORT_METHOD(bol:(double)a
                  b:(double)b
                  resolve:(RCTPromiseResolveBlock)resolve
                  reject:(RCTPromiseRejectBlock)reject)
{
    NSNumber *result = @(rnfridadetection::bol(a, b));

    resolve(result);
}


@end
