
#define BLYNK_TEMPLATE_ID "TMPLlgF2jGe-"
#define BLYNK_DEVICE_NAME "blink led"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#include "BlynkEdgent.h"

BlynkTimer timer;
 
int GaSSensor = A0; 
int data = 0; 
#define GreenLed 14 
#define RedLed 12 
int buzzer = 0; 

void setup()
{
   Serial.begin(115200);
  pinMode(GreenLed, OUTPUT);
  pinMode(RedLed, OUTPUT);
  timer.setInterval(1000L, getSendData);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  timer.run(); 
  
}
void getSendData()
{
data = analogRead(GasSensor); 
  Blynk.virtualWrite(V2, data);
  
 if (data > 300)
  {
    Blynk.notify("DİKKAT !!! GAZ SENSORUNUZ CALISTI");
    digitalWrite(GreenLed, HIGH);
    digitalWrite(RedLed, LOW);
    tone(buzzer, 1000, 200);
  }

  else
  {
    digitalWrite(GreenLed, LOW);
    digitalWrite(RedLed, HIGH);
    noTone(buzzer);
  }
}

  
