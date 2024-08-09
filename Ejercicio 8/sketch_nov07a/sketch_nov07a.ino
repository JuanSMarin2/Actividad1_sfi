void setup() { 
  Serial.begin(9600);  // Inicializar el puerto serie
  pinMode(LED_BUILTIN, OUTPUT); 
} 

void loop() { 
  static uint32_t previousTime = 0; 
  uint32_t currentTime = millis(); 

  if ((currentTime - previousTime) > 3000) { 
    Serial.print(" SOS3 ");
    previousTime = currentTime; // Reiniciar el temporizador después de 3 segundos
  } 
  else if ((currentTime - previousTime) > 2000) { 
    Serial.print(" SOS2 "); 
  } 
  else if ((currentTime - previousTime) > 1000) { 
    Serial.print(" SOS1"); 
  } 
}
