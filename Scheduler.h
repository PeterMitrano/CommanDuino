#pragma once
/** \brief is the master of all commands.
 * It knows executes the inialize, execute, and end functions
 * of each commands.
 * Scheduler is also a singleton, so the constructor is private
 * and there's only one instance.
 */

#include "LinkedList.h"
#include "Command.h"

class Scheduler {
  public:

    /** \brief returns pointer to the singleton of scheduler
     * \return pointer to singleton
     */
    static Scheduler *getInstance();

    /** \brief adds a command to the command group
     * \param[_in] command the pointer
     */
    void addCommand(Command *command);

    /** \brief runs all the commands.
     * Iterates through the list of commands and runs them.
     * If they are done, it removes them from the list of commands.
     */
    void run();

  private:

    /** \brief singleton accessor */
    Scheduler();

    /** \brief singleton instance */
    static Scheduler *instance;

    /** \brief list of commands */
    LinkedList<Command *> commands;
};
