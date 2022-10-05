#include <stdio.h>
#include <stdlib.h>

//create double node
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

//create circular double linked list
typedef struct
{
    node *head;
    node *tail;
    int size;
} circularDoublyLinkedList;

//push head
void push(circularDoublyLinkedList *list, int data)
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
void append(circularDoublyLinkedList *list, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = list->tail;
    if (list->tail != NULL)
        list->tail->next = newNode;
    list->tail = newNode;
    if (list->head == NULL)
        list->head = newNode;
    list->size++;
}