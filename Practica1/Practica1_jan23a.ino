#define LED_PIN 2

void setup() {
  // put your setup code here, to run once:
 pinMode(LED_PIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=100;i<1000;i+=100){
    digitalWrite(LED_PIN, HIGH);
    delay(i);
    digitalWrite(LED_PIN, LOW);
    delay(i);
  }
  for(int i=1000;i>0;i-=100){
    digitalWrite(LED_PIN, HIGH);
    delay(i);
    digitalWrite(LED_PIN, LOW);
    delay(i);
  }
}
