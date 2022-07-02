#include <iostream>
#include <stdbool.h>
#include <time.h>
#include <chrono>
#define GETTIME std::chrono::steady_clock::now
#define CALCTIME std::chrono::duration_cast<std::chrono::milliseconds>

typedef int elemtype;

struct elem {
    elemtype value;
    struct elem* next;
    struct elem* prev;
};

struct myList {
    struct elem* head;
    struct elem* tail;
    size_t size;
};

typedef struct elem cNode;
typedef struct myList cList;

cList* createList(void)
{
    cList* list = (cList*)malloc(sizeof(cList));
    if (list)
    {
        list->size = 0;
        list->head = list->tail = NULL;
    }
    return list;
}

void deleteList(cList* list)
{
    cNode* head = list->head;
    cNode* next = NULL;
    while (head)
    {
        next = head->next;
        free(head);
        head = next;
    }
    free(list);
    list = NULL;
}


bool isEmptyList(cList* list)
{
    return ((list->head == NULL) || (list->tail == NULL));
}

int pushFront(cList* list, elemtype* data)
{
    cNode* node = (cNode*)malloc(sizeof(cNode));
    if (!node)
    {
        return(-1);
    }
    node->value = *data;
    node->next = list->head;
    node->prev = NULL;

    if (!isEmptyList(list))
    {
        list->head->prev = node;
    }
    else
    {
        list->tail = node;
    }
    list->head = node;

    list->size++;
    return(0);
}

int popFront(cList* list, elemtype* data)
{
    cNode* node;

    if (isEmptyList(list))
    {
        return(-2);
    }

    node = list->head;
    list->head = list->head->next;

    if (!isEmptyList(list))
    {
        list->head->prev = NULL;
    }
    else
    {
        list->tail = NULL;
    }

    *data = node->value;
    list->size--;
    free(node);

    return(0);
}

int pushBack(cList* list, elemtype* data)
{
    cNode* node = (cNode*)malloc(sizeof(cNode));
    if (!node)
    {
        return(-3);
    }

    node->value = *data;
    node->next = NULL;
    node->prev = list->tail;
    if (!isEmptyList(list))
    {
        list->tail->next = node;
    }
    else
    {
        list->head = node;
    }
    list->tail = node;

    list->size++;
    return(0);
}

int popBack(cList* list, elemtype* data)
{
    cNode* node = NULL;

    if (isEmptyList(list))
    {
        return(-4);
    }

    node = list->tail;
    list->tail = list->tail->prev;
    if (!isEmptyList(list))
    {
        list->tail->next = NULL;
    }
    else
    {
        list->head = NULL;
    }

    *data = node->value;
    list->size--;
    free(node);

    return(0);
}

cNode* getNode(cList* list, int index)
{
    cNode* node = NULL;
    int i;

    if (index >= list->size)
    {
        return (NULL);
    }

    if (index < list->size / 2)
    {
        i = 0;
        node = list->head;
        while (node && i < index)
        {
            node = node->next;
            i++;
        }
    }
    else
    {
        i = list->size - 1;
        node = list->tail;
        while (node && i > index)
        {
            node = node->prev;
            i--;
        }
    }

    return node;
}

int pushIndex(cList* list, elemtype* data, int index)
{
    cNode* node = (cNode*)malloc(sizeof(cNode));

    if (index == 0)
    {
        return pushFront(list, data);
    }
    if (index == list->size - 1)
    {
        return pushBack(list, data);
    }
    if (index < 0 || index>list->size - 1)
    {
        return -1;
    }

    cNode* next = getNode(list, index);
    cNode* prev = getNode(list, index)->prev;

    node->value = *data;

    getNode(list, index - 1)->next = node;
    getNode(list, index)->prev = node;

    node->next = next;
    node->prev = prev;

    list->size++;
}

int popIndex(cList* list, int index)
{
    if (index == 0)
    {
        elemtype tmp;
        return popFront(list, &tmp);
    }
    if (index == list->size - 1)
    {
        elemtype tmp;
        return popBack(list, &tmp);
    }
    if (index < 0 || index>list->size - 1)
    {
        return -1;
    }

    cNode* next = getNode(list, index)->next;
    cNode* prev = getNode(list, index)->prev;

    free(getNode(list, index));

    getNode(list, index - 1)->next = next;
    getNode(list, index + 1)->prev = prev;

    list->size--;

    return 0;
}

void printList(cList* list, void (*func)(elemtype*))
{
    cNode* node = list->head;

    if (isEmptyList(list))
    {
        return;
    }

    while (node)
    {
        func(&node->value);
        node = node->next;
    }
}

void printNode(elemtype* value) {
    printf("%d\t", *((int*)value));
}

int main()
{
    cList* myList = createList();
    int amount, value[10000];
    srand(time(NULL));
    printf("Enter amount of items in list: "); scanf_s("%d", &amount);
    for (int i = 0; i < amount; i++) {
        value[i] = rand() % 101;
        pushFront(myList, &value[i]);
    }
    elemtype tempValue;
    printf("\nList:\n");
    printList(myList, printNode);
    auto begin = GETTIME();
    for (int i = 1; i < amount; i++) {
        tempValue = getNode(myList, i)->value;
        for (int j = i - 1; j >= 0 && getNode(myList, j)->value > tempValue; j--) {
            getNode(myList, j + 1)->value = getNode(myList, j)->value;
            getNode(myList, j)->value = tempValue;
        }
    }
    auto end = GETTIME();
    auto elapsed_ms = CALCTIME(end - begin);
    printf("\n\nSorted list:\n");
    printList(myList, printNode);
    printf("\n\nSorting time: %lld ms\n", elapsed_ms.count());

    return 0;
}
