#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct Array
{
    char name[100];
    int harga;
};

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