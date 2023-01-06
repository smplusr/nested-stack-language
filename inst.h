#pragma once

#include <stdio.h>

#include "type.h"
#include "util.h"




/* Simple operations for manipulating data from and to stacks
 * */

void instGet (stack_t *stack);
void instSet (stack_t *stack);
void instDup (stack_t *stack);
void instPop (stack_t *stack);
void instSwp (stack_t *stack);




/* Stack pointer manipulation
 * Allows pointer arithmetics and manipulating multiple stacks
 * Required for the language to be Turing complete, Turing equivalent
 * Manipulating stacks inside of the language qualifies it of Nested Stack Automaton (NSA)
 * */

void instBase (stack_t *stack);
void instHere (stack_t *stack);
void instJump (stack_t *stack);
void instName (stack_t *stack);




/* Arithmetics operations
 * Carried out using postfix notation
 * Example:
 * prefix	infix		postfix
 * (+ 2 2)	(2 + 2)		(2 2 +)
 * */

void instMathAdd (stack_t *stack);
void instMathSub (stack_t *stack);
void instMathMul (stack_t *stack);
void instMathDiv (stack_t *stack);
void instMathInc (stack_t *stack);
void instMathDec (stack_t *stack);
