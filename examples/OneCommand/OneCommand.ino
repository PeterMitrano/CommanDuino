#include <CommanDuino.h>

#include "Blink.h"

Scheduler scheduler(new Blink());

void setup(){}

void loop(){
  scheduler.run();
}
