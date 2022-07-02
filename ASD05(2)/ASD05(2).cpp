#include <iostream>
#include <time.h>
#include <chrono>
#define GETTIME std::chrono::steady_clock::now
#define CALCTIME std::chrono::duration_cast<std::chrono::milliseconds>

int main()
{

    int amount, value[10000], tempValue = 0;
    srand(time(NULL));
    printf("Enter amount of items in list: "); scanf_s("%d", &amount);
    for (int i = 0; i < amount; i++) {
        value[i] = rand() % 101;
    }
    for (int i = 0; i < amount; i++) {
        printf("%d\t", value[i]);
    }
    auto begin = GETTIME();
    for (int i = 1; i < amount; i++) {//проходження по циклу починається з першого елементу, так як він має порівнятись з попереднім
        tempValue = value[i];//в допоміжну змінну записується значення елемента, що має вставлятись
        for (int j = i - 1; j >= 0 && value[j] > tempValue; j--) {//відбувається проходження по усім попереднім вже відсорттованим елементам, доки елемент, що вставляється, не стане за меншим від нього
            value[j + 1] = value[j];//елемент міняється місцями з попереднім
            value[j] = tempValue;
        }
    }
    auto end = GETTIME();
    auto elapsed_ms = CALCTIME(end - begin);
    printf("\n\nSorted list:\n");
    for (int i = 0; i < amount; i++) {
        printf("%d\t", value[i]);
    }
    printf("\n\nSorting time: %lld ms\n", elapsed_ms.count());

    return 0;
}

