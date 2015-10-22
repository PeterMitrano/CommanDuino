#pragma once

#include <CommanDuino.h>

#include "Arduino.h"

//This command will blink an LED every 500ms for 5s
class Blink : public Command{
public:
  Blink();
  void initialize();
  void execute();
  bool isFinished();
  void end();
private:
  const int pin = 13;
  const int period = 500;
};

