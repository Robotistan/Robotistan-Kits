#define BLYNK_TEMPLATE_ID "TMPLlgF2jGe-"
#define BLYNK_DEVICE_NAME "blink led"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#include "BlynkEdgent.h"

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  digitalWrite(5,pinValue);
}
BLYNK_WRITE(V0)
{
 int pinValue = param.asInt();
  digitalWrite(4,pinValue);
}
void setup()
{
  Serial.begin(115200);
  delay(100);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  BlynkEdgent.begin();
}
void loop() {
  BlynkEdgent.run();
}
