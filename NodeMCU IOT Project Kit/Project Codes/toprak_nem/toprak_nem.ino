
#define BLYNK_TEMPLATE_ID "TMPLlgF2jGe-"
#define BLYNK_DEVICE_NAME "blink led"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
#define BLYNK_DEBUG

#define APP_DEBUG
#include "BlynkEdgent.h"

int soilmoisture;
int analogInput = A0;
int relay = D1;

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt(); 
}

void setup() {
  
pinMode(analogInput, INPUT);
pinMode(relay, OUTPUT); 
Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() { 
Blynk.run();
soilmoisture = analogRead(analogInput);
Serial.println(soilmoisture);
Blynk.virtualWrite(V0,soilmoisture);
BlynkEdgent.run();
if(soilmoisture>950) 
{
  digitalWrite(relay,HIGH);
}
else
{
  digitalWrite(relay,LOW);
}
}
