// C++ code

const int green = 13;
const int blue = 12;
const int red = 11;

void setup()
{
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);

    Serial.begin(9600);
}

void loop()
{
    if (Serial.available() > 0)
    {
        String color = Serial.readStringUntil('\n');

        // Separar los valores por espacio
        int commaIndex1 = color.indexOf(' ');     // Primer espacio
        int commaIndex2 = color.lastIndexOf(' '); // Segundo espacio

        // Serial.println((String) "Index: " + commaIndex1 + " " + commaIndex2);

        // Extraer los valores como Strings
        String r = color.substring(0, commaIndex1);
        String g = color.substring(commaIndex1 + 1, commaIndex2);
        String b = color.substring(commaIndex2 + 1);

        Serial.println((String) "Usted ingreso: " + r + " " + g + " " + b);

        analogWrite(red, r.toInt());
        analogWrite(green, g.toInt());
        analogWrite(blue, b.toInt());
    }
}
