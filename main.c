#include <stdio.h>

#include "type.h"
#include "inst.h"
#include "lang.h"




int main (int argc, char *argv[]) {
	INIT_STACK(stack);


	if (*(argv + 1)) {
	/*	char *rom;
		for (rom = *(argv + 1); *rom; rom++);
		for (; rom >= *(argv + 1); rom--) {*/
		for (char *rom = *(argv + 1); *rom; rom++) {
			utilPush (&stack, *rom);
			langEval (&stack);
		}
	}

	/*
	utilPush (&stack, 0);
	instHere (&stack);
	instMathDec (&stack);

	size_t romptr = utilPeek (&stack);
	for (; stack.ptr >= stack.data; ) {
		langCall (&stack);
		utilPush(&stack, romptr);
	}
	*/


	for (; stack.ptr >= stack.data; ) {
		utilInput (&stack);
		langEval (&stack);
	}
}
