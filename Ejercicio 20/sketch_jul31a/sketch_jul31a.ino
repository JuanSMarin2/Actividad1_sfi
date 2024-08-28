char configuracion;
char codigo;
String contras;
bool pausado = false;

static uint32_t lastTime;
static uint32_t currentTime;
int tiempo = 5;

const int botonSubir = 2; // Pin para el botón S
const int botonBajar = 3; // Pin para el botón B

void setup() {
  pinMode(botonSubir, INPUT);
  pinMode(botonBajar, INPUT);
  Serial.begin(115200);
}

void loop() {
  task1();
}

void task1() {
  enum class Task1States {
    INIT,
    WAIT_FOR_TIMEOUT
  };

  static Task1States task1State = Task1States::INIT;

  switch (task1State) {
    case Task1States::INIT: {
      Serial.begin(115200);
      lastTime = millis();
      task1State = Task1States::WAIT_FOR_TIMEOUT;
      break;
    }

    case Task1States::WAIT_FOR_TIMEOUT: {
      Serial.println("CONFIG");
      Serial.println(tiempo);
      CONFIG();
      break;
    }

    default: {
      break;
    }
  }
}

void CONFIG() {
  Serial.println("CONFIG");
  Serial.println(tiempo);

  while (true) {
    if (Serial.available() > 0) {
      configuracion = Serial.read();

      switch (configuracion) {
        case 's': {
          if (tiempo < 150) {
            tiempo++;
          }
          break;
        }
        case 'b': {
          if (tiempo > 0) {
            tiempo--;
          }
          break;
        }
        case 'l': {
          CUENTA();
          break;
        }
        default: {
          Serial.println("CONFIG");
          break;
        }
      }
      Serial.println(tiempo); // Mostrar el nuevo valor de tiempo
      delay(1000);
    }
  }
}

void CUENTA() {
  while (true) {
    currentTime = millis();
    if ((currentTime - lastTime) >= 1000) {
      tiempo--;
      lastTime = currentTime;
      Serial.println(tiempo); // Mostrar el nuevo valor de tiempo
    

    if (Serial.available() > 0) {
      codigo = Serial.read();
    }

    if (codigo == 'c') {
      CONTRASENA();
    }

    if (tiempo <= 0) {
      Serial.println("RADIACIÓN NUCLEAR ACTIVA");
      delay(2000);
      break; // Terminar el loop en lugar de llamar a loop() directamente
    }
    }
  }
}

void CONTRASENA() {
  Serial.println("Ingrese el código");
  contras = ""; // Limpiar la cadena de entrada

  while (true) {
    if (Serial.available() > 0) {
      char inputChar = Serial.read();
      contras += inputChar; // Agregar el carácter leído a la cadena

      // Verificar si la contraseña es correcta
      if (contras == "4321") {
        Serial.println("SALVASTE AL MUNDO");
        break; // Salir del bucle si la contraseña es correcta
      } else if (contras.length() >= 4) { // Si la longitud de la cadena es mayor o igual a 4 y no es correcta
        Serial.println("Contraseña incorrecta");
        contras = ""; // Limpiar la cadena para volver a intentarlo
        FATAL();
        
      }
    }
  }
}


void FATAL (){
 while (true) {
    currentTime = millis();
   
      tiempo--;
      lastTime = currentTime;
      Serial.println(tiempo); // Mostrar el nuevo valor de tiempo
    delay(1000);

    if (Serial.available() > 0) {
      codigo = Serial.read();
    }



    if (tiempo <= 0) {
      Serial.println("RADIACIÓN NUCLEAR ACTIVA");
      delay(2000);

      loop();
      break; // Terminar el loop en lugar de llamar a loop() directamente
    }
    
  }

  
  
  
  }
