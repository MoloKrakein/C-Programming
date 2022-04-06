#include <stdio.h>
#include <stdlib.h>


int angk;
int darifile;

struct theNumber
{
	int n1, n2, n3;
};

void readBIN() {
	
	int n;
	struct theNumber numb;
	FILE *grab;
	grab = fopen("output.bin", "rb");
	if (grab == NULL)
	{
		printf("tidak ada data !");
	}
	for (n = 1; n < 5; n++)
	{
		fread(&numb, sizeof(struct theNumber), 1, grab);
		printf("n1 = %d, n2 = %d,n3 = %d\n",numb.n1,numb.n2,numb.n3);

	}
	fclose(grab);

}

void binary() {

	int n;
	struct theNumber numb;
	FILE *grab;
	grab = fopen("output.bin", "wb");
	if (grab == NULL)
	{
		printf("tidak ada data !");
	}
	for (n = 0; n < 5; n++)
	{
		numb.n1 = n;
		numb.n2 = 5 * n;
		numb.n3 = 5 * n + 1;
		fwrite(&numb, sizeof(struct theNumber), 1, grab);
	}
	fclose(grab);
}


void read() {
	FILE *grab;
	if ((grab = fopen("Output.txt", "r")) == NULL) {
		printf("Gagal Diambil");
	}
	fscanf(grab, "%d", &darifile);
	printf("Isi File = %d\n", darifile);
	fclose(grab);
}


void create() {
	FILE *fileptr;

	fileptr = fopen("Output.txt", "w");
	if (fileptr == NULL)
	{
		printf("Kosong");
	}
	printf("Masukan Angka :\n");
	scanf("%d", &angk);

	fprintf(fileptr, "%d", angk);
	fclose(fileptr);
}

int main() {
	char yes;

	binary();
	readBIN();
	scanf("%c", &yes);

}