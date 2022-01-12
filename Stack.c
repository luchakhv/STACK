#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_MAX_ITEMS 50
typedef int Elem;
typedef struct stack {
    Elem elements[STACK_MAX_ITEMS];
    Elem len;
} Stack;

void Push(Stack *s, int n);

int Pop(Stack *s);

int Top(const Stack *s);

_Bool IsStackEmpty(const Stack *s);

int main() {
    srand((unsigned int) time(0));
    Stack s;
    s.len = 0;//initialising stack
    for (int i = 0; i < 10; i++) {
        Push(&s, rand() % 100);
    }
    for (int i = 0; i < 10; i++) {
        printf("%d : \n", i);
        printf("%d\n", Top(&s));
        printf("%d\n", Pop(&s));
    }


    return 0;
}

void Push(Stack *s, const int n) {
    if (s->len >= STACK_MAX_ITEMS)
        exit(EXIT_FAILURE);
    s->elements[s->len] = n;
    s->len++;
}

int Pop(Stack *s) {
    if (s->len == 0)
        exit(EXIT_FAILURE);
    s->len--;
    return (s->elements[s->len]);
}

int Top(const Stack *s) {
    if (s->len == 0)
        exit(EXIT_FAILURE);
    return (s->elements[s->len - 1]);
}

_Bool IsStackEmpty(const Stack *s) {
    if (s->len == 0)
        return 1;
    else
        return 0;
}
