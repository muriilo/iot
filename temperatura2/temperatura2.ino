
const int sensor_temperatura = A0;
int led_vermelho = 4;
int led_amarelo = 2;
int led_verde = 3;
int buzina = 5;
int botao1 = 11;
int botao2 = 12;
int leitura_sensor;
int estadoBotao1 = LOW;
int estadoBotao2 = LOW;
int ultimoestadobotao = LOW;
int ultimoestadobotao2 = LOW;
float temperatura;

void setup() {
    pinMode (led_vermelho, OUTPUT); 
  pinMode (led_amarelo, OUTPUT); 
  pinMode (led_verde, OUTPUT); 
  pinMode (buzina, OUTPUT);
  pinMode (botao1, INPUT);
  pinMode (botao2, INPUT);
analogReference(INTERNAL);
Serial.begin(9600);


}

void loop() {
  
  leitura_sensor = analogRead (sensor_temperatura);
  temperatura = leitura_sensor * 0.1075268817204301;
  Serial.print("Temperatura; ");
  Serial.println(temperatura);
  delay(1000);
  estadoBotao1 = digitalRead(botao1);
  if ((temperatura <=25 || estadoBotao1 == LOW)){
    digitalWrite(led_verde,HIGH);
    digitalWrite(led_amarelo,LOW);
       digitalWrite(led_vermelho,LOW);
       noTone (buzina);

  }
    else if ((temperatura >=25) && (temperatura <=28)) {
       digitalWrite(led_vermelho,LOW);
       digitalWrite(led_amarelo,HIGH);
       digitalWrite(led_verde,LOW);
       noTone (buzina);
    }
    estadoBotao2 = digitalRead(botao2);
    Serial.print("estadobotao: ");
    Serial.println(estadoBotao2);
      if ((temperatura >=28 || estadoBotao2 == HIGH)) {
          digitalWrite(led_amarelo,LOW);
       digitalWrite(led_verde,LOW);
                 digitalWrite(led_vermelho,HIGH);
                 tone(buzina, 600);
                
      } 
      ultimoestadobotao = estadoBotao1;
      ultimoestadobotao2 = estadoBotao2;
  }

