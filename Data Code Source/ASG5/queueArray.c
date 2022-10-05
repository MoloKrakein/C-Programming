#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

//aplikasi antrian donor darah

//struktur data
struct Queue {
    int front, rear, size;
    unsigned kapasitas;
    int *nik;
    char *golDarah;
};

//queue baru
struct Queue *createQueue(unsigned kapasitas)
{
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->kapasitas = kapasitas;
    queue->front = queue->size = 0;
    queue->rear = kapasitas - 1;
    queue->nik = (int*)malloc(queue->kapasitas * sizeof(int));
    queue->golDarah = (char*)malloc(queue->kapasitas * sizeof(char));
    return queue;
}

//operasi enqueue
struct Queue *enqueue(struct Queue* queue, int newData, char golDarah)
{
    queue->rear = (queue->rear + 1) % queue->kapasitas;
    queue->nik[queue->rear] = newData;
    queue->golDarah[queue->rear] = golDarah;
    queue->size += 1;
    return queue;
}


//operasi dequeue
struct Queue *dequeue(struct Queue* queue)
{
    printf("data %d telah dihapus", queue->nik[queue->front]);
    queue->front = (queue->front + 1) % queue->kapasitas;
    queue->size -= 1;
    return queue;
}

//cek apa queue kosong
bool isEmpty(struct Queue *queue)
{
    return (queue->size == 0);
}

//cek apa queue penuh
bool isFull(struct Queue *queue)
{
    return (queue->size == queue->kapasitas);
}

//print queue
void printQueue(struct Queue *q)
{

    if (q->front == q->rear + 1)
    {
        printf("Queue is empty\n\n");
        return;
    }
    printf("+----+-------------------+-----------------+\n");
    printf("| No |      NIK          |    Gol. Darah   |\n");
    printf("+----+-------------------+-----------------+\n");
    for (int i = q->front; i <= q->rear; i++)
    {
        //cek apakah golDarah adalah C
        if (q->golDarah[i] == 'C')
        {
            printf("| %d  | %d               | %c%c            |\n", i, q->nik[i], 'A', 'B');
        }
        else
        {
            printf("| %d  | %d               | %c               |\n", i, q->nik[i], q->golDarah[i]);
        }
    }
    printf("+----+-------------------+-----------------+\n");
    printf("\n");
}

//tanya user berapa max data
int maxData()
{
    int max;
    printf("Masukkan jumlah maksimal data yang diinginkan: ");
    scanf("%d", &max);
    return max;
}



//main
int main(){
    int max = maxData();
    struct Queue *queue = createQueue(max);
    int nik, pilih;
    char golDarah;
    do{
        system("cls");
        printf("\nAplikasi Antre Donor Darah\n");
        printf("1. Tambah Data\n");
        printf("2. Hapus Data\n");
        printf("3. Cetak Data\n");
        printf("4. Keluar\n");
        printf("\n");
        printf("Pilih: ");
        scanf("%d", &pilih);
        switch(pilih){
            case 1:
            //cek apakah queue penuh
            if (isFull(queue))
            {
                printf("Queue penuh\n");
                break;
            }
            printf("Masukkan NIK: ");
            scanf("%d", &nik);
            gol:
            printf("Masukkan Golongan Darah (jika AB input C): ");
            scanf(" %c", &golDarah);
            //check apakah golDarah ada
            if (golDarah != 'A' && golDarah != 'B' && golDarah != 'O' && golDarah != 'C'){
                printf("Golongan Darah tidak valid\n");
                goto gol;
            }
            //enqueue
            queue = enqueue(queue, nik, golDarah);
                break;
            case 2:
            //cek apakah queue kosong
            if (isEmpty(queue))
            {
                printf("Queue kosong\n");
                break;
            }
            //dequeue
                dequeue(queue);
                break;
            case 3:
                printQueue(queue);
                break;
            case 4:
                printf("\n");
                printf("Terima Kasih\n");
                break;
            default:
                printf("\n");
                printf("Pilihan tidak ada\n");
                break;
        }
    }while(pilih != 4);
}




