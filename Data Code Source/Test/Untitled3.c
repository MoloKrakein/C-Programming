#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct Node//kegiatan
{
char name[256];
struct Node* next;
};

struct Node2//waktu
{
char time[256];
struct Node2* next;
};

struct Node* pushHead(struct Node *head, char* newData)//kegiatan
{
	if(head == NULL)
	{
		head = (struct Node*)malloc(sizeof(struct Node));

		strcpy(head->name, newData);
		head->next = NULL; 
	}
	else
	{
		struct Node *newNode = NULL;
		newNode = (struct Node*)malloc(sizeof(struct Node));

		strcpy(newNode->name, newData);
		newNode->next = head;
		
		head = newNode;
	}
	return head;
}

struct Node2* pushHeadtime(struct Node2 *head, char* newData)//waktu
{
	if(head == NULL)
	{
		head = (struct Node2*)malloc(sizeof(struct Node2));

		strcpy(head->time, newData);
		head->next = NULL; 
	}
	else
	{
		struct Node2 *newNode2 = NULL;
		newNode2 = (struct Node2*)malloc(sizeof(struct Node2));

		strcpy(newNode2->time, newData);
		newNode2->next = head;
		
		head = newNode2;
	}
	return head;
}

void pushTail(char name[256]){
	struct Node *head, *temp;
	
}

// struct Node* pushTail(struct Node *head,char* name) //Push kegiatan
// {
//     struct Node *new, *temp;
//     new =(struct Node*)malloc(sizeof(struct Node));
//     if (new == NULL)
//     {
//       printf("\n Out of memory\n");
//     }
//     else
//     {
//         strcpy(new->name, name);
//         new->next = NULL;

//         temp = head;

//         while (temp != NULL && temp->next != NULL)
//         {
//             temp = temp->next;
//         }
//         temp->next = new;
//         printf("Data Successfully Added\n");
//     }
// }
// struct Node2* pushTailTime(struct Node2 *head,char* time) //Push waktu
// {
//     struct Node2 *new, *temp;
//     new =(struct Node2*)malloc(sizeof(struct Node2));
//     if (new == NULL)
//     {
//       printf("\n Out of memory\n");
//     }
//     else
//     {
//         strcpy(new->time, time);
//         new->next = NULL;

//         temp = head;

//         while (temp != NULL && temp->next != NULL)
//         {
//             temp = temp->next;
//         }
//         temp->next = new;
//         printf("Data Successfully Added\n");
//     }
// }

void viewData(struct Node *head, struct Node2 *head2)
{
	struct Node *ptr;
	struct Node2 *ptr2;
	int i=1;
	ptr = head;
	ptr2 = head2;

	if(ptr == NULL && ptr2 == NULL)
	{
		printf("Tak ada data\n");
	}
	else
	{
		printf("\nNo | Kegiatan       | Waktu   |\n");
    	printf("===============================\n");
	}
	while(ptr != NULL && ptr2!=NULL)
	{
		
		printf("%-2d |%-15s | %-8s|\n", i, ptr->name, ptr2->time);
		ptr = ptr->next;
		ptr2 = ptr2->next;
		i++;
	}
}

int getCurrSize(struct Node *node){
    int size=0;

    while(node!=NULL){
        node = node->next;
        size++;
    }
    return size;
}


struct Node* insertAfterNthNode(int n, char* data, struct Node* head)
{
    int size = getCurrSize(head);

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); 

    strcpy(newNode->name, data);
    newNode->next = NULL;
    
    if(n < 0 || n > size) 
        printf("Invalid position to insert\n"); 
        
    else if(n == 0){

        newNode->next = head; 
        head = newNode;
    }
    
    else 
    {

        struct Node* temp = head; 
        
        
        while(--n)
            temp=temp->next;
        
       
        newNode->next= temp->next;
       
        temp->next = newNode;
        
    }
}

int getCurrSize2(struct Node2 *node){
    int size=0;

    while(node!=NULL){
        node = node->next;
        size++;
    }
    return size;
}


struct Node2* insertAfterNthNodeTime(int n, char* data, struct Node2* head)
{
    int size = getCurrSize2(head);

    struct Node2* newNode = (struct Node2*) malloc(sizeof(struct Node2)); 

    strcpy(newNode->time, data);
    newNode->next = NULL;
    
