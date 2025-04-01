#define bLed 2
#define baud 115200
#define butPin 5
#define w1s 50  // Ajusta la velocidad del conteo

// Pines del ESP32 conectados a los segmentos del display
const int segmentos[] = {14, 4, 5, 19, 18, 13, 21};  // A7, B7, C7, D7, E7, F7, G7
const int digitos[] = {23, 22, 25, 26};              // Unidades, decenas, centenas, miles

const byte numeros[10][7] = {
  {0, 0, 0, 0, 0, 0, 1},  // 0
  {1, 0, 0, 1, 1, 1, 1},  // 1
  {0, 0, 1, 0, 0, 1, 0},  // 2
  {0, 0, 0, 0, 1, 1, 0},  // 3
  {1, 0, 0, 1, 1, 0, 0},  // 4
  {0, 1, 0, 0, 1, 0, 0},  // 5
  {0, 1, 0, 0, 0, 0, 0},  // 6
  {0, 0, 0, 1, 1, 1, 1},  // 7
  {0, 0, 0, 0, 0, 0, 0},  // 8
  {0, 0, 0, 0, 1, 0, 0}   // 9
};

int horas = 0, minutos = 0;

void setup() {
  Serial.begin(baud);

  pinMode(bLed, OUTPUT);
  pinMode(butPin, INPUT);

  for (int i = 0; i < 7; i++) pinMode(segmentos[i], OUTPUT);
  for (int i = 0; i < 4; i++) pinMode(digitos[i], OUTPUT);
}

void loop() {
  unsigned long lastMillis = millis();
  
  while (millis() - lastMillis < w1s) {
    mostrarNumero(horas, minutos);
  }

  minutos++;
  
  if (minutos == 60) {  // Cuando llega a 60, reiniciar y aumentar las horas
    minutos = 0;
    horas++;
  }
  
  if (horas == 24) {  // Cuando llega a 24, reiniciar el conteo
    horas = 0;
  }
}

void mostrarNumero(int h, int m) {
  int cifras[4] = {
    (h / 10) % 10,  // Decenas de horas
    h % 10,         // Unidades de horas
    (m / 10) % 10,  // Decenas de minutos
    m % 10          // Unidades de minutos
  };

  for (int j = 0; j < 15; j++) {
    for (int i = 0; i < 4; i++) {
      mostrar(cifras[i], digitos[i]);
      delay(2);
      apagar();
    }
  }
}

void mostrar(int numero, int digito) {
  for (int i = 0; i < 4; i++) digitalWrite(digitos[i], LOW);
  digitalWrite(digito, HIGH);

  for (int i = 0; i < 7; i++) digitalWrite(segmentos[i], numeros[numero][i]);
}

void apagar() {
  for (int i = 0; i < 7; i++) digitalWrite(segmentos[i], HIGH);
}