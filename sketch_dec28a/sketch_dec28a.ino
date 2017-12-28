const int sensor_temperatura = A0;
int led_vermelho = 4;
int led_amarelo = 2;
int led_verde = 3;
int buzina = 5;
int botao1 = 12;
int botao2 = 11;
int leitura_sensor;
int estadoBotao1 = LOW;
int estadoBotao2 = LOW;
float temperatura;

void setup() {
  pinMode (led_vermelho, OUTPUT);
  pinMode (led_amarelo, OUTPUT);
  pinMode (led_verde, OUTPUT);
  pinMode (buzina, OUTPUT);
  pinMode (botao1, OUTPUT);
  pinMode (botao2, OUTPUT);
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
  estadoBotao2 = digitalRead(botao2);
  if (temperatura <= 25) {
    digitalWrite(led_verde, HIGH);
    digitalWrite(led_amarelo, LOW);
    digitalWrite(led_vermelho, LOW);
    noTone (buzina);
  }
  if ((temperatura >= 25) && (temperatura <= 28)) {
    digitalWrite(led_vermelho, LOW);
    digitalWrite(led_amarelo, HIGH);
    digitalWrite(led_verde, LOW);
    noTone (buzina);
  }
  if (temperatura >= 28) {
    digitalWrite(led_amarelo, LOW);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_vermelho, HIGH);
    tone(buzina, 1000);

  }
  if (estadoBotao1 == HIGH )
  {
    while (estadoBotao2 == LOW)
    {

      digitalWrite (led_vermelho, HIGH);
      delay(5);
      digitalWrite (led_vermelho, LOW);
      delay(300);
      digitalWrite (led_amarelo, LOW);
      digitalWrite (led_verde, LOW);
      tone(buzina, 262, 200); //DO
      delay(300);
      tone(buzina, 349, 300); //FA
      delay(300);
      estadoBotao2 = digitalRead(botao2);
    }
  }
}
