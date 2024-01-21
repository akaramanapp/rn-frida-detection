#ifdef __cplusplus
#import "rn-frida-detection.h"
#endif

#ifdef RCT_NEW_ARCH_ENABLED
#import "RNRnFridaDetectionSpec.h"

@interface RnFridaDetection : NSObject <NativeRnFridaDetectionSpec>
#else
#import <React/RCTBridgeModule.h>

@interface RnFridaDetection : NSObject <RCTBridgeModule>
#endif

@end
