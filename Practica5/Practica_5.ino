const int ledPin = 2;    // Pin del LED
const int ldrPin = 15;   // Pin de la fotoresistencia (LDR)
int ldrValor = 0;        // Valor leído de la LDR
int perc = 0;            // Porcentaje de luz

void setup() {
  Serial.begin(9600);    // Iniciar comunicación serial
  delay(1000);           // Pequeño retardo inicial
}

void loop() {
  ldrValor = analogRead(ldrPin); // Leer el valor de la LDR

  // Invertir el valor para que sea mayor en la oscuridad
  ldrValor = 4095 - ldrValor;

  // Calcular el porcentaje de luz (opcional)
  perc = (ldrValor * 100) / 4095;

  // Mostrar valores en el monitor serial
  Serial.print("Valor LDR: " + String(ldrValor));
  Serial.println("\tPorcentaje: " + String(perc));

  // Ajustar el brillo del LED (0-255)
  int brillo = map(ldrValor, 0, 4095, 0, 255);
  analogWrite(ledPin, brillo);

  delay(100); // Pequeño retardo para estabilizar la lectura
}