#include <stdio.h>
#include <stdlib.h>
#include "Dynamic_Stack.h"
#include <time.h>

int main() {
    srand((unsigned int) time(0));

    Stack *s = CreateStack();
    DeleteStack(&s);
    puts("hello world");
    s = CreateStack();
    for (int i = 0; i < 10; i++) {
        Push(s, rand() % 100);
    }
    for (int i = 0; i < 10; i++) {
        printf("%d : \n", i);
        printf("%d\n", Peek(s));
        printf("%d\n", Pop(s));
    }
    DeleteStack(&s);
    puts("hello world");
    return 0;
}
