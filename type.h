#pragma once

#include <stddef.h>




#define STACK_SIZE 65536
#define INIT_STACK(S) stack_t S = {&*S.data, {}}


typedef struct stack_t {
	size_t *ptr;
	size_t data[STACK_SIZE];
} stack_t;

typedef struct lookup_t {
	unsigned char key;
	void (*ptr) (stack_t *stack);
} lookup_t;
