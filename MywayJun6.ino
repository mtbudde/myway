#include <FreeSixIMU.h>
#include <FIMU_ADXL345.h>
#include <FIMU_ITG3200.h>
#include <Wire.h>
#include <Sabertooth.h>

float angles[3];

FreeSixIMU board = FreeSixIMU();

int pidVal = 0;
int motorVal = 0;
int motorValL;
int motorValR;

Sabertooth motors(128);

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  delay(5);
  board.init();
  delay(5);
}

void loop()
{
  //Sensor and angle
  board.getEuler(angles); 
  angles[2] = angles[2] + 90;
  //End sensor and angle
  
  //PID and motor control
  pidVal = updatePid(94, angles[2]);
  //Serial.println(pidVal);
  motors.motor(1, pidVal);
  motors.motor(2, -pidVal);
  //End PID and motor control
}
