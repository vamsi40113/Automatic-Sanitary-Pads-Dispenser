#define trigPin 12
#define echoPin 11
#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);//connect RX to pin 10 , connect TX to pin 9

int duration, distance;

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT); //defin ultrasonic tri pin as out put pin 
  pinMode(echoPin, INPUT);  //defin ultrasonic echo as in put pin
  delay(100);
}


void loop()
{
    //setting for ultrasonic sensor reading

    
    digitalWrite(trigPin, HIGH); 
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;

    
  if (distance >= 15) 
        {
        Serial.println("no pads detected");
        Serial.print("distance= ");              
        Serial.print(distance);

        delay(1000);
        
        }
  else {
    
    
        Serial.println("pads detected \n");
        Serial.print("distance= ");              
        Serial.print(distance); 
        delay(1000);   

           // code for send SMS

  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+91123456789\"\r"); // Replace x with your mobile number(not the number which insert in to gsm module)
  delay(1000);
  mySerial.println("Alert Pads are Empty!! Please Refill it ;) ");
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(10000);
        
  }
    
 
  
}
