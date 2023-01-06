#include "inst.h"




void instGet (stack_t *stack) {
	size_t *ptr = (size_t *) utilPop (stack);
	utilPush (stack, *--ptr);
	utilPush (stack, (size_t) ptr);
}
void instSet (stack_t *stack) {
	size_t *ptr = (size_t *) utilPop (stack);
	*ptr++ = utilPop (stack);
	utilPush (stack, (size_t) ptr);
}
void instDup (stack_t *stack) { 
	size_t *ptr = &*stack->ptr;
	utilPush (stack, *--ptr);
}
void instPop (stack_t *stack) { *--stack->ptr = 0; }
void instSwp (stack_t *stack) { 
	size_t tmp = *(stack->ptr - 1);
	*(stack->ptr - 1) = *(stack->ptr - 2);
	*(stack->ptr - 2) = tmp;
}




void instBase (stack_t *stack) { utilPush (stack, (size_t) stack->data); }
void instHere (stack_t *stack) { utilPush (stack, (size_t) stack->ptr); }
void instJump (stack_t *stack) { stack->ptr = (size_t *) utilPop (stack); }
void instName (stack_t *stack) {
	size_t acc = 0;
	for (size_t i = 1; utilPeek (stack); i++) {
		acc += utilPop (stack) * i;
	}
	instPop (stack);
	utilPush (stack, acc);
}




void instMathAdd (stack_t *stack) { utilPush (stack, utilPop (stack) + utilPop (stack)); }
void instMathSub (stack_t *stack) { size_t a = utilPop (stack); utilPush (stack, utilPop (stack) - a); }

void instMathMul (stack_t *stack) { utilPush (stack, utilPop (stack) * utilPop (stack)); }
void instMathDiv (stack_t *stack) { size_t a = utilPop (stack); utilPush (stack, utilPop (stack) / a); }

void instMathInc (stack_t *stack) { utilPush (stack, utilPop (stack) + sizeof(*stack->data)); }
void instMathDec (stack_t *stack) { utilPush (stack, utilPop (stack) - sizeof(*stack->data)); }
