# Hipotesis: 
Va a iniciar a correr en el setup que lleva a task1 que asigna Task1States en el estado de INIT que hace que empieze a correr a 115200 baudios y asigna el estado WAIT_DATA a Task1States, después se ejecuta el loop que lleva de nuevo a task1 y entra en el caso de  WAIT_DATA que revisa si ha pasado un dato por el puerto serial y si se cumple, crea la variable var y la iguala a 0, crea el puntero pvar y le asigna la dirección de var, se ejecuta la función printvar con el contenido de la variable por lo que lee 0, después se ejecuta changeVar con pvar y le asigna 10, se vuelve a leer printVar y esta vez lee 10; después se repite en un ciclo.

## La hipotesis fue correcta.
