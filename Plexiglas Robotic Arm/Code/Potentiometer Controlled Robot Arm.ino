#include <Servo.h>
 //assigning the servo motor numbers
Servo s1; 
Servo s2;
Servo s3;
Servo s4;
//assigning the analog pin numbers where the potentiometer signal pins are connected
int pot1 = 0; 
int pot2 = 1;
int pot3 = 2;
int pot4 = 3;
int val;              // variable to read the value from the analog pin

void setup() {
 //assigning the servo pin no. connections on arduino
  s1.attach(9);     
  s2.attach(6);
  s3.attach(5);
  s4.attach(3);
}

void loop() {
  val = analogRead(pot1);             // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 90);     // scale it to use it with the servo (value between 0 and 90)
  s1.write(val);                      // sets the servo position according to the scaled value
  delay(15);                          // waits for the servo to get there

  val = analogRead(pot2);            
  val = map(val, 0, 1023, 0, 90);     // scale it to use it with the servo (value between 0 and 90)
  s2.write(val);                  
  delay(15);

  val = analogRead(pot3);        
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  s3.write(val);                  
  delay(15);

  val = analogRead(pot4);          
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  s4.write(val);                  
  delay(15); 
}
