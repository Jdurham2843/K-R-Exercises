#include <stdio.h>

#define MAXLINE 1000
#define TAB_LENGTH 4

int getlinee(char line[], int limit);

int main() {
    int len;
    char line[MAXLINE];

    len = getlinee(line, MAXLINE);
    printf("Original (length = %d): %s", len, line);

    return 0;
}

int getlinee(char line[], int limit) {
    int c, i, j;

    for (i = 0; ((c = getchar()) != EOF) && c != '\n'; ++i) {
        if (c == '\t') {
            for (j = 0; j < TAB_LENGTH; ++j) {
                if (i < limit - 1) {
                    line[i] = 'd';
                    ++i;
                }
            }
        } else {
            if (i < limit - 1) {
                line[i] = c;
            }
        }
    }

    if (c == '\n' || c == '\r') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
