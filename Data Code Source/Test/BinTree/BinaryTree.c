#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


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


void inOrder(struct Node *node)
{
    
	if(node != NULL)
	{
		inOrder(node->left);
		printf("%s \t %d \n", node->string, node->data);
		inOrder(node->right);
	}

}

void postOrder(struct Node *node)
{
    
	if(node != NULL)
	{
		postOrder(node->left);
		postOrder(node->right);
		printf("%s \t %d \n", node->string, node->data);
	}

}

void preOrder(struct Node *node)
{
    
	if(node != NULL)
	{
		printf("%s \t %d \n", node->string, node->data);
		preOrder(node->left);
		preOrder(node->right);
	}

}

struct Node *newNode(int data, char string[100]) 
{
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	
	node->data = data;
	strcpy(node->string, string);
	
	node->left = NULL;
	node->right = NULL;
	
	printf("Data berhasil di tambah");
	
	return node;	
}

int isEmpty(struct Node *root)
{
    if(root == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *addNode(struct Node *root, int data, char string[100], int maxHeight)
{
	if(root == NULL)
	{
		root =  newNode(data, string);
	}
	else
	{
		struct Node *temp, *preTemp; 
		int height = 1;
		int pilihLR;
		temp = root;
		
		while(temp != NULL)
		{
			if(height >= maxHeight)
			{
				printf("Data penuh");
				return root;
			}
			printf("1. Kiri\n");
			printf("2. Kanan\n");
			
			printf("Ditambah di mana-nya data %s - %d?\n", temp->string, temp->data);
			scanf("%d", &pilihLR);
			
			switch(pilihLR)
			{
				case 1:{
					preTemp = temp;
					temp = temp->left;
					if(temp == NULL)
					{
						preTemp->left = newNode(data, string);
					}
					height++;
					break;
				}
				case 2:{
					preTemp = temp;
					temp = temp->right;
					if(temp == NULL)
					{
						preTemp->right = newNode(data, string);
					}
					height++;
					break;
				}
				default:{
					printf("Salah Input!\n");
					break;
				}
			}
		}
	}
	return root;
}


struct Node *delAll(struct Node *node)
{
	if(node != NULL)
	{
		delAll(node->left);
		delAll(node->right);
		free(node);
		return NULL;
	}
}


struct Node *delNode(struct Node *temp, struct Node *preTemp, int data)
{
	if(temp != NULL)
	{
		if(temp->data == data)
		{
			if(preTemp == temp)
				preTemp = delAll(temp);
			else if(preTemp->left->data == temp->data)
				preTemp->left = delAll(temp);
			else
				preTemp->right = delAll(temp);
			printf("Data berhasil di hapus");
		}
		else
		{
			delNode(temp->left, temp, data);
			delNode(temp->right, temp, data);
		}
	}
	return preTemp;
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

//print root
void printRoot(struct Node *root)
{
    if(root != NULL)
    {
        printf("%s - %d \n", root->string, root->data);
    }
}

int main()
{
	struct Node *root;
	root = NULL;
	
	int maxHeight = 4;
	
	int menu;
	do
	{			
		system("cls");
        printf("Aplikasi Data Usia\n");
		printf("1. Tambah data\n");
		printf("2. Hapus data\n");
		printf("3. view data\n");
		printf("4. Visualisasi\n");
        printf("5. Exit\n");
		scanf("%d",&menu);
		
		switch(menu)
		{
			case 1:{
				int newData;
				char newString[100];
				
				printf("Masukan data\n");
				printf("Nama : ");
				scanf("%s",&newString);
				printf("Umur : ");
				scanf("%d",&newData);
				
				root = addNode(root, newData, newString, maxHeight);
				
				getch();
				break;
			}
			case 2:{
         
                if(isEmpty(root))
                {
                    printf("Binary kosong");
                }
                else
                {
                    int data;
                    printf("Masukan data yang akan di hapus\n");
                    printf("Data : ");
                    scanf("%d",&data);
                    if(isEmpty(root))
                    {
                        printf("Data tidak ditemukan");
                    }
                    else
                    {
                        root = delNode(root, root, data);
                    }
                }
			}
			case 3:{
				if(isEmpty(root))
                {
                    printf("Binary kosong");
                }
                else
                {
                    int pil;
                    printf("Pilih Urutan\n");
                    printf("1. InOrder\n");
                    printf("2. PreOrder\n");
                    printf("3. PostOrder\n");
                    printf("4. Cancel\n");
                    scanf("%d",&pil);
                    switch(pil)
                    {
                        case 1:{
                            inOrder(root);
                            break;
                        }
                        case 2:{
                            preOrder(root);
                            break;
                        }
                        case 3:{
                            postOrder(root);
                            break;
                        }
                        case 4:{
                            break;
                        }
                        default:{
                            printf("Salah Input");
                            break;
                        }
                    }
                }
                getch();
                break;
			} case 4: {
                if(isEmpty(root))
                {
                    printf("Binary kosong");
                    getch();
                }
                else
                {
                printf("Tree Dicetak Dari Kiri ke kanan!\n");
                printf("Root : ");
                printRoot(root);
                printTree(root, 0);
                getch();
                break;
                }
            }
		}
		
	}while(menu != 5);
	return 0;
}