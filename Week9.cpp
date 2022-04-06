#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char data[10];
void grabText()
{
	int line =0;
	FILE *fp;
	fp = fopen("output.bin", "r");


	if (fp == NULL)
	{
		printf("Error: could not open file samsat.txt");
	}

	char ch[100] ;
	while (fgets(ch, 6, fp))
	{
		scanf("%s", data[line]);
		line++;
	}
	fclose(fp);
}


void printout()
{
	for (int i = 0; i < sizeof(data); i++)
	{
		printf("%s line:%d", data[i], i + 1);
	}
}
void writter()
{

	int angka;
	FILE *fileptr;

	fileptr = fopen("samsat.txt", "a");
	if (fileptr == NULL)
	{
		printf("Kosong");
	}
	printf("Masukan Angka :\n");
	scanf("%d", &angka);

	fprintf(fileptr, "%d", angka);
	fclose(fileptr);
}
void editor() {}

int main()
{
	grabText();
	printout();
}