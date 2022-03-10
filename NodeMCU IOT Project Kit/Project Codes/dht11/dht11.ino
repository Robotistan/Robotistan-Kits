
#define BLYNK_TEMPLATE_ID "TMPLlgF2jGe-"
#define BLYNK_DEVICE_NAME "blink led"
#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#define DHTPIN 14 //D5 pin = 14
#define DHTTYPE DHT11
#define MODE
#include "BlynkEdgent.h"
#include <DHT.h>

int value = 200;

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer1;
float h , t;

void sendSensor()
{
 h = dht.readHumidity();
 t = dht.readTemperature(); // Fahrenheit olarak da ölçülebilir.

  if (isnan(h) || isnan(t)) {
    Serial.println("DHT Sensörü Bulunamadı!!");
    return;
  }
  Blynk.virtualWrite(V2, h);
  Blynk.virtualWrite(V1, t);
}


void setup()
{
  Serial.begin(115200);
  delay(100);
  dht.begin();
  BlynkEdgent.begin();
  timer1.setInterval(2000L, sendSensor);
}

void loop() 
{
  
 BlynkEdgent.run();
 timer1.run();
  
  h = dht.readHumidity();
  t = dht.readTemperature();
  
  if (t>0 && t<15)        
  { 
    Serial.print("SOGUK   "); 
    
  }
  else if (t>14 && t<30)  
  { 
    Serial.print("SICAK  "); 
     
  }
  
  else if (t>30 && t<45)  
  { 
    Serial.print("SICAK   "); 
    ; 
  }
  
  else                    
  { 
    Serial.print("COK SICAK  ");
    
  }

  if (h>0 && h<30)        
  { 
    Serial.println("DUSUK NEM"); 
   
  }
  
  else if (h>30 && h<50)  
  { 
    Serial.println("ORTALAMA NEM"); 
    
  }
  else                    
  {
    Serial.println("YUKSEK NEM");
     
  }
  delay(800);
}
