// C++ code

const int redLed1 = 12;
const int blueLed1 = 11;
const int greenLed1 = 10;

const int interruptor = 13;
int mode;

void setup()
{
    pinMode(redLed1, OUTPUT);
    pinMode(blueLed1, OUTPUT);
    pinMode(greenLed1, OUTPUT);
    pinMode(interruptor, INPUT);
}

void loop()
{
    mode = digitalRead(interruptor);
    if (mode == HIGH)
    {
        analogWrite(redLed1, 255);
        analogWrite(blueLed1, 0);
        analogWrite(greenLed1, 255);

        delay(500); // Wait for 1000 millisecond(s)

        analogWrite(redLed1, 0);
        analogWrite(blueLed1, 0);
        analogWrite(greenLed1, 0);

        delay(500); // Wait for 1000 millisecond(s)
    }
    else
    {
        analogWrite(redLed1, 1);
        analogWrite(blueLed1, 1);
        analogWrite(greenLed1, 255);
    }
}