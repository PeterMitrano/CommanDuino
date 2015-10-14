#include "Command.h"

#include "Robot.h"
#include "Scheduler.h"

Command::Command() : initialized(false) {}

Command::Command(String name) : initialized(false), name(name), startTime(Robot::getTime()) {}

bool Command::cycle() {
  bool finished = false;

  if (!initialized) {
    initialize();
    _initialize();
    initialized = true;
  }
  else if (isFinished()) {
    finished = true;
    end();
    _end();
  }
  else {
    execute();
    _execute();
  }


  return finished;
}

void Command::setTimeout(unsigned long timeout) {
  this->timeout = timeout;
}

unsigned long Command::getTime() {
  return Robot::getTime() - startTime;
}

bool Command::isTimedOut() {
  return getTime() > timeout;
}

bool Command::isRunning() {
  return running;
}

void Command::initialize() {}
void Command::_initialize() {
  running = true;
  startTime = Robot::getTime();
}

void Command::execute() {}
void Command::_execute() {}

bool Command::isFinished() {}

void Command::end() {}
void Command::_end() {
  running = false;
}

void Command::start() {
  Scheduler::getInstance()->addCommand(this);
}

bool Command::operator!=(const Command& other){
    return this->name != other.name;
}
