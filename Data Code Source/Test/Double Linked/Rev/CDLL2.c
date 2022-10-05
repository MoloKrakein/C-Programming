#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
};

// Persis seperti Single Linked List (Circular)
void viewData(struct Node *head)
{
	struct Node *ptr;
	ptr = head;
	
	if(head == NULL)
		printf("No Data");
	else
	{
		do
		{
			printf("%d ", ptr->data);
			ptr = ptr->next;
		}while(ptr != head);
	}
	
}

struct Node *pushTail(struct Node *head, struct Node *tail, int newData)
{
	if(head == NULL)
	{
		head = (struct Node*)malloc(sizeof(struct Node));
		head->data = newData;
		head->next = head;
		head->prev = head;
	}
	else
	{
		struct Node *newNode;
		newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = newData;
		
		tail->next = newNode;
		head->prev = newNode;
		newNode->prev = tail;
		newNode->next = head;
		
//		tail = newNode;
	}
	printf("Data sudah ditambahkan");
	return head;
}

struct Node *popHead(struct Node *head, struct Node *tail)
{
	if(head == NULL)
		printf("No Data");
	else if(head == tail)
	{
		printf("Data %d dihapus", head->data);
		free(head);
		head = NULL;
	}
	else
	{
		struct Node *temp;
		temp = head;
		head = temp->next;
		
		tail->next = temp->next;
		head->prev = temp->prev;
		
		printf("Data %d dihapus", temp->data);
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
			tail = head->prev;
				
		system("cls");
		printf("1. push tail data\n");
		printf("2. pop head data\n");
		printf("3. view data\n");
		printf("4. exit\n");
		scanf("%d",&menu);
		
		switch(menu)
		{
			case 1:{
				int newData;
				printf("Masukan data : ");
				scanf("%d",&newData);
				
				head = pushTail(head, tail, newData);
				getch();
				break;
			}
			case 2:{
				head = popHead(head, tail);
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

