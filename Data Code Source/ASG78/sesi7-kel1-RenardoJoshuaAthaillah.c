
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
/*
Tambah menu awal, akhir, dan sorting = Adhar
Tambah setelah posisi tertentu dan menghapus menu pertama = Renardo
Hapus menu terakhir dan hapus pada posisi tertentu = Joshua
*/
// double node
struct Node
{
    int data;
    char string[100];
    struct Node *next;
    struct Node *prev;
};

// cari ukuran doubly linkedlist
int findSize(struct Node *node)
{
	struct Node *ptr = node;
   int res = 0;
   do
   {
       res++;
       ptr = ptr->next;
   }while (ptr != node);
   return res;
}

// display data table
void viewData(struct Node *head)
{
    struct Node *ptr, *ptr2;
    ptr = head;
    int i = 1;
    if (head == NULL)
        printf("Data Kosong !\n");
    else
    {
        
            printf("---------------------------------------------\n");
            printf("No. \t Nama Menu \t Harga\n");
            printf("---------------------------------------------\n");
        do{
            if(i==1)
            {
            printf("%d \t %s \t\t %d\t\t(head)\n", i, ptr->string, ptr->data);
            ptr = ptr->next;
            i++;
            }
            else if (i==findSize(head))
            {
            printf("%d \t %s \t\t %d\t\t(tail)\n", i, ptr->string, ptr->data);
            ptr = ptr->next;
            i++;
            }
            else{
            printf("%d \t %s \t\t %d\n", i, ptr->string, ptr->data);
            ptr = ptr->next;
            i++;
            }
            
        }while(ptr != head);
            printf("---------------------------------------------\n");
    }
}

// push head
struct Node *pushHead(struct Node *head, struct Node *tail, int newData, char newString[100])
{
    if (head == NULL)
    {
        head = (struct Node *)malloc(sizeof(struct Node));
        head->data = newData;
        strcpy(head->string, newString);
        head->next = head;
        head->prev = head;
    }
    else
    {
        struct Node *newNode;
        struct Node *tail = head->prev;
        
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = newData;
        strcpy(newNode->string, newString);

        newNode->next = head;
        newNode->prev = tail;

		tail->next = head->prev = newNode;

        head = newNode;
    }

    return head;
}

