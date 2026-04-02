int pinbtnesquerda = 2;
int pinbtndireita = 3;
int pin1a = 4;
int pin2a = 5;
int pin12en = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinbtnesquerda,INPUT_PULLUP);
  pinMode(pinbtndireita,INPUT_PULLUP);
  pinMode(pin1a,OUTPUT);
  pinMOde(pin2a,OUTPUT);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  int valor = analogRead(A0);
  if(btnesquerdoapertado()){
    digitalWrite(pin1a,HIGH);
    digitalWrite(pin2a,LOW);
    analogWrite(pin)
  }
  else if(btndireitoapertado()){

  }
  else{

  }
}
bool btnesquerdoapertado(){
  
  return digitalRead(pinbtnesquerda)&& !digitalRead(pinbtndireita);
}


bool btndireitoapertado(){
  
  return digitalRead(pinbtndireita)&& !digitalRead(pinbtnequerda);
}
