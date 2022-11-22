#define BLYNK_TEMPLATE_ID "TMPLvHkfTAZ0"
#define BLYNK_DEVICE_NAME "Home Automation System"
#define BLYNK_AUTH_TOKEN "0-Zdp4BWEe32G4e8er-79-pdpETN57sr"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;


const int Flamepin = D0;
const int threshold = 200; // sets threshold value for flame sensor
int flamesensvalue = 0;
int BuzzerPin = D6;                
int MotionPin = D5;
int LedPin= D7;   
int LedPinf= D8;             
int val = 0;

char ssid[] = "Redmi";
char pass[] = "12345678";

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  Serial.println(value);
  if (value == 1)
  {
    Serial.println("on");
    digitalWrite(D1, LOW);

  }

  if (value == 0)
  {
    Serial.println("off");
    digitalWrite(D1, HIGH);
  }
}


BLYNK_WRITE(V1)
{
  int value = param.asInt();
  Serial.println(value);
  if (value == 1)
  {
    Serial.println("on");
    digitalWrite(D2, LOW);

  }

  if (value == 0)
  {
    Serial.println("off");
    digitalWrite(D2, HIGH);
  }
}


BLYNK_WRITE(V2)
{
  int value = param.asInt();
  Serial.println(value);
  if (value == 1)
  {
    Serial.println("on");
    digitalWrite(D3, LOW);

  }

  if (value == 0)
  {
    Serial.println("off");
    digitalWrite(D3, HIGH);
  }
}

BLYNK_WRITE(V3)
{
  int value = param.asInt();
  Serial.println(value);
  if (value == 1)
  {
    Serial.println("on");
    digitalWrite(D4, LOW);

  }

  if (value == 0)
  {
    Serial.println("off");
    digitalWrite(D4, HIGH);
  }
}
void setup()
{

  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);

  pinMode(D1, OUTPUT);

  pinMode(D2, OUTPUT);

  pinMode(D3, OUTPUT);

  pinMode(D4, OUTPUT);

  pinMode(MotionPin, INPUT);
  pinMode(Flamepin, INPUT);     
  pinMode(BuzzerPin, OUTPUT);
  pinMode(LedPin, OUTPUT);
}

void loop()
{
  Blynk.run();
  // motion
  val = digitalRead(MotionPin);  

  if (val == HIGH)  
  {
    digitalWrite(BuzzerPin, HIGH);
    digitalWrite(LedPin, HIGH);  

   // Serial.println("Motion detected!"); 
    delay(1000); 

  }
  else
  {
    digitalWrite(BuzzerPin, LOW);
    digitalWrite(LedPin, LOW); 

    Serial.println("Motion ended!");  

  }

  //flame
 flamesensvalue = analogRead(Flamepin); // reads analog data from flame sensor
  if (flamesensvalue <= threshold) { // compares reading from flame sensor with the threshold value
    digitalWrite(BuzzerPin, HIGH);
    
    digitalWrite(LedPinf, HIGH);  
    delay(1000); //stops program for 1 second
  }
  else {
    digitalWrite(BuzzerPin, LOW);
    
    digitalWrite(LedPinf,LOW);  
  }

}
