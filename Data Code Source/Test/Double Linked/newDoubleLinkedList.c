#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// double node
struct Node
{
    int data;
    char string[100];
    struct Node *next;
    struct Node *prev;
};

// display data table
void viewData(struct Node *head)
{
    struct Node *ptr;
    ptr = head;
    int i = 1;
    if (head == NULL)
        printf("Data Kosong !\n");
    else
    {
        
            printf("---------------------------------------------\n");
            printf("No. \t Nama Menu \t Harga\n");
            printf("---------------------------------------------\n");
        while (ptr != NULL){
            //check if string has space
            if (strchr(ptr->string, ' ') != NULL){
                printf("%d. \t %s \t %d\n", i, ptr->string, ptr->data);
            }
            else{
                printf("%d. \t %s\t\t %d\n", i, ptr->string, ptr->data);
            }
            ptr = ptr->next;

        } 
            printf("---------------------------------------------\n");
    }
}

// push head
struct Node *pushHead(struct Node *head, int newData, char newString[100])
{
    if (head == NULL)
    {
        head = (struct Node *)malloc(sizeof(struct Node));
        head->data = newData;
        strcpy(head->string, newString);
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        struct Node *newNode;
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = newData;
        strcpy(newNode->string, newString);

        head->prev = newNode;
        newNode->next = head;
        newNode->prev = NULL;

        head = newNode;
    }

    return head;
}

// push tail
struct Node *pushTail(struct Node *head, int newData, char newString[100])
{
    if (head == NULL)
    {
        head = (struct Node *)malloc(sizeof(struct Node));
        head->data = newData;
        strcpy(head->string, newString);
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        struct Node *newNode;
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = newData;
        strcpy(newNode->string, newString);

        struct Node *temp;
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }

    return head;
}

