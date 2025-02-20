
const int led = 13;          
const int sensor_pin = 36;  
int sensor;					
const int threshold = 1000;  

void setup(){  

  pinMode(led, OUTPUT);  
  Serial.begin(9600);   
}

void loop(){  
  sensor = analogRead(sensor_pin);   
  delay(500);
  Serial.println(sensor);			 
  if(sensor>threshold){  
    digitalWrite(led,HIGH);  
  }  
  else{ 
    digitalWrite(led,LOW);    
  }
}