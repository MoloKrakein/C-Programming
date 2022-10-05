#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct yogurt // Struct bernama yogurt
{
    char code[6]; // Menampung code
    char name[100];
    int stock;
    int price;
    int valid; // Verifikasi apakah struct bernilai atau tidak

} barang[100]; // Memiliki 100 data yang dapat ditampung

void placeholder() // Placeholder untuk item yang ada di soal
{
    strcpy(barang[0].code, "HE002");
    strcpy(barang[0].name, "Plain Yoghurt");
    barang[0].stock = 18;
    barang[0].price = 15000;
    strcpy(barang[1].code, "HE003");
    strcpy(barang[1].name, "Blueberry Yoghurt");
    barang[1].stock = 23;
    barang[1].price = 15000;
    strcpy(barang[2].code, "HE006");
    strcpy(barang[2].name, "Manggo Peach Yoghurt");
    barang[2].stock = 19;
    barang[2].price = 18000;
    strcpy(barang[3].code, "HE007");
    strcpy(barang[3].name, "Pamogranate Yoghurt");
    barang[3].stock = 12;
    barang[3].price = 20000;
    strcpy(barang[4].code, "HE011");
    strcpy(barang[4].name, "Banana Strawberry Yoghurt");
    barang[4].stock = 22;
    barang[4].price = 18000;
    strcpy(barang[5].code, "HE018");
    strcpy(barang[5].name, "Choco Granola Yoghurt");
    barang[5].stock = 14;
    barang[5].price = 20000;
    strcpy(barang[6].code, "HE022");
    strcpy(barang[6].name, "Berry Smooth Yoghurt");
    barang[6].stock = 17;
    barang[6].price = 20000;
    for (int i = 0; i < 7; i++)
    {
        barang[i].valid = 1;
    }
}
int sizedata() // Function untuk menghitung struct barang
{
    int size = 0;
    for (int i = 0; i < sizeof(barang) / sizeof(barang[0]); i++)
    {
        // Melakukan Pengecekan Apakah Index Struct tersebut valid
        if (barang[i].valid == 0) // Jika tidak valid atau berisi 0
        {
            size = i; // Mengisi variabel size dengan i
            break; // Hentikan perulangan
        }
        else // Jika berisi 1 / Valid
        {
            size++; // Tambah size
        }
    }
    return size; // Mengembalikan nilai variabel size
}

void tampildata(int size) // Menampilkan Data Dalam Struct
{

    printf("\nNo | Code  | Name                           | Stock | Price \n");
    printf("================================================================\n");
    for (int i = 0; i < size; i++)
    {
        printf("%-2d | %-5s | %-30s | %-6d | %d\n", i + 1, barang[i].code, barang[i].name, barang[i].stock, barang[i].price);
    }
    printf("================================================================\n");
}

int sell(char code[5], int size) // Function untuk melakukan penjualan
{
    int found = 0; // Verifikasi apakah code valid atau tidak
    int line;
    ///////////////////////////////////////////////////////////////
    for (int i = 0; i < size; i++) // Pencarian Code pada struct
    {
        if (strcmp(code, barang[i].code) == 0) // Jika ketemu maka
        {
            found = 1; // Aktifkan validasi
            line = i; // Tentukan index yang sesuai
            break; // Hentikan perulangan
        }
    }
    ////////////////////////////////////////////////////////////////
    
    if (found == 1) // Jika kode yang dicari sesuai
    {
        int quantity;
        while (found == 1)
        {
            printf("\nHow many yogurt you want to buy ?\n");
            if (scanf("\n%d", &quantity)) // Menanyakan brp banyak yg mau dibeli
            {
                if (quantity <= barang[line].stock && quantity > 0 ) // Pengecekan apakah jumlah yang diminta kurang dari stok atau kurang dari 0
                {
                    // Jika valid
                    barang[line].stock = barang[line].stock - quantity;
                    printf("yogurt : %s\ntotal quantity: %d\ntotal price: %d", barang[line].name, quantity, quantity * barang[line].price);
                    break;
                }
                else
                {
                    // Jika tidak
                    printf("quantity is out of stock\n");
                    continue; // Kembali tanyakan brp jumlah yg mau dibeli
                }
            }
            else
            {
                printf("Invalid input\n"); // Jika Yg di input user 'Aneh'
                break;
                return 0;
            }
        }
    }
    else
    {
        printf("Code not found\n"); // Jika Kode tidak ada
        return 0;
    }
}

int addStock(char code[5], int size) // Function untuk menambah stok + menu
{
    int found = 0;
    int line;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(code, barang[i].code) == 0) // Pencarian Kode yg diminta
        {
            found = 1;
            line = i;
            break;
        }
    }

    if (found == 1) // Jika ketemu
    {
        int quantity;
        while (found == 1)
        {
            printf("\nHow many yogurt you want to add ?\n");
            if (scanf("\n%d", &quantity))
            {
                if (quantity <= 100 && quantity >= 1) // Pengecekan apakah yg ditambah lebih dari 0 dan kurang dari 100
                {
                    barang[line].stock = barang[line].stock + quantity; // Tambahkan stok awal dengan stok yg ditambah
                    printf("yogurt : %s\ntotal quantity: %d\ntotal price: %d", barang[line].name, quantity, quantity * barang[line].price);
                    break;
                }
                else
                {
                    printf("Only beetwen 1 and 100\n"); // Jika inputan lebih 100 dan kurang dari 0
                    continue; // Kembali tanyakan
                }
            }
            else
            {
                printf("Invalid input\n"); // Jika user menginput hal 'aneh'
                break;
                return 0;
            }
        }
    }
    else // Jika kode tidak ketemu
    {
        char yes = 'n';
        printf("Code not found, add new stock ? [y/n]\n"); // tanya user apakah ingin menambah menu / tidak
        scanf(" %c", &yes);
        if (yes == 'y') // Jika iya
        {
            int size = sizedata(); // Mengambil index paling akhir
            char temp[20];
            //   printf("Code :\n");
            //   scanf(" %5s",&temp);
            strcpy(barang[size].code, code);
            printf("Name :\n"); // Tanyakan nama
            scanf(" %[^\n]s", temp);
            //   scanf(" %30s",&temp);
            strcpy(barang[size].name, temp);
            printf("quantity :\n"); // Stok
            scanf(" %d", &barang[size].stock);
            printf("Price :\n"); // Harga
            scanf(" %d", &barang[size].price);
            barang[size].valid = 1; // kasih tau bahwa index ini di struct valid / berisi
            printf("Add Data Success");
        }
        else
        {
            printf("Action Canceled\n"); // Jika user memilih selain "Y"
            return 0;
        }
    }
}

void menu()
{
    int menu = 0;
    char temp[256];
    while (menu == 0)
    {
        int size = sizedata();
        tampildata(size);
        printf("\nMenu\n");
        printf("[1] Sell\n");
        printf("[2] Add stock\n");
        printf("[3] Exit\n");
        int printer = 0, input = 0;
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("Please enter code\n");
            scanf(" %s", &temp);
            if (strlen(temp) == 5)
            {
                sell(temp, sizedata());
            }
            else
            {

                printf("Invalid input!\n");
            }
                break;

        case 2:
            printf("Please enter code\n");
            scanf(" %s", &temp);
            if (strlen(temp) == 5)
            {
                addStock(temp, sizedata());
            }
            else
            {
                printf("Invalid input!\n");
            }
            break;
        case 3:
            menu = 1;
            break;
        default:
            system("cls");
            printf("Invalid Input\n");
            break;
        }
    }
}

void main()
{
    placeholder();
    menu();
}