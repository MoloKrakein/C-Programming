// import library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// aplikasi pemetaan

// create graph data structure
struct data
{
    char nama[32];
    int no;
} data[100];

// graph
typedef struct node
{
    int id;
    struct node *next;
} node;

// create undirected graph
typedef struct graph
{
    int n;
    node **adj;
} graph;

// add node
node *add_node(int id)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->id = id;
    new_node->next = NULL;
    return new_node;
}

// add data
void add_data(graph *g, int id, char nama[], int no)
{
    g->adj[id] = add_node(id);
    strcpy(data[id].nama, nama);
}

// add edge
void add_edge(graph *g, int id1, int id2)
{
    node *new_node = add_node(id2);
    new_node->next = g->adj[id1];
    g->adj[id1] = new_node;
}

// build graph
graph *create_graph(int n)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->n = n;
    g->adj = (node **)malloc(n * sizeof(node *));
    for (int i = 0; i < n; i++)
        g->adj[i] = NULL;
    return g;
}

// create connection base on user
void create_connection(graph *g, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                add_edge(g, i, j);
            }
        }
    }
}

// check if nama and id is already exist
int check_exist(graph *g, int n, char nama[], int no)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (strcmp(data[i].nama, nama) == 0 && data[i].no == no)
        {
            return i;
        }
    }
    return -1;
}

// print all data and id
void print_data(graph *g, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d. %s [%d]\n", i + 1, data[i].nama, data[i].no);
    }
}

// find id by name
int find_id(graph *g, char nama[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (strcmp(nama, data[i].nama) == 0)
        {
            return i;
        }
    }
    return -1;
}
// check if already connected or not
int check_connection(graph *g, int id1, int id2)
{
    node *curr = g->adj[id1];
    while (curr != NULL)
    {
        if (curr->id == id2)
        {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}
//find id by no
int find_id_by_no(graph *g, int no, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (data[i].no == no)
        {
            return i;
        }
    }
    return -1;
}

// ask user to connect and ask if want add connection again or not
void ask_connection(graph *g, int n)
{
    int i, j;
    char nama[32];
    // print data
    print_data(g, n);
    printf("Masukkan nama user yang ingin dihubungkan: ");
    scanf("%s", nama);
    i = find_id(g, nama, n);
    if (i == -1)
    {
        printf("User tidak ditemukan\n");
    }
    else
    {
        printf("Masukkan nama user yang ingin dihubungkan: ");
        scanf("%s", nama);
        j = find_id(g, nama, n);

        if (j == -1)
        {
            printf("User tidak ditemukan\n");
        }
        else
        {

            if (check_connection(g, i, j) == 1)
            {
                printf("User sudah terhubung\n");
            }
            else
            {
                //check if name is same, if same, ask the no
                if (strcmp(data[i].nama, data[j].nama) == 0)
                {
                    int temp;
                    printf("Menghubungkan %s [%d] dengan\n", data[i].nama, data[i].no);
                    printf("Masukkan no user yang ingin dihubungkan: ");
                    scanf("%d", &temp);
                    j = find_id_by_no(g, temp, n);
                    if (j == -1)
                    {
                        printf("User tidak ditemukan\n");
                    }
                    else
                    {
                        printf("Menghubungkan %s [%d]...", data[j].nama, data[j].no);
                        add_edge(g, i, j);
                        printf("User berhasil dihubungkan\n");
                    }
                }else{
                    printf("Menghubungkan %s [%d] dengan\n", data[i].nama, data[i].no);
                add_edge(g, i, j);
                printf("User berhasil dihubungkan\n");
                }
            }
        }
    }
    printf("Apakah anda ingin menambah koneksi lagi? (y/n) ");
    char answer;
    scanf("%s", &answer);
    if (answer == 'y')
    {
        system("clear");
        ask_connection(g, n);
    }
}

// input alamat
void input_alamat(graph *g, int n)
{
    int i, j;
    char tempNama[32];
    int tempNo;
    ;
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            printf("Data ke-%d\n", i + 1);
            printf("Masukkan Nama Gedung: \n");
            scanf("%s", data[i].nama);
            printf("Masukkan ID Gedung : \n");
            scanf("%d", &data[i].no);
            system("cls");
        }
        else
        {
        back:
            printf("Data ke-%d\n", i + 1);
            printf("Masukkan Nama Gedung: \n");
            scanf("%s", tempNama);
            printf("Masukkan ID Gedung : \n");
            scanf("%d", &tempNo);
            // check if nama and id is already exist
            j = check_exist(g, n, tempNama, tempNo);
            if (j != -1)
            {
                printf("Data sudah ada !\n");
                system("pause");
                system("cls");
                goto back;
            }
            else
            {
                strcpy(data[i].nama, tempNama);
                data[i].no = tempNo;
                printf("\nBerhasil Ditambahkan !\n");
                system("pause");
            }
            system("cls");
        }
    }
    // clear screen
    system("cls");
    // create connection
    ask_connection(g, n);
}

