#include <stdio.h>

int main() {
    int c;

    c = getchar() != EOF;

    printf("c is %d\n", c);

    printf("printing EOF: %d\n", EOF);
    return 0;
}
