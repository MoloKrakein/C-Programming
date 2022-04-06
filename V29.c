#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

char namaFile[] = { "penduduk.txt" };
char namaFile2[] = { "samsat.txt" };
char combinedOutput[40];
int totalPenduduk;
int totalMobil;

struct penduduk
{
	char nama[20];
	char kode[8];
	char alamat[50];
	int tgl, bln, thn;
}data[10];

struct mobil
{
	char kode[8];
	char nama[50];
	char alamat[50];
	int tgl;
	int bln;
	int thn;
}car[10];



void grabCarData() {
	int line = 0;
	char tempkode[20];
	char tempNama[20];
	int ttgl, tbln, tthn;
	char tempAlamat[50];
	char *filename2 = namaFile2;
	FILE *fp2 = fopen(filename2, "r");
	while (fscanf(fp2, "%s %s %s %d/%d/%d", &tempkode, &tempNama, &tempAlamat, &ttgl, &tbln, &tthn) != EOF)
	{
		strcpy(data[line].kode, tempkode);
		strcpy(car[line].kode, tempkode);
		strcpy(car[line].nama, tempNama);
		strcpy(car[line].alamat, tempAlamat);
		car[line].tgl = ttgl;
		car[line].bln = tbln;
		car[line].thn = tthn;
		line++;
		totalMobil++;


	}


	fclose(fp2);
}

void grabData()
{

	char tempNama[20];
	char tempAlamat[50];
	int ttgl, tbln, tthn;
	int line = 0;

	char *filename = namaFile;

	FILE *fp = fopen(filename, "r");

	if (fp == NULL)
	{
		printf("Error: could not open file %s", filename);
	}
	else {
		while (fscanf(fp, "%s %s %d/%d/%d", &tempNama, &tempAlamat, &ttgl, &tbln, &tthn) != EOF)
		{
			//printf("%s \n",kode[line]);
			strcpy(data[line].nama, tempNama);
			strcpy(data[line].alamat, tempAlamat);
			strcpy(data[line].alamat, tempAlamat);
			data[line].tgl = ttgl;
			data[line].bln = tbln;
			data[line].thn = tthn;
			line++;
			totalPenduduk++;
		}
		line = 0;

	}
	fclose(fp);

}

void displayData() {
	printf("=======================================================\n");
	printf("|No| Nama            | Address         | Date Of Birth \n");
	printf("=======================================================\n");
	for (int i = 0; i < totalPenduduk; i++)
	{
		printf("|%d | %-15s | %-15s | %02d/%02d/%02d \n", i + 1, data[i].nama, data[i].alamat, data[i].tgl, data[i].bln, data[i].thn);
	}
	printf("=======================================================\n");
}
void findBykode() {
	char search[8];
	int found = 0;
	int line;
	printf("Find By License Number : \n");
	scanf("%s", &search);
	for (int i = 0; i < sizeof(car); i++)
	{
		if (strcmp(search, data[i].kode) == 0)
		{
			found = 1;
			line = i;

		}
	}
	if (found == 1)
	{
		printf("License Number : %s\n", car[line].kode);
		printf("Name : %s\n", car[line].nama);
		printf("Address : %s\n", car[line].alamat);
		printf("DOB [DD/MM/YY] : %d/%d/%d\n", car[line].tgl, car[line].bln, car[line].thn);
	}
	else {
		printf("Huh ? Data Not Found, error 404 I guess");
	}

}
// By Name
void findder(int kasus) {

	int found = 0;
	int line;
	if (kasus == 0)
	{
		char search[50];
		printf("Find By Name : \n");
		scanf("%s", &search);
		for (int i = 0; i < sizeof(data); i++)
		{
			if (strcmp(search, data[i].nama) == 0)
			{
				found = 1;
				line = i;
				break;
			}
		}
		if (found == 1)
		{
			printf("Name : %s\n", data[line].nama);
			printf("Address : %s\n", data[line].alamat);
			printf("DOB [DD/MM/YY] : %02d/%02d/%02d\n", data[line].tgl, data[line].bln, data[line].thn);
		}
		else {
			printf("Huh ? Data Not Found, Error 404 I Guess");
		}
	}
	else if (kasus == 1)
	{
		char search[8];
		int checker;
		printf("Find By License Number : \n");
		scanf("%s", &search);
		int i = 0;
		while (i < totalMobil + 1)
		{
			for (int j = 0; j < 8; j++)
			{
				if (car[i].kode[j] == search[j])
				{
					checker++;
				}
				else {
					checker = 0;
					break;
				}
			}
			if (checker == 8)
			{
				found = 1;
				line = i;
				break;
			}
			i++;
		}
		if (found == 1)
		{
			printf("License Number : %s\n", search);
			printf("Name : %s\n", car[line].nama);
			printf("Address : %s\n", car[line].alamat);
			printf("DOB [DD/MM/YY] : %d/%d/%d\n", car[line].tgl, car[line].bln, car[line].thn);
		}
		else {
			printf("Huh ? Data Not Found, error 404 I guess");
		}

	}





}

void combiner(char nama[60], char alamat[60], char ttl[5]) {
	strcat(combinedOutput, nama);
	strcat(combinedOutput, " ");
	strcat(combinedOutput, alamat);
	strcat(combinedOutput, " ");
	strcat(combinedOutput, ttl);

}
void writter()
{
	FILE *fileptr;

	char kode;
	char name[60], alamat[60];
	char temp;

	fileptr = fopen(namaFile, "a");
	if (fileptr == NULL)
	{
		printf("Kosong");
	}
	printf("\nPlease Provide Your Name : ");
	scanf("%s", &name);
	printf("\nPlease Provide Your Address : ");
	scanf(" %s", &alamat);
	printf("Insert Date Of Birth (dd mm yy) :\n");
	int valid = 0;
	int itgl, ibln, ithn;
	char exp[5];
	while (valid == 0)
	{

		scanf(" %d %d %d", &itgl, &ibln, &ithn);
		if (itgl <= 31 && ibln <= 12 && ithn >= 21)
		{

			sprintf(exp, "%02d/%02d/%02d", itgl, ibln, ithn);
			break;
		}
		else
		{
			printf("Insert Date Of Birth (dd mm yy):\n");
		}
	}
	combiner(name, alamat, exp);
	fprintf(fileptr, "\n%s", combinedOutput);
	fclose(fileptr);
}

void displayMenu() {
	printf("SAMSAT ON LAN 2.9\n");
	printf("\nMenu\n");
	printf("[1] Display All Penduduk Data\n");
	printf("[2] Add Penduduk Data\n");
	printf("[3] Search\n");
	printf("[4] Exit\n");
}
int main() {
	int menu = 0;
	grabCarData();
	grabData();
	displayMenu();
	while (menu != 4)
	{
		scanf("%d", &menu);
		if (menu == 1)
		{
			system("cls");
			displayData();
			menu = 0;
			displayMenu();

		}
		else if (menu == 2) {
			system("cls");
			writter();
			menu = 0;
			displayMenu();
		}
		else if(menu == 3)
		{
			system("cls");
			int choose = 0;
			printf("Please Choose What Type You Search\n");
			printf("[1] Search By Name\n");
			printf("[2] Search By License Code\n");
			while (choose == 0 || choose > 2 )
			{
				printf("Your Command : \n");
				scanf("%d", &choose);
				if (choose == 1)
				{
					findder(0);
				}
				else if (choose == 2) {
					findder(1);
				}
			}
		}

	}




}