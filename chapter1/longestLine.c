#include <stdio.h>

#define MAXLINE 1000

int getlinee(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len;               /* current line length */
    int max;               /* maxium length seen so far */
    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while((len = getlinee(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("%s", longest);
    }
    return 0;
}

int getlinee(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        /* Adding this if to have a termination case. This isn't present in the book. */
        if (c == 'Q') { 
            return -1;
        }
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0') {
        ++i;
    }
}
