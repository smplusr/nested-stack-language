#include "lang.h"




lookup_t inst_lookup[] = {
	{'>', instGet},
	{'<', instSet},
	{'$', instDup},
	{0x7f, instPop},
//	{'%', instSwp},

	{'#', instBase},
//	{'@', instHere},
	{'\t', instJump},
	{'&', instName},

	{'+', instMathAdd},
	{'-', instMathSub},
	{'*', instMathMul},
	{'/', instMathDiv},
	{'`', instMathInc},
	{'`', instMathDec},

	{'?', utilPrint},

	{';', utilInput},
	{',', utilOutput},

	{'@', fileOpen},
	{')', fileRead},
	{'(', fileWrite},

	{'E', procExec},

	{'\r', langCall},
	{'!', langEval},
};




void langEval (stack_t *stack) {
	size_t *data = stack->ptr;
	char key = (char) *--data;

	for (lookup_t *lookup = inst_lookup; lookup->key; lookup++)
		if (key == lookup->key) {
			*--stack->ptr = 0;
			lookup->ptr (stack);
		}
}




void langCall (stack_t *stack) {
	size_t ptr = utilPeek (stack);
start:	for (; utilPeek (stack); ) {
		instGet (stack);
		size_t tmp = utilPop (stack);
		switch (utilPeek (stack)) {
			case 0:
				utilPop (stack);
				return;
			case '%':
				utilPop (stack);
				utilPush (stack, ptr);
				goto start;
			default:
				langEval (stack);
				if (!utilPeek (stack)) {
					instPop (stack);
					return;
				}
				break;
		}
		utilPush (stack, tmp);
	}
}
