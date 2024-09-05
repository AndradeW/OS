// C++ code

const int redLed1 = 12;
const int blueLed1 = 11;
const int greenLed1 = 10;

const int mode = 13;

void setup()
{
    pinMode(redLed1, OUTPUT);
    pinMode(blueLed1, OUTPUT);
    pinMode(greenLed1, OUTPUT);
    pinMode(mode, INPUT);
}

void loop()
{
    (digitalRead(mode) == HIGH) ? normalState() : yellowState();
}

void normalState()
{
    analogWrite(redLed1, 1);
    analogWrite(blueLed1, 1);
    analogWrite(greenLed1, 255);
}

void yellowState()
{

    analogWrite(redLed1, 255);
    analogWrite(blueLed1, 0);
    analogWrite(greenLed1, 255);

    delay(500);

    analogWrite(redLed1, 0);
    analogWrite(blueLed1, 0);
    analogWrite(greenLed1, 0);

    delay(500);
}
