#include <stdio.h>

/* print kelvin, celcius, fahreheit table*/
int main()
{
    float kelvin, celcius, fahreheit;
    int lower, upper, step;

    lower = 0;
    upper = 500;
    step = 20;

    printf("%s\t%s\t%s\n", "K", "C", "F");

    kelvin = lower;
    while(kelvin <= upper) {
        celcius = kelvin - 273.15;
        fahreheit = celcius * 9.0 / 5.0 + 32.0;
        printf("%7.2f\t%7.2f\t%7.2f\n", kelvin, celcius, fahreheit);
        kelvin = kelvin + step;
    }

    return 0;
}
