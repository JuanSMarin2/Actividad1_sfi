void task1()
{
    enum class Task1States {
        INIT,
        WAIT_DATA
    };
    static Task1States task1State = Task1States::INIT;
    static int bufferSyze[32];
    static int bufferIndex = 0;

    switch (task1State)
    {
    case Task1States::INIT:
    {
        Serial.begin(115200);
        task1State = Task1States::WAIT_DATA;
        break;
    }

    case Task1States::WAIT_DATA:
    {
        while (Serial.available() > 0 && bufferIndex < 32) {
            bufferSyze[bufferIndex] = Serial.read();
            bufferIndex++;
        }

        
        break;
    }

    default:
        break;
    }
}

void setup()
{
    // Inicialmente llama a la tarea
    task1();
}

void loop()
{
    // Llama a la tarea continuamente
    task1();
}
