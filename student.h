#ifndef STUDENT_H
#define STUDENT_H

#include <stddef.h>  /* size_t type */
#include <stdio.h>   /* printf etc. */
#include <stdlib.h>  /* malloc etc. */
#include <stdbool.h> /* bool type */

#include "stack.h"

struct student; /* Opaque pointer */

void *student_clone(void *elem);
void student_destroy(void *elem);
void student_print(void *elem);




#endif //STUDENT_H
