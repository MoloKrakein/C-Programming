#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hapus depan
// Tambah Belakang

struct Node
{
    char name[256];
    int hour;
    int min;
    struct Node *next;
};

struct Node *popHead(struct Node *head)
{
    struct Node *temp;
    if (head == NULL)
    {
        printf("Its Empty!\n");
    }
    else
    {
        temp = head;
        head = head->next;

        printf("\n Data Delete: %d\n", temp->name);
        free(temp);
        printf("Delete Success!\n");
    }
}

void pushTail(char name[256], int hour, int min, struct Node *head)
{
    struct Node *new, *temp;
    new = malloc(sizeof(struct Node));
    if (new == NULL)
    {
        printf("\n Out of memory\n");
    }
    else
    {
        strcpy(new->name, name);
        new->hour = hour;
        new->min = min;
        new->next = NULL;

        temp = head;

        while (temp != NULL && temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        printf("Data Successfully Added\n");
    }
}

void viewdata(struct Node *head)
{
    struct Node *temp;
    temp = head;

    if (temp == NULL)
    {
        printf("Data Empty\n");
    }
    while (temp != NULL)
    {
        printf("%-15s %02d:%02d\n", temp->name, temp->hour, temp->min);
        temp = temp->next;
    }
}
void addmenu(int menu, struct Node *head)
{
}

void removemenu(int menu, struct Node *head)
{
}

int main()
{
    char name[256];
    int hour;
    int min;
    struct Node *head = NULL;
    int menu;
    int menu2;
    printf("\nTo-do List App\n");
    printf("[1] View List\n");
    printf("[2] Add Memo\n");
    printf("[3] Delete Memo\n");
    printf("[4] Exit\n");
    scanf("%d", &menu);
    switch (menu)
    {
    case 2:
    { // Add menu
        printf("[1] Add From Behind\n");
        scanf("%d", &menu2, head);

        switch (menu2)
        {
        case 1:
        { // add from last
            printf("Please input agenda name:\n");
            scanf(" %[^\n]s", &name);
        hour:
            printf("Please input hour (1-24):\n");
            scanf("%d", &hour);
            if (hour < 0 || hour > 24)
            {
                printf("invalid input\n");
                goto hour;
            }
        min:
            printf("Please input minute (0-59):\n");
            scanf("%d", &min);
            if (min < -1 || min > 60)
            {
                printf("invalid input\n");
                goto min;
            }
            pushTail(name, hour, min,head);
        }
        }
        break;
    }
    case 3:
    { // Delete menu
        printf("[1] Delete First\n");
        scanf("%d", &menu2, head);
    }
    }
}
