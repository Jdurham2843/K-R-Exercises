#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *str;

	str = malloc(15);
	strcpy(str, "tutorialspoint");
	printf("String = %s, Address = %p\n", str, str);

	str = realloc(str, 25);
	strcat(str, ".com");
	printf("String = %s, Address = %p\n", str, str);

	free(str);

	return 0;
}
