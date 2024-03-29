#ifndef STACK_H
#define STACK_H

#include <stddef.h>  /* size_t type */
#include <stdio.h>   /* printf etc. */
#include <stdlib.h>  /* malloc etc. */
#include <stdbool.h> /* bool type */
#include <string.h>
#include "common.h"

/* typename of list user functions */
typedef void* (*clone_t)(elem_t e);/* Clones the element */
typedef void (*destroy_t)(elem_t e); /* Returns 1 iff (*a)==(*b) */
typedef void (*print_t)(elem_t e); /* Print the element */

struct stack; /* Opaque pointer */


struct stack * stack_create(int max_size_of_stack,
                           clone_t clone,
                           destroy_t destroy,
                           print_t print);

int stack_destroy(struct stack * stack);

int stack_push(struct stack * stack, elem_t elem);

void stack_pop(struct stack * stack);

elem_t stack_peek(struct stack * stack);

int stack_size(struct stack * stack);

bool stack_is_empty(struct stack * stack);

int stack_capacity(struct stack * stack);

void stack_print(struct stack * stack);

#endif //STACK_H

