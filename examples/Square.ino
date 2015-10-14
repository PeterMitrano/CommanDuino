#include <CommanDuino.h>
#include "DriveInSquare.h"

Scheduler scheduler;

void setup() {
  scheduler(new DriveInSquare());
}


void loop() {
  // Scheduler is in charge of running all the commands, so it must always be called
  Scheduler::getInstance()->run();
}
