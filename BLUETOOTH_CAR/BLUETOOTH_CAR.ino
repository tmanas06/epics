#include <AFMotor.h>
#include <SoftwareSerial.h>
SoftwareSerial bluetoothSerial(9, 10); 
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
char command;
void setup()
{
  bluetoothSerial.begin(9600);  
}
void loop() {
  if (bluetoothSerial.available() > 0) {
    command = bluetoothSerial.read();
    Stop(); 
    switch (command) {
      case 'F':
        Serial.println("F");
        forward();
        break;
      case 'B':
        Serial.println("B");
        back();
        break;
      case 'L':
        Serial.println("L");
        left();
        break;
      case 'R':
        Serial.println("R");
        right();
        break;
    }
  }
}
void forward()
{
  motor1.setSpeed(255); 
  motor1.run(FORWARD);  
  motor2.setSpeed(255); 
  motor2.run(FORWARD);  
  motor3.setSpeed(255); 
  motor3.run(FORWARD);  
  motor4.setSpeed(255); 
  motor4.run(FORWARD);  
}

void back()
{
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(255); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(255); 
  motor4.run(BACKWARD); 
}

void left()
{
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(255); 
  motor3.run(FORWARD);  
  motor4.setSpeed(255); 
  motor4.run(FORWARD);  
}

void right()
{
  motor1.setSpeed(255); 
  motor1.run(FORWARD);  
  motor2.setSpeed(255); 
  motor2.run(FORWARD);  
  motor3.setSpeed(255); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(255); 
  motor4.run(BACKWARD); 
}

void Stop()
{
  motor1.setSpeed(0);  
  motor1.run(RELEASE); 
  motor2.setSpeed(0);  
  motor2.run(RELEASE); 
  motor3.setSpeed(0);  
  motor3.run(RELEASE); 
  motor4.setSpeed(0);  
  motor4.run(RELEASE); 
}
