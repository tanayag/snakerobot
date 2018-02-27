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

 s5.attach(m5);
  /*s1.attach(m1);
  s2.attach(m2);
  s3.attach(m3);
  s4.attach(m4);
  s5.attach(m5);
  s6.attach(m6);
  s7.attach(m7);
  s8.attach(m8);
  s9.attach(m9); */
}



void loop()
{
  s5.write(125);
  delay(400);
  s5.write(65);
  delay(400);
  delay(1000);
  }


/*{

  s1.write(125);
  delay(400);
  s1.write(65);
  delay(400);
  delay(1000);
  
  s2.write(125);
  delay(400);
  s2.write(65);
  delay(400);
  delay(1000);
  
  s3.write(125);
  delay(400);
  s3.write(65);
  delay(400);
  delay(1000);
  
  s4.write(125);
  delay(400);
  s4.write(65);
  delay(400);
  delay(1000);
  
  s5.write(125);
  delay(400);
  s5.write(65);
  delay(400);
  delay(1000);
  
  s6.write(125);
  delay(400);
  s6.write(65);
  delay(400);
  delay(1000);
  
  s7.write(125);
  delay(400);
  s7.write(65);
  delay(400);
  delay(1000);

  s8.write(125);
  delay(400);
  s8.write(65);
  delay(400);
  delay(1000);

  s9.write(125);
  delay(400);
  s9.write(65);
  delay(400);
  delay(1000);
  
  }*/


/*void loop() {
  float c=0;
  for(float i=135;i>=45;i=i-2.5)
  {
    s8.write(i);
    delay(c+1);
    c=c+1;
    }
int d=0;
    for(float i=45;i<=135;i=i+2.5)
  {
    s8.write(i);
    delay(d+1);
    d=d+1;
    }
    
}*/
