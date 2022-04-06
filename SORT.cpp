#include <stdio.h>


//==========================[Bubble Teritory]===================================
void sortBubble(int arr[],int size) {
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size-i-1; j++)
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		
	}
}

void printer(int arr[],int size) {
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

}

void SbRunner(){
	int isiAngka[5];
	printf("Masukan 5 angka\n");
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &isiAngka[i]);
	}
	int size = sizeof(isiAngka) / sizeof(isiAngka[0]);
	sortBubble(isiAngka, size);
	printf("Data Urut = \n");
	printer(isiAngka, size);
}
//==========================================================================

//========================[SELECT Teritory]===================================
void swapper(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selector(int arr[], int size) {
	for (int i = 0; i < size-1; i++)
	{
		int min_index = i;
		for (int j = i+1; j < size; j++)
		{
			if (arr[j] < arr[min_index])
			{
				min_index = j;
			}
		}
		swapper(&arr[min_index], &arr[i]);
	}
}

void selPrinter(int arr[], int size) {
	int i;
	for (int i = 0; i < size; i++)
	{
		printf(" %d", arr[i]);
	}
}

void selectInputer() {
	int isiAngka[5];
	printf("Masukan 5 angka\n");
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &isiAngka[i]);
	}
	int size = sizeof(isiAngka) / sizeof(isiAngka[0]);
	selector(isiAngka, size);
	printf("hasil Urut :");
	selPrinter(isiAngka, size);

}

//============================================================================

int main() {
	char y;
	selectInputer();
	scanf("%d", &y);
}