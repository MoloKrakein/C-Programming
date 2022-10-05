#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(struct node *head)
{
    struct node *node, *ptr;
    int angka;

    printf("\nKetika masuin angka \"-1\" = keluar\n");
    printf("Masukkan angka : "); 
    scanf("%d", &angka);
    while (angka != -1)
    {
        node = (struct node *)malloc(sizeof(struct node));
        node->data = angka;
        if (head == NULL)
        {
            node->next = NULL;
            head = node;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = node;
            node->next = NULL;
        }
        printf("Masukkan angka : ");
        scanf("%d", &angka);
    }
    printf("\n\nAngka Telah masuk dalam node!!!\n\n");
    return head;
}

struct node *buatNodeDiawal(struct node *head)
{
    int angka;
    struct node *nodeBaru, *ptr;
    nodeBaru = (struct node *)malloc(sizeof(struct node));

    printf("Masukkan angka (ditambah diawal): ");
    scanf("%d", &angka);
    if (head != NULL)
    {
        ptr = head;
        nodeBaru->next = ptr;
        nodeBaru->data = angka;
        head = nodeBaru;
    }
    else
    {
        printf("\nMaaf, anda belum memasukkan data.\n");
    }
    return head;
}
struct node *buatNodeDiantara(struct node *head)
{
    int angka, num;
    struct node *ptr, *Node, *temp;
    Node = (struct node *)malloc(sizeof(struct node));

    printf("\nSetelah angka berapa (setelahnya akan ditambahkan node): ");
    scanf("%d", &angka);
    printf("\nMasukkan angka yang ingin ditambahkan : ");
    scanf("%d", &num);

    if (head != NULL)
    {
        ptr = head;
        while (ptr != NULL)
        {
            if (ptr->data == angka)
            {
                temp = ptr->next;
                ptr->next = Node;
                Node->data = num;
                Node->next = temp;
            }
            ptr = ptr->next;
        }
        if (Node->data == 0)
        {
            printf("Maaf, angka %d tidak ada dalam node.\n", angka);
        }
        else
        {
            printf("\nAngka %d telah masuk setelah angka %d\n", angka, num);
        }
    }
    else
    {
        printf("\nMaaf, anda belum memasukkan angka.\n");
    }
    return head;
}

void displayNode(struct node *head)
{
    struct node *ptr;
    int c = 0;
    ptr = head;
    while (ptr != NULL)
    {
        c++;
        printf("Node %d : %d\n", c, ptr->data);
        ptr = ptr->next;
    }
}

struct node *deleteNode(struct node *head)
{
    int angka;
    struct node *ptr, *preptr;

    printf("\nMasukkan angka untuk dihapus : ");
    scanf("%d", &angka);
    if (head != NULL)
    {
        ptr = head;
        preptr = head;

        if (head->data == angka)
        {
            ptr = ptr->next;
            head->data = ptr->data;
            head->next = ptr->next;
            goto end;
        }

        while (ptr->next != NULL)
        {
            if (ptr->data == angka)
            {
                preptr = ptr;
                ptr = ptr->next;
                preptr->data = ptr->data;
                preptr->next = ptr->next;
                goto end;
            }
            preptr = ptr;
            ptr = ptr->next;
        }
        if (ptr->next == NULL)
        {
            preptr->next = NULL;
            goto end;
        }
        printf("\nMaaf, angka yang anda masukkan tidak ditemukan.\n");
        goto endd;
    end:
        printf("\nAngka %d dalam node telah dihapus.\n", angka);
    endd:
        free(ptr);
        return head;
    }
    else
    {
        printf("\nMaaf, anda belum menambahkan Node\n");
    }
    return head;
}

struct node *buatNode(struct node *head)
{
    int pilih;
    awalBuatNode:
    printf("===== Menu Create Node =====\n");
    printf("1. Isi data dalam node\n");
    printf("2. Buat Node diawal\n");
    printf("3. Buat Node diantara Node\n");
    printf("4. Buat Node diakhir\n");
    printf("5. Kembali\n");
    printf("Pilih : "); scanf("%d", &pilih);
    switch (pilih)
    {
    case 1:
        head = createNode(head);
        goto awalBuatNode;
        break;
    case 2:
        head = buatNodeDiawal(head);
        goto awalBuatNode;
        break;
    case 3:
        head = buatNodeDiantara(head);
        goto awalBuatNode;
        break;
    case 4:
        head = createNode(head);
        goto awalBuatNode;
        break;
    case 5:
        break;
    
    default:
        break;
    }
    return head;
}

struct node *hapusNode(struct node *head)
{

}
int main()
{
   
    struct node *head = NULL;
    int pilih;
    char enter;

awal:
 system("clear");
    printf("======== M A I N   M E N U =========\n");
    printf("1. Create Node\n");
    printf("2. Display Node\n");
    printf("3. Delete Node\n");
    printf("4. Keluar\n");
    printf("\nPilih : ");
    scanf("%d", &pilih);
    switch (pilih)
    {
    case 1:
        printf("\n");
        head = buatNode(head);
        goto awal;
        break;
    case 2:
        printf("\n");
        displayNode(head);
        printf("\n");
        getchar();
        printf("\nKlik \"enter\" to main menu :"); scanf("%c", &enter);
        goto awal;
        break;
    case 3:
        printf("\n");
        head = deleteNode(head);
        printf("\n");
        getchar();
        printf("\nKlik \"enter\" to main menu :"); scanf("%c", &enter);
        goto awal;
        break;
    case 4:
        break;

    default:
        break;
    }
}
//create function for create 
