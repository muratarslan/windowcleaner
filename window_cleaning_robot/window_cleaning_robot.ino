/*
    WINDOW CLEANING ROBOT
*/

// Stepper Pins 
#define DIR 13
#define ENA 5
#define PUL 6

// Sonar
#define trigPin 4
#define echoPin 3

// LED 
const int ledPin =  7;     
int ledState = LOW;           
long previousMillis = 0;     
long interval = 1000;  
 

// MOTORS
int motorPins[]= {8,9,10,11};


// BUTTON
int motorButton = 2;
int buttonState = 0;  
int lastButtonState = 0; 
int buttonCounter = -1;


boolean start = false;


void setup() { 
  Serial.begin(9600);  
  
  // Stepper Pins
  pinMode(DIR, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(PUL, OUTPUT);
  digitalWrite(DIR, LOW);
  digitalWrite(ENA, LOW);
  
  // Sonar Pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
    
  // Set Motors Output
  for(int i=0; i<4; i++){
    pinMode(motorPins[i], OUTPUT);
    digitalWrite(motorPins[i],LOW);
  }
  
  pinMode(ledPin, OUTPUT);   
  pinMode(motorButton, INPUT);
}


void motorUp(){
  digitalWrite(ENA, LOW);
  digitalWrite(DIR, LOW);
  tone(PUL, 1600);
  delay(1000);
  digitalWrite(ENA, HIGH);
}


void motorDown(){
digitalWrite(ENA, LOW);
digitalWrite(DIR, HIGH);
tone(PUL, 1600);
delay(1000);
digitalWrite(ENA, HIGH);
}

// Sonar - Stepper function
void sonar(){
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  if (distance < 4) { 
    if(start == false){
      motorUp();      
    }
    start = true;
  }
  else{
     if(start == true){
      motorDown();
    }
    start = false;
  }
  
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}


// Blink led function using time interval
void blink_led(){
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;  

    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    digitalWrite(ledPin, ledState);
  }
}


// Set motors with button
void motors(){
  buttonCounter++;
  
  if (buttonCounter % 2 == 1){
   for(int i=0; i<4; i++){
    digitalWrite(motorPins[i],HIGH);
    delay(100);}
  }
  else{
   for(int i=0; i<4; i++){
    digitalWrite(motorPins[i],LOW);
    delay(100);}
  }
}



void loop() {
  blink_led();
  sonar();
  
  buttonState = digitalRead(motorButton);
 
    if (buttonState != lastButtonState) {
      if (buttonState == HIGH) {
        motors();
      }
     lastButtonState = buttonState;
    }
  
  Serial.println(buttonCounter);

}





