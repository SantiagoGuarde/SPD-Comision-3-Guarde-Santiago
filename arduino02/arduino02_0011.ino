
int buttonState = LOW;
void setup() 
{
	pinMode(2, INPUT);
	pinMode(5, OUTPUT);
	pinMode(12, OUTPUT);
}

void loop()
{
  	buttonState = digitalRead(2);
  
	if (buttonState == HIGH)
	{
  		digitalWrite(5, LOW);
  		digitalWrite(12, HIGH);
  		delay(500);	
  		digitalWrite(5, HIGH);
  		digitalWrite(12, LOW);
  		delay(500); 
	} 
  	else
    { 
		digitalWrite(5, LOW);
		digitalWrite(12, LOW);
	}
}