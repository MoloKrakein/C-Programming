#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

//buat node
struct node {
    int nik;
    char golDarah[3];
    char nama[400];
    struct node *next;
};

//buat queue
struct node *front;
struct node *rear;

//fungsi create queue
struct node *createQueue(int nik, char golDarah[], char nama[]) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->nik = nik;
    strcpy(newNode->golDarah, golDarah);
    strcpy(newNode->nama, nama);
    newNode->next = NULL;
    return newNode;
}

//fungsi enqueue
struct node *enqueue(int nik, char golDarah[], char nama[]) {
    struct node *newNode = createQueue(nik, golDarah, nama);
    if (front == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    return newNode;
}

//fungsi dequeue
struct node *dequeue(struct node *front) {
    if (front == NULL) {
        printf("Queue kosong\n");
        return NULL;
    } else {
        struct node *temp = front;
        front = front->next;
        printf("Data %d telah dihapus\n", temp->nik);
        free(temp);
        return front;
    }
}

//fungsi cek apakah queue kosong
bool isEmpty(struct node *front) {
    if (front == NULL) {
        return true;
    } else {
        return false;
    }
}

//fungsi tanya user max data
int maxData() {
    int max;
    printf("Masukkan max data: ");
    scanf("%d", &max);
    return max;
}

//fungsi print queue paling depan
void printFront(struct node *front) {
    if (front == NULL) {
        printf("Queue kosong\n");
    } else {
        printf("Data %d\n", front->nik);
    }
}

//fungsi print queue paling belakang
void printRear(struct node *rear) {
    if (rear == NULL) {
        printf("Queue kosong\n");
    } else {
        printf("Data %d\n", rear->nik);
    }
}

//fungsi cek apakah queue sudah penuh
bool isFull(struct node *front, int max) {
    if (front == NULL) {
        return false;
    } else {
        struct node *temp = front;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        if (count == max) {
            return true;
        } else {
            return false;
        }
    }
}


//fungsi print queue
void printQueue(struct node *front) {
    if (front == NULL) {
        printf("Queue kosong\n\n");
        return;
    }
    printf("\n");
    //buat tabel no, nik,nama,golDarah
    printf("No\tNik\tNama\t\tGol Darah\n");
    int i = 1;
    while (front != NULL) {
        printf("%d\t%d\t%s\t\t%s\n", i, front->nik, front->nama, front->golDarah);
        front = front->next;
        i++;
    }
    printf("\n");
}

//main function
int main(){
    int max = maxData();
    int nik;
    char golDarah[3];
    char nama[400];
    int pilihan;
    int i = 1;
    do {printf("\n");
        printf("---------------------------------\n");
        printf("Aplikasi Antrian Donor Darah\n");
        printf("---------------------------------\n");
        printf("1. Tambah Data\n");
        printf("2. Hapus Data\n");
        printf("3. Cek Data\n");
        printf("4. Exit\n");
        printf("---------------------------------\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        switch (pilihan) {
            case 1:
                    
                    if (isFull(front, max)){
                        printf("Antrian sudah penuh!\n");

                    }else{
                    printf("Masukkan NIK: ");
                    scanf("%d", &nik);
                    gd:
                    printf("Masukkan Gol Darah: ");
                    scanf("%s", &golDarah);
                    if (strcmp(golDarah, "A") != 0 && strcmp(golDarah, "B") != 0 && strcmp(golDarah, "AB") != 0 && strcmp(golDarah, "O") != 0) {
                        printf("Golongan Darah tidak ada\n");
                        goto gd;
                    }
                    printf("Masukkan Nama: ");
                    scanf("%s", &nama);
                    enqueue(nik, golDarah, nama);
                    printf("Data berhasil ditambahkan\n");
                    }
                break;
            case 2:
                if (isEmpty(front)) {
                    printf("Antrian kosong\n");
                } else {
                    front = dequeue(front);
                }
                break;
            case 3:
                printf("1. Data paling depan\n");
                printf("2. Data paling belakang\n");
                printf("3. Semua data\n");
                printf("Pilihan: ");
                scanf("%d", &pilihan);
                switch (pilihan) {
                    case 1:
                        printFront(front);
                        break;
                    case 2:
                        printRear(rear);
                        break;
                    case 3:
                        printQueue(front);
                        break;
                    default:
                        printf("Pilihan tidak ada\n");
                        break;
                }
                break;
            case 4:
                printf("Terima kasih\n");
                break;
            default:
                printf("Pilihan tidak ada\n");
                break;
        }

    }
    while (pilihan != 4);
    return 0;
}