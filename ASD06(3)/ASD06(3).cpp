#include <iostream>
#include <time.h>
#include <chrono>
#define GETTIME std::chrono::steady_clock::now
#define CALCTIME std::chrono::duration_cast<std::chrono::milliseconds>
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))

void countSort(short* arr, int n) {

    //знаходимо максимальний елемент
    int maximum = -1;

    for (int i = 0; i < n; i++) {
        maximum = max(arr[i], maximum);
    }

    //ініціалізуємо рахувальний масив довжиною на 1 більше ніж значення максимально елементу
    int count[212];
    memset(count, 0, sizeof(count));

    //рахуємо кількість елементів відповідно
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    //виаховуємо накопичену(кумулятивну) частоту
    for (int i = 1; i <= maximum; i++) {
        count[i] += count[i - 1];
    }

    //фіксуємо значення у відсортованому масиві
    int newArr[10000];

    for (int i = 0; i < n; i++) {
        newArr[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    //переписуємо всі значення в початковий масив
    for (int i = 0; i < n; i++) {
        arr[i] = newArr[i] - 200;
    }
}


int main()
{

    int n;
    short arr[10000];
    srand(time(NULL));
    printf("Enter amount of items in list: "); scanf_s("%d", &n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 211;
    }
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i] - 200);
    }

    auto begin = GETTIME();
    countSort(arr, n);
    auto end = GETTIME();
    auto elapsed_ms = CALCTIME(end - begin);

    printf("\n\nSorted list:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    printf("\n\nSorting time: %lld ms\n", elapsed_ms.count());
    return 0;
}