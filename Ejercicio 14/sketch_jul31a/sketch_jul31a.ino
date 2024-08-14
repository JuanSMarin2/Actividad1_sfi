void swap(uint32_t *a, uint32_t *b) {
    int temp = *a; // Guarda el valor de a en una variable temporal
    *a = *b;       // Asigna el valor de b a a
    *b = temp;     // Asigna el valor de temp (el valor original de a) a b
}

void task1()
{
    enum class Task1States    {
        INIT,
        WAIT_DATA
    };
    static Task1States task1State = Task1States::INIT;

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
        // evento 1:        // Ha llegado al menos un dato por el puerto serial?        
  if (Serial.available() > 0)
        {
            Serial.read();
            uint32_t var1 = 5;
            uint32_t var2 = 6;

        Serial.print("Antes del intercambio: var1 = ");
    Serial.print(var1);
    Serial.print(", var2 = ");
    Serial.println(var2);

   
    swap(&var1, &var2);

    Serial.print("Después del intercambio: var1 = ");
    Serial.print(var1);
    Serial.print(", var2 = ");
    Serial.println(var2);    

        }
        break;
    }

    default:
    {
        break;
    }
    }
}

void setup()
{
    task1();
}

void loop()
{
    task1();
}
