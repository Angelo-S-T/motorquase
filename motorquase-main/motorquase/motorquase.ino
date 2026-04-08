int pinbtnesquerda = 2;
int pinbtndireita = 3;
int pin1a = 4;
int pin2a = 5;
int pin12en = 6;

void setup() {
  // Configuração dos pinos
  pinMode(pinbtnesquerda, INPUT_PULLUP);
  pinMode(pinbtndireita, INPUT_PULLUP);
  pinMode(pin1a, OUTPUT);
  pinMode(pin2a, OUTPUT);
  pinMode(pin12en, OUTPUT); // Adicionado para garantir o funcionamento correto do PWM
}

void loop() {
  // Lê o potenciômetro (0 a 1023)
  int valor = analogRead(A0);
  
  // Converte a leitura para o padrão do analogWrite (0 a 255)
  int valorPWM = valor / 4; 

  if(btnesquerdoapertado()) {
    digitalWrite(pin1a, HIGH);
    digitalWrite(pin2a, LOW);
    analogWrite(pin12en, valorPWM);
  }
  else if(btndireitoapertado()) {
    digitalWrite(pin1a, LOW);
    digitalWrite(pin2a, HIGH);
    analogWrite(pin12en, valorPWM);
  }
  else {
    digitalWrite(pin1a, LOW);
    digitalWrite(pin2a, LOW);
    analogWrite(pin12en, 0); // Garante que a velocidade vá a zero quando parar
  }
} // Fim da função loop

// --- Funções Auxiliares ---

bool btnesquerdoapertado() {
  // Com INPUT_PULLUP: apertado = LOW (!digitalRead), solto = HIGH (digitalRead)
  // Retorna verdadeiro se o esquerdo estiver APERTADO e o direito SOLTO
  return !digitalRead(pinbtnesquerda) && digitalRead(pinbtndireita);
}

bool btndireitoapertado() {
  // Retorna verdadeiro se o direito estiver APERTADO e o esquerdo SOLTO
  return !digitalRead(pinbtndireita) && digitalRead(pinbtnesquerda);
}