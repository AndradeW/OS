// C++ code

const int green = 13;
const int blue = 12;
const int red = 11;

String r;
String g;
String b;

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
        Serial.println("Ingrese un valor entre 0 - 255 RED: ");
        r = Serial.parseInt();

        Serial.println("Ingrese un valor entre 0 - 255 GREEN: ");
        g = Serial.parseInt();

        Serial.println("Ingrese un valor entre 0 - 255 BLUE: ");
        b = Serial.parseInt();

        Serial.println("Salio");
        analogWrite(red, r.toInt());
        analogWrite(green, g.toInt());
        analogWrite(blue, b.toInt());
    }
}

/* void getColor(string color){

    switch (color)
    {
    case 'red':

        break;

    default:
        break;
    }

} */

// Color palette[] = {
//     {255, 0, 0},    // Rojo
//     {0, 255, 0},    // Verde
//     {0, 0, 255},    // Azul
//     {255, 255, 0},  // Amarillo
//     {0, 255, 255},  // Cian
//     {255, 0, 255},  // Magenta
//     {192, 192, 192} // Gris claro
// };