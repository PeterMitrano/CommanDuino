#include "Robot.h"

void Robot::driveForward(){
  leftMotor.write(180);
  rightMotor.write(0);
}

void Robot::turnLeft(){
  leftMotor.write(180);
  rightMotor.write(180);

}
