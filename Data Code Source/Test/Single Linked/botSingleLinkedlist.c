#include <stdio.h>
#include <stdlib.h>

//create single linked list
typedef struct node
{
    int data;
    struct node *next;
} node;

// push head
void push(node **head, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// push tail
void append(node **head, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
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
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

// print single linked list
void printList(node *head)
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
        printf("| %d  | %d                | %d              | %d      |\n", i, head->data, head->data, head->data);
        head = head->next;
        i++;
    }
    printf("+----+-------------------+-----------------+---------+\n");
}

// insert at index
void insertAtIndex(node **head, int index, int data)
{
    if (*head == NULL)
    {
        printf("\n[!] Sorry Queue is empty\n");
        return;
    }
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    if (index == 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    node *temp = *head;
    int i = 1;
    while (i < index - 1)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// delete at index
void deleteAtIndex(node **head, int index)
{
    if (*head == NULL)
    {
        printf("\n[!] Sorry Queue is empty\n");
        return;
    }
    if (index == 1)
    {
        node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    node *temp = *head;
    int i = 1;
    while (i < index - 1)
    {
        temp = temp->next;
        i++;
    }
    node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
}

//main
int main(){
    int index;
    int data;
    node *head = NULL;
    int choice;
    do
    {
        printf("Single Linked List\n");
        printf("1. Push Head\n");
        printf("2. Push Tail\n");
        printf("3. Pop Head\n");
        printf("4. Pop Tail\n");
        printf("5. Print List\n");
        printf("6. Insert At Index\n");
        printf("7. Delete At Index\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            push(&head, data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            append(&head, data);
            break;
        case 3:
            pop(&head);
            break;
        case 4:
            removeLast(&head);
            break;
        case 5:
            printList(head);
            break;
        case 6:
            printf("Enter index: ");
            scanf("%d", &index);
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtIndex(&head, index, data);
            break;
        case 7:
            printf("Enter index: ");
            scanf("%d", &index);
            deleteAtIndex(&head, index);
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 8);

}