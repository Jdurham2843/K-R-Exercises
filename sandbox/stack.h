typedef struct Frame {
    int i;
    struct Frame* next;
} Frame;

typedef struct Stack {
    struct Frame* top;
    int size;
} Stack;

Stack* newStack();

void printFrame(Frame* frame);

void printStack(Stack* stack);

void freeStack(Stack* stack);

void push(Stack* stack, int number);

int pop(Stack* stack);
