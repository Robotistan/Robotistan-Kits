#define BLYNK_TEMPLATE_ID "TMPLlgF2jGe-"
#define BLYNK_DEVICE_NAME "blink led"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#include "BlynkEdgent.h"
int ledpin  = 13;
int ledpin1 = 12;
int ledpin2 = 14;
  BLYNK_WRITE(V19){
    int pinvalue = param.asInt();
    digitalWrite(ledpin,pinvalue);
}
  BLYNK_WRITE(V20){
    int pinvalue = param.asInt();
    digitalWrite(ledpin1,pinvalue);
}
  BLYNK_WRITE(V21){
    int pinvalue = param.asInt();
    digitalWrite(ledpin2,pinvalue);
}
void setup() {
  Serial.begin(115200);
  delay(100);
  pinMode(ledpin, OUTPUT);
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  BlynkEdgent.begin();
}
void loop() {
  BlynkEdgent.run(); }
