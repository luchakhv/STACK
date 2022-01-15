#include <stdio.h>
#include <stdlib.h>
#include "Dynamic_Stack.h"

Stack *CreateStack() {
    Stack *help = NULL;
    help = malloc(sizeof(Stack));
    if (help == NULL) {
        ERROR(OUT_OF_MEMORY);
        return NULL;
    }
    help->len = STACK_MAX_ELEMENTS;
    help->elements = calloc(help->len, sizeof(Elem));
    if (help->elements == NULL) {
        free(help);
        ERROR(OUT_OF_MEMORY);
        return NULL;
    }
    help->CurLen = 0;
    return help;
}

int DeleteStack(Stack **s) {
    if (s == NULL || s->elements == NULL || (*s) == NULL || (*s)->elements == NULL) {
        ERROR(OUT_OF_MEMORY);
        return OUT_OF_MEMORY;
    }
    free((*s)->elements);
    free(*s);
    *s = NULL;
    return 0;
}

int Push(Stack *s, const int n) {
    if (s == NULL || s->elements == NULL) {
        ERROR(OUT_OF_MEMORY);
        return OUT_OF_MEMORY;
    }
    if (s->CurLen >= s->len) {
        Resize(s, ARR_INCREASE);
    }
    s->elements[s->CurLen] = n;
    s->CurLen++;
    return 0;
}

int Pop(Stack *s) {
    if (s == NULL || s->elements == NULL) {
        ERROR(OUT_OF_MEMORY);
        return OUT_OF_MEMORY;
    }
    if (s->CurLen == 0) {
        ERROR(STACK_UNDERFLOW);
        return STACK_UNDERFLOW;
    }
    s->CurLen--;
    if (s->CurLen < (s->len / MULTIPLIER)) {
        Resize(s, ARR_REDUCE);
    }
    return (s->elements[s->CurLen]);
}

int Peek(const Stack *s) {
    if (s == NULL || s->elements == NULL) {
        ERROR(OUT_OF_MEMORY);
        return OUT_OF_MEMORY;
    }
    if (s->CurLen == 0) {
        ERROR(STACK_UNDERFLOW);
        return STACK_UNDERFLOW;
    }
    return (s->elements[s->CurLen - 1]);
}

int IsStackEmpty(const Stack *s) {
    if (s == NULL || s->elements == NULL) {
        ERROR(OUT_OF_MEMORY);
        return OUT_OF_MEMORY;
    }
    if (s->CurLen == 0)
        return 1;
    else
        return 0;
}


int Resize(Stack *s, int flag) {
    if (s == NULL || s->elements == NULL) {
        ERROR(OUT_OF_MEMORY);
        return OUT_OF_MEMORY;
    }

    switch (flag) {
        case (ARR_INCREASE):
            s->len *= MULTIPLIER;
            s->elements = realloc(s->elements, s->len * sizeof(Elem));
            if (s->elements == NULL) {
                ERROR(OUT_OF_MEMORY);
                return OUT_OF_MEMORY;
            }
            break;
        case (ARR_REDUCE):
            s->len = s->len / MULTIPLIER;
            s->elements = realloc(s->elements, s->len * sizeof(Elem));
            if (s->elements == NULL) {
                ERROR(OUT_OF_MEMORY);
                return OUT_OF_MEMORY;
            }
            break;
    }

    return 0;
}

int ERROR(int err) {

    switch (err) {
        case STACK_OVERFLOW:
            printf("Stack Overflow\n");
            break;
        case STACK_UNDERFLOW:
            printf("Stack Underflow\n");
            break;
        case OUT_OF_MEMORY:
            printf("Out of memory\n");
            break;
        default:
            printf("Unexpected error\n");
            break;
    }
    return 0;
}
