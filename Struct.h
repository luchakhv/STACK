//
// Created by luchk on 12.01.2022.
//
#define CHANGE 2
#define STACK_ITEMS 4
#define STACK_OVERFLOW 404
#define STACK_UNDERFLOW 401
#define OUT_OF_MEMORY 407

#ifndef STRUCTURES_STRUCT_H
#define STRUCTURES_STRUCT_H

#endif //STRUCTURES_STRUCT_H

#define CHANGE 2
#define STACK_ITEMS 4
#define STACK_OVERFLOW 404
#define STACK_UNDERFLOW 401
#define OUT_OF_MEMORY 407

typedef int Elem;
typedef struct stack {
    Elem *elements;
    Elem len;
    Elem CurLen;
} Stack;

Stack *CreateStack();

void Refresh(Stack *s);

void DeleteStack(Stack **del);

void Push(Stack *s, int n);

int Pop(Stack *s);

int Top(const Stack *s);

_Bool IsStackEmpty(const Stack *s);
