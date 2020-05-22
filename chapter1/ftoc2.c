#include <stdio.h>

float fahrenheitToCelcius(float fahr);

int main() {
	float fahr, celcius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("----- Fahrenheit to Celcius -------\n");
	fahr = lower;
	while (fahr <= upper) {
		celcius = fahrenheitToCelcius(fahr);
		printf("%3.0f\t%6.1f\n", fahr, celcius);
		fahr = fahr + step;
	}

	return 0;
}

float fahrenheitToCelcius(float fahr) {
    return (5.0/9.0) * (fahr - 32);
}
