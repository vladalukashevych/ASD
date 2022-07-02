#include <stdio.h>
#include <math.h>

double factorial(int x)
{
    return(x < 2) ? 1 : x * factorial(x - 1);
}

int main()
{
    double   x, y, y1, y2, y3, y4, y5, a = 0, b = 50;

    printf("f(n) = n\tf(n) = log(n)\tf(n) = n*log(n)\tf(n) = n^2\tf(n) = 2^n\t\tf(n) = n!\n\n");
    for (x = 1; x <= b; x++)
    {
        y = x;
        printf("f(n) = %.2lf\t", y);
        y1 = log(x);
        printf("f(n) = %.2lf\t", y1);
        y2 = x * log(x);
        printf("f(n) = %.2lf\t", y2);
        y3 = pow(x, 2);
        printf("f(n) = %.2lf\t", y3);
        y4 = pow(2, x);
        printf("f(n) = %.2lf\t\t", y4);
        y5 = factorial(x);
        printf("f(n) = %.2lf\n", y5);
    }
    return  0;
}