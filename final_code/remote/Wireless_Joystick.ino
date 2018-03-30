/*
 * Team ID: 3875
 * Author List: Tanay Agrawal
 * Filename: remote.ino
 * Theme: Spotter Snake
 * Functions: setup(), loop()
 * Global Variables: x1,x2,y1,y2,z1,z2(pins of jouysticks)
 *                   pin_arr(array of digital pins used for remote switches)
 *                   r_x1,r_y1,r_z1,r_x2,r_y2,r_z2(mapped analog reading of pins)
 *                   address(used to describe radio address)
 */

//========================================================================
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int pin_arr[7]={2,3,4,5,6,7,9}; 
RF24 radio( 8,10 ); // CE, CSN

//for joysticks
int x1 = A1;
int y1 = A0;
int z1 = A2;
int x2 = A4;
int y2 = A5;
int z2 = A3;
int r_x1,r_y1,r_z1,r_x2,r_y2,r_z2;

const byte address[6] = "00001";

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();
  
  Serial.begin(9600);
  pinMode(x1,INPUT);
  pinMode(y1,INPUT);
  pinMode(z1,INPUT);
  pinMode(x2,INPUT);
  pinMode(y2,INPUT);
  pinMode(z2,INPUT);
  //switches
  for(int i=0;i<7;i++){
    pinMode(pin_arr[i],INPUT);
    }
}


/*
 * Loop reading Value of respective JoySticks
 */
void loop() {

  int send_arr[13];
    
    for(int i=0;i<7;i++)
    {
    send_arr[i] = digitalRead(pin_arr[i]);
    }

  //joystick1    
  r_x1 = analogRead(x1);
  r_x1 = map(r_x1,0,1023,180,0);
  send_arr[7]=r_x1;
  r_y1 = analogRead(y1);
  r_y1 = map(r_y1,0,1023,180,0);
  send_arr[8]=r_y1;
  r_z1 = analogRead(z1);
  if(r_z1>50)
    {
       send_arr[9]=1;
    }
  else
    {
       send_arr[9]=0;
    }

  //joystick2(reading, mapping and sending values)
  r_x2 = analogRead(x2);
  r_x2 = map(r_x2,0,1023,0,180);
   send_arr[10]=r_x2;
  r_y2 = analogRead(y2);
  r_y2 = map(r_y2,0,1023,0,180);
   send_arr[11]=r_y2;
  r_z2 = analogRead(z2);
  if(r_z2>50)
    {
       send_arr[12]=1;
    }
  else
    {
       send_arr[12]=0;
    }

    for(int j=0;j<13;j++)
    {
      Serial.println(send_arr[j]);
      }
      Serial.println("======");

    //sending array
    radio.write(&send_arr, sizeof(send_arr));

//delay(1000);
}
