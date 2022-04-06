#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

char namaFile[] = { "samsat.txt" };
char data[10];
char kode[15][15];
char nama[20][15];
char alamat[50][15];
int tgl[15], bln[15], thn[15];

void grabText()
{
	char tempkode[10];
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
		while (fscanf(fp, "%s %s %s %d/%d/%d", &tempkode, &tempNama, &tempAlamat, &ttgl, &tbln, &tthn) != EOF)
		{
			strcpy(kode[line], tempkode);
			//printf("%s \n",kode[line]);
			strcpy(nama[line],tempNama);
			strcpy(alamat[line],tempAlamat);
			tgl[line] = ttgl;
			bln[line] = tbln;
			thn[line] = tthn;
			line++;
		}


	}
	fclose(fp);
}
void shorter(){
		FILE *fileptr;
		fileptr = fopen("samsat.txt", "a");
	if (fileptr == NULL)
	{
		printf("Kosong");
	}
	grabText();
	int line;
	// if (kasus == 1) //Sort By Exp
	// {
		for (int i = 0; i < sizeof(thn)-1; ++i)
		{
			for (int j = 0; j < sizeof(thn) - i-1; ++j)
			{
				if (thn[i] > thn[i+1])
				{
					int temp = thn[i];
					thn[i] = thn[i+1];
					thn[i+1]=temp;
					fprintf(fileptr,"%d ",thn[i]);
				}
				
			}
				
		}
		
	}
	
// }

void displayData(){
	printf("==================================================\n");
	printf("|No| Code     | Name | Address | Exp Date \n");
	for (int i = 0; i < strlen(kode[i]); i++)
	{		
		printf("|%d | %s | %s | %s | %d/%01d/%d \n",i+1,kode[i],nama[i],alamat[i],tgl[i],bln[i],thn[i]);
	}
	printf("==================================================\n");
}


char generatedkode[8];
char combinedOutput[50];
void kodeGEN(){
	char theKode[8];
	srand(time(0));
	scanf(" %c",&theKode[0]);
	int border = (rand()%9)+1;

	for (int i = 1; i <= 4; i++)
	{
		{
			theKode[i] = border+'0';
			border=(rand()%9)+1;
		}	
	}
	for (int i = 1; i < 4; i++)
	{
		char c = (90 - (rand() % 26));
		theKode[4+i] = c;
	}
	printf("Your Plate Number is :\n");
	for (int i = 0; i < sizeof(theKode); i++)
	{	
		generatedkode[i] = theKode[i];
		printf("%c",generatedkode[i]);
	
	}

}



void writter()
{	
	FILE *fileptr;

	char kode;
	char name[60],alamat[60];
	char temp;

	fileptr = fopen("samsat.txt", "a");
	if (fileptr == NULL)
	{
		printf("Kosong");
	}
	printf("Input First Letter of Plate Number : ");
	kodeGEN();
	printf("\nPlease Provide Your Name : ");
	scanf("%s",&name);
	printf("\nPlease Provide Your Address : ");
	scanf(" %s",&alamat);
	printf(" Insert Expired Date [dd mm yy]\n");
	int valid = 0; 
	int itgl,ibln,ithn;
	char exp[5];
	while (valid == 0) 
	{	

		scanf("%d %d %d", &itgl, &ibln, &ithn); 
		if (itgl <= 31 && ibln <= 12 && ithn >= 21) 
		{

			sprintf(exp, "%d/%d/%d", itgl,ibln,ithn);
			break;
			}
		else
		{ 
			printf(" Insert Expired Date [dd mm yy]\n");
		}
	}
	combiner(generatedkode,name,alamat,exp);
	fprintf(fileptr,"%s",combinedOutput);
	fclose(fileptr);
}

void combiner(char kode[8],char nama[60],char alamat[60],char expired[5]){
char temp[2];
strcat(combinedOutput,kode);
strcat(combinedOutput," ");
strcat(combinedOutput,nama);
strcat(combinedOutput," ");
strcat(combinedOutput,alamat);
strcat(combinedOutput," ");
strcat(combinedOutput,expired);

}



void mainMenu(){
	int menu = 0;
	void textmenu(){
	printf("\nWelcome to Samsat ON LAN\n");
	printf("[1] Display\n");
	printf("[2] Add Data\n");
	printf("[3] Edit Data\n");
	printf("[4] Sort\n");
	printf("[99] Exit\n");
	printf("Menu : ");
	scanf("%d",&menu);
	}
	
	while (menu != 99)
	{
		textmenu();
		if (menu == 1)
		{
			grabText();
			displayData();
			textmenu();
		}else if(menu == 2){
			writter();
		}else{
			printf("NULL");
		}
	
	}
	

}
int main()
{
	mainMenu();
}