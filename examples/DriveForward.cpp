#include "DriveForward.h"

DriveForward::DriveForward(unsigned long timeout){
  this->timeToDrive = timeout;
}

DriveForward::DriveForward(){
  timeToDrive = 1000;
}

void DriveForward::initialize(){
  setTimeout(timeToDrive);
}

void DriveForward::execute(){

}

bool DriveForward::isFinished(){
  return isTimedOut();
}

void DriveForward::end(){
  //cleanup stuff might go here
}
