#include <stdlib.h>
#include <stdio.h>

//Doubly linked list
typedef struct NodeList
{
    int value;
    struct NodeList* next;
    struct NodeList* previous;
}NodeList;

void push(NodeList** head, NodeList** tail, int value);
NodeList* findByIndex(NodeList* head, int index);
void fillList(NodeList** head, NodeList** tail, int size);
void rearrangeList(NodeList* head, int n);
void printList(NodeList* head, int size);

int main()
{
    NodeList* head = NULL;
    NodeList* tail = NULL;
    int n, size;

    printf("\nWELCOME TO THE PROGRAM\n");
    printf("Input n: ");
    scanf("%d", &n);

    size = 2*n;

    fillList(&head, &tail, size);
    printf("An origin list: ");
    printList(head, size);

    rearrangeList(head, n);
    printf("The rearrange list: ");
    printList(head, size);
}

void push(NodeList** head, NodeList** tail, int value)
{
    NodeList* temp = malloc(sizeof(NodeList));

    temp->value = value;
    temp->next = NULL;
    temp->previous = *tail;

    if (*tail != NULL)
    {
        (*tail)->next = temp;
    }

    *tail = temp;

    if (*head == NULL)
    {
        *head = temp;
    }
}

NodeList* findByIndex(NodeList* head, int index)
{
    for (int i = 0; i < index; i++)
    {
        head = head->next;
    }

    return head;
}

void fillList(NodeList** head, NodeList** tail, int size)
{
    for (int i = 0; i < size; i++)
    {
        push(head, tail, i);
    }
}

void rearrangeList(NodeList* head, int n)
{
    NodeList* currentNodeFromMiddle = findByIndex(head, n);

    for (int i = 0; i < n; i++)
    {
        NodeList* next = head->next;
        NodeList* nextFromMiddle = currentNodeFromMiddle->next;

        head->next = currentNodeFromMiddle;
        currentNodeFromMiddle->next = next;
        currentNodeFromMiddle->previous = head->previous;

        head = next;
        currentNodeFromMiddle = nextFromMiddle;
    }
}

void printList(NodeList* head, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", head->value);
        head = head->next;
    }

    printf("\n");
}