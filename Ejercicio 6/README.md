# Juan Sebastián Marín Aristizábal 
# ID: 000186343


## Ejercicio 6
### ¿Cómo se ejecuta este programa?
Se inicializa la comunicación serie y entra en un bucle infinito (loop) donde se ejecuta la máquina de estados, alternando entre los estados INIT y WAIT_TIMEOUT.

### Pudiste ver este mensaje: Serial.print("Task1States::WAIT_TIMEOUT\n");. ¿Por qué crees que ocurre esto?
Este mensaje se imprime cuando el programa cambia del estado INIT al estado WAIT_TIMEOUT. Esto ocurre sólo una vez, cuando se inicializa la comunicación serie y se configura el programa para comenzar el ciclo de espera.

### ¿Cuántas veces se ejecuta el código en el case Task1States::INIT?
Se ejecuta solo una vez, durante la inicialización. Después de esto, el estado cambia a WAIT_TIMEOUT y permanece allí, ejecutando el código en el case Task1States::WAIT_TIMEOUT repetidamente.
