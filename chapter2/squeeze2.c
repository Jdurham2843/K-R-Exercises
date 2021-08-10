#include <stdio.h>

#define TRUE  1
#define FALSE 0 

void squeeze2(char s[], char s1[]);
int inString(char c, char s[]);

int main(void) {
    char s[] = "hello world";
    char s2[] = "hi wanda";

    printf("original: %s\n", s);
    squeeze2(s, s2);
    printf("after: %s\n", s);

    return 0;
}

void squeeze2(char s[], char s1[]) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++) {
	if (!inString(s[i], s1)) {
	    s[j++] = s[i];
	}
    }
    s[j] = '\0';
}

int inString(char c, char s[]) {
    int i;

    for (i = 0; s[i] != '\0'; i++){
        if (s[i] == c) return TRUE;
    }
    return FALSE;
}
