#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct Node // kegiatan
{
	char name[256];
	int harga;
	struct Node *next;
};

struct Node2 // waktu
{
	char time[256];
	struct Node2 *next;
};

struct Node *pushHead(struct Node *head, char *newData) // kegiatan
{
	if (head == NULL)
	{
		head = (struct Node *)malloc(sizeof(struct Node));

		strcpy(head->name, newData);
		head->next = head;
	}
	else
	{
		struct Node *newNode = NULL;
		newNode = (struct Node *)malloc(sizeof(struct Node));

		strcpy(newNode->name, newData);
		newNode->next = head;

		head = newNode;
	}
	return head;
}

struct Node2 *pushHeadtime(struct Node2 *head, char *newData) // waktu
{
	if (head == NULL)
	{
		head = (struct Node2 *)malloc(sizeof(struct Node2));

		strcpy(head->time, newData);
		head->next = NULL;
	}
	else
	{
		struct Node2 *newNode2 = NULL;
		newNode2 = (struct Node2 *)malloc(sizeof(struct Node2));

		strcpy(newNode2->time, newData);
		newNode2->next = head;

		head = newNode2;
	}
	return head;
}

void viewDataKBBI(struct Node *head)
{
	if (head == NULL)
		printf("No Data found!");
	else
	{
		int i = 1;
		struct Node *ptr;
		ptr = head;

			printf("\nNo | Kegiatan       | Hari   |\n");
		do
		{
			printf("%-2d |%-15s | %-8s|\n", i, ptr->name, ptr->harga);
			ptr = ptr->next;
		} while (ptr != head);
			printf("===============================\n");
	}
}
void viewHarga(struct Node *head)
{
	if(head == NULL)
		printf("No Data found!");
	else
	{
		struct Node *ptr;
		ptr = head;
		
		do
		{
			printf("%d ", ptr->harga);
			ptr = ptr->next;
		}while(ptr != head);
		
	}
}

void viewData(struct Node *head)
{
	int i = 1;


	if (head == NULL)
	{
		printf("Kosong\n");
	}
	else
	{
	struct Node *ptr;
		ptr = head;
		printf("\nNo | String       | Angka   |\n");
		printf("===============================\n");
		do
		{
			printf("%-2d | %-10s   | %-6d \n",i,ptr->name,ptr->harga);
			ptr = ptr->next;
			i++;
		} while (ptr != head);
		
	}
}

int getCurrSize(struct Node *node)
{
	int size = 0;

	while (node != NULL)
	{
		node = node->next;
		size++;
	}
	return size;
}

struct Node *insertAfterNthNode(int n, char *data, struct Node *head)
{
	int size = getCurrSize(head);

	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

	strcpy(newNode->name, data);
	newNode->next = NULL;

	if (n < 0 || n > size)
		printf("Invalid position to insert\n");

	else if (n == 0)
	{

		newNode->next = head;
		head = newNode;
	}

	else
	{

		struct Node *temp = head;

		while (--n)
			temp = temp->next;

		newNode->next = temp->next;

		temp->next = newNode;
	}
}



int getCurrSize2(struct Node2 *node)
{
	int size = 0;

	while (node != NULL)
	{
		node = node->next;
		size++;
	}
	return size;
}

struct Node2 *insertAfterNthNodeTime(int n, char *data, struct Node2 *head)
{
	int size = getCurrSize2(head);

	struct Node2 *newNode = (struct Node2 *)malloc(sizeof(struct Node2));

	strcpy(newNode->time, data);
	newNode->next = NULL;

	if (n < 0 || n > size)
		printf("Invalid position to insert\n");

	else if (n == 0)
	{

		newNode->next = head;
		head = newNode;
	}

	else
	{

		struct Node2 *temp = head;

		while (--n)
			temp = temp->next;

		newNode->next = temp->next;

		temp->next = newNode;
	}
}

