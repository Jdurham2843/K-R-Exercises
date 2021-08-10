#include <stdio.h>

#define FALSE 0
#define TRUE  1

int firstOccurence(char* s1, char* s2);
int inString(char c, char* s);

int main(int argc, char** argv) {
  if (argc < 3) {
    printf("Please enter two strings.\n"); 
    return -1;
  }

  char* s1 = argv[1];
  char* s2 = argv[2];

  int pos = firstOccurence(s1, s2);

  if (pos > -1) {
    printf("%c appeared at position %d\n", s1[pos], pos);
  } else {
    printf("No characters in common.\n");
  }

  return 0;
}

int firstOccurence(char* s1, char* s2) {
  int i;

  for (i = 0; s1[i] != '\0'; i++) {
    if (inString(s1[i], s2)) return i;
  }
  
  return -1;
}

int inString(char c, char* s) {
  int i;

  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == c) return TRUE;
  }

  return FALSE;
}
