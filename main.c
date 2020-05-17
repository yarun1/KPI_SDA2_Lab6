#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
    int value;
    struct List* next;
}List;

void fillList(List** head, List** begin, List** end);
void push(List** head, int value);
void printList(List* head);
void rearrangeList(List** head, List** begin, List** end);

int n;

int main()
{
    List* head = NULL;
    List* begin = NULL;
    List* end = NULL;

    printf("\nWELCOME TO THE PROGRAM\n");
    fillList(&head, &begin, &end);

    printf("Original list: ");
    printList(head);

    rearrangeList(&head, &begin, &end);
}

void fillList(List** head, List** begin, List** end)
{
    printf("Input n: ");
    scanf("%d", &n);
    printf("\n");

    push(head, 2*n);
    *end = &(**head);

    for (int i = 2*n-1; i > 0; i--)
    {
        push(head, i);
    }

    *begin = &(**head);
}

void push(List** head, int value)
{
    List* temp = malloc(sizeof(List));

    temp->value = value;
    temp->next = *head;
    *head = temp;
}

void printList(List* head)
{
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }

    printf("\n");
}

void rearrangeList(List** head, List** begin, List** end)
{
    List* tempPointer = *begin;
    int tempValue1 = tempPointer->next->value;
    int tempValue2 = tempPointer->next->next->value;

    for (int i = 1; i <= n/2; i++)
    {
        if (i != 1)
        {
            tempValue1 = tempPointer->next->next->value;
        }

        tempPointer = tempPointer->next;

        if (i != 1)
        {
            tempValue2 = tempPointer->next->next->value;
        }

        for (int j = 1; j <= n; j++)
        {
            *head = (*head)->next;
        }

        tempPointer->value = (*head)->value;
        tempPointer->next->value = tempValue1;
        (*head)->value = tempValue2;
        (*head) = tempPointer;
    }
}