#pragma once
/** \brief
* drives past the intersection
*/
#include "Robot.h"
#include "Command.h"

class ScootPastIntersection : public Command {
  public:
    ScootPastIntersection();

    /** \brief
    * sets timeout 
    */
    void initialize();

    /** \brief
    * follows line forward
    */
    void execute();

    /** \returns true when timeout has occurred 
    */
    bool isFinished();

    /** \brief
    * does nothing 
    */
    void end();
  private:
    /** \brief time to line follow in ms */
    const int scootTime = 350;
};
