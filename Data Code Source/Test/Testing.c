#include <stdio.h>

//create a new node
struct Node
{
    char name[256];
    int harga;
    struct Node *next;
};

//create function for creating circular single linked list
struct Node *createNode(char name[], int harga)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->harga = harga;
    newNode->next = newNode;
    return newNode;
}

//create function for add node to circular single linked list
void addNode(struct Node *head, char name[], int harga)
{
    struct Node *newNode = createNode(name, harga);
    struct Node *current = head;
    while (current->next != head)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
}

//create function for delete first node of circular single linked list
void deleteFirstNode(struct Node *head)
{
    struct Node *current = head;
    while (current->next != head)
    {
        current = current->next;
    }
    current->next = head->next;
    free(head);
}

//create function for delete last node of circular single linked list
void deleteLastNode(struct Node *head)
{
    struct Node *current = head;
    while (current->next != head)
    {
        current = current->next;
    }
    current->next = head;
    free(head->next);
}

//create function for add node of spesified place in circular list
void addNodeAt(struct Node *head, char name[], int harga, int place)
{
    struct Node *newNode = createNode(name, harga);
    struct Node *current = head;
    int i = 0;
    while (i < place)
    {
        current = current->next;
        i++;
    }
    newNode->next = current->next;
    current->next = newNode;
}