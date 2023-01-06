#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "type.h"
#include "util.h"




/* Opens a file and puts its pointer onto the stack.
 * Needs the file's name.
 * WARNING : It is impossible to differenciate a
 * file pointer and a stack pointer.
 * */

void fileOpen (stack_t *stack);




/* Closes the file associated with the pointer
 * given as parameter.
 * */

void fileClose (stack_t *stack);




/* Reads a single character / value from a file.
 * The file needs to be specified as a pointer,
 * thus fileOpen needs to be invoked beforehand.
 * */

void fileRead (stack_t *stack);




/* Writes a single character / value from a file.
 * The file needs to be specified as a pointer,
 * thus fileOpen needs to be invoked beforehand.
 * */

void fileWrite (stack_t *stack);
