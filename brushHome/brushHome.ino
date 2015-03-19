// Stepper Pins 
#define DIR 7
#define ENA 5
#define PUL 6

int stopSwitch;
int stopSwitch2;

boolean start = false;


void motorUp(){
  digitalWrite(ENA, LOW);
  digitalWrite(DIR, LOW);
  tone(PUL, 1600);
  delay(50);
  digitalWrite(ENA, HIGH);
}


void motorDown(){
  digitalWrite(ENA, LOW);
  digitalWrite(DIR, HIGH);
  tone(PUL, 1600);
  delay(50);
  digitalWrite(ENA, HIGH);
}

void motorStop(){
  digitalWrite(ENA, HIGH);
}

void brushHome(){
stopSwitch2 = digitalRead(A0);

if(stopSwitch2==1)
{digitalWrite(7,HIGH);
  motorUp();}
else
{digitalWrite(7,LOW);
  motorStop();
  //delay(10);
  start = true;}
 
/*
do{
  motorUp();
} while (stopSwitch2==1);

motorStop();
*/
}


void brushEdge(){
stopSwitch = digitalRead(A2);

if(stopSwitch==1)
{digitalWrite(7,HIGH);
  motorDown();}
else
{digitalWrite(7,LOW);
  motorStop();
  //delay(10);
  start = false;}
}


void gelGit(){
  if (start == false)
    brushHome();
  else
    brushEdge();
}


void setup(){
  Serial.begin(9600);
  
  // Stepper Pins
  pinMode(DIR, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(PUL, OUTPUT);
  digitalWrite(DIR, LOW);
  digitalWrite(ENA, LOW);
  
  pinMode(A2,INPUT);
  pinMode(A0,INPUT);
  pinMode(13,OUTPUT);
}

void loop(){
 stopSwitch2 = digitalRead(A0);
 stopSwitch = digitalRead(A2); 
 gelGit(); 
 
 Serial.println(stopSwitch);
 Serial.print("\t");
 Serial.print(stopSwitch2);
 Serial.print("\t");
 //delay(100);
   
}
