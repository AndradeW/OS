// C++ code

// Definir el pin donde se conectará la luz (por ejemplo, un LED)
const int yellowLed = 13;
const int redLed1 = 12;
const int greenLed1 = 11;

// Variables para el modo intermitente
bool intermitente = false; // Para controlar el modo intermitente
unsigned long previousTime = 0;
const int intervalTime = 500; // Intervalo de parpadeo en milisegundos

void setup()
{
    // Configurar el pin como salida
    pinMode(yellowLed, OUTPUT);
    pinMode(redLed1, OUTPUT);
    pinMode(greenLed1, OUTPUT);

    // Iniciar la comunicación serial (tasa de baudios, similar a bps)
    Serial.begin(9600);

    // Mensaje de bienvenida
    Serial.println("Control de luces por Serial Monitor");
    Serial.println("Presionar 1, para encender/apagar la luz verde");
    Serial.println("Presionar 2, para encender/apagar la luz roja");
    Serial.println("Presionar 3, para encender/apagar la luz amarilla");
    Serial.println("Presionar 4, para encender todas las luces");
    Serial.println("Presionar 5, para apagar todas las luces");
    Serial.println("Presionar 6, para piner las luces en modo intermitente");
}

void loop()
{
    // Verificar si hay datos disponibles en el puerto serial
    if (Serial.available() > 0)
    {
        // Leer el comando enviado desde el Serial Monitor
        String comando = Serial.readStringUntil('\n');

        // Quitar espacios en blanco adicionales
        comando.trim();

        // Controlar la luz según el comando recibido
        switch (comando.toInt())
        {
        case 1:
            Serial.println("1 -> Encender/apagar la luz verde");
            digitalWrite(greenLed1, !digitalRead(greenLed1));
            break;
        case 2:
            Serial.println("2 -> Encender/apagar la luz rojo");
            digitalWrite(redLed1, !digitalRead(redLed1));
            break;
        case 3:
            Serial.println("3 -> Encender/apagar la luz amarilla");
            digitalWrite(yellowLed, !digitalRead(yellowLed));
            break;
        case 4:
            Serial.println("4 -> Encender todas las luces");
            digitalWrite(greenLed1, HIGH);
            digitalWrite(redLed1, HIGH);
            digitalWrite(yellowLed, HIGH);
            break;
        case 5:
            Serial.println("5 -> Apagar todas las luces");
            digitalWrite(greenLed1, LOW);
            digitalWrite(redLed1, LOW);
            digitalWrite(yellowLed, LOW);
            break;
        case 6:
            Serial.println("6 -> poner las luces en modo intermitente");
            intermitente = !intermitente;
            break;
        default:
            Serial.println("Opcion invalida");
        }
    }

    // Si el modo intermitente está activado, hacer parpadear la luz
    if (intermitente)
    {
        unsigned long currentTime = millis();
        if (currentTime - previousTime >= intervalTime)
        {
            previousTime = currentTime;
            // Cambiar el estado de la luz (encender/apagar)
            digitalWrite(greenLed1, !digitalRead(greenLed1));
            digitalWrite(redLed1, !digitalRead(redLed1));
            digitalWrite(yellowLed, !digitalRead(yellowLed));
        }
    }
}
