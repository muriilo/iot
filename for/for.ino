int contador = 1; 

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando a Serial ...");
}

void loop() {
for (contador = 1; contador <= 50 ; contador++)

{
 Serial.print("Contador: ");
 Serial.println(contador);
}
}
