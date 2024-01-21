import { NativeModules, Platform } from 'react-native';

const LINKING_ERROR =
  `The package 'rn-frida-detection' doesn't seem to be linked. Make sure: \n\n` +
  Platform.select({ ios: "- You have run 'pod install'\n", default: '' }) +
  '- You rebuilt the app after installing the package\n' +
  '- You are not using Expo Go\n';

const RnFridaDetection = NativeModules.RnFridaDetection
  ? NativeModules.RnFridaDetection
  : new Proxy(
      {},
      {
        get() {
          throw new Error(LINKING_ERROR);
        },
      }
    );

export function multiply(a: number, b: number): Promise<number> {
  return RnFridaDetection.multiply(a, b);
}

export function bol(a: number, b: number): Promise<number> {
  return RnFridaDetection.bol(a, b);
}

export function detect(): Promise<number> {
  return RnFridaDetection.detect();
}
