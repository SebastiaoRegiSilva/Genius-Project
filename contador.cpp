/*
	Define os valores dos dígitos.
    Cada dígito representa um traço dentro do segmento, 
    sendo 0 (apagado) e 1 (aceso).
*/
const byte digitos[10][7] = 
{
  	{1,1,1,1,1,1,0},
	{0,1,1,0,0,0,0},
	{1,1,0,1,1,0,1},
	{1,1,1,1,0,0,1},
	{0,1,1,0,0,1,1},
  	{1,0,1,1,0,1,1},
	{1,0,1,1,1,1,1},
	{1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1},
	{1,1,1,0,0,1,1}
};

void setup()
{
  for(int i = 13; i >= 7; i--)
    pinMode(i,OUTPUT);
}

void loop(){
  for(int digito = 0; digito < 10; digito++)
  {
    for(int led = 0; led < 7; led++)
    	digitalWrite((13-led),digitos[digito][led]);    
    delay(1000);
  }
}
