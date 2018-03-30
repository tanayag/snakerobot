/*
 * Team ID: 3875
 * Author List: Tanay Agrawal, Abhishek Chauhan
 * Filename: slave.ino
 * Theme: Spotter Snake
 * Functions: setup(), rgb(), loop()
 * Global Variables: redPin, greenPin, bluePin(LED Pins)
 *                    s2,s3,outpin(Sensor Pins)
 *                    pulseWidth, val_red,val_blue,val_green
 *                    
 */

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

//rgb
int redPin = 3;
int greenPin = 9;
int bluePin = 10;

int flag= -1;

int s2 = 5;
int s3 = 6;

int outPin = 4;

int pulseWidth;
int val_red,val_blue,val_green;


void setup() {
  
  Serial.begin(9600);
  
  //setting up nrf module
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();

  //setting up I2C
  Wire.begin(); 
  Wire.flush();

  //rgb
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(outPin,INPUT);

  rgb();
}

/*
 * Function Name: rgb()
 * Input: None
 * Output: None
 * Logic: takes input from the rgb sensor and shows appropriate output in rgb leds. 
 * Example Call: to be called when triggered with detection button, i.e: rgb().
 */
void rgb()
{ 
  if(flag==0||flag==-1)
  {
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);

  pulseWidth = pulseIn(outPin,LOW);

  val_red = pulseWidth;
  //Serial.print(val_red/10);
  //Serial.print(" , ");

  digitalWrite(s2,LOW);
  digitalWrite(s3,HIGH);

  pulseWidth = pulseIn(outPin,LOW);

  val_blue = pulseWidth;
  //Serial.print(val_blue/10);
  //Serial.print(" , ");
  
  digitalWrite(s2,HIGH);
  digitalWrite(s3,HIGH);

  pulseWidth = pulseIn(outPin,LOW);

  val_green = pulseWidth;
  //Serial.println(val_green/10);
if(val_red < val_green && val_red < val_blue)
{
   val_red = 0;
   val_green = 255;
   val_blue = 255;
  }

else if(val_green < val_red && val_green < val_blue)
{
  val_green = 0;
  val_red = 255;
  val_blue = 255;
  
  }

else if(val_blue < val_green && val_blue < val_red)
{
  val_green = 255;
  val_red = 255;
  val_blue = 0;
  }


    analogWrite(redPin,val_red);
    //Serial.print(val_red);
    //Serial.print(" , ");
    analogWrite(greenPin,val_green);
    //Serial.print(val_green);
    //Serial.print(" , ");
    analogWrite(bluePin,val_blue);
    //Serial.println(val_blue);
    delay(2000);
    analogWrite(redPin,255);
    //Serial.print(val_red);
    //Serial.print(" , ");
    analogWrite(greenPin,255);
    //Serial.print(val_green);
    //Serial.print(" , ");
    analogWrite(bluePin,255);
    //Serial.println(val_blue);
    
  }
  flag=flag+1;
  }



/*
 * Using this loop to recieve the values of Joystick from Remote through NRF 
 * and transfering it Recieve_Snake_Arduino using I2C.
 */
void loop() {
  if (radio.available()) 
  {
    //reading nrf
    int joystick_val[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};  //14th position value for detection_buzzer

    radio.read(&joystick_val, sizeof(joystick_val));
   
    for(int i=0;i<14;i++)
    {
      Serial.println(joystick_val[i]);
    }
    Serial.println("======");

    //I2C
    Wire.beginTransmission(8);
    for(int i=0;i<14;i++)
    {
      Wire.write(joystick_val[i]); 
    }
    Wire.endTransmission();
    delay(10);
    
    
    int detection_buzz = 0;


    
    
    if(joystick_val[2])
   {
       detection_buzz = 1;
            //I2C
             joystick_val[13] = detection_buzz;
          Wire.beginTransmission(8);
          for(int i=0;i<14;i++)
          {
            Wire.write(joystick_val[i]); 
          }
          Wire.endTransmission();
      rgb();
    }
    else
    {
      flag =0;
      }

    
    
    
    
  }
  
}

