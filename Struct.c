
#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"

Stack *CreateStack() {
    Stack *help = NULL;
    help = malloc(sizeof(Stack));
    if (help == NULL) {
        exit(OUT_OF_MEMORY);
    }
    help->len = STACK_ITEMS;
    help->elements = malloc(help->len * sizeof(Elem));
    if (help->elements == NULL) {
        free(help);
        exit(OUT_OF_MEMORY);
    }
    help->CurLen = 0;
    return help;
}

void Push(Stack *s, const int n) {
    if (s->CurLen >= s->len) {
        Refresh(s);
    }
    s->elements[s->CurLen] = n;
    s->CurLen++;
}

int Pop(Stack *s) {
    if (s->CurLen == 0)
        exit(STACK_UNDERFLOW);
    s->CurLen--;
    return (s->elements[s->CurLen]);
}

int Top(const Stack *s) {
    if (s->CurLen == 0)
        exit(STACK_UNDERFLOW);
    return (s->elements[s->CurLen - 1]);
}

_Bool IsStackEmpty(const Stack *s) {
    if (s->CurLen == 0)
        return 1;
    else
        return 0;
}

void DeleteStack(Stack **del) {
    free((*del)->elements);
    free(*del);
    *del = NULL;
}

void Refresh(Stack *s) {
    s->len *= CHANGE;
    s->elements = realloc(s->elements, s->len * sizeof(Elem));
    if (s->elements == NULL) {
        exit(OUT_OF_MEMORY);
    }
}