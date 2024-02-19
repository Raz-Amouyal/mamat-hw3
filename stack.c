#include "stack.h"

#define EMPTY 0

struct stack {
    struct node *head;
    struct node *tail;
    int max_size;
    int size;
    clone_t clone;
    destroy_t destroy;
    print_t print;
};

struct node {
    struct node *prev;
    struct node *next;
    void *element;
};



struct stack * stack_creat(int max_size_of_stack,
                  clone_t clone,
                  destroy_t destroy,
                  print_t print){
    struct stack * stack;
    stack = (struct stack *)malloc(sizeof(*stack));
    if(!stack){
        return NULL;
    }
    stack->head = NULL;
    stack->tail = NULL;
    stack->max_size = max_size_of_stack;
    stack->size = EMPTY;
    stack->clone = clone;
    stack->destroy = destroy;
    stack->print = print;
    return stack;
}

int stack_destroy(struct stack * stack){
    if(!stack){
        return FAIL;
    }

    struct node *cursor;
    struct node *tmp;

    cursor = stack->head;
    while (cursor){
        tmp = cursor;
        cursor = cursor->next;
        stack->destroy(tmp->element);
        free(tmp);
    }

    free(stack);
    if(!stack){ /*need to check this*/
        return SUCCESS;
    }
    return FAIL;
}

int stack_push(struct stack * stack, elem_t elem){
    if (!stack || !elem || stack->size >= stack->max_size) {
        return FAIL;
    }
    struct node * new_node;
    void *clone;

    new_node = (struct node *)malloc(sizeof(*new_node));
    clone = stack->clone(elem);
    if (!new_node || !clone){
        /* Error - No memory */
        free(new_node);
        free(clone);
        return FAIL;
    }
    new_node->next = stack->head;
    new_node->prev = NULL;
    new_node->element = clone;

    if (stack->head) {
        stack->head->prev = new_node;
    }
    stack->head = new_node;
    if (!stack->tail) {
        stack->tail = new_node;
    }
    stack->size++;
    return SUCCESS;
}
void stack_pop(struct stack * stack){
    if(!stack->size){
        return;
    }
    struct node * node = stack->head;
    stack->head = stack->head->next; /* Update head */
    stack->head->prev = NULL;
    free(node);
    stack->size--;
}

void* stack_peek(struct stack * stack){
    if (!stack->head){
        return NULL;
    }
    return stack->head;
}
int stack_size(struct stack * stack){
    if(!stack){
        return 0;
    }
    return stack->size;
}
bool stack_is_empty(struct stack * stack){
    if(!stack){
        return false;
    }
    return (stack->size) ? false : true;
}

int stack_capacity(struct stack * stack){
    if(!stack){
        return 0;
    }
    int capacity = stack->max_size - stack->size;
    return capacity;
}

void stack_print(struct stack * stack){
    struct node *cursor;
    cursor = stack->head;
    while (cursor){
        stack->print(cursor->element);
        cursor = cursor->next;
    }
}


