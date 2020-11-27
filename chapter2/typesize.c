#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {
    unsigned char charMax;
    char sCharMin, sCharMax;
    unsigned short shortMax; 
    short sShortMin, sShortMax;
    unsigned int intMax; 
    int sIntMin, sIntMax;
    unsigned long longMax; 
    long sLongMin, sLongMax; 

    /* from limit.h */
    printf("--- From limits.h ---\n");
    printf("unsigned char range: %d to %d\n", 0, UCHAR_MAX);
    printf("signed char range: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned short range: %d to %d\n", 0, USHRT_MAX);
    printf("signed short range: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned int range: %d to %u\n", 0, UINT_MAX);
    printf("signed int range: %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned long range: %d to %lu\n", 0, ULONG_MAX);
    printf("signed long range: %ld to %ld\n", LONG_MIN, LONG_MAX);

    /* computed */

    printf("--- Computed values ---\n");
    charMax = (unsigned char) (pow(2, sizeof(char) * 8) - 1);
    sCharMax = (charMax / 2);
    sCharMin = 0 - (sCharMax) - 1;
    printf("computed unsigned char range: %d to %d\n", 0, charMax);
    printf("computed signed char range: %d to %d\n", sCharMin, sCharMax);

    shortMax = (unsigned short) (pow(2, sizeof(short) * 8) - 1);
    sShortMax = (shortMax / 2);
    sShortMin = 0 - (sShortMax) - 1;
    printf("computed unsigned short range: %d to %d\n", 0, shortMax);
    printf("computed signed short range: %d to %d\n", sShortMin, sShortMax);


    intMax = (unsigned int) (pow(2, sizeof(int) * 8) - 1);
    sIntMax = (intMax / 2);
    sIntMin = 0 - (sIntMax) - 1;
    printf("computed unsigned int range: %d to %u\n", 0, intMax);
    printf("computed signed int range: %d to %d\n", sIntMin, sIntMax);


    longMax = (unsigned long) (pow(2, sizeof(long) * 8) - 1);
    sLongMax = (longMax / 2);
    sLongMin = 0 - (sLongMax) - 1;
    printf("computed unsigned long range: %d to %lu\n", 0, longMax);
    printf("computed signed long range: %ld to %ld\n", sLongMin, sLongMax); 

    return 0;
}