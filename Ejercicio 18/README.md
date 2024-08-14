# Inventa un programa que ilustre todo lo anterior y en el archivo README.md escribe cómo solucionaste el problema.

Cree el arreglo static int bufferSyze[32]; para representar el buffer de recepción y la variable static int bufferIndex = 0; como contador del while y para rastrear el byte actual.
##
while (Serial.available() > 0 && bufferIndex < 32) Se emplea si a entrado mas de un byte y menos de 32.

##
Esta condición asegura que el programa continuará leyendo datos del puerto serial mientras:

Serial.available() > 0: tenga datos disponibles en el buffer serial.
bufferIndex < 32: El buffer no esté lleno (es decir, no se hayan almacenado 32 bytes).

##

Despues se guarda el dato en la posición de memoria correspondiente al byte con bufferSyze[bufferIndex] = Serial.read();
