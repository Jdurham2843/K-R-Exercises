#include <stdio.h>

#define MAXLINE 1000

int getlinee(char line[], int limit);
void reverse(char line[], int length);
void clear(char line[], int length);

int main() {
    int len;
    char line[MAXLINE];

    len = getlinee(line, MAXLINE);

    while((len = getlinee(line, MAXLINE)) > 0) {
        printf("Original(length = %d): %s", len, line);
        reverse(line, len);
        printf("Reversed: %s\n", line);
        clear(line, len);
    }

    return 0;
}

int getlinee(char line[], int limit) {
    int c, i;

    for(i = 0; ((c = getchar()) != EOF) && c != '\n' && c != '\r'; ++i) {
        if (i < limit - 1) {
            line[i] = c;
        }
    }

    if (c == '\n' || c != '\r') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void reverse(char line[], int length) {
    int offset, start, end;
    char temp;

    start = 0;
    end = length - 2;
    while(start < end) {
        temp = line[start];
        line[start] = line[end];
        line[end] = temp;

        start++;
        end--;
    }
}

void clear(char line[], int length) {
    int i;

    for (i = 0; i < length; ++i) {
        line[i] = 0;
    }
}

