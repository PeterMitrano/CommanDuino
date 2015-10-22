#include "TurnLeft.h"

TurnLeft::TurnLeft(unsigned long timeout){
  this->timeout = timeout;
}

TurnLeft::TurnLeft() {
  timeout = 1000l;
}

void TurnLeft::initialize(){
  setTimeout(timeout);
}


void TurnLeft::execute(){
  Robot.turnLeft();
}


bool TurnLeft::isFinished(){
  return isTimedOut();
}


void TurnLeft::end(){
  Robot1n.stopDriving();
}
