#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include <time.h>
#include <random>


int main()
{
    unsigned int array[40000], counter[250] = { 0 }, a = 22695477, c = 1;
    unsigned long long m = pow(2, 32);
    double statProb[250] = { 0 }, arr4[250] = { 0 }, M = 0, D = 0;

    array[0] = time(0);

    for (int i = 1; i < 40000; i++)
    {
        array[i] = (a * array[i - 1] + c) % m;
        array[i - 1] %= 250;
        counter[array[i - 1]]++;
    }
    array[39999] %= 250;

    for (int i = 0; i < 40000; i++)
    {
        printf("%d\n", array[i]);
    }

    printf("\tNumber count");
    for (int i = 0; i < 250; i++)
    {
        printf("\n %d - %d", i, counter[i]);
    }

    printf("\n\t Statistical probability");
    for (int i = 0; i < 250; i++)
    {
        statProb[i] = counter[i] / 40000.0;
        M += statProb[i] * i;
        printf("\n %d - %f", i, statProb[i]);
    }
    printf("\n Expected value = %f", M);

    for (int i = 0; i < 250; i++)
    {
        D += pow((i - M), 2) * statProb[i];
    }
    printf("\n Dispersion = %f", D);
    printf("\n Standard deviation = %f", pow(D, 1 / 2.));

    return 0;
}