void deleteEnd(struct Node *head)
{
	struct Node *temp, *prevnode;
	if (head == NULL)
		printf("\nList is Empty\n");
	else
	{
		temp = head;
		while (temp->next != 0)
		{
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
	else
	{
		temp = head;
		while (temp->next != 0)
		{
			prevnode = temp;
			temp = temp->next;
		}
		free(temp);
		prevnode->next = 0;
	}
}

void deletePosition(struct Node *head, int pos)
{
	struct Node *temp, *position;
	int i = 1;
	if (head == NULL)
		printf("\nList is empty\n");
	else
	{
		position = malloc(sizeof(struct Node));
		temp = head;

		while (i < pos - 1)
		{
			temp = temp->next;
			i++;
		}

		position = temp->next;
		temp->next = position->next;

		free(position);
	}
}

void deletePositionTime(struct Node2 *head, int pos)
{
	struct Node2 *temp, *position;
	int i = 1;
	if (head == NULL)
		printf("\nList is empty\n");
	else
	{
		position = malloc(sizeof(struct Node2));
		temp = head;

		while (i < pos - 1)
		{
			temp = temp->next;
			i++;
		}

		position = temp->next;
		temp->next = position->next;

		free(position);
	}
}

struct Node *pushTail(struct Node *head, int newData, char *data)
{
	if(head == NULL)
	{
		head = (struct Node*)malloc(sizeof(struct Node));
		strcpy(head->name, data);
		head->harga = newData;
		head->next = head;
	}
	else
	{
		struct Node *newNode, *ptr;
		ptr = head;
		newNode = (struct Node *)malloc(sizeof(struct Node));		
		strcpy(newNode->name, data);
		newNode->harga = newData;
		newNode->next = head;
		
		while(ptr->next != head)
			ptr = ptr->next;
		
		ptr->next = newNode;
	}
	printf("Success!");
	return head;
}

void delete_first_node(struct Node** head)
{
	struct Node *first = *head,*prev=*head;
	

	if (*head == NULL){
		printf("List is empty\n");
		return;
	}
		if (prev->next == prev)
		{
			*head = NULL;
			return;
		}
		
		while(prev->next != *head){
			prev=prev->next;
		}
	prev->next = first->next;
	*head = prev->next;
	free(first);
	return;
}


int main()
{
	struct Node *head = NULL;
	struct Node2 *head2 = NULL;

	int menu;
	do
	{
		// system("cls");
		printf("\n1. push data\n");
		printf("2. view data\n");
		printf("3. push data in certain position\n");
		printf("4. Delete last\n");
		printf("5. Delete data in certain position\n");
		printf("6. Push last\n");
		printf("7. Delete front\n");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
		{
			char newData[100];
			char waktu[100];

			printf("Masukan nama kegiatan : ");
			scanf(" %[^\n]s", newData);
			head = pushHead(head, newData);

			printf("Masukan hari : ");
			scanf("%s", waktu);
			head2 = pushHeadtime(head2, waktu);

			getch();
			break;
		}
		case 2:
		{
			// viewData(head, head2);
			// viewDataKBBI(head);
			// viewHarga(head);
			viewData(head);
			printf("\n");
			getch();
			break;
		}
		case 3:
		{
			char newData[100];
			char waktu[100];
			int posisi;

			printf("Masukan nama kegiatan : ");
			scanf(" %[^\n]s", newData);

			printf("Masukan hari : ");
			scanf("%s", waktu);

			printf("Ingin dimasukan setelah data ke = ");
			scanf("%d", &posisi);

			insertAfterNthNode(posisi, newData, head);
			insertAfterNthNodeTime(posisi, waktu, head2);

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
			scanf("%d", &posisi);
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
			int harga;

			printf("Masukan nama kegiatan : ");
			scanf(" %[^\n]s", &newData);
		hari:
			printf("Masukan harga : ");
			scanf("%d", &harga);

			if (head ==NULL)
			{
				head = pushTail(head, harga, newData);
			}else
			{
				pushTail(head, harga, newData);
			}
			getch();
			break;
		}
		case 7:
		{
			delete_first_node(&head);
			printf("\n");
			getch();
			break;
		}
		}

	} while (menu != 8);
	return 0;
}