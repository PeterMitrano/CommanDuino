#include "ScootPastIntersection.h"

ScootPastIntersection::ScootPastIntersection(){}

void ScootPastIntersection::initialize(){
  setTimeout(scootTime);
}

void ScootPastIntersection::execute(){
  Robot::getInstance()->followLine();
}

bool ScootPastIntersection::isFinished(){
  return isTimedOut();
}

void ScootPastIntersection::end(){
  Robot::getInstance()->stopDriving();
}
