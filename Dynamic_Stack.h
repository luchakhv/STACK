enum ERRORS {
 STACK_OVERFLOW =404,
 STACK_UNDERFLOW= 401,
 OUT_OF_MEMORY= 407
};

enum VARIABLES
{
    MULTIPLIER = 2,
    STACK_INITIALISE =4,
    ARR_INCREASE = 7,
    ARR_REDUCE = 9
};

#ifndef STRUCTURES_STRUCT_H
#define STRUCTURES_STRUCT_H

#endif //STRUCTURES_STRUCT_H



typedef int Elem;
typedef struct stack {
    Elem *elements;
    Elem len;
    Elem CurLen;
} Stack;

Stack *CreateStack();

int Resize(Stack *s, int flag);

int DeleteStack(Stack **s);

int Push(Stack *s, int n);

int Pop(Stack *s);

int Peek(const Stack *s);

int IsStackEmpty(const Stack *s);

int ERROR(int n);
