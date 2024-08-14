### Así se pueden leer 3 datos que han llegado al puerto serial:

**`if**(Serial.available() >= 3){
    int dataRx1 = Serial.read()
    int dataRx2 = Serial.read()
    int dataRx3 = Serial.read()
}`
## ¿Qué escenarios podría tener en este caso?

**`if**(Serial.available() >= 2){
    int dataRx1 = Serial.read()
    int dataRx2 = Serial.read()
    int dataRx3 = Serial.read()
}`

Podria no haber suficientes bytes almacenados para llenar las 3 variables entonces podria declararse como -1.
