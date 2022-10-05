#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

//deklarasi node untuk menyimpan data warna
struct node{
    char warna[10];
    struct node *next;
    };

//tampilkan semua data warna
void tampilkan(struct node *head){
    struct node *p;
    p = head;
    while(p != NULL){
        printf("%s\n", p->warna);
        p = p->next;
        }
    }

// //create node
// struct node {
//     int data;
//     struct node *next;
// };

// //initialize node
// struct node *generate(int data) {
//     struct node *newNode = (struct node *)malloc(sizeof(struct node));
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }
// //generate random data for node
// int generate_data() {
//     return rand() % 100;
// }

// //insert 5 random data to node
// void insert_data(struct node *head) {
//     int i;
//     for (i = 0; i < 5; i++) {
//         struct node *new_node = generate(generate_data());
//         new_node->next = head->next;
//         head->next = new_node;
//     }
// }

// //print all data in node mark head and tail
// void print_data(struct node *head) {
//     struct node *current = head->next;
//     while (current != NULL) {
//         printf("%d ", current->data);
//         current = current->next;
//     }
//     printf("\n");
// }

// //change last node with user input data
// void change_data(struct node *head) {
//     struct node *current = head->next;
//     while (current->next != NULL) {
//         current = current->next;
//     }
//     printf("Enter new data: ");
//     scanf("%d", &current->data);
// }
// //convert into circular linked list
// void convert_to_circular(struct node *head) {
//     struct node *current = head->next;
//     while (current->next != NULL) {
//         current = current->next;
//     }
//     current->next = head->next;
// }
// //delete head
// void delete_head(struct node *head) {
//     struct node *temp = head->next;
//     head->next = temp->next;
//     free(temp);
// }
// //input data to head
// void insert_head(struct node *head) {
//     struct node *new_node = generate(generate_data());
//     new_node->next = head->next;
//     head->next = new_node;
// }

// //print circular linked list
// void print_circular(struct node *head) {
//     struct node *current = head;
//     do {
//         printf("%d ", current->data);
//         current = current->next;
//     } while (current != head);
//     printf("\n");
// }

// //create linked list
// int main(){
//     struct node *head = generate(0);
//     insert_data(head);
//     // print_data(head);
//     printf("\n===========\n");
//     convert_to_circular(head);
//     printf("Circular Linked List\n");
//     print_circular(head);
//     // printf("Delete First Node\n");
//     // delete_head(head);
//     // print_data(head);
//     // printf("Input new data to head\n");
//     // insert_head(head);
//     // print_data(head);

//     return 0;
// }
