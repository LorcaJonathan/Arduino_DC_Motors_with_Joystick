// Definición de los pines de entrada y salida
int speedPin1 = 3;   // Pin de velocidad del motor 1
int dirPin1 = 4;     // Pin de dirección 1 del motor 1
int dirPin2 = 5;     // Pin de dirección 2 del motor 1

int speedPin2 = 6;   // Pin de velocidad del motor 2
int dirPin3 = 7;     // Pin de dirección 1 del motor 2
int dirPin4 = 8;     // Pin de dirección 2 del motor 2

int yVal = A0;    // Pin de lectura analógica
int readValue;       // Variable para almacenar el valor leído del joystick del eje Y

void setup() {
  // Configuración de los pines como entrada o salida
  pinMode(speedPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);

  pinMode(speedPin2, OUTPUT);
  pinMode(dirPin3, OUTPUT);
  pinMode(dirPin4, OUTPUT);

  pinMode(yVal, INPUT);
}

void loop() {
  // Lectura del valor analógico del pin del joystick del eje Y
  readValue = analogRead(yVal);

  // Establecer la velocidad del motor 1 al máximo
  analogWrite(speedPin1, 255);
  analogWrite(speedPin2, 255);

  // Comprobar el valor leído para determinar la dirección del motor 1
  if (readValue < 400) {  // Si el valor del joystick es menor de 400 del eje Y
    digitalWrite(dirPin1, HIGH);   // Establecer dirección 1 del motor 1 como HIGH
    digitalWrite(dirPin2, LOW);    // Establecer dirección 2 del motor 1 como LOW

    digitalWrite(dirPin3, HIGH);
    digitalWrite(dirPin4, LOW);
  }
  else if (readValue < 600) {
    digitalWrite(dirPin1, LOW);    // Establecer dirección 1 del motor 1 como LOW
    digitalWrite(dirPin2, LOW);    // Establecer dirección 2 del motor 1 como LOW
    
    digitalWrite(dirPin3, LOW);
    digitalWrite(dirPin4, LOW);
  }
  else {
    digitalWrite(dirPin1, LOW);    // Establecer dirección 1 del motor 1 como LOW
    digitalWrite(dirPin2, HIGH);   // Establecer dirección 2 del motor 1 como HIGH

    digitalWrite(dirPin3, LOW);
    digitalWrite(dirPin4, HIGH);
  }
}
