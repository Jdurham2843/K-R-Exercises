#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);

int main(char** args) {
    int len;
    char line[MAXLINE];

    len = getline(line, MAXLINE);
    printf("%s\n", line);

    return 0;
}

int getline(char line[], int maxline) {
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n' && c != '\r'; ++i) {
        line[i] = c;
    }

    ++i;
    line[i] = '\0';
    return i;
}