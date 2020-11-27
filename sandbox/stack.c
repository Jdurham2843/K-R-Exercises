#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* newStack() {
    Stack* stack = (Stack*) malloc(sizeof (Stack));
    stack->top = 0;
    stack->size = 0;
    return stack;
}

void printFrame(Frame* frame) {
    printf("Frame#%p { i: %d }\n", frame, frame->i);
}

void printStack(Stack* stack) {
    Frame* current;
    int i;

    printf("Printing stack ----\n");
    current = stack->top;

    for (i = 0; i < stack->size; ++i) {
        printFrame(current);
        current = current->next;
    }
}

void freeStack(Stack* stack) {
    Frame* next = stack->top->next;
    free(stack->top);
    while(next != NULL) {
        Frame* temp = next;
        next = next->next;
        free(temp);
    }

    free(stack);
}

void push(Stack* stack, int number) {
    Frame* newTop = (Frame*) malloc(sizeof (Frame));
    newTop->i = number;
    if (stack->top != NULL) {
        newTop->next = stack->top;
    }

    stack->top = newTop;
    stack->size += 1;
}

int pop(Stack* stack) {
    int retVal;

    if (stack->top == NULL) {
        retVal = -1;
    } else {
        Frame* top = stack->top;
        retVal = top->i;
        stack->top = top->next;
        stack->size -= 1;
        free(top);
    }

    return retVal;
}