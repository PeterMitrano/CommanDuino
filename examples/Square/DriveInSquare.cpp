#include "DriveInSquare.h"

#include "DriveForward.h"
#include "TurnLeft.h"

DriveInSquare::DriveInSquare() : 
CommandGroup("drive in square") {
  for (int i=0;i<4;i++){
    addSequential(new DriveForward());
    addSequential(new TurnLeft());
  }
}

