void setup()
{
    pinMode(1, OUTPUT);
}

void loop()
{
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(1, HIGH);
        delay(500);
        digitalWrite(1, LOW);
        delay(500);
    }
    digitalWrite(1, LOW);
    delay(2500);
}