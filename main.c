#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"
#include <time.h>

int main() {
    srand((unsigned int) time(0));
    Stack *s = CreateStack();

    for (int i = 0; i < 10; i++) {
        Push(s, rand() % 100);
    }
    for (int i = 0; i < 10; i++) {
        printf("%d : \n", i);
        printf("%d\n", Top(s));
        printf("%d\n", Pop(s));
    }


    return 0;
}