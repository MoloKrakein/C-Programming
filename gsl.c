#include <stdio.h>

struct mhs
{
	int nim;
	float gpa;
	char name[20];
} data[10];

void sortSelection()
{
	struct mhs temp; //Menyiapkan struct untuk menampung temp
	int indexLow; //Menyiapkan int untuk menampung index paling kecil
	for (int i = 0; i < 10 - 1; i++) //Memulai perulangan pertama
	{
		indexLow = i; //Mengisi Var dengan nilai i
		for (int j = i + 1; j < 10; j++) //Perulangan Kedua untuk mengecek nilai dari GPA
			if (data[j].gpa < data[indexLow].gpa)
			{
				indexLow = j; //Jika gpa di index sekarang lebih kecil maka isi index low dengan J
			}
        //Melakukan "Swapping"
		temp = data[indexLow];
		data[indexLow] = data[i];
		data[i] = temp;
	}
}

void sortBubble()
{
	struct mhs temp;
	for (int i = 0; i < 5 - 1; i++)
	{
		for (int j = 0; j < (5 - 1 - i); j++)
		{
			if (data[j].gpa < data[j + 1].gpa)
			{
				temp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = temp;
			}
		}
	}
}

int main()
{
    //User Melakukan Input Selama 10x
	for (int i = 0; i < 10; i++)
	{
		printf("\n[Data %d]\n", i + 1);
		printf("Please Input Nim, GPA, Name [nim GPA Name]\n");
		scanf("%d %f %s", &data[i].nim, &data[i].gpa, &data[i].name);
	}
    //Menampilkan Data yang belum Urut
	printf("\n\nSebelum Urut\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d %d %f %s\n", i + 1, data[i].nim, data[i].gpa, data[i].name);
	}
	printf("\nSudah Dipindah\n");
    //Memanggil Function Untuk sortSelection Diatas
	sortSelection();
    //Menampilkan lagi setelah melakukan Sorting
	for (int i = 0; i < 10; i++)
	{
		printf("%d %d %f %s\n", i + 1, data[i].nim, data[i].gpa, data[i].name);
	}
}