#include <stdio.h>
#include <string.h>
#include <chrono>
#define GETTIME std::chrono::steady_clock::now
#define CALCTIME std::chrono::duration_cast<std::chrono::nanoseconds>

void pushFront(char* str, int num)
{
    int len = strlen(str);
    for (int i = len; i >=0; i--)
    {
        str[i] = str[i - 1];
    }
    str[0] = num + '0';
}

int countBiString(const char* str)
{
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '0' || str[i] == '1')
            count++;
    }
    return count;
}

const char* convertTo2(long long int num)
{
    int num2 = 0;
    char str[300];
    while (num != 0) 
    {
        num2 = num % 2;
        pushFront(str, num2);
        num /= 2;
    }

    int count = countBiString(str);
    for (int i = 0; i < count; i++)
        printf("%c", str[i]);
    return str;
}

int main()
{
    long long int num;

    printf("Enter n-bit integer (8 < n < 64): ");
    scanf_s("%lld", &num);
    auto begin = GETTIME();
    const char* str = convertTo2(num);
    auto end = GETTIME();
    auto elapsed_ns = CALCTIME(end - begin);
    
    printf("\nTime: %lld ns\n", elapsed_ns.count());

    return 0;
}