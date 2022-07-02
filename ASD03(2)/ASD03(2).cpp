#include <stdio.h>
#include <math.h>
#include <chrono>
#define GETTIME std::chrono::steady_clock::now
#define CALCTIME std::chrono::duration_cast<std::chrono::nanoseconds>

int fibonacci(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    printf("Enter n (<=40): ");
    int n;
    scanf_s("%d", &n);
    auto begin = GETTIME();
    for (int j = 0; j < n; j++)
    {
        printf("%d ", fibonacci(j));
    }
    auto end = GETTIME();
    auto elapsed_ns = CALCTIME(end - begin);
    printf("\nTime: %lld ns\n", elapsed_ns.count());

    /*for (int j = 0; j <= 40; j+=2)
    {
        auto begin = GETTIME();
        for (int i = 0; i <= j; i++)
        {
            printf("%d ", fibonacci(i));
        }
        auto end = GETTIME();
        auto elapsed_ns = CALCTIME(end - begin);
        printf("\nTime: %lld ns\n", elapsed_ns.count());
    }*/

    return  0;
}

