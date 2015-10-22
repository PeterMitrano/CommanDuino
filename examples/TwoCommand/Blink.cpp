#include "Blink.h"

Blink::Blink(int period) : Command("Blink"){
  this->period = period;
}

//This command will blink an LED every 500ms for 5s
void Blink::initialize(){
  setTimeout(5000);
}

void Blink::execute(){
  if ((getTime() / period) % 2 == 0){
    digitalWrite(pin,HIGH);
  }
  else {
    digitalWrite(pin,LOW);
  }
}

bool Blink::isFinished(){
  return isTimedOut();
}

void Blink::end(){
  digitalWrite(pin, LOW);
}
