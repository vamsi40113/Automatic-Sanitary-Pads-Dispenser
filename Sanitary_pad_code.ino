#include <SPI.h>
#include <MFRC522.h>
#include <Stepper.h>
 
#define SS_PIN 10
#define RST_PIN 9
const int stepsPerRevolution = 500;
Stepper myStepper(stepsPerRevolution, 4, 5, 6, 3);
int j;

MFRC522 mfrc522(SS_PIN, RST_PIN);   
 
void setup() 
{

   myStepper.setSpeed(40);
  Serial.begin(9600);   
  SPI.begin();      
  mfrc522.PCD_Init();   
  Serial.println("Put your card to the reader...");
  Serial.println();

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "C2 D0 C0 89" )//  content.substring(1) == "97 4F 04 37"  content.substring(1)=="4B B3 5F C0") 
  {
    Serial.println("Authorized access");
    int j=1;
    if(j==1){
      for(int k=1;k<=4;k++){
  myStepper.step(stepsPerRevolution);
  delay(100); 
      }
    }
    j=j-1;
    
    Serial.println("Vamsi age =20 s = M");
        Serial.println();

    delay(500);
  
  }
  else  if (content.substring(1) == "3A F4 55 0D" )//  content.substring(1) == "97 4F 04 37"  content.substring(1)=="4B B3 5F C0") 
  {
    Serial.println("Authorized access");
    int j=1;
    if(j==1){
      for(int k=1;k<=4;k++){
  myStepper.step(stepsPerRevolution);
  delay(100); 
      }
    }
    j=j-1;
    Serial.println("Kalyan age = 20 s= M");
    Serial.println();
    delay(500);
  
  }
 
 else   {
    Serial.println(" Access denied");
        Serial.println();
         delay(500);

   
  }
}
