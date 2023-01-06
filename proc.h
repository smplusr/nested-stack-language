#include <unistd.h>

#include "type.h"
#include "util.h"




/* Executes a sub process.
 * Needs an argv UNIX char table in order to operate.
 * Requires the unistd library.
 * */

void procExec (stack_t *stack);
