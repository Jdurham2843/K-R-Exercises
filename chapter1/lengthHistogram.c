#include <stdio.h>


int main() {
    int cc, c, i, j;

    while((c = getchar()) != EOF && c != 'Q') {
        if (c == '\n' || c == ' ' || c == '\t') {
            for (j = 0; j < cc; ++j) {
                printf("=");
            }
            c = 0;
            cc = 0;
            printf("\n");
        } else {
            printf("%c", c);
            ++cc;
        }
    }

    return 0;
}

/* print histogram for the length of words */
