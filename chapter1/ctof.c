#include <stdio.h>

int main() {
    float fahr, celcius;
    int start, limit, step;

    start = celcius = 0;
    limit = 300;
    step = 20;

    printf("----- Fahrenheit to Celcius -------\n");
    while(celcius <= limit) {
        fahr = ((9.0/5.0) * celcius) + 32.0;
        printf("%6.1f\t%3.0f\n", celcius, fahr);
        celcius = celcius + step;
    }

    return 0;
}
