/* Convert hexidecimal to decimal */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

static long convert(char* hexstring);
static int convertChar(char hexc);

int main(int argc, char** argv) {
    char* hexstring;
    long decimal;

    if (argc > 1) {
        hexstring = argv[1];
    } else {
	printf("There was a problem getting the command line argument.\n");
	exit(1);
    }

    decimal = convert(hexstring);

    printf("Hexidecimal: %s\nDecimal: %ld\n", hexstring, decimal);

    return 0;
}

static long convert(char* hexstring) {
    int i;
    char c;
    int realVal;
    int length = strlen(hexstring);
    long result = 0;

    /* strip 0x or OX */
    if (hexstring[0] == '0' && 
	(hexstring[1] == 'x' || hexstring[1] == 'X')) {
	i = 2;
    } else {
	i = 0;
    }

    for (; i < length; i++) {
	c = hexstring[i];
	realVal = convertChar(c);
	result += (realVal * pow(16, length-i-1));
    }

    return result;
}

static int convertChar(char hexc) {
    if (hexc >= '0' && hexc <= '9') {
	return hexc - '0';
    } else if (hexc >= 'A' && hexc <= 'F')  {
	return hexc - 'A' + 10;
    } else if (hexc >= 'a' && hexc <= 'f') {
        return hexc - 'a' + 10;
    } else {
	printf("%c is not a valid hexidecimal character.\n", hexc);
	exit(1);
    }
}
