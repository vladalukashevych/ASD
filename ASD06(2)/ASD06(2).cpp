#include <iostream>
#include <time.h>
#include <chrono>
#define GETTIME std::chrono::steady_clock::now
#define CALCTIME std::chrono::duration_cast<std::chrono::milliseconds>

int increment(long inc[], long size)
{
    int p1, p2, p3, s;

    p1 = p2 = p3 = 1;
    s = -1;
    do {
        if (++s % 2) {
            inc[s] = 8 * p1 - 6 * p2 + 1;
        }
        else {
            inc[s] = 9 * p1 - 9 * p3 + 1;
            p2 *= 2;
            p3 *= 2;
        }
        p1 *= 2;
    } while (3 * inc[s] < size);

    return s > 0 ? --s : 0;
}

void shellSort(double* arr, int n)
{
    long inc, i, j, seq[40];
    int s;
    s = increment(seq, n); //вирахування послідовності приростів
    while (s >= 0)
    {
        inc = seq[s--];// сортування вставками з інкрементом inc[] 

        for (i = inc; i < n; i++)
        {
            double temp = arr[i];//оголошуємо змінну в яку записуємо значення поточного елементу
            for (j = i - inc; j >= 0 && arr[j] > temp; j -= inc)
                arr[j + inc] = arr[j];//шукаємо, куди можна вставити поточний елемент, щоб його лівий сусід заданого приросту був меншим, а правий - більшим
            arr[j + inc] = temp;
        }
    }
}

int main()
{

    int n;
    double arr[10000];
    srand(time(NULL));
    printf("Enter amount of items in list: "); scanf_s("%d", &n);
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 32000 - 2000) / 100.0;
    }

    for (int i = 0; i < n; i++) {
        printf("%.2f\t", arr[i]);
    }

    auto begin = GETTIME();
    shellSort(arr, n);

    auto end = GETTIME();
    auto elapsed_ms = CALCTIME(end - begin);
    printf("\n\nSorted list:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f\t", arr[i]);
    }
    printf("\n\nSorting time: %lld ms\n", elapsed_ms.count());
    return 0;
}