// ilustrate graph
void illustrate_graph(graph *g, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf(" %s [%d]\n", data[i].nama, data[i].no);
        node *curr = g->adj[i];
        while (curr != NULL)
        {
            printf("\t %s [%d]\n", curr->id + 1, data[curr->id].nama, data[curr->id].no);
            curr = curr->next;
        }
    }
}

// print graph peta alamat
void printGraph(graph *g, int i)
{
    int count = 0;
    node *curr = g->adj[i];
    system("cls");
    printf("================================================\n");
    printf("Gedung %s dengan nomor %d memiliki jalan ke\n", data[i].nama, data[i].no);
    printf("================================================\n");
    printf("No | Nama Gedung        | ID\n");
    printf("================================================\n");
    while (curr != NULL)
    {
        if (curr->id != i)
        {
            printf("%d. | %-15s | %-4d\n", count + 1, data[curr->id].nama, data[curr->id].no);
            curr = curr->next;
        }
        else
        {
            break;
        }
        count++;
    }
    printf("================================================\n");
}
// graph visualizer
void graph_visualizer(graph *g)
{
    int i;
    for (i = 0; i < g->n; i++)
    {
        printGraph(g, i);
        system("pause");
    }
}
//print adjacency list
void print_adj_list(graph *g)
{
    int i;
    for (i = 0; i < g->n; i++)
    {
        printf("%s [%d]\n", data[i].nama, data[i].no);
        node *curr = g->adj[i];
        while (curr != NULL)
        {
            printf("\t %s [%d]\n", curr->id + 1, data[curr->id].nama, data[curr->id].no);
            curr = curr->next;
        }
    }
}

//adjacency matrix
void print_adj_matrix(graph *g)
{
    int i, j;
    for (i = 0; i < g->n; i++)
    {
        printf("%s [%d]\n", data[i].nama, data[i].no);
        for (j = 0; j < g->n; j++)
        {
            if (check_connection(g, i, j) == 1)
            {
                printf("\t %s [%d]\n", data[j].nama, data[j].no);
            }
        }
    }
}

//degree of a node
int degree(graph *g, int i)
{
    int count = 0;
    node *curr = g->adj[i];
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

//menu
void menu(graph *g, int n)
{
    int choice;
    while (1)
    {
        system("cls");
        printf("================================================\n");
        printf("\t\t\tMENU\n");
        printf("================================================\n");
        printf("1. Input Data Gedung\n");
        printf("2. Tampilkan Data Gedung\n");
        printf("3. Tampilkan Grafik Gedung\n");
        printf("4. Tampilkan Grafik Gedung dengan adjacency list\n");
        printf("5. Tampilkan Grafik Gedung dengan adjacency matrix\n");
        printf("6. Tampilkan Grafik Gedung dengan adjacency list dan adjacency matrix\n");
        printf("7. Keluar\n");
        printf("================================================\n");
        printf("Masukkan Pilihan Anda: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            input_alamat(g, n);
            break;
        case 2:
            system("cls");
            printf("================================================\n");
            printf("\t\t\tDATA GEDUNG\n");
            printf("================================================\n");
            printf("No | Nama Gedung        | ID\n");
            printf("================================================\n");
            int i;
            for (i = 0; i < n; i++)
            {
                printf("%d. | %-15s | %-4d\n", i + 1, data[i].nama, data[i].no);
            }
            printf("================================================\n");
            system("pause");
            break;
        case 3:
            system("cls");
            printf("================================================\n");
            printf("\t\t\tGRAFIK GEDUNG\n");
            printf("================================================\n");
            graph_visualizer(g);
            printf("================================================\n");
            system("pause");
            break;
        case 4:
        // adj list
            system("cls");
            printf("================================================\n");
            printf("\t\t\tGRAFIK GEDUNG\n");
            printf("================================================\n");
            print_adj_list(g);
            printf("================================================\n");
            system("pause");
            break;
        case 5:
        // adj matrix
            system("cls");
            printf("================================================\n");
            printf("\t\t\tGRAFIK GEDUNG\n");
            printf("================================================\n");
            print_adj_matrix(g);
            printf("================================================\n");
            system("pause");
            break;
        case 6:
        // adj list & adj matrix
            system("cls");
            printf("================================================\n");
            printf("\t\t\tGRAFIK GEDUNG\n");
            printf("================================================\n");
            print_adj_list(g);
            printf("================================================\n");
            print_adj_matrix(g);
            printf("================================================\n");
            system("pause");
            break;
        case 7:
            return;
        default:
            printf("Pilihan tidak ada\n");
            system("pause");
            break;
        }
    }
}


int main()
{
    printf("Aplikasi Koneksi Internet Gedung\n");
    printf("================================================\n");
    printf("Masukkan jumlah gedung: ");
    int n;
    scanf("%d", &n);
    graph *g = createGraph(n);
    menu(g, n);
    return 0;
}
