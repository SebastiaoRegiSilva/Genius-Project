// C++ code

#define led_pin2 2
#define temp_pin A5

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
  	if(temp > 50)
    	digitalWrite(led_pin2, HIGH);
	
  	// Apagar o led.
  	digitalWrite(led_pin2, LOW);
}