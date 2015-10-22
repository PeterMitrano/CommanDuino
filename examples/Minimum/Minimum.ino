#include <CommanDuino.h>

//This command will blink an LED every 500ms for 5s
class Blink : public Command{
public:

  Blink(){}

  void initialize(){
    setTimeout(5000);
  }

  void execute(){
    if ((getTime() / period) % 2 == 0){
      digitalWrite(pin,HIGH);
    }
    else {
      digitalWrite(pin,LOW);
    }
  }

  bool isFinished(){
    return isTimedOut();
  }

  void end(){
    digitalWrite(pin, LOW);
  }

private:
  const int pin = 13;
  const int period = 500;
};

Scheduler scheduler(new Blink());

void setup(){}

void loop(){
  scheduler.run();
}
