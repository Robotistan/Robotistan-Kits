#define BLYNK_TEMPLATE_ID "TMPLlgF2jGe-"
#define BLYNK_DEVICE_NAME "blink led"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG

#include "Servo.h"
#include "BlynkEdgent.h"

Servo servo;

BlynkTimer timer;
 
BLYNK_WRITE(V0){
  servo.write(param.asInt());
}

void setup()
{
   Serial.begin(115200);
   servo.attach(D1);
   BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
 
  
}
