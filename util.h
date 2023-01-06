#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "type.h"




/* Standard stack push and pop operations
 * Not to be called directly as language instructions
 * Only to be used by the interpreter or compiler
 * or invoked by language instructions
 * */

void utilPush (stack_t *stack, size_t data);
size_t utilPeek (stack_t *stack);
size_t utilPop (stack_t *stack);


/* Output operation for POSIX compliant system
 * Writes out one character to standard output
 * Requires stdio to operate
 * Might be implemented differently on non POSIX systems
 * */

void utilOutput (stack_t *stack);




/* Input operation for POSIX compliant system
 * Grabs one character from standard input
 * Requires stdlib and stdio to operate
 * Might be implemented differently on non POSIX systems
 * */

void utilInput (stack_t *stack);




/* Print / help instruction
 * Requires the standard input output library to operate
 * Might be implemented differently on non POSIX systems
 * (see minimal implementation)
 * */

void utilPrint (stack_t *stack);




/* Opens (or creates) a file and reads it.
 * Implementation for UNIX like systems.
 * Needs a stack containing the file's name.
 * */

void utilFile (stack_t *stack);
void utilRead (stack_t *stack);
