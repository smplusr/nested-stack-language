#include "proc.h"



/*void procExec (stack_t *stack) {

	char argv[16][16] = {};
	size_t i;

	for (i = -1; stack->ptr >= stack->data; i++) {
		size_t *ptr = (size_t *) utilPop (stack) - 1;
		if (!ptr) break;

		for (size_t j = 0; *ptr; j++, ptr--) {
			 argv[i][j] = *ptr;
		}
	}
	
	for (size_t j = 0; *argv[j]; j++)
		printf ("argv[%i] = %s\n", (int) j, argv[--i]);


}*/


void procExec (stack_t *stack) {

	size_t *ptr = stack->ptr;
	for (size_t i = 0; stack->ptr > stack->data && *ptr; ptr--);

	printf ("Low pointer : 0x%x\n", ptr);

}
