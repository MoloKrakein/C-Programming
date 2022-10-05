#include <stdio.h>
#include <stdlib.h>

//create double node
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

//create double linked list
typedef struct
{
    node *head;
    node *tail;
    int size;
} doubleLinkedList;

//push head
void push(doubleLinkedList *list, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = list->head;
    newNode->prev = NULL;
    if (list->head != NULL)
        list->head->prev = newNode;
    list->head = newNode;
    if (list->tail == NULL)
        list->tail = newNode;
    list->size++;
}

//push tail
void append(node **head, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// pop head
void pop(node **head)
{
    if (*head == NULL)
    {
        printf("\n[!] Sorry Queue is empty\n");
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(temp);
}

// pop tail
void removeLast(node **head)
{
    if (*head == NULL)
    {
        printf("\n[!] Sorry Queue is empty\n");
        return;
    }
    node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

// print double linked list
void print(node *head)
{
    if (head == NULL)
    {
        printf("\n[!] Sorry Queue is empty\n");
        return;
    }
    printf("+----+-------------------+-----------------+---------+\n");
    printf("| No |      Atribute     |    Atribute 2   |  Queue  |\n");
    printf("+----+-------------------+-----------------+---------+\n");
    int i = 1;
    while (head != NULL)
    {
        printf("| %2d | %15d | %15d | %10d |\n", i, head->data, head->data, head->data);
        head = head->next;
        i++;
    }
    printf("+----+-------------------+-----------------+---------+\n");
}

// insert node at specific position
void insertAt(node **head, int data, int position)
{
    if (*head == NULL)
    {
        printf("\n[!] Sorry Queue is empty\n");
        return;
    }
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (position == 1)
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    node *temp = *head;
    int i = 1;
    while (temp->next != NULL && i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    if (newNode->next != NULL)
        newNode->next->prev = newNode;
}

// delete node at specific position
void deleteAt(node **head, int position)
{
    if (*head == NULL)
    {
        printf("\n[!] Sorry Queue is empty\n");
        return;
    }
    if (position == 1)
    {
        node *temp = *head;
        *head = (*head)->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return;
    }
    node *temp = *head;
    int i = 1;
    while (temp->next != NULL && i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp->next == NULL)
    {
        printf("\n[!] Sorry Queue is empty\n");
        return;
    }
    node *temp2 = temp->next;
    temp->next = temp->next->next;
    if (temp->next != NULL)
        temp->next->prev = temp;
    free(temp2);
}

// main function
int main(){
    int pil;
    node *head = NULL;
    int newData;
    int position;
    do
    {
        printf("Double linked list\n");
        printf("1. Push Head\n");
        printf("2. Push Tail\n");
        printf("3. Pop Head\n");
        printf("4. Pop Tail\n");
        printf("5. Insert At\n");
        printf("6. Delete At\n");
        printf("7. Print\n");
        printf("8. Exit\n");
        printf("Pilihan : ");
        scanf("%d", &pil);
        switch (pil)
        {
        case 1:
            printf("Masukkan data : ");
            scanf("%d", &newData);
            push(&head, newData);
            break;
        case 2:
            printf("Masukkan data : ");
            scanf("%d", &newData);
            append(&head, newData);
            break;
        case 3:
            pop(&head);
            break;
        case 4:
            removeLast(&head);
            break;
        case 5:
            printf("Masukkan data : ");
            scanf("%d", &newData);
            printf("Masukkan posisi : ");
            scanf("%d", &position);
            insertAt(&head, newData, position);
            break;
        case 6:
            printf("Masukkan posisi : ");
            scanf("%d", &position);
            deleteAt(&head, position);
            break;
        case 7:
            print(head);
            break;
        case 8:
            break;
        default:
            printf("\n[!] Wrong input\n");
            break;
        }
    } while (pil != 8);

}