void task1() {
    enum class Task1States {
        INIT,
        WAIT_FOR_TIMEOUT
    };

    static Task1States task1State = Task1States::INIT;
    static uint32_t lastTime1;
    static constexpr uint32_t INTERVAL1 = 1000;  // Intervalo de 1 segundo (1000 ms)

    switch (task1State) {
        case Task1States::INIT: {
            Serial.begin(115200);  // Inicializar la comunicación serie una vez
            lastTime1 = millis();
            task1State = Task1States::WAIT_FOR_TIMEOUT;
            break;
        }

        case Task1States::WAIT_FOR_TIMEOUT: {
            uint32_t currentTime = millis();
            if ((currentTime - lastTime1) >= INTERVAL1) {
                lastTime1 = currentTime;
                Serial.print("Tarea 1: mensaje a 1Hz\n");
            }
            break;
        }

        default: {
            break;
        }
    }
}

void task2() {
    enum class Task2States {
        INIT,
        WAIT_FOR_TIMEOUT
    };

    static Task2States task2State = Task2States::INIT;
    static uint32_t lastTime2;
    static constexpr uint32_t INTERVAL2 = 2000;  // Intervalo de 2 segundos (2000 ms)

    switch (task2State) {
        case Task2States::INIT: {
            lastTime2 = millis();
            task2State = Task2States::WAIT_FOR_TIMEOUT;
            break;
        }

        case Task2States::WAIT_FOR_TIMEOUT: {
            uint32_t currentTime = millis();
            if ((currentTime - lastTime2) >= INTERVAL2) {
                lastTime2 = currentTime;
                Serial.print("Tarea 2: mensaje a 0.5Hz\n");
            }
            break;
        }

        default: {
            break;
        }
    }
}

void task3() {
    enum class Task3States {
        INIT,
        WAIT_FOR_TIMEOUT
    };

    static Task3States task3State = Task3States::INIT;
    static uint32_t lastTime3;
    static constexpr uint32_t INTERVAL3 = 4000;  // Intervalo de 4 segundos (4000 ms)

    switch (task3State) {
        case Task3States::INIT: {
            lastTime3 = millis();
            task3State = Task3States::WAIT_FOR_TIMEOUT;
            break;
        }

        case Task3States::WAIT_FOR_TIMEOUT: {
            uint32_t currentTime = millis();
            if ((currentTime - lastTime3) >= INTERVAL3) {
                lastTime3 = currentTime;
                Serial.print("Tarea 3: mensaje a 0.25Hz\n");
            }
            break;
        }

        default: {
            break;
        }
    }
}

void setup() {
    task1();  // Llamar a la tarea 1 para inicializarla
    task2();  // Llamar a la tarea 2 para inicializarla
    task3();  // Llamar a la tarea 3 para inicializarla
}

void loop() {
    task1();  // Ejecutar la tarea 1
    task2();  // Ejecutar la tarea 2
    task3();  // Ejecutar la tarea 3
}
