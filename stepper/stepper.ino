#define DIR 4
#define ENA 5
#define PUL 6

void setup() 
{
  pinMode(DIR, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(PUL, OUTPUT);

  digitalWrite(DIR, LOW);
  digitalWrite(ENA, LOW);
}

void loop(){
  analogWrite(PUL, 100);

}

