#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

void setup() {
  Wire.begin();//
  Wire.flush();
  
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  if (radio.available()) {
    int arr[5];
    radio.read(&arr, sizeof(arr));
    for(int i=0;i<5;i++)
    {
      Serial.println(arr[i]);
      }
      Serial.println("======");
       //I2C
    Wire.beginTransmission(8);
    for(int i=0;i<5;i++)
    {
      Wire.write(arr[i]); 
    }
    Wire.endTransmission();
    delay(10);

    
  }
}