// insert index
struct Node *insertIndex(struct Node *head, int newData, char newString[100], int index)
{
    if (head == NULL)
    {
        head = (struct Node *)malloc(sizeof(struct Node));
        head->data = newData;
        strcpy(head->string, newString);
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        struct Node *newNode;
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = newData;
        strcpy(newNode->string, newString);

        struct Node *temp;
        temp = head;
        int i = 1;
        while (i < index)
        {
            temp = temp->next;
            i++;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    return head;
}

// delete head
struct Node *deleteHead(struct Node *head, struct Node *tail)
{
    if (head == NULL)
        printf("Data Kosong !\n");
    else if (head == tail)
    {
        printf("Data %s telah dihapus\n", head->string);
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *temp;
        temp = head;
        head = temp->next;
        head->prev = NULL;
        printf("Data %s telah dihapus\n", head->string);
        free(temp);
        printf("press any key to continue...\n");
        getch();
    }

    return head;
}

// delete tail
struct Node *deleteTail(struct Node *head, struct Node *tail)
{
    if (head == NULL)
        printf("Data Kosong !\n");
    else if (head == tail)
    {
        printf("Data %s telah dihapus\n", head->string);
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *temp;
        temp = tail;
        tail = temp->prev;
        tail->next = NULL;
        printf("Data %s telah dihapus\n", head->string);
        free(temp);
        printf("press any key to continue...");
        getch();
    }

    return head;
}

// delete index
struct Node *deleteIndex(struct Node *head, struct Node *tail, int index)
{
    if (head == NULL)
        printf("Data Kosong !\n");
    else if (head == tail)
    {
        printf("Data %s telah dihapus\n", head->string);
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *temp;
        temp = head;
        int i = 1;
        while (i < index)
        {
            temp = temp->next;
            i++;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        printf("Data %s telah dihapus\n", head->string);
        printf("press any key to continue...\n");
        getch();
        free(temp);
    }

    return head;
}


//sort ascending order by data
struct Node *sortAscending(struct Node *head, int maxData)
{
    struct Node *temp;
    temp = head;
    int i, j;
    int tempData;
    char tempString[100];
    for (i = 0; i < maxData; i++)
    {
        for (j = 0; j < maxData - i - 1; j++)
        {
            if (temp->data > temp->next->data)
            {
                tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;

                strcpy(tempString, temp->string);
                strcpy(temp->string, temp->next->string);
                strcpy(temp->next->string, tempString);
            }
            temp = temp->next;
        }
        temp = head;
    }
    return head;

}

// sort descending order by data
struct Node *sortDescending(struct Node *head,int maxData)
{
    struct Node *temp;
    temp = head;
    int i, j;
    int tempData;
    char tempString[100];
    for (i = 0; i < maxData; i++)
    {
        for (j = 0; j < maxData - i - 1; j++)
        {
            if (temp->data < temp->next->data)
            {
                tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;

                strcpy(tempString, temp->string);
                strcpy(temp->string, temp->next->string);
                strcpy(temp->next->string, tempString);
            }
            temp = temp->next;
        }
        temp = head;
    }
    return head;
}


//data counter
int countData(struct Node *head)
{
    struct Node *ptr;
    ptr = head;
    int i = 0;
    while (ptr != NULL)
    {
        i++;
        ptr = ptr->next;
    }
    return i;
}

// main aplikasi restoran
int main()
{
    struct Node *head = NULL;
    struct Node *tail = NULL;
    int pilihanA, pilihanB;
    int newData;
    char newString[100];
    int index;

    do
    {
        int totalData = countData(head);
        printf("---------------------------------------------\n");
        printf("Aplikasi Menu Restoran\n");
        printf("---------------------------------------------\n");
        printf("[1] Tambah Menu Baru >\n");
        printf("[2] Hapus Menu Yang Ada >\n");
        printf("[3] Tampilkan Menu\n");
        printf("[4] Urutkan Menu >\n");
        printf("[5] Keluar\n");
        printf("---------------------------------------------\n");
        printf("Masukkan Pilihan Anda : ");
        scanf("%d", &pilihanA);
        switch (pilihanA)
        {
        case 1:
            do
            {
                system("cls");
                printf("---------------------------------------------\n");
                printf("Tambah Menu Baru\n");
                printf("---------------------------------------------\n");
                printf("[1] Tambah Menu Pertama >\n");
                printf("[2] Tambah Menu Terakhir >\n");
                printf("[3] Tambah Menu Di Posisi >\n");
                printf("[4] Tampilkan menu\n");
                printf("[5] Kembali <\n");
                printf("---------------------------------------------\n");
                printf("Masukkan Pilihan Anda : ");
                scanf("%d", &pilihanB);
                switch (pilihanB)
                {
                case 1:
                    printf("Masukkan Nama Menu : ");
                    scanf(" %[^\n]", &newString);  
                    printf("Masukkan Harga Menu : ");
                    scanf(" %d", &newData);
                    head = pushHead(head, newData, newString);
                    system("cls");
                    printf("Menu Berhasil Ditambahkan\n");
                    printf("press any key to continue...\n");
                getch();
                    break;
                case 2:
                    printf("Masukkan Nama Menu : ");
                      scanf(" %[^\n]", &newString);      
                    scanf(" %s", &newString);
                    printf("Masukkan Harga Menu : ");
                    scanf(" %d", &newData);
                    head = pushTail(head, newData, newString);
                    system("cls");
                    printf("Menu Berhasil Ditambahkan\n");
                    printf("press any key to continue...\n");
                getch();
                    break;
                case 3:
                    printf("Masukkan Nama Menu : ");
                    scanf(" %[^\n]", &newString);    
                    printf("Masukkan Harga Menu : ");
                    scanf(" %d", &newData);
                    printf("Masukkan Posisi : ");
                    scanf(" %d", &index);
                    head = insertIndex(head, newData, newString, index);
                    system("cls");
                    printf("Menu Berhasil Ditambahkan\n");
                    printf("press any key to continue...\n");
                getch();
                    break;
                case 4:
                if(head == NULL){
                    printf("Masih Kosong !\n");
                    printf("press any key to continue...\n");
                    getch();
                }else
                {
                system("cls");
                viewData(head);
                printf("press any key to continue...\n");
                getch();
                    
                }
                
                break;
                case 5:
                    system("cls");
                    break;
                default:
                system("cls");
                    printf("Pilihan Tidak Ada !\n");
                    break;
                }
            } while (pilihanB != 5);
            break;
        case 2:
            if (head == NULL)
            {
                system("cls");
                printf("Data Kosong !\n");
                printf("press any key to continue...\n");
                getch();
            }
            else
            {
                do
            {   system("cls");
                printf("---------------------------------------------\n");
                printf("Hapus Menu Yang Ada\n");
                printf("---------------------------------------------\n");
                printf("[1] Hapus Menu Pertama >\n");
                printf("[2] Hapus Menu Terakhir >\n");
                printf("[3] Hapus Menu Di Posisi >\n");
                printf("[4] Kembali <\n");
                printf("---------------------------------------------\n");
                printf("Masukkan Pilihan Anda : ");
                scanf("%d", &pilihanB);
                switch (pilihanB)
                {
                case 1:
                    head = deleteHead(head, tail);
                    system("cls");
                    break;
                case 2:
                    head = deleteTail(head, tail);
                    system("cls");
                    break;
                case 3:
                del:
                    printf("Masukkan Posisi : ");
                    scanf("%d", &index);
                    if (index > totalData)
                    {
                        printf("Posisi Tidak Valid !\n");
                        printf("press any key to continue...\n");
                        getch();
                        system("cls");
                        goto del;
                    }
                    break;
                case 4:
                system("cls");
                    break;
                default:
                    system("cls");
                    printf("Pilihan Tidak Ada !\n");
                    break;
                }
            } while (pilihanB != 4);
            }
            break;

        case 3:
            if (head == NULL){
                system("cls");
                printf("Data Kosong !\n");
                printf("press any key to continue...\n");
                getch();}
            else
            {
                system("cls");
               viewData(head);
            }
            break;
        case 4:
            if (head == NULL){
                system("cls");
                printf("Data Kosong !\n");
                printf("press any key to continue...\n");
                getch();}
            else
            {
                printf("Urutkan Menu Berdasarkan harga : \n");
                printf("[1] Ascending\n");
                printf("[2] Descending\n");
                printf("Masukkan Pilihan Anda : ");
                scanf("%d", &pilihanB);
                switch (pilihanB)
                {
                case 1:
                    head = sortAscending(head, totalData);
                    system("cls");
                    break;
                case 2:
                    head = sortDescending(head,totalData);
                    system("cls");
                    break;
                default:
                    system("cls");
                    printf("Pilihan Tidak Ada !\n");
                    break;
                }

            }
            break;
        case 5:
        system("cls");
        printf("Terima Kasih Telah Menggunakan Aplikasi ini :D\n");
            break;
        default:
        system("cls");
            printf("Pilihan Tidak Ada ! D:\n");
            break;
        }
    } while (pilihanA != 5);
}
