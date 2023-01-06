#include "file.h"




void fileOpen (stack_t *stack) {
	size_t *ptr = (size_t *) utilPop (stack) - 1;
	char name[16];
	for (size_t i = 0; *ptr && i < sizeof (name) / sizeof (*name); ptr--, i++)
		name[i] = *ptr;

/*	char name[16];
	for (size_t i = 0; utilPeek (stack) && stack->ptr > stack->data; i++)
		name[i] = utilPop (stack);
*/
	FILE *fptr = fopen (name, "a+");
	if (!fptr) perror (NULL);

	utilPush (stack, (size_t) fptr);
}




void fileClose (stack_t *stack) {
	fclose ((FILE *) utilPop (stack));
}




void fileRead (stack_t *stack) {
	FILE *fptr = (FILE *) utilPop (stack);
	utilPush (stack, fgetc (fptr));
	utilPush (stack, (size_t) fptr);
}




void fileWrite (stack_t *stack) {
	FILE *fptr = (FILE *) utilPop (stack);
	fputc (utilPop (stack), fptr);
	utilPush (stack, (size_t) fptr);
}
