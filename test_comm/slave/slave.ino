#include <Wire.h>

int arr[5];

void setup() {
  Wire.begin(8);// join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output

}

void loop() {
    for(int val=0;val<5;val++)
  {
      Serial.println(arr[val]);
      //Serial.println(" ");
      
    }
    Serial.println("====");
}

void receiveEvent(int howMany) {
  while (1 <= Wire.available()) { // loop through all but the last
    
    for(int val=0;val<5;val++)
    {
      arr[val] = Wire.read();
    }
    
    // print the character
  }
 
  //int x = Wire.read();    // receive byte as an integer
  //Serial.println(x);         // print the integer
}
