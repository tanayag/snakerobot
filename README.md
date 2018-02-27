# Snake Robot

## Team
* Rishav Sharma
* Md. Zeeshan Qazi
* Abhishek Chauhan
* Tanay Agrawal

## About Code and Project

This is a project where we are implementing a robotic snake with degree of freedom 9, 9 servo motors are connected with their axis of motion perpendicular to each other on alternate positions.
Project is using 2 Arduino Nano(on Snake) and a Arduino Pro Mini(on remote control), however you can use whatever Arduino you want for remote control but will have space constraints in Snake, and the code is implemented in Embedded C. final_code folder contains 3 sub folders, remote, master and slave.

### Remote
Remote control uses a PCB board, with integrated Switches and two Joysticks. These switches are connected with digital pins of Adrduino Pro Mini, after reading the digital input from the switches on PCB, these digital values are transmitted to the Arduino which is refered as "master" in the "final_code" folder. Transreciever NRF24L01 is being used for Transmission of all the digital values to the transreceiver(same NRF24L01) connected on "master arduino".
For Connection of NRF Module to Arduino, you can check [docs](https://github.com/tanayag/snakerobot/blob/master/Documentation.txt).
Remote has a Li-Po Battery of 11.1 V.

### Body
As in the description two arduinos are used in snake's body.

#### Master Arduino

"Master" is recieving values from remote control and transmitting it to slave arduino using I2C communication. Master arduino along with Slave is fitted in head of the robot. Check ["test_comm."](https://github.com/tanayag/snakerobot/tree/master/test_comm) if you want to checkout the communication code.
Along with acting as a bridge for communication, "master" arduino is also attached with a RGB color sensor, which reads the surface on which snake is placed, for now we are using the color sensors, later vision or thermal cameras can also be implemented, as per need.
The RGB values from color sensors are reflected at the RGB leds fixed in the eyes of snake.

#### Slave Arduino

"Slave" recieves the value from Remote Control which are being communicated via "Master" Arduino using I2C Communication. Again to understand how I2C code is working, check master and slave of ["test_comm."](https://github.com/tanayag/snakerobot/tree/master/test_comm) 
Slave Arduino connects with a buzzer and 9 Servo Motors(Goteck GS-5515MG). In Slave Arduino are implemented various Gaits as per the motion of Snake, for now we are implementing Catterpillar Gait, Sidewinding Gait and Serpentile Gait.
