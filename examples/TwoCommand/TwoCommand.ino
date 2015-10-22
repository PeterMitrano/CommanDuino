#include <CommanDuino.h>

#include "BlinkAlot.h"

Scheduler scheduler(new BlinkAlot());

void setup(){}

void loop(){
  scheduler.run();
}
