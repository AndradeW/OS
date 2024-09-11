// C++ code

// red, green, blue
const int led1[] = {12, 11, 10};
const int led2[] = {9, 8, 7};
const int led3[] = {6, 5, 4};

const int mode = 13;

void setup()
{
    setPinModeOutput(led1);
    setPinModeOutput(led2);
    setPinModeOutput(led3);

    pinMode(mode, INPUT);
}

void loop()
{
    (digitalRead(mode) == HIGH) ? normalState() : yellowState();
}

void yellowState()
{
    setAllLedsColor('y');
    delay(500);

    setAllLedsColor('0');
    delay(500);
}

void normalState()
{
    setLedColors(led1, 'g');
    setLedColors(led2, 'r');
    setLedColors(led3, 'r');
    delay(2000);

    setLedColors(led1, 'y');
    setLedColors(led2, 'y');
    setLedColors(led3, 'r');
    delay(500);

    setLedColors(led1, 'r');
    setLedColors(led2, 'g');
    setLedColors(led3, 'r');
    delay(2000);

    setLedColors(led1, 'r');
    setLedColors(led2, 'y');
    setLedColors(led3, 'y');
    delay(500);

    setLedColors(led1, 'r');
    setLedColors(led2, 'r');
    setLedColors(led3, 'g');
    delay(2000);

    setLedColors(led1, 'y');
    setLedColors(led2, 'r');
    setLedColors(led3, 'y');
    delay(500);
}

void setPinModeOutput(const int led[])
{
    pinMode(led[0], OUTPUT);
    pinMode(led[1], OUTPUT);
    pinMode(led[2], OUTPUT);
}

void setLedColors(const int led[], char color)
{
    int red = 0, green = 0, blue = 0;

    switch (color)
    {
    case 'r':
        red = 255;
        break;
    case 'g':
        blue = 255;
        break;
    case 'y':
        red = 255;
        blue = 255;
        break;
    case '0':
        break;
    }

    analogWrite(led[0], red);
    analogWrite(led[1], green);
    analogWrite(led[2], blue);
}

void setAllLedsColor(char color)
{
    setLedColors(led1, color);
    setLedColors(led2, color);
    setLedColors(led3, color);
}
