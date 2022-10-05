#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>

struct Node{
    char data[20];
    int harga;
    struct Node *next;
};

//check apakah stack kosong
bool isEmpty(struct Node* top)
{
    return (top == NULL);
}

//check apakah stack penuh (Athaillah)
bool isOverflow(struct Node *top, int maxData)
{
    int count = 0;
    struct Node *ptr;
    ptr = top;
    
    if(isEmpty(top))
        return false;
    else
    {
        while(ptr != NULL)
        {
            ptr = ptr->next;
            count++;
        }
        
        return (count == maxData);
    }
}

//buat node baru (Athaillah)
struct Node* push1(struct Node *top, char newData[20], int harga)
{
    if(isEmpty(top))
    {
        top = (struct Node*)malloc(sizeof(struct Node));
        strcpy(top->data, newData);
        top->harga = harga;
        top->next = NULL;
    }
    else
    {
        struct Node *newNode;
        newNode = (struct Node*)malloc(sizeof(struct Node));
        strcpy(newNode->data, newData);
        newNode->harga = harga;
        newNode->next = top;
        top = newNode;
    }
    return top;
}

//hapus node (Renardo)
struct Node* pop1(struct Node *top)
{
    if(isEmpty(top))
    {
        printf("Stack kosong\n");
        return top;
    }
    else
    {
        struct Node *ptr;
        ptr = top;
        top = top->next;
        free(ptr);
        return top;
    }
}

//fungsi peek untuk menampilkan data paling atas (Joshua)
void peek1(struct Node *top)
{
    if(isEmpty(top))
    {
        printf("Stack kosong\n");
    }
    else
    {
        printf("Data paling atas: %s | %d \n", top->data, top->harga);
    }
}

//fungsi menampilkan data stack (Joshua)
void viewData1(struct Node *top)
{
    struct Node *ptr;
    ptr = top;
    int i;
    if(isEmpty(top))
    {
        printf("Stack kosong\n");
    }
    else
    {
        printf("---------------------------------\n");
        printf("No. \t Barang \t Harga \n");
        printf("---------------------------------\n");
        while (ptr != NULL)
        {
            printf("%d \t %s \t %d \n", i+1, ptr->data, ptr->harga);
            ptr = ptr->next;
            i++;
        }
    }
}

int withLinkedList(){
    struct Node *top = NULL;
    char newData[20];
    int harga;
    int maxData = 5;
    int pil;
    int i;
    int temp;
    printf("Masukan jumlah max barang: ");
    scanf("%d", &maxData);
    do{
    printf("-------------------------------------\n");
    printf("Aplikasi Keranjang Belanja\n");
    printf("-------------------------------------\n");
        printf("1. Tambah Barang\n");
        printf("2. Hapus Barang\n");
        printf("3. Tampilkan Paling Atas\n");
        printf("4. View Data\n");
        printf("5. Atur jumlah max barang\n");
        printf("6. Exit\n");
        printf("-------------------------------------\n");
        printf("Pilih: ");
        scanf("%d", &pil);
        
        switch(pil)
        {
            case 1:
            if (isOverflow(top, maxData))
            {
                printf("Stack is overflow\n");
            }
            else
            {
                printf("Masukkan nama barang: ");
                scanf("%s", newData);
                printf("Masukkan harga barang: ");
                scanf("%d", &harga);
                top = push1(top, newData, harga);
            }
            break;
            case 2:
                top = pop1(top);
                break;
            case 3:
                peek1(top);
                break;
            case 4:
                viewData1(top);
                break;
            case 5:
                printf("Masukkan jumlah max barang: ");
                scanf("%d", &temp);
                if (temp < maxData){
                    printf("Jumlah barang tidak boleh kurang dari %d\n", maxData);
                }else{
                    maxData = temp;
                    printf("Jumlah max barang berhasil diubah menjadi %d\n", maxData);
                }
                break;
            case 6:
                printf("Terima kasih telah menggunakan aplikasi ini\n");
                break;
            default:
                printf("\nPilihan tidak ada\n");
                break;
        }
    }while(pil != 6);
    
    return 0;
}
