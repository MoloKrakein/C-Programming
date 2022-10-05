#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/*
Renardo : : Add Data + Inorder
Joshua : : delete Data + Post order
Athaillah : : visualisasi + pre order
*/

struct Node{
    int data;
    char string[100];
    struct Node *left, *right;
};


struct Node* newNode(int data, char string[100]){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    strcpy(node->string, string);
    node->left = NULL;
    node->right = NULL;
    return node;
}


struct Node* addNode(struct Node *root, int data, char string[100]){
    if(root == NULL){
        root = newNode(data, string);
    }else{
        if(data < root->data){
            root->left = addNode(root->left, data, string);
        }else{
            root->right = addNode(root->right, data, string);
        }
    }
    return root;
}


void inOrder(struct Node *node){
    if(node != NULL){
        inOrder(node->left);
        printf("%s \t\t %d \n", node->string, node->data);
        inOrder(node->right);
    }
}


void postOrder(struct Node *node){
    if(node != NULL){
        postOrder(node->left);
        postOrder(node->right);
        printf("%s \t\t %d \n", node->string, node->data);
    }
}


void preOrder(struct Node *node){
    if(node != NULL){
        printf("%s \t\t %d \n", node->string, node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}


struct Node* delNode(struct Node *root, struct Node *parent, int data){
    if(root == NULL){
        printf("ID tidak ditemukan");
    }else{
        if(data < root->data){
            root->left = delNode(root->left, root, data);
        }else if(data > root->data){
            root->right = delNode(root->right, root, data);
        }else{
            if(root->left == NULL && root->right == NULL){
                if(parent->left == root){
                    parent->left = NULL;
                }else{
                    parent->right = NULL;
                }
                free(root);
            }else if(root->left == NULL){
                if(parent->left == root){
                    parent->left = root->right;
                }else{
                    parent->right = root->right;
                }
                free(root);
            }else if(root->right == NULL){
                if(parent->left == root){
                    parent->left = root->left;
                }else{
                    parent->right = root->left;
                }
                free(root);
            }else{
                struct Node *temp = root->right;
                while(temp->left != NULL){
                    temp = temp->left;
                }
                root->data = temp->data;
                strcpy(root->string, temp->string);
                root->right = delNode(root->right, root, temp->data);
            }
        }
    }
    return root;
}

// void visualize(struct Node *root){
//     if(root != NULL){
//         printf(" %s ", root->string);
//         if(root->left != NULL){
//             printf("-> %s ", root->left->string);
//         }
//         if(root->right != NULL){
//             printf("-> %s ", root->right->string);
//         }
//         printf("\n");
//         visualize(root->left);
//         visualize(root->right);
//     }
// }

void visualize(struct Node *root){
    if(root != NULL){
        printf(" %s ", root->string);
        if(root->left != NULL){
            printf("-> %s ", root->left->string);
        }
        if(root->right != NULL){
            printf("-> %s ", root->right->string);
        }
        printf("\n");
        visualize(root->left);
        visualize(root->right);
    }
}

void printTree(struct Node *root, int space)
{
    if(root == NULL)
        return;
    
    space += 5;
    
    printTree(root->right, space);
    
    printf("\n");
    for(int i = 5; i < space; i++)
        printf("-");
    printf("[ %s - %d ]\n", root->string, root->data);

    printTree(root->left, space);
}

int checkID(struct Node *root, int data){
    if(root == NULL){
        return 0;
    }else{
        if(data == root->data){
            return 1;
        }else{
            if(data < root->data){
                return checkID(root->left, data);
            }else{
                return checkID(root->right, data);
            }
        }
    }
}

//main
int main(){
    struct Node *root = NULL;
    int data;
    char string[100];
    int pilihan;
    int pilihantampil;
    do{
        printf("\n");
        printf("1. Tambah Buku\n");
        printf("2. Tampilkan Data Buku\n");
        printf("3. Delete Node\n");
        printf("4. Visualize\n");
        printf("5. Exit\n");
        printf("\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);
        switch(pilihan){
            case 1:
                tambah:
                printf("\n");
                printf("Masukkan ID Buku : ");
                scanf("%d", &data);
                if(checkID(root, data) == 1){
                    printf("ID sudah ada\n");
                    goto tambah;
                }
                printf("Masukkan Judul Buku : ");
                scanf("%s", string);
                root = addNode(root, data, string);
                break;
            case 2:
                printf("\n");
                printf("1. InOrder\n");
                printf("2. PreOrder\n");
                printf("3. PostOrder\n");
                printf("Pilihan : ");
                scanf("%d", &pilihantampil);
                switch(pilihantampil){
                    case 1:
                        printf("InOrder\n");
                        printf("\nNama Buku \t ID\n");
                        printf("\n");
                        inOrder(root);
                        break;
                    case 2:
                        printf("PreOrder\n");
                        printf("\nNama Buku \t ID\n");
                        printf("\n");
                        preOrder(root);
                        break;
                    case 3:
                        printf("PostOrder\n");
                        printf("\nNama Buku \t ID\n");
                        printf("\n");
                        postOrder(root);
                        break;
                    default:
                        printf("\n");
                        printf("Pilihan tidak ada\n");
                        printf("\n");
                        break;
                }
                break;
            case 3:
                printf("ID : ");
                scanf("%d", &data);
                delNode(root, NULL, data);
                break;
            case 4:
                // visualize(root);
                printTree(root, 0);
                break;
            case 5:
                break;
            default:
                printf("Pilihan tidak ada\n");
        }
    }while(pilihan != 7);
    return 0;
}