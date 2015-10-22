#pragma once

#include <CommandDuino.h>

class DriveForward: 
public Command {
public:
  DriveForward();
  DriveForward(unsigned long time);
  void initialize();
  void execute();
  bool isFinished();
  void end();
private:
  unsigned long timeToTurn;
};

