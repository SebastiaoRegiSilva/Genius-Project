// C++ code

#define led_pin2 2
#define temp_pin A5

// Cores para o LED RGB.
int vermelho = 8; 
int verde = 9;
int azul = 10;


int temp_adc;
float temp_volt,temp;
 

  
void setup()
{
  pinMode(led_pin2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
	temp_adc = analogRead(A5);
  	temp_volt = (5* temp_adc)/(pow(2,10)-1);
    	
  	// Temperatura em graus.
	temp = ((temp_volt -0.1)*100)+(-40);
  	Serial.print("Temperatura: ");
  	Serial.println(temp);
	
  	// Se a temperatura for mais que 50º, acender o led.
  	if(temp < 0)
    {
    	analogWrite(vermelho,0XBA);
  		analogWrite(verde, 0XC7);
  		analogWrite(azul, 0XFCF);
    }
  	else if(temp > 0 && temp < 20)
    {
    	analogWrite(vermelho,0XFF);
  		analogWrite(verde, 0XC2);
  		analogWrite(azul, 0X22);
    }
  	else if(temp > 20 && temp < 60)
    {
    	analogWrite(vermelho,0XFF);
  		analogWrite(verde, 0XFF);
  		analogWrite(azul, 0X00);
    }
  	else
    {
    	analogWrite(vermelho,0XFF);
  		analogWrite(verde, 0X28);
  		analogWrite(azul, 0X00);
    }
}