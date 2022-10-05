#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
};

// Persis seperti Single Linked List (Non Circular)
void viewData(struct Node *head)
{
	struct Node *ptr;
	ptr = head;
	
	if(head == NULL)
		printf("No Data");
	else
	{
		while(ptr != NULL)
		{
			printf("%d ", ptr->data);
			ptr = ptr->next;
		}
	}
	
}

struct Node *pushHead(struct Node *head, int newData)
{
	if(head == NULL)
	{
		head = (struct Node*)malloc(sizeof(struct Node));
		head->data = newData;
		head->next = NULL;
		head->prev = NULL;
	}
	else
	{
		struct Node *newNode;
		newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = newData;
		
		head->prev = newNode;
		newNode->next = head;
		newNode->prev = NULL;
		
		head = newNode;
	}
	
	return head;
}

struct Node *popTail(struct Node *head, struct Node *tail)
{
	if(head == NULL)
		printf("No Data");
	else if(head == tail)
	{
		printf("data %d dihapus", head->data);
		free(head);
		head = NULL;
	}
	else
	{
		struct Node *temp;
		temp = tail;
		tail = temp->prev;
		tail->next = NULL;
		printf("data %d dihapus", temp->data);
		free(temp);		
	}
	
	return head;
}

int main()
{
	struct Node *head = NULL;
	struct Node *tail = NULL;
	
	int menu;
	do
	{
		tail = head;
		if(head != NULL)
			while(tail->next != NULL)
				tail = tail->next;
				
		system("cls");
		printf("1. push head data\n");
		printf("2. pop tail data\n");
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
				head = popTail(head, tail);
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

