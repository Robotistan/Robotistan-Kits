#include <SoftwareSerial.h>
#include <Servo.h>   // servo ve seri haberleşme için kütüphaneleri tanımlıyoruz.

Servo myservo1, myservo2, myservo3, myservo4; // servolarımızı tanımlıyoruz.

int bluetoothTx = 10;
int bluetoothRx = 11;  // Bluetooth alıcı vericilerini tanımlıyoruz.

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
myservo1.attach(5);   // Servolarımızı Arduino'nun pwm(~) çıkışlarına bağlayalım.
myservo2.attach(6);
myservo3.attach(9);
myservo4.attach(3);
Serial.begin(9600);  
bluetooth.begin(9600);  // 9600 baud'luk bir haberleşme tanımlayalım.
}

void loop()
{
if (bluetooth.available() >= 2 ) // 2 hız seviyesindeki Bluetooth sinyal alıyor mu? 
{
unsigned int servopos = bluetooth.read(); 
unsigned int servopos1 = bluetooth.read(); 
unsigned int realservo = (servopos1 * 256) + servopos;  

// Alınan sinyaller kaydediliyor.
// AppInventor'da her servo için ayrı sinyal göndermiştik.
//Şimdi de her servo için tanımlanan sinyalin alınıp alınmadığını kontrol ediyoruz.
//realservo , Uygulamamızdan gelen sinyal değerleri.
// Bu değerler her servo için ayrı ayrı tekrar tanımlanıyor.
// "map" komutu ile bu sinyalleri, motora vereceğimiz açı değerlerine çeviriyoruz.
// örnek: map(servo,alınan min.sinyal,alınan max.sinyal,min.Açı,max.Açı);

if (realservo >= 1000 && realservo <= 1135) // tut bırak
{
int servo1 = realservo;
servo1 = map(servo1, 1000, 1135, 0, 135);
myservo1.write(servo1);
delay(10);
}

if (realservo >= 2000 && realservo <= 2090) { // sağ sol

int servo2 = realservo;
servo2 = map(servo2, 2000, 2090, 0, 90);
myservo2.write(servo2);
delay(10);
}

if (realservo >= 3000 && realservo <= 3180) { // yukarı aşağı
int servo3 = realservo;
servo3 = map(servo3, 3000, 3180, 0, 180);
myservo3.write(servo3);
delay(10);

}

if (realservo >= 4000 && realservo <= 4120) { // ileri geri

int servo4 = realservo;
servo4 = map(servo4, 4000, 4120, 0, 120);
myservo4.write(servo4);
delay(10);

}
}
}
