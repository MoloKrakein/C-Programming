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
		printf("\nNo | Kegiatan       | Hari   |\n");
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

struct Node* insertAtEnd(struct Node *head, char* newData)
{
    if (head == NULL)
    {
        head = (struct Node*)malloc(sizeof(struct Node));

        strcpy(head->name, newData);
		head->next = NULL; //Ganti
        head = newData;
    }

    else
    {
        struct Node *temp, *first;
        temp = malloc(sizeof(struct Node));
        
        temp->next = 0;

        strcpy(temp->name, newData);
        first = head;
        while (head->next != NULL) 
        {
            head = head->next;
        }
        head->next = temp;
    }
    return head;
}

struct Node2* insertAtEndtime(struct Node2 *head, char* newData)
{
    if (head == NULL)
    {
        head = (struct Node2*)malloc(sizeof(struct Node));

        strcpy(head->time, newData);
		head->next = NULL; 
        head = newData;
    }

    else
    {
        struct Node2 *temp, *first;
        temp = malloc(sizeof(struct Node));
        
        temp->next = 0;

        strcpy(temp->time, newData);
        first = head;
        while (head->next != NULL) {
            head = head->next;
        }
        head->next = temp;
    }
    return head;
}

void delete_first_node(struct Node *head) {
  struct Node *tmp;
  
  if(head == NULL || head == NULL) return;
 
  tmp = head;  
 
  head = head->next;
 
  free(tmp);
}

void delete_first_node_time(struct Node2 *head) {
  struct Node2 *tmp;

  if(head == NULL || head == NULL) return;

  tmp = head;

  head = head->next;
  
  free(tmp);
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
		printf("3. push data in certain position\n");
		printf("4. Delete last\n");
		printf("5. Delete data in certain position\n");
		printf("6. Push last\n");
		printf("7. Delete front\n");
		scanf("%d",&menu);
		
		switch(menu)
		{
			case 1:{
				char newData[100];
				char waktu[100];

				printf("Masukan nama kegiatan : ");
				scanf(" %[^\n]s", newData);
				head = pushHead(head, newData);

				printf("Masukan hari : ");
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
				char newData[100];
				char waktu[100];
				int posisi;

				printf("Masukan nama kegiatan : ");
				scanf(" %[^\n]s", newData);

				printf("Masukan hari : ");
				scanf("%s",waktu);

				printf("Ingin dimasukan setelah data ke = ");
				scanf("%d",&posisi);

				insertAfterNthNode(posisi,newData,head);
				insertAfterNthNodeTime(posisi,waktu,head2);

				printf("\n");

				getch();
				break;
			}
			case 4:
			{
				deleteEnd(head);
				deleteEndTime(head2);
				printf("\n");
				getch();
				break;
			}
			case 5:
			{
				int posisi;
				printf("Posisi yang ingin dihapus :");
				scanf("%d",&posisi);
				deletePosition(head, posisi);
				deletePositionTime(head2, posisi);
				printf("\n");

				getch();
				break;
			}
			case 6:
			{
				char newData[100];
				char waktu[100];

				printf("Masukan nama kegiatan : ");
				scanf(" %[^\n]s", newData);
                hari:
                printf("Masukan hari : ");
				scanf("%s",waktu);

				if (head == NULL)
				{
					head = insertAtEnd(head, newData);
					head2 = insertAtEndtime(head2, waktu);
				}
				else{
				insertAtEnd(head, newData);
				insertAtEndtime(head2, waktu);
				}

				printf("\n");

				getch();
				break;

			}
			case 7:
			{
				delete_first_node(head);
				delete_first_node_time(head2);
                
                head=head->next;
                head2=head2->next;
				printf("\n");	
				getch();
				break;
			}
		}
		
	}while(menu != 8);
	return 0;
}