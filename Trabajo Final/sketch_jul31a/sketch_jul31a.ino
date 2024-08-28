char configuracion;

char codigo;

String contras;

bool pausado = false;

static uint32_t lastTime;

static uint32_t currentTime;

int tiempo = 5;

const int botonSubir = 2; // Pin para el botón S

const int botonBajar = 3; // Pin para el botón B

const int botonCuenta = 4; // Pin para el botón B
 
 


void setup() {

  pinMode(botonSubir, INPUT);

  pinMode(botonBajar, INPUT);
 
}

void loop() {

  task1();

  Serial.begin(115200);

}

void task1() {

  enum class Task1States {

    INIT,

    WAIT_FOR_TIMEOUT

  };

  static Task1States task1State = Task1States::INIT;

  switch (task1State) {

    case Task1States::INIT: {
 
      lastTime = millis();

      task1State = Task1States::WAIT_FOR_TIMEOUT;

      break;

    }

    case Task1States::WAIT_FOR_TIMEOUT: {
 
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

          if (tiempo < 40) {

            tiempo++;

          }

          break;

        }

        case 'b': {

          if (tiempo > 1) {

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

  String contras = ""; // Limpiar la cadena de entrada
 
  while (true) {

    if (Serial.available() > 0) {

      char inputChar = Serial.read();

      // Solo añadir el carácter si no es un salto de línea o retorno de carro

      if (inputChar != '\n' && inputChar != '\r') {

        contras += inputChar; // Agregar el carácter leído a la cadena

      }
 
 
      // Verificar si la longitud de la cadena es 4

      if (contras.length() == 4) {

        // Verificar si la contraseña es correcta

        if (contras == "4321") {

          Serial.println("SALVASTE AL MUNDO");

          CONFIG();

          break; // Salir del bucle si la contraseña es correcta

        } else {

          Serial.println("Contraseña incorrecta");
 
          contras = ""; // Limpiar la cadena para volver a intentarlo

          CUENTA();

        }

      }

    }

  }

}

 
 
