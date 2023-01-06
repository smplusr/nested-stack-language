#include "util.h"




void utilPush (stack_t *stack, size_t data) { *stack->ptr++ = data; }
size_t utilPeek (stack_t *stack) { return *(stack->ptr - 1); }
size_t utilPop (stack_t *stack) { 
	size_t data = *--stack->ptr;
	*stack->ptr = 0;
	return data;
}




void utilOutput (stack_t *stack) { putc (utilPop (stack), stdout); }
void utilInput (stack_t *stack) {
	system ("/bin/stty raw");
	utilPush (stack, getc (stdin));
	system ("/bin/stty cooked");
}




void utilPrint (stack_t *stack) {
	printf ("\n+----------+----------+---+\n");
	for (size_t *ptr = stack->ptr - 1; *ptr && ptr >= stack->data; ptr--) {
		printf ("| %8x | %8x | %c |", (unsigned int) (size_t) ptr, (unsigned int) *ptr, (int) *ptr);
		printf ("\n+----------+----------+---+\n");	
	}
}
