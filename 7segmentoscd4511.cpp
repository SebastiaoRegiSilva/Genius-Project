/*
	Define os valores dos dígitos.
    Cada dígito representa um traço dentro do segmento, 
    sendo 0 (apagado) e 1 (aceso).
*/

void setup()
{
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop()
{
  //Ligar o Zero.
  digitalWrite(8,LOW); 
  digitalWrite(9,LOW); 
  digitalWrite(10,LOW); 
  digitalWrite(11,LOW); 
  delay(1000);
  
  //Ligar o Um.
  digitalWrite(8,HIGH); 
  digitalWrite(9,LOW); 
  digitalWrite(10,LOW);
  digitalWrite(11,LOW); 
  delay(1000);
  
  //Ligar o Dois.
  digitalWrite(8,LOW); 
  digitalWrite(9,HIGH); 
  digitalWrite(10,LOW); 
  digitalWrite(11,LOW); 
  delay(1000);
  
  //Ligar o Três.
  digitalWrite(8,HIGH); 
  digitalWrite(9,HIGH); 
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);; 
  delay(1000);
  
  //Ligar o Quatro.
  digitalWrite(8,LOW); 
  digitalWrite(9,LOW); 
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW); 
  delay(1000);
}