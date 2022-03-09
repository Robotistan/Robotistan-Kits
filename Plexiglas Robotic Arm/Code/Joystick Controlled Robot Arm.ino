#include <Servo.h>
Servo motor;
Servo motor1;
Servo motor2;
Servo motor3;
#define yPin1 A0
#define xPin1 A1
#define yPin2 A3
#define xPin2 A4
void setup() {

motor.attach(8);
motor1.attach(9);
motor2.attach(10);
motor3.attach(11);
}

void loop() {

int ydeger1 = analogRead(yPin1);
int xdeger1 = analogRead(xPin1);
int xderece1 = map(xdeger1,0,1023,0,180);
int yderece1 = map(ydeger1,0,1023,0,180);
int ydeger2 = analogRead(yPin2);
int xdeger2 = analogRead(xPin2);
int xderece2 = map(xdeger2,0,1023,0,180);
int yderece2 = map(ydeger2,0,1023,0,180);
motor.write(yderece1);
motor1.write(xderece1);
motor2.write(yderece2);
motor3.write(xderece2);
}
