#pragma once

#include "type.h"
#include "inst.h"
#include "util.h"
#include "file.h"
#include "proc.h"




/* Declaration of the main instruction lookup table
 * Defined in corresponding translation unit
 * */

extern lookup_t inst_lookup[];




/* Evaluation functions
 * Tests the top value of the stack and
 * runs the corresponding instruction
 * Returning when no instruction has been found 
 * (char is not a key)
 * THIS OPERATION SHOULD NOT BE DESTRUCTIVE
 * */

void langEval (stack_t *stack);




/* language internal loop and parser
 * Runs the evaluation function for each character in given stack
 * Skips (does not push back) non-key characters
 * Returns when hitting NULL (en of the stack)
 * */

void langCall (stack_t *stack);
