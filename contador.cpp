// Define os valores dos digitos
const byte digitos[10][7] = {{1,1,1,1,1,1,0},
					   		 {0,1,1,0,0,0,0},
					   		 {1,1,0,1,1,0,1},
					   		 {1,1,1,1,0,0,1},
					   		 {0,1,1,0,0,1,1},
  					   		 {1,0,1,1,0,1,1},
					   		 {1,0,1,1,1,1,1},
					   		 {1,1,1,0,0,0,0},
				       		 {1,1,1,1,1,1,1},
					   		 {1,1,1,0,0,1,1}};

void setup()
{
  for(int i = 13; i >= 7; i--)
  {
    pinMode(i,OUTPUT);
  }
}

void loop(){
  for(int digito = 0; digito < 10; digito++){ // Percorre os digitos
    for(int led = 0; led < 7; led++){ // Percorre os valores dos leds
    	digitalWrite((13-led),digitos[digito][led]);// Define valor lógico do led
    }
    delay(1000);
  }
}

/*
OBS: Se a escolha for display catodo comum, ligue o resistor no
GND, se for anodo comun ligue o resistor no 5V e altere a matriz
ou inverta os valoresdos led com o operador de negacao "!".
*/