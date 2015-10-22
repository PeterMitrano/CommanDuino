#pragma once

#include <CommanDuino.h>

class TurnLeft: 
public Command {
public:
  TurnLeft();
  TurnLeft(unsigned long timeout);
  void initialize();
  void execute();
  bool isFinished();
  void end();
private:
  unsigned long timeout;
};

