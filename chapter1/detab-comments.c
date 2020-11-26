#include <stdio.h>

#define MAXLINE 1000
#define TAB_LENGTH 4

int getlinee(char line[], int limit);

/* my comments */
int main() {
    int len;
    char line[MAXLINE];

    while((len = getlinee(line, MAXLINE)) > 0) {
        printf("Original (length = %d): %s", len, line);
    }

    return 0;
}

/*
int getlinee(char line[], int limit) {
    int c, i, j;

    for (i = 0; ((c = getchar()) != EOF) && c != '\n' && c != '\r'; ++i) {
        if (c == '\t') {
            for (j = 0; j < TAB_LENGTH; ++j) {
                if (i < limit - 1) {
                    line[i + j] = ' ';
                }
            }
            i += TAB_LENGTH - 1;
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
}*/