#define MT1 32
#define MT2 33
#define MT3 25
#define MT4 26

// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 200;

void motorsSetup(){
  pinMode(MT1, OUTPUT);
  pinMode(MT2, OUTPUT);
  pinMode(MT3, OUTPUT);
  pinMode(MT4, OUTPUT);

  // configure LED PWM functionalitites
  ledcSetup(pwmChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(MT1, pwmChannel);
}

/* 
*  Movements
*/

void stopIt(){
  digitalWrite(MT1, LOW);
  digitalWrite(MT2, LOW);
  digitalWrite(MT3, LOW);
  digitalWrite(MT4, LOW);
}

void goForward(void) {
  digitalWrite(MT2, LOW);
  digitalWrite(MT4, LOW);
  digitalWrite(MT1, HIGH);
  digitalWrite(MT3, HIGH);
  delay(1000);
  stopIt();
}

void goBack(){
  digitalWrite(MT1, LOW);
  digitalWrite(MT3, LOW);
  digitalWrite(MT2, HIGH);
  digitalWrite(MT4, HIGH);
  delay(1000);
  stopIt();
}

void goLeft(){
  digitalWrite(MT2, LOW);
  digitalWrite(MT3, LOW);
  digitalWrite(MT4, LOW);
  digitalWrite(MT1, HIGH);
  delay(500);
  stopIt();
}

void goRight(){
  digitalWrite(MT2, LOW);
  digitalWrite(MT1, LOW);
  digitalWrite(MT4, LOW);
  digitalWrite(MT3, HIGH);
  delay(500);
  stopIt();
}

void goHead(){
  // Move DC motor forward with increasing speed
  goForward();
  while (dutyCycle <= 255){
    ledcWrite(pwmChannel, dutyCycle);   
//    Serial.print("Forward with duty cycle: ");
//    Serial.println(dutyCycle);
    dutyCycle = dutyCycle + 5;
    delay(500);
  }
  dutyCycle = 200;
}
