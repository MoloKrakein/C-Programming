#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node* pushHead(struct Node *head, int newData)
{
	if(head == NULL)
	{
		head = (struct Node*)malloc(sizeof(struct Node));
		head->data = newData;
		head->next = NULL; 
	}
	else
	{
		struct Node *newNode = NULL;
		newNode = (struct Node*)malloc(sizeof(struct Node));
		
		newNode->data = newData;
		newNode->next = head;
		
		head = newNode;
	}
	return head;
}

struct Node* popTail(struct Node *head)
{
	struct Node *ptr, *preptr;
	
//	ptr = head;
//	preptr = head;
//	
//	while(ptr->next != NULL)
//		ptr = ptr->next;
//	
//	while(preptr->next != ptr)
//		preptr = preptr->next;
//	
//	printf("data deleted: %d", ptr->data);
//	free(ptr);
//	preptr->next = NULL;
	
	ptr = head;
	
	while(ptr->next->next != NULL)
		ptr = ptr->next;
	
	printf("data deleted: %d", ptr->next->data);
	free(ptr->next);
	ptr->next = NULL;	
	
	return head;
}

void viewData(struct Node *head)
{
	struct Node *ptr;
	ptr = head;
	
	if(ptr == NULL)
	{
		printf("No Data Here!\n");
	}
	
	while(ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	
}

int main()
{
	struct Node *head = NULL;
//	head = (struct Node*)malloc(sizeof(struct Node));
//	head->next = NULL
	
	int menu;
	do
	{
		system("cls");
		printf("1. push data\n");
		printf("2. pop data\n");
		printf("3. view data\n");
		printf("4. exit\n");
		scanf("%d",&menu);
		
		switch(menu)
		{
			case 1:{
				int newData;
				printf("Masukan data : ");
				scanf("%d",&newData);
				
				head = pushHead(head, newData);
				getch();
				break;
			}
			case 2:{
				popTail(head);
				getch();
				break;
			}
			case 3:{
				viewData(head);
				getch();
				break;
			}
		}
		
	}while(menu != 4);
	return 0;
}



