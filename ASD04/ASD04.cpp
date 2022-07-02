#include <iostream>
#include <stdbool.h>


typedef int elemtype;

struct elem {
    elemtype* value;
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

cList* createList(void) {
    cList* list = (cList*)malloc(sizeof(cList));
    if (list) {
        list->size = 0;
        list->head = list->tail = NULL;
    }
    return list;
}

void deleteList(cList* list) {
    cNode* head = list->head;
    cNode* next = NULL;
    while (head) {
        next = head->next;
        free(head);
        head = next;
    }
    free(list);
    list = NULL;
}

bool isEmptyList(cList* list) {
    return ((list->head == NULL) || (list->tail == NULL));
}

int pushFront(cList* list, elemtype* data) {
    cNode* node = (cNode*)malloc(sizeof(cNode));
    if (!node) {
        return -1;
    }
    node->value = data;
    node->next = list->head;
    node->prev = NULL;

    if (!isEmptyList(list)) {
        list->head->prev = node;
    }
    else {
        list->tail = node;
    }
    list->head = node;

    list->size++;
    return 0;
}

int popFront(cList* list, elemtype* data) {
    cNode* node;

    if (isEmptyList(list)) {
        return(-2);
    }

    node = list->head;
    list->head = list->head->next;

    if (!isEmptyList(list)) {
        list->head->prev = NULL;
    }
    else {
        list->tail = NULL;
    }

    data = node->value;
    list->size--;
    free(node);

    return 0;
}

int pushBack(cList* list, elemtype* data) {
    cNode* node = (cNode*)malloc(sizeof(cNode));
    if (!node) {
        return -3;
    }

    node->value = data;
    node->next = NULL;
    node->prev = list->tail;
    if (!isEmptyList(list)) {
        list->tail->next = node;
    }
    else {
        list->head = node;
    }
    list->tail = node;

    list->size++;
    return 0;
}

int popBack(cList* list, elemtype* data) {
    cNode* node = NULL;

    if (isEmptyList(list)) {
        return(-4);
    }

    node = list->tail;
    list->tail = list->tail->prev;
    if (!isEmptyList(list)) {
        list->tail->next = NULL;
    }
    else {
        list->head = NULL;
    }

    data = node->value;
    list->size--;
    free(node);

    return 0;
}

cNode* getNode(cList* list, int index) {
    cNode* node = NULL;
    int i;

    if (index >= list->size) {
        return (NULL);
    }

    if (index < list->size / 2) {
        i = 0;
        node = list->head;
        while (node && i < index) {
            node = node->next;
            i++;
        }
    }
    else {
        i = list->size - 1;
        node = list->tail;
        while (node && i > index) {
            node = node->prev;
            i--;
        }
    }

    return node;
}

void printNode(elemtype* value) {
    printf("%d\n", *((int*)value));
}

void printList(cList* list, void (*func)(elemtype*)) {
    cNode* node = list->head;

    if (isEmptyList(list)) {
        return;
    }

    while (node) {
        func(node->value);
        node = node->next;
    }
}


int main()
{
    int menuNumber = 0, newElement[100], position = 0;
    cList* myList = createList();
    do
    {
        printf("1. Enter element to head.\n");
        printf("2. Enter element to tail.\n");
        printf("3. Delete head element.\n");
        printf("4. Delete tail element.\n");
        printf("5. Print list.\n");
        printf("6. Delete list.\n");
        printf("0. End work.\n");
        printf("Select: "); scanf_s("%d", &menuNumber);
        switch (menuNumber)
        {
        case 0:
            {
                break;
            }
        case 1:
            {
                printf("Enter new element to head: "); scanf_s("%d", &newElement[position]);
                pushFront(myList, &newElement[position]); position++;
                printf("Elemenet was added.");
                printf("\n\n");
                break;
            }
        case 2:
            {
                printf("Enter new element to tail: "); scanf_s("%d", &newElement[position]);
                pushBack(myList, &newElement[position]); position++;
                printf("Elemenet was added.");
                printf("\n\n");
                break;
            }
        case 3:
            {
                int temp;
                popFront(myList, &temp);
                printf("Elemenet was deleted.");
                printf("\n\n");
                break;
            }
        case 4:
            {
                int temp;
                popBack(myList, &temp);
                printf("Elemenet was deleted.");
                printf("\n\n");
                break;
            }
        case 5:
            {
                printList(myList, printNode);
                printf("\n\n");
                break;
            }
        case 6:
            {
                deleteList(myList);
                printf("List was deleted.");
                printf("\n\n");
                break;
            }
        default:
            {
                printf("There is no such operation.");
                printf("\n\n");
                break;
            }
        }
    } while (menuNumber != 0);
}