    if(n < 0 || n > size) 
        printf("Invalid position to insert\n"); 
        
    else if(n == 0){

        newNode->next = head; 
        head = newNode;
    }
    
    else 
    {

        struct Node2* temp = head; 
        
        
        while(--n)
            temp=temp->next;
        
       
        newNode->next= temp->next;
       
        temp->next = newNode;
        
    }
}

void deleteEnd(struct Node *head)
{
    struct Node *temp, *prevnode;
    if (head == NULL)
        printf("\nList is Empty\n");
    else {
        temp = head;
        while (temp->next != 0) {
            prevnode = temp;
            temp = temp->next;
        }
        free(temp);
        prevnode->next = 0;
    }
}

void popHead(struct Node **head,struct Node2 **head2) //Dua Duanya I guess
{
    struct Node *toDelete;
    struct Node2 *toDelete2;

	if (head == NULL && head2 == NULL || *head == NULL && *head2 == NULL)
	{
		printf("List is already empty.");
	}
	else
	{
	toDelete=*head;
	toDelete2=*head2;

	*head = (*head)->next;
	*head2 = (*head2)->next;
	free(toDelete);
	free(toDelete2);
	}
}


void deleteEndTime(struct Node2 *head)
{
    struct Node2 *temp, *prevnode;
    if (head == NULL)
        printf("\nList is Empty\n");
    else {
        temp = head;
        while (temp->next != 0) {
            prevnode = temp;
            temp = temp->next;
        }
        free(temp);
        prevnode->next = 0;
    }
}

void deletePosition(struct Node *head,int pos)
{
    struct Node *temp, *position;
    int i = 1;
    if (head == NULL)
        printf("\nList is empty\n");
    else {
        position = malloc(sizeof(struct Node));
        temp = head;

        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }

        position = temp->next;
        temp->next = position->next;

        free(position);
    }
}

void deletePositionTime(struct Node2 *head,int pos)
{
    struct Node2 *temp, *position;
    int i = 1;
    if (head == NULL)
        printf("\nList is empty\n");
    else {
        position = malloc(sizeof(struct Node2));
        temp = head;

        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }

        position = temp->next;
        temp->next = position->next;

        free(position);
    }
}

int main()
{
	struct Node *head = NULL;
	struct Node2 *head2 = NULL;

	int menu;
	do
	{
		//system("cls");
		printf("1. push data\n");
		printf("2. view data\n");
		printf("3. push last data\n");
		printf("4. push data in certain position\n");
		printf("5. Delete last\n");
		printf("6. delete first data\n");
		printf("7. Delete data in certain position\n");
		scanf("%d",&menu);
		
		switch(menu)
		{
			case 1:{
				char newData[100];
				char waktu[100];

				printf("Masukan nama kegiatan : ");
				scanf("%s",newData);
				head = pushHead(head, newData);

				printf("Masukan waktu : ");
				scanf("%s",waktu);
				head2 = pushHeadtime(head2, waktu);

				getch();
				break;
			}
			case 2:{
				viewData(head,head2);
                printf("\n");
				getch();
				break;
			}
			case 3:{
				char name[100];
				char time[100];

				printf("Masukan nama kegiatan : ");
				scanf("%s",name);
				head = pushTail(head, name);

				printf("Masukan waktu : ");
				scanf("%s",time);
				head2 = pushTailTime(head2, time);

				getch();
				break;
			}

			case 4:{
				char newData[100];
				char waktu[100];
				int posisi;

				printf("Masukan nama kegiatan : ");
				scanf("%s",newData);

				printf("Masukan waktu : ");
				scanf("%s",waktu);

				printf("Ingin dimasukan setelah data ke = ");
				scanf("%d",&posisi);

				insertAfterNthNode(posisi,newData,head);
				insertAfterNthNodeTime(posisi,waktu,head2);

				getch();
				break;
			}
			case 5:
			{
				deleteEnd(head);
				deleteEndTime(head2);
				getch();
				break;
			}
			case 6: {
				popHead(&head,&head2);
				getch();
				break;
			}
			case 7:
			{
				int posisi;
				printf("Posisi yang ingin dihapus :");
				scanf("%d",&posisi);
				deletePosition(head, posisi);
				deletePositionTime(head2, posisi);
				break;
			}
		}
		
	}while(menu != 8);
	return 0;
}