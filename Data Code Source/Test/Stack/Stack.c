//import all library functions
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//create stuck object
struct Node
{
    char name[256];
    int data;
    struct Node *next;
};

//create function for checking if stack is empty
int isEmpty(struct Node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//create a new node
struct Node *createNode(struct Node *head, int data, char *newData)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    strcpy(temp->name, newData);
    temp->data = data;

    temp->next = head;

    return temp;
}

//create function for checking if stack is full
int isOverflow(struct Node *head, int maxData)
{
    int count = 0;
    struct Node *ptr;
    ptr = head;

    if (isEmpty(head))
    {
        return 0;
    }
    else
    {
        while (ptr != NULL)
        {
            ptr = ptr->next;
            count++;
        }

        return (count == maxData);
    }
}

int main(){
    struct Node *head = NULL;
    int menu;
    int max;
    printf("Masukkan jumlah barang yang diinginkan: ");
    scanf("%d", &max);
    do
    {
        // system("cls");
        printf("1. Push First\n");// 
        printf("2. Pop First\n");
        printf("3. Peek\n");
        printf("4. View Stack\n");
        printf("5. Exit\n");
        printf("Pilih menu: ");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            if (isOverflow(head,max))
            {
                printf("Stack is overflow\n");
            }
            else
            {
                char newData[256];
                int data;
                printf("Masukkan data: ");
                scanf("%d", &data);

                struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
                newNode->data = data;
                newNode->next = head;
                head = newNode;
            }
            break;
        case 2:
            if (isEmpty(head))
            {
                printf("Stack is empty\n");
            }
            else
            {
                struct Node *temp = head;
                head = head->next;
                free(temp);
                temp = NULL;
            }
            break;
        case 3:
            printf("Data: %d\n", peek(head));
            break;
        case 4:
            display(head);
            break;
        case 5:
            break;
        default:
            printf("Menu tidak ada\n");
            break;
        }
        printf("\n");
    } while (menu != 5);
    return 0;
}