#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct Node // kegiatan
{
    char name[256];
    int harga;
    struct Node *next;
};

void viewData(struct Node *tail)
{
    struct Node *ptr;
    ptr = tail->next;

    int i = 1;

    if (tail == NULL)
    {
        printf("Kosong\n");
    }
    else
    {

        printf("\nNo | String       | Angka   |\n");
        printf("===============================\n");
        do
        {

            printf("%-2d | %-10s   | %-6d \n", i, ptr->name, ptr->harga);
            ptr = ptr->next;
            i++;
        } while (ptr != tail->next);
    }
}

struct Node *addToEmpty(struct Node *tail, int data, char *newData)
{
    if (tail != NULL)
        return tail;

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    strcpy(temp->name, newData);
    temp->harga = data;

    tail = temp;

    temp->next = tail;

    return tail;
}

struct Node *pushTail(struct Node *tail, int data, char *newData)
{
    if (tail == NULL)
    {
        return addToEmpty(tail, data, newData);
    }
    else
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

        strcpy(temp->name, newData);
        temp->harga = data;

        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }

    printf("Data berhasil ditambahkan!\n");
    return tail;
}

struct Node *pushFront(struct Node *tail, int data, char *newData)
{
    if (tail == NULL)
    {
        return addToEmpty(tail, data, newData);
    }
    else
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

        strcpy(temp->name, newData);
        temp->harga = data;

        temp->next = tail->next;
        tail->next = temp;
    }
    printf("Data berhasil ditambahkan!\n");
    return tail;
}

int getCurrSize(struct Node *node)
{
    int size = 0;
    struct Node *ptr;
    ptr = node->next;

    do
    {
        node = node->next;
        size++;
    } while (ptr != node->next);

    return size;
}

struct Node *insertAtNode(int n, char *data, int newData, struct Node *tail)
{
    int size = getCurrSize(tail);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->name, data);
    newNode->harga = newData;

    newNode->next = NULL;

    if (n < 0 || n > size)
        printf("Invalid position to insert\n");

    else if (n == 0)
    {

        newNode->next = tail;
        tail = newNode;
    }

    else
    {

        struct Node *temp = tail;

        while (--n)
            temp = temp->next;

        newNode->next = temp->next;

        temp->next = newNode;
    }
}

// void fixedDeleteLast(struct Node** tail){
//     struct Node *temp = *tail,*ptr=*tail,*prev;

//     if(*tail == NULL){
//         printf("empty node\n");
//         return;
//     }

//     if (ptr->next == temp)
//     {
//         *tail = NULL;
//         return;
//     }

//     while (ptr->next != *tail){
//         prev = temp;
//         temp = ptr;

//     }

//     prev->next = temp->next;
//     *tail = prev->next;
//     free(temp);
//     return;
    
// }

void deletelast(struct Node *tail)
{
    struct Node *temp, *ptr;
    temp = tail;
    if (tail == NULL)
    {
        printf("\nTak ada data\n");
    }
    else if (tail->next == tail)
    {
        printf("Hapus Data %s \n", tail->name);
        free(tail);
        tail = NULL;
    }
    else
    {
        temp = tail->next;
        temp->next = tail->next;
        printf("Hapus Data %s \n", tail->name);
        free(tail);
    }
}

void deleteAtIndex(struct Node *tail, int pos)
{
    int i = 1;
    struct Node *temp = tail->next;

    if (tail == NULL)
        printf("\nData kosong\n");

    if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
    }
    while (pos > 2)
    {
        temp = temp->next;
        pos--;
    }
    
    struct Node *temp2 = temp->next;
    temp->next = temp2->next;
    if (temp2 = tail)
    {
        tail = temp;
    }
    free(temp2);
    temp2 = NULL;
}
struct Node *pophead(struct Node *tail)
{
    if (tail == NULL)
    {
        printf("Data tak ada");
        return tail;
    }
    if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    struct Node *temp = tail->next;
    tail->next = temp->next;
    free(temp);
    temp = NULL;
    return tail;
}

void sortList(struct Node *tail)
{
    struct Node *current = tail, *index = NULL;
    int temp;
    char temp2[100];
    if (tail == NULL)
    {
        printf("List is empty");
    }
    else
    {
        do
        {
            index = current->next;
            while (index != tail->next)
            {

                if (current->harga > index->harga)
                {
                    temp = current->harga;
                    current->harga = index->harga;
                    index->harga = temp;

                    strcpy(temp2, current->name);
                    strcpy(current->name, index->name);
                    strcpy(index->name, temp2);
                }
                index = index->next;
            }

            current = current->next;

        } while (current->next != tail->next);
    }
}

int main()
{
    struct Node *tail = NULL;

    int menu;
    do
    {
        // system("cls");
        printf("1. Push First\n");
        printf("2. Push Last\n");
        printf("3. Push in certain position\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete in certain position\n");
        printf("7. View data\n");
        printf("8. Sort data\n");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
        {
            int harga;
            char newData[100];

            printf("Masukan nama barang : ");
            scanf(" %[^\n]s", newData);

            printf("Masukan harga : ");
            scanf("%d", &harga);

            tail = pushFront(tail, harga, newData);

            getch();
            break;
        }
        case 2:
        {
            int harga;
            char newData[100];

            printf("Masukan nama barang : ");
            scanf(" %[^\n]s", newData);

            printf("Masukan harga : ");
            scanf("%d", &harga);

            tail = pushTail(tail, harga, newData);

            getch();
            break;
        }
        case 3:
        {
            int harga;
            char newData[100];
            int pos;
            printf("Masukan nama barang : ");
            scanf(" %[^\n]s", newData);

            printf("Masukan harga : ");
            scanf("%d", &harga);

            printf("Masukan data pada data ke : ");
            scanf("%d", &pos);

            insertAtNode(pos, newData, harga, tail);

            getch();
            break;
        }
        case 4:
        {
            tail = pophead(tail);
            getch();
            break;
        }
        case 5:
        {
            deletelast(tail);
            // fixedDeleteLast(&tail);
            printf("data berhasil dihapus\n");
            getch();
            break;
        }
        case 6:
        {
            int posisi;
            printf("Posisi yang ingin dihapus :");
            scanf("%d", &posisi);
            deleteAtIndex(tail, posisi);
            printf("\n");
            getch();
            break;
        }
        case 7:
        {
            viewData(tail);
            getch();
            break;
        }
        case 8:
        {
            sortList(tail);
            getch();
            break;
        }
        case 9:
        {
            printf("%s %d\n ", tail->name, tail->harga);
            getch();
            break;
        }
        }

    } while (menu != 10);
    return 0;
}