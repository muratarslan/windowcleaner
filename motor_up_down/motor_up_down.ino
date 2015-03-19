// Stepper Pins 
#define DIR 7
#define ENA 5
#define PUL 6

void motorUp(){
  digitalWrite(ENA, LOW);
  digitalWrite(DIR, LOW);
  tone(PUL, 1600);
  delay(100);
  digitalWrite(ENA, HIGH);
}


void motorDown(){
  digitalWrite(ENA, LOW);
  digitalWrite(DIR, HIGH);
  tone(PUL, 1600);
  delay(100);
  digitalWrite(ENA, HIGH);
}

void motorStop(){
  digitalWrite(ENA, HIGH);
}

void setup(){
  Serial.begin(9600);
  
  // Stepper Pins
  pinMode(DIR, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(PUL, OUTPUT);
  digitalWrite(DIR, LOW);
  digitalWrite(ENA, LOW);
 
}

void loop(){ 
 motorDown();
   
}
