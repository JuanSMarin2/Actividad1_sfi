## ¿Qué pasa cuando hago un Serial.available()? 
Devuelve la cantidad de bytes disponibles para leer en el buffer de recepción.

## ¿Qué pasa cuando hago un Serial.read()?
Se lee el primer byte en la cola del buffer de recepción y se elimina.

## ¿Qué pasa cuando hago un Serial.read() y no hay nada en el buffer de recepción??
Se devuelve -1.

## ¿Cuántos datos lee Serial.read()?
Uno solo, el del siguiente byte de datos.

## ¿Y si quiero leer más de un dato?
Se puede usar un ciclo for ya que Serial.read() elimina el dato que lee.

## ¿Qué pasa si te envían datos por serial y se te olvida llamar Serial.read()?
Se puede llenar el buffer de recepción lo que puede impedir la lectura de proximos datos.
