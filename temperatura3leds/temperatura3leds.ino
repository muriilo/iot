
const int led = 2;
const int led2 = 3;
const int led3 = 4;   
const int botao = 11; 
const int botao2 = 12; 
int estadoBotao = 0;
void setup() {
  pinMode(led,OUTPUT); 
  pinMode(led2,OUTPUT);  
  pinMode(led3,OUTPUT);   
  pinMode(botao,INPUT); 
    pinMode(botao2,INPUT); 
}

void loop() {  
 estadoBotao = digitalRead(botao);          
  if (estadoBotao == HIGH) {
    digitalWrite(led,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  } else {
    digitalWrite(led,LOW); 
  }       
}
