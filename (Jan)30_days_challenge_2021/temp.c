#include <stdio.h>
#include <math.h>
int main() {
    double d;
    scanf("%lf", &d);

    long long x = d;
    printf("Number without decimal: %ld\n", x);
    int digits = (int)log10(x) + 1;

    printf("Number of digits before decimal: %d\n", digits);

    int v = 4 + digits;
    printf("Number of significant digits to consider: %d\n", v);
    printf("%.*g\n", v, d);
    return 0;
}