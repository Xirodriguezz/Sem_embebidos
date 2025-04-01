const int pinPot = 15;  // Pin del potenciómetro
const int LED = 13;      // Pin del LED

void setup() {
    Serial.begin(115200);
    pinMode(LED, OUTPUT); 
}

void loop() {
    int valorADC = analogRead(pinPot); // Leer el valor del potenciómetro
    valorADC = (valorADC * 0.7) + (analogRead(pinPot) * 0.3); 
    int brillo = map(valorADC, 0, 4095, 0, 255); // Convierte ADC a brillo (0-255)
    int angulo = map(valorADC, 0, 4095, 0, 360); // Convierte ADC a ángulo

    analogWrite(LED, brillo); // Ajusta el brillo del LED

    Serial.print("Valor ADC: ");
    Serial.print(valorADC);
    Serial.print("  -  Brillo: ");
    Serial.print(brillo);
    Serial.print("  -  Ángulo: ");
    Serial.println(angulo);

//    delay(200); // 
}
