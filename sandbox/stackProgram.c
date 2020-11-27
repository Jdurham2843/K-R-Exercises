#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "hello.h"

int main(int argc, char** argv) {
    Stack* stack;
    int i;
    const int size = 100;
    int number;

    stack = newStack();

    for (i = 0; i < size; ++i) {
        push(stack, i);
    }

    push(stack, 1001);
    number = pop(stack);

    printf("Popped %d\n", number);

    printStack(stack);
    /*freeStack(stack); */

    helloWorld();

    return 0;
}