// C++ code

// Definir el pin donde se conectará la luz (por ejemplo, un LED)
const int yellowLed = 13;
const int redLed = 12;
const int greenLed = 11;

// Variables para el modo intermitente
bool intermitente = false; // Para controlar el modo intermitente
unsigned long previousTime = 0;
const int intervalTime = 500; // Intervalo de parpadeo en milisegundos

void setup() {
  // Configurar el pin como salida
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  // Iniciar la comunicación serial (tasa de baudios, similar a bps)
  Serial.begin(9600);

  // Mensaje de bienvenida
  Serial.println("Control de luces por Serial Monitor");
  Serial.println("Presionar 1, para encender la luz verde");
  Serial.println("Presionar 2, para apagar la luz verde");
  Serial.println("Presionar 3, para encender la luz roja");
  Serial.println("Presionar 4, para apagar la luz roja");
  Serial.println("Presionar 5, para encender la luz amarilla");
  Serial.println("Presionar 6, para apagar la luz amarilla");
  Serial.println("Presionar 7, para encender todas las luces");
  Serial.println("Presionar 8, para apagar todas las luces");
  Serial.println("Presionar 9, para piner las luces en modo intermitente");
}

void loop() {
  // Verificar si hay datos disponibles en el puerto serial
  if (Serial.available() > 0) {
    // Leer el comando enviado desde el Serial Monitor
    String comando = Serial.readStringUntil('\n');

    // Quitar espacios en blanco adicionales
    comando.trim();

    // Controlar la luz según el comando recibido
    switch (comando.toInt()) {
    case 1:
      Serial.println("1 -> Encender la luz verde");
      digitalWrite(greenLed, HIGH);
      break;
    case 2:
      Serial.println("2 -> Apagar la luz verde");
      digitalWrite(greenLed, LOW);
      break;
    case 3:
      Serial.println("3 -> Encender la luz roja");
      digitalWrite(redLed, HIGH);
      break;
    case 4:
      Serial.println("4 -> Apagar la luz roja");
      digitalWrite(redLed, LOW);
      break;
    case 5:
      Serial.println("5 -> Encender la luz amarilla");
      digitalWrite(yellowLed, HIGH);
      break;
    case 6:
      Serial.println("6 -> Apagar la luz amarilla");
      digitalWrite(yellowLed, LOW);
      break;
    case 7:
      Serial.println("7 -> Encender todas las luces");
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, HIGH);
      digitalWrite(yellowLed, HIGH);
      break;
    case 8:
      Serial.println("8 -> Apagar todas las luces");
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, LOW);
      digitalWrite(yellowLed, LOW);
      break;
    case 9:
      Serial.println("9 -> piner las luces en modo intermitente");
      intermitente = !intermitente;
      break;
    }
  }
  // Si el modo intermitente está activado, hacer parpadear la luz
  if (intermitente) {
    unsigned long currentTime = millis();
    if (currentTime - previousTime >= intervalTime) {
      previousTime = currentTime;
      // Cambiar el estado de la luz (encender/apagar)
      digitalWrite(greenLed, !digitalRead(greenLed));
      digitalWrite(redLed, !digitalRead(redLed));
      digitalWrite(yellowLed, !digitalRead(yellowLed));
    }
  }
}
