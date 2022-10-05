#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
/*
Array add, remove & view data = Renardo
Single linked list add, remove & view data = Athaillah
Array & linked list view first & last = Joshua

Applikasi que vaksin untuk array dan
dan list golongan darah untuk linked list
*/

//Data
struct Queue { // <- Array
    int front, rear, size;
    unsigned kapasitas;
    int *nik;
    char *golDarah;
};

struct node { // <- Linked List
    int nik;
    char golDarah[3];
    char nama[400];
    struct node *next;
};

//buat queue
struct node *front; // <- Linked List
struct node *rear; // <- Linked List

//=============================== Array Block ============================================
//queue baru
struct Queue *createQueueArray(unsigned kapasitas)
{
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->kapasitas = kapasitas;
    queue->front = queue->size = 0;
    queue->rear = kapasitas - 1;
    queue->nik = (int*)malloc(queue->kapasitas * sizeof(int));
    queue->golDarah = (char*)malloc(queue->kapasitas * sizeof(char));
    return queue;
}

//enqueue
struct Queue *enqueueArray(struct Queue* queue, int newData, char golDarah)
{
    queue->rear = (queue->rear + 1) % queue->kapasitas;
    queue->nik[queue->rear] = newData;
    queue->golDarah[queue->rear] = golDarah;
    queue->size += 1;
    return queue;
}


//dequeue
struct Queue *dequeueArray(struct Queue* queue)
{
    printf("data %d telah dihapus", queue->nik[queue->front]);
    queue->front = (queue->front + 1) % queue->kapasitas;
    queue->size -= 1;
    return queue;
}

//cek apa queue kosong
bool isEmptyArray(struct Queue *queue)
{
    return (queue->size == 0);
}

//cek apa queue penuh
bool isFullArray(struct Queue *queue)
{
    return (queue->size == queue->kapasitas);
}

//print front
void printFrontArray(struct Queue *queue)
{
    printf("%d ", queue->nik[queue->front]);
    //cek apakah queue berisi c
    if (queue->golDarah[queue->front] == 'A')
    {
        printf("Millenials");
    }
    else if(queue->golDarah[queue->front] == 'B')
    {
        printf("MonoVak");
    }
    else if(queue->golDarah[queue->front] == 'C')
    {
        printf("Apl3Ju1c3");
    }
}

//print last
void printLastArray(struct Queue *queue)
{
    printf("%d", queue->nik[queue->rear]);
    //cek apakah queue berisi c
     if (queue->golDarah[queue->rear] == 'A')
    {
        printf("Millenials\n");
    }
    else if(queue->golDarah[queue->rear] == 'B')
    {
        printf("MonoVak\n");
    }
    else if(queue->golDarah[queue->rear] == 'C')
    {
        printf("Apl3Ju1c3\n");
    }
}

//print queue
void printQueueArray(struct Queue *q)
{

    if (q->front == q->rear + 1)
    {
        printf("Queue is empty\n\n");
        return;
    }
    else{
    printf("+----+------------------+-----------------+\n");
    printf("| No |  Nomor Vaksin    |   Jenis Vaksin  |\n");
    printf("+----+------------------+-----------------+\n");
    for (int i = q->front; i <= q->rear; i++)
    {
        //cek Nomor vaksin
        if (q->golDarah[i] == 'C')
        {
            printf("| %d  | %d           | Apl3Ju1c3       |\n", i+1, q->nik[i], 'A', 'B');
        }
        else if(q->golDarah[i] == 'A')
        {
            printf("| %d  | %d           | Millenials      |\n", i+1, q->nik[i], q->golDarah[i]);
        }
        else if(q->golDarah[i] == 'B')
        {
            printf("| %d  | %d           | MonoVak         |\n", i+1, q->nik[i], q->golDarah[i]);
        }
    }
    printf("+----+------------------+----------------+\n");
    printf("\n");
    }

}

//tanya user max data
int maxDataArray()
{
    int max;
    printf("Masukkan jumlah maksimal data yang diinginkan: ");
    scanf("%d", &max);
    return max;
}

