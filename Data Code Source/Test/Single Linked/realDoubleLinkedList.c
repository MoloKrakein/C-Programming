#include <stdio.h>
#include <stdlib.h>

//example of double linked list
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

//push head using struct
struct node *push(struct node *head, int data)
{

    //check if list is empty
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = data;
        head->next = head;
        head->prev = head;
        return head;
    }else{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    head->prev = newNode;

    head = newNode;
    return head;
    }
}


//pop head using struct node
struct node *pop(struct node *head)
{
    if (head == NULL)
    {
        printf("\n[!] Sorry Queue is empty\n");
        return head;
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
        return head;
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        return head;
    }
}


//pop tail using struct node
struct node *removeLast(struct node *head, struct node *tail)
{
  
    if (head == NULL)
    {
        printf("\n[!] Sorry Queue is empty\n");
        return head;
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
        return head;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != tail)
            temp = temp->next;
        temp->next = NULL;
        tail->prev = temp;
        free(tail);
        return head;
    }
}

//main function
//create menu

