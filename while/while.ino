
const int button1Pin = 4;
int button1State = 1;


void setup() {
  pinMode (1, OUTPUT); 
  pinMode (2, OUTPUT); 
  pinMode (3, OUTPUT); 
  pinMode (button1Pin, INPUT);

}

void loop() {

  button1State = digitalRead(button1Pin);          
  if (button1State == HIGH) {
  digitalWrite(1,HIGH);  
    delay(5000); 
  digitalWrite(1,LOW); 
  digitalWrite(2,HIGH);
  delay(2000);         
  digitalWrite(2,LOW);      
   digitalWrite(3,HIGH); 
     delay(7000);
    digitalWrite(3,LOW); 

        button1State = digitalRead(button1Pin);          
  if (button1State == HIGH) {   
  digitalWrite(1,LOW);  
  digitalWrite(1,LOW); 
  digitalWrite(2,LOW);     
  digitalWrite(2,LOW);      
   digitalWrite(3,LOW);
    digitalWrite(3,LOW);  

  }
  else {
    return;
  }
}
}
