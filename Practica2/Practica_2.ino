int LEDS[8] = {5, 22, 19, 21, 4, 16, 18, 23};
int N[10][8] = {{0, 22, 19, 21, 4, 16, 18,  0}, {1,  0, 19, 21, 0,  0,  0,  0}, {2, 22, 19,  0, 4, 16,  0, 23}, {3, 22, 19, 21, 4,  0,  0, 23}, {4,  0, 19, 21, 0,  0, 18, 23}, {5, 22,  0, 21, 4,  0, 18, 23}, {6, 22,  0, 21, 4, 16, 18, 23}, {7, 22, 19, 21, 0,  0,  0,  0}, {8, 22, 19, 21, 4, 16, 18, 23}, {9, 22, 19, 21, 4,  0, 18, 23}};
void setup() {
  pinMode(LEDS[0], INPUT_PULLUP);
  for(int i = 1; i < 8; i++){
    pinMode(LEDS[i], OUTPUT);
  }
}
void loop() {
  for(int k = 0; k < 10; k++){
    while(digitalRead(LEDS[0])==HIGH){
      for(int j = 1; j < 8; j++){
          digitalWrite(LEDS[j], LOW);
      }
      for(int j = 1; j < 8; j++){
        if(N[k][j] == LEDS[j]){ 
          digitalWrite(LEDS[j], HIGH);   
        }
      }
    }
    while(digitalRead(LEDS[0])==LOW);
  }
}
