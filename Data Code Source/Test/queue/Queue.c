#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int *data;
    int front;
    int rear;
    int size;
} queue;

queue *createQueue(int size)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->data = (int *)malloc(size * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = size;
    return q;
}

void enqueue(queue *q, int data)
{
    if (q->rear == q->size - 1)
    {
        printf("\n[!] Sorry Queue is full please deaqueue\n");

        printf("\nPress \"Enter\" to continue...");
        char enter;
        scanf("%c", &enter);
        getchar();
        return;
    }
    q->rear++;
    q->data[q->rear] = data;
}

int dequeue(queue *q)
{
    if (q->front == q->rear + 1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    q->front++;
    return q->data[q->front - 1];
}

void printQueue(queue *q)
{

    if (q->front == q->rear + 1)
    {
        printf("Queue is empty\n\n");
        return;
    }
    printf("+----+-------------------+-----------------+---------+\n");
    printf("| No |      Atribute     |    Atribute 2   |  Queue  |\n");
    printf("+----+-------------------+-----------------+---------+\n");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("| %-2d |      Testing%-2d    |   Unkhown%-4d   |  %-5d  |\n", i + 1, i + 1, i + 1, q->data[i]);
    }
    printf("+----+-------------------+-----------------+---------+\n");
    printf("\n");
}

void deleteQueue(queue *q)
{
    int len, choice;

    printf("\nDo you want to delete the queue?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        free(q->data);
        free(q);

        printf("\nSuccessfully deleted the queue\n");
        int pilih;

        printf("\nEnter the length of the new queue : ");
        scanf("%d", &len);
        createQueue(len);
    }
    else
    {
        printf("\nPress \"Enter\" to continue...");
        char enter;
        scanf("%c", &enter);
        getchar();
    }
}

int main(int argc, char const *argv[])
{
    queue *q;

    int pilih;
    int data;
    system("cls");
    printf("Input Max Size Queue : ");
    scanf("%d", &data);
    q = createQueue(data);
    system("cls");
    printQueue(q);
    printf("Menu Queue : \n");
    printf("[1] Enqueue\n");
    printf("[2] Dequeue\n");
    printf("[3] Delete Queue\n");
    printf("[4] Exit\n");
    printf("Choice Menu : ");
    scanf("%d", &pilih);

    do
    {
        switch (pilih)
        {
        case 1:
            printf("Input Data : ");
            scanf("%d", &data);
            enqueue(q, data);
            break;
        case 2:
            data = dequeue(q);
            if (data != -1)
                printf("Data yang dihapus : %d\n", data);
            break;
        case 3:
            deleteQueue(q);
            break;
        case 4:
            printf("Exit\n");
            break;
        default:
            printf("Pilihan tidak ada\n");
            break;
        }
        system("cls");
        printQueue(q);
        printf("Menu Queue : \n");
        printf("[1] Enqueue\n");
        printf("[2] Dequeue\n");
        printf("[3] Delete Queue\n");
        printf("[4] Exit\n");
        printf("Choice Menu : ");
        scanf("%d", &pilih);
    } while (pilih != 4);

    return 0;
}