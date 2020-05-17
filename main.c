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

}