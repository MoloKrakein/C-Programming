#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>

struct Array
{
    char name[100];
    int harga;
};

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
struct Node* push(struct Node *top, char newData[20], int harga)
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
struct Node* pop(struct Node *top)
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
void peek(struct Node *top)
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
void viewData(struct Node *top)
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
                top = push(top, newData, harga);
            }
            break;
            case 2:
                top = pop(top);
                break;
            case 3:
                peek(top);
                break;
            case 4:
                viewData(top);
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

}


int withArray(){
    int maxData;
    tanya:
    printf("Masukkan jumlah data yang ingin disimpan: ");
    scanf("%d", &maxData);
    if(maxData < 0 || maxData>64){ //user bisa pasang max data selama kurang dari limit array (Athaillah)
        printf("Jumlah data tidak kurang dari 0 atau lebih dari 64\n");
        goto tanya;
    }
    struct Array stack[64];
    int top = -1;
    int menu;
    int i;
    char newData[100];
    int data;
    do
    {
        printf("\nAplikasi Keranjang\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Top\n");
        printf("4. Display All\n");
        printf("5. Exit\n");
        printf("\n");
        printf("Masukkan pilihan menu: ");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1: //push (Athaillah)
            if(top == maxData-1){
                printf("Stack sudah penuh\n");
            }
            else{
                printf("Masukkan nama barang: ");
                scanf("%s", newData);
                printf("Masukkan harga barang: ");
                scanf("%d", &data);
                top++;
                stack[top].harga = data;
                strcpy(stack[top].name, newData);
            }
            break;
        case 2: //pop (Renardo)
            if(top == -1){
                printf("Stack kosong\n");
            }
            else{
                printf("Barang yang dihapus: %s\n", stack[top].name);
                printf("Harga barang yang dihapus: %d\n", stack[top].harga);
                top--;
            }
            break;
        case 3: //peek (Joshua)
            if(top == -1){
                printf("Stack kosong\n");
            }
            else{
                printf("Barang : %s\n", stack[top].name);
                printf("Harga : %d\n", stack[top].harga);
            }
            break;
        case 4: //show all (Joshua)
            if(top == -1){
                printf("Stack kosong\n");
            }
            else{
                
                printf("No.\tNama\t\tHarga\n");
                printf("====================================================\n");
                for(i=0; i<=top; i++){
                    printf("%d\t%s\t\t%d\n", i+1, stack[i].name, stack[i].harga);
                }
                printf("====================================================\n");
            }
            break;
        case 5:
            printf("Terima kasih\n");
            break;
        default:
            printf("Pilihan tidak ada\n");
            break;
        }
    } while (menu != 5);
}

int main(){
    int pil;
  do{
    printf("\nAplikasi Keranjang\n");
    printf("1. Dengan Linked List\n");
    printf("2. Dengan Array\n");
    printf("3. Exit\n");
    printf("\n");
    printf("Masukkan pilihan menu: ");
    scanf("%d", &pil);
    switch (pil)
    {
    case 1:
        withLinkedList();
        break;
    case 2:
        withArray();
        break;
    case 3:
        printf("Terima kasih\n");
        break;
    default:
        printf("Pilihan tidak ada\n");
        break;
    }
  }while(pil != 3);
}