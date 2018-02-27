#include <Servo.h>

Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;
Servo s6;
Servo s7;
Servo s8;
Servo s9;

int m1=9;
int m2=4;
int m3=2;
int m4=7;
int m5=10;
int m6=3;
int m7=5;
int m8=6;
int m9=8;

void setup() {
 
  s1.attach(m1);
  s2.attach(m2);
  s3.attach(m3);
  s4.attach(m4);
  s5.attach(m5);
  s6.attach(m6);
  s7.attach(m7);
  s8.attach(m8);
  s9.attach(m9); 
}

void loop()
{
  s9.write(90);
  s7.write(67);
  delay(100);

  s9.write(44);
  delay(300);
  
  s9.write(67);
  s5.write(113);
  s7.write(90+23);
  delay(300);

  s9.write(90+23);
  s7.write(90+23+23);
  s5.write(113);
  delay(300);

  s5.write(90-23-23);
  s3.write(90-23);
  s7.write(90-23);
  s9.write(90);
  delay(300);

  s7.write(90);
  s5.write(90+23);
  s3.write(90+23+23);
  s1.write(90+23);
  delay(300);

  s5.write(100);
  s3.write(90);
  s1.write(90);
  delay(300);
  
  s5.write(90);
  delay(200);
  
}


















  
