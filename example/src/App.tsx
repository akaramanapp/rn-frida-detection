import * as React from 'react';

import { StyleSheet, View, Text, Platform } from 'react-native';
import { multiply, bol, detect } from 'rn-frida-detection';

export default function App() {
  const [result, setResult] = React.useState<number | undefined>();
  const [bolum, setBolum] = React.useState<number | undefined>();

  React.useEffect(() => {
    multiply(3, 7).then(setResult);
    bol(10, 2).then(setBolum);

    Platform.OS === 'android' && detect()
  }, []);

  return (
    <View style={styles.container}>
      <Text>Result: {result}</Text>
      <Text>Bolum: {bolum}</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  box: {
    width: 60,
    height: 60,
    marginVertical: 20,
  },
});