//main array
int QueueWithArray(){
    int max = maxDataArray();
    struct Queue *queue = createQueueArray(max);
    int nik, pilih;
    int temp;
    char jVak;
    do{
        system("cls");
        printf("\nAplikasi Antre Jenis Vaksin\n");
        printf("1. Tambah Data\n");
        printf("2. Hapus Data\n");
        printf("3. Cetak Data\n");
        printf("4. Keluar\n");
        printf("\n");
        printf("Pilih: ");
        scanf("%d", &pilih);
        switch(pilih){
            case 1:
                if(isFullArray(queue)){
                    printf("\nAntrean penuh\n");
                    break;
                }
                printf("\nMasukkan Kode Vaksin: ");
                scanf("%d", &nik);
                
                
                printf("(A)Millenials\n(B)MonoVak\n(C)Apl3Ju1c3\nMasukkan Jenis Vaksin: ");
                
                getchar();
                scanf("%c", &jVak);
                
                enqueueArray(queue, nik, jVak);
                break;
            case 2:
                if(isEmptyArray(queue)){
                    printf("\nAntrean kosong\n");
                    break;
                }
                dequeueArray(queue);
                break;
            case 3:
                if(isEmptyArray(queue)){
                    printf("\nAntrean kosong\n");
                    break;
                }else{
                    printf("1. Cetak Antrean Pertama\n");
                    printf("2. Cetak Antrean Terakhir\n");
                    printf("3. Cetak Semua Antrean\n");
                    printf("\nPilih: ");
                    scanf("%d", &temp);
                    switch(temp){
                        case 1:
                            printFrontArray(queue);
                            system("pause");
                            break;
                        case 2:
                            printLastArray(queue);
                            system("pause");
                            break;
                        case 3:
                            printQueueArray(queue);
                            system("pause");
                            break;
                        default:
                            printf("\nPilihan tidak ada\n");
                            break;
                    }
                }
                break;
            case 4:
                printf("\nTerima Kasih\n");
                break;
            default:
                printf("\nPilihan tidak ada\n");
        }
    }while(pilih != 4);
    return 0;
}
//====================================== Array Block ====================================================

//====================================== Linked List Block ====================================================

//queue baru
struct node *createQueue(int nik, char golDarah[], char nama[]) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->nik = nik;
    strcpy(newNode->golDarah, golDarah);
    strcpy(newNode->nama, nama);
    newNode->next = NULL;
    return newNode;
}

//enqueue
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

//dequeue
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

//cek apakah queue kosong
bool isEmpty(struct node *front) {
    if (front == NULL) {
        return true;
    } else {
        return false;
    }
}

//tanya user max data
int maxData() {
    int max;
    printf("Masukkan max data: ");
    scanf("%d", &max);
    return max;
}

//print queue paling depan
void printFront(struct node *front) {
    if (front == NULL) {
        printf("Queue kosong\n");
    } else {
        printf("Data %d\n", front->nik);
    }
}

//print queue paling belakang
void printRear(struct node *rear) {
    if (rear == NULL) {
        printf("Queue kosong\n");
    } else {
        printf("Data %d\n", rear->nik);
    }
}

//cek apakah queue sudah penuh
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


//print queue
void printQueue(struct node *front) {
    if (front == NULL) {
        printf("Queue kosong\n\n");
        return;
    }
    printf("\n");
    printf("No\tNik\tNama\t\tGol Darah\n");
    int i = 1;
    while (front != NULL) {
        printf("%d\t%d\t%s\t\t%s\n", i, front->nik, front->nama, front->golDarah);
        front = front->next;
        i++;
    }
    printf("\n");
}

//main linked list
int QueueWithSLL(){
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
//====================================== Linked List Block ==================================================

//fungsi main
int main() {
    int pilihan;
    do {
        printf("\n");
        printf("---------------------------------\n");
        printf("Aplikasi Antrian Donor Darah\n");
        printf("---------------------------------\n");
        printf("1. Queue dengan Array\n");
        printf("2. Queue dengan Singly Linked List\n");
        printf("3. Exit\n");
        printf("---------------------------------\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        switch (pilihan) {
            case 1:
                system("cls");
                QueueWithArray();
                break;
            case 2:
                system("cls");
                QueueWithSLL();
                break;
            case 3:
                printf("Terima kasih\n");
                break;
            default:
                printf("Pilihan tidak ada\n");
                break;
        }
    }
    while (pilihan != 3);
}