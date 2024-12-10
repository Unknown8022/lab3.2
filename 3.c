#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#define PUT_DELIM(x, h, b) (((x) + (h)) > (b) ? '\n' : '\t')
#define PUT_DELIM1(y, h1, d) (((y) + (h1)) > (d) ? '\n' : '\t')
#define FUNC(x, y) ((x != y) ? sqrt((x) * ((y) + 1)) / ((x) - (y)) :NAN)
#define TABULATE(msg, a, b, h, a1, d, h1)                   \
    printf("%s\n", msg);                                    \
    for (x = (a); x <= (b); x += (h)) {                     \
        for (y = (a1); y <= (d); y += (h1)) {               \
            printf("x = %6.2f, y = %6.2f, FUNC = %6.2f%c",  \
                   x, y, FUNC(x, y), PUT_DELIM1(y, h1, d)); \
        }                                                   \
        printf("%c", PUT_DELIM(x, h, b));                   \
    }
int main() {
    double a = -3.0, b = 3.0, h = 0.25, x;
    double a1 = 1.0, d = 2.0, h1 = 0.15, y;
    double min = INFINITY, max = -INFINITY, value;
    TABULATE("x, y:", a, b, h, a1, d, h1);
    for (x = a; x <= b; x += h) {
        for (y = a1; y <= d; y += h1) {
            if (x != y) {
                value = FUNC(x, y);
                if (value < min) min = value;
                if (value > max) max = value;
            }
        }
    }
    if (min == INFINITY || max == -INFINITY) {
        printf("\nНемає коректних значень функції у заданій області.\n");
    }
    else {
        printf("\nmin: %10.5f\n", min);
        printf("max: %10.5f\n", max);
    }
    return 0;
}