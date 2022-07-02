#include <iostream>
#include <time.h>
#include <chrono>
#define  root i+sh
#define  left 2*i+1+sh
#define  right 2*i+2+sh
#define GETTIME std::chrono::steady_clock::now
#define CALCTIME std::chrono::duration_cast<std::chrono::milliseconds>

int main()
{

    int n;
    int arr[10000];
    int sh = 0, b = 0;
    srand(time(NULL));
    printf("Enter amount of items in list: "); scanf_s("%d", &n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 101;
    }
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    auto begin = GETTIME();
    while (true)
    {
        b = 0;
        for (int i = 0; i < n; ++i)//запускаєм цикл по всьому масиву
        {
            if (right < n)
            {
                if (arr[root] > arr[left] || arr[root] > arr[right])
                {
                    if (arr[left] < arr[right])
                    {
                        int t = arr[root]; arr[root] = arr[left]; arr[left] = t;
                        b = 1;
                    }
                    else if (arr[right] < arr[left])
                    {
                        int t = arr[root]; arr[root] = arr[right]; arr[right] = t;
                        b = 1;
                    }
                }
            }
            else if (left < n)
            {
                if (arr[root] > arr[left])
                {
                    int t = arr[root]; arr[root] = arr[left]; arr[left] = t;
                    b = 1;
                }
            }
        }
        if (!b) sh++;
        if (sh + 2 == n) break;
    }

    auto end = GETTIME();
    auto elapsed_ms = CALCTIME(end - begin);
    printf("\n\nSorted list:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n\nSorting time: %lld ms\n", elapsed_ms.count());

    return 0;
}