#include <Servo.h> //dummy include because arduino IDE is shit
#include <Encoder.h>
#include <BluetoothMaster.h>
#include <ReactorProtocol.h>
#include <TimerOne.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <TimerThree.h>
#include <MemoryFree.h>

#include "Robot.h"
#include "Scheduler.h"
#include "GetDemRods.h"

#include "Docs.h"

Robot *steve;
volatile bool paused = true;
const int panicPin = 24;

void setup() {
  Serial.begin(9600);

  pinMode(panicPin,INPUT_PULLUP);

  steve = Robot::getInstance();
  steve->setup();

  steve->debugPrint("setup");

  // here we start the parent commands which should run throughout the life of the program
  GetDemRods *cmd = new GetDemRods();
  cmd->start();
}


void loop() {
  if (!digitalRead(panicPin)){
    paused = !paused;
  }
  steve->btClient.readMessage();
  steve->btClient.sendHeartbeat();

  if (!paused){

    // Scheduler is in charge of running all the commands, so it must always be called
     Scheduler::getInstance()->run();

    // we also a few special functions, like cache and controlArm, which must run continuously, outside of all commands
    // while these could be done with commands, it's easier to just functions
    steve->playSong();
    steve->lineSensor.cache();
    steve->blinkLEDs();
    steve->arm.control();
    steve->resetTimerFlags();
    char str[17];
    snprintf(str,17,"I'm at (%i,%i)",steve->row, steve->col);
    steve->debugPrint(str);
  }
  else {
    steve->stopDriving();
  }
}