// push tail
struct Node *pushTail(struct Node *head, struct Node *tail , int newData, char newString[100])
{
    if (head == NULL)
    {
        head = (struct Node *)malloc(sizeof(struct Node));
        head->data = newData;
        strcpy(head->string, newString);
        head->next = head;
        head->prev = head;
    }
    else
    {
        struct Node *newNode;
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = newData;
        strcpy(newNode->string, newString);

        tail->next = newNode;
		head->prev = newNode;
		newNode->prev = tail;
		newNode->next = head;
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
    if (head == NULL){
        printf("Data Kosong !\n");
        system("pause");

    }
    else if (head == tail)
    {
        printf("Data pertama telah dihapus\n");
        free(head);
        head = NULL;
        system("pause");
    }
    else
    {
        struct Node *temp;
        temp = head;
        head = temp->next;
        
        tail->next = temp->next;
		head->prev = temp->prev;
		
        printf("Data %s telah dihapus\n", temp->string);
        free(temp);
        system("pause");
    }

    return head;
}

// delete tail
struct Node *deleteTail(struct Node *head, struct Node *tail)
{
    if (head == NULL){
        printf("Data Kosong !\n");
        system("pause");

    }
    else if (head == tail)
    {
        printf("Data pertama telah dihapus\n");
        free(head);
        head = NULL;
        system("pause");
    }
    else
    {
        struct Node *temp;
        temp = tail;
        tail = temp->prev;
        tail->next = head;
        printf("Data %s telah dihapus\n", temp->string);
        free(temp);
        system("pause");
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


// delete index
struct Node *deleteIndex(struct Node *head, struct Node *tail, int index)
{
    if (head == NULL){
        printf("Data Kosong !\n");
        system("pause");

    }
   else if (index == 1)
   {
       head = deleteHead(head, tail);
   }
   else if(index == findSize(head))
   {
       head = deleteTail(head, tail);
   }
   else
   {
        struct Node* temp = head;
        int i;
        for (int i = 1; temp != NULL && i < index; i++)
        temp = temp->next;
        temp->prev->next = temp->next;

        printf("Data ke %d telah dihapus\n", index);
        free(temp);
        system("pause");
   }  
    return head;
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
        printf("---------------------------------------------\n");
        printf("Aplikasi Menu Restoran\n");
        printf("---------------------------------------------\n");
        printf("[1] Tambah Menu Baru\n");
        printf("[2] Hapus Menu Yang Ada\n");
        printf("[3] Tampilkan Menu\n");
        printf("[4] Urutkan Menu\n");
        printf("[5] Keluar\n");
        printf("---------------------------------------------\n");
        printf("Masukkan Pilihan Anda : ");
        scanf("%d", &pilihanA);
        switch (pilihanA)
        {
        case 1:
            do
            {
            		tail = head;
					if(head != NULL)
						tail = head->prev;
                	
            	
                system("cls");
                printf("---------------------------------------------\n");
                printf("Tambah Menu Baru\n");
                printf("---------------------------------------------\n");
                printf("[1] Tambah Menu Pertama\n");
                printf("[2] Tambah Menu Terakhir\n");
                printf("[3] Tambah Menu Setelah Posisi\n");
                printf("[4] Tampilkan menu\n");
                printf("[5] Kembali\n");
                printf("---------------------------------------------\n");
                printf("Masukkan Pilihan Anda : ");
                scanf("%d", &pilihanB);
                switch (pilihanB)
                {
                case 1:
                	
                    printf("Masukkan Nama Menu : ");
                    scanf(" %s", &newString);
                    printf("Masukkan Harga Menu : ");
                    scanf(" %d", &newData);
                    head = pushHead(head, tail, newData, newString);
                    getch();
                    system("cls");
                    printf("Menu Berhasil Ditambahkan\n");
                    system("pause");
                    break;
                case 2:
                
                    printf("Masukkan Nama Menu : ");
                    scanf(" %s", &newString);
                    printf("Masukkan Harga Menu : ");
                    scanf(" %d", &newData);
                    head = pushTail(head, tail, newData, newString);
                    getch();
                    system("cls");
                    printf("Menu Berhasil Ditambahkan\n");
                    system("pause");
                    break;
                case 3:
                	
                    printf("Masukkan Nama Menu : ");
                    scanf(" %s", &newString);
                    printf("Masukkan Harga Menu : ");
                    scanf(" %d", &newData);
                sut:
                    printf("Masukkan Setelah Posisi Ke: ");
                    scanf(" %d", &index);
                    if(index > findSize(head))
                    {
                        printf("Posisi Tidak Valid !\n");
                        system("pause");
                        system("cls");
                        goto sut;
                    }
                    else if(index == findSize(head))
                    {
                        head = pushTail(head, tail, newData, newString);
                        getch();
                        printf("Menu Berhasil Ditambahkan\n");
                        system("pause");
                    }
                    else if(index == 0)
                    {
                        head = pushHead(head, tail, newData, newString);
                        getch();
                        printf("Menu Berhasil Ditambahkan\n");
                        system("pause");
                    }
                    else
                    { 
                    head = insertIndex(head, newData, newString, index);
                    getch();
                    system("cls");
                    printf("Menu Berhasil Ditambahkan\n");
                    system("pause");
                    } 
                    break;
                case 4:
                if(head == NULL){
                    printf("Masih Kosong !\n");
                    system("pause");
                }else
                {
                system("cls");
                viewData(head);
                system("pause");
                    
                }
                break;
                
                case 5:
                system("cls");
                break;
                    
                default:
                system("cls");
                    printf("Pilihan Tidak Ada !\n");
                    system("pause");
                    break;
                }
            } while (pilihanB != 5);
            break;
        case 2:
            if (head == NULL)
            {
                system("cls");
                printf("Data Kosong !\n");
                system("pause");
            }
            else
            {
                do
            {   
                tail = head;
					if(head != NULL)
						tail = head->prev;
						
                system("cls");
                printf("---------------------------------------------\n");
                printf("Hapus Menu Yang Ada\n");
                printf("---------------------------------------------\n");
                printf("[1] Hapus Menu Pertama\n");
                printf("[2] Hapus Menu Terakhir\n");
                printf("[3] Hapus Menu Di Posisi\n");
                printf("[4] Kembali\n");
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
                    if (index > findSize(head))
                    {
                        printf("Posisi Tidak Valid !\n");
                        system("pause");
                        system("cls");
                        goto del;
                    }
                    else
                        head = deleteIndex(head,tail,index);
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
                system("pause");
                }
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
                system("pause");
                }
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
                    head = sortAscending(head,findSize(head));
                    system("cls");
                    break;
                case 2:
                    head = sortDescending(head,findSize(head));
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