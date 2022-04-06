#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct kotak
{
	char isi[6];
} isikotak[16];
int kotakkosong = 0;
struct player
{
	char nama[50];
	int score;
} pemain[2];
struct ranking
{
	char nama[60];
	int score;
} listscore[100];

int bot()
{
	strcpy(pemain[1].nama, "Kompie");
	srand(time(NULL));
	int pick = rand() % 16;
	return pick;
}

void grabtxt()
{
	kotakkosong = 0;
	int line = 0;
	FILE *fp = fopen("Data.txt", "r");
	if (fp == NULL)
	{
		printf("Permainan Gagal Tidak ada Data\n");
	}
	else
	{
		char temp[6];
		while (fscanf(fp, "%s ", &temp) != EOF)
		{
			strcpy(isikotak[line].isi, temp);
			if (strcmp(temp, "null") == 0)
			{
				kotakkosong++;
			}

			line++;
		}
	}
	fclose(fp);
}
void isi()
{
	int counter = 0;

	char temp[6];
	static const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	srand(time(NULL));
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			temp[j] = charset[rand() % (sizeof charset - 1)];
		}
		temp[5] = 0;
		strcpy(isikotak[i].isi, temp);
	}

}

void printisikotak()
{
	int angk = 0;
	struct kotak display[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			strcpy(display[i][j].isi, isikotak[angk].isi);
			angk++;
		}
	}

	int no = 0;
	printf("====================\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("| %-5s ", display[i][j]);
		}
		printf("|\n====================\n");
	}

}

void printkotakangka()
{
	int no = 1;
	printf("====================\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("|| %-2d ", no);
			no++;
		}
		printf("|\n====================\n");
	}
}
void saveFile()
{
	
	FILE *fp = fopen("Data.txt", "w");
	for (int i = 0; i < 16; i++)
	{
		
		if (i < 3)
		{
			fprintf(fp, "%s ", isikotak[i].isi);
		}
		else if (i == 3)
		{
			fprintf(fp, "%s\n", isikotak[i].isi);
		}
		else if (i > 3 && i < 7)
		{
			fprintf(fp, "%s ", isikotak[i].isi);
		}
		else if (i == 7)
		{
			fprintf(fp, "%s\n", isikotak[i].isi);
		}
		else if (i > 7 && i < 11)
		{
			fprintf(fp, "%s ", isikotak[i].isi);
		}
		else if (i == 11)
		{
			fprintf(fp, "%s\n", isikotak[i].isi);
		}
		else if (i > 11 && i < 15)
		{
			fprintf(fp, "%s ", isikotak[i].isi);
		}
		else if (i == 15)
		{
			fprintf(fp, "%s\n", isikotak[i].isi);
		}
	}
	fclose(fp);
}

void hapus(int kunci)
{
	strcpy(isikotak[kunci].isi, "null");
	saveFile();
}

int soal()
{
	srand(time(NULL));
	int counter = 0;
	int randNum;
	int kunci;
	struct kotak tempdata[16];

	while (counter < 16)
	{
		randNum = rand() % 16;
		strcpy(tempdata[counter].isi, isikotak[randNum].isi);
		if (strcmp(tempdata[counter].isi, "null") == 0)
		{
			randNum = rand() % 16;
			continue;
		}
		else
		{
			kunci = randNum;
			return kunci;
			break;
		}
		counter++;
	}
}
int pilihanPlayer = 0;

int ambiljawab(int player, int kunci)
{
	srand(time(NULL));
	int pilih = 0;
	if (player == 1)
	{
	start:
		scanf(" %d", &pilih);
		if (pilih > 16)
		{
			printf("Input Salah !\n");
			printf("Masukan Jawaban :");
			goto start;
		}
		else
		{

			if (pilih - 1 == kunci)
			{
				system("cls");
				printf("\nBenar\n");
				hapus(kunci);

				return 1;
			}
			else
			{
				printf("\n%s Salah\n", pemain[0].nama);
				pilihanPlayer = pilih - 1;

				return 2;
			}
		}
	}
	else
	{

		int temp;
		temp = bot() - 1;
	bot:
		while (pilihanPlayer == temp)
		{
			temp = bot() - 1;
		}
		if (temp <= 0)
		{
			temp++;
		}
		else
		{
			pilih = temp + 1;
		}
		if (pilih == 0)
		{
			goto bot;
		}

		printf("\nBot Memilih : %d\n", pilih);
		if (pilih - 1 == kunci)
		{

			printf("Benar\n");
			pemain[1].score += 10;
			hapus(kunci);

			return 2;
		}
		else
		{
			printf("%s Salah\n\n", pemain[1].nama);
			return 2;
		}
	}
}

void endScreen()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3 - i; i++)
		{
			if (pemain[j].score < pemain[j + 1].score)
			{
				struct player temp;
				temp = pemain[i];
				pemain[j] = pemain[j + 1];
				pemain[j + 1] = temp;
			}
		}
	}
	printf("Pemenang : %s [%d]\n", pemain[0].nama, pemain[0].score);
	printf("%s [%d]", pemain[1].nama, pemain[1].score);
	if (strcmp(pemain[0].nama, "Kompie") == 0)
	{
		printf("Terima kasih %s Telah Bermain !\n", pemain[0].nama);
	}
	else if (strcmp(pemain[0].nama, "Kompie") != 0)
	{
		char temp;
		printf("\nSimpan Score ? [y/n]");
		scanf(" %c", &temp);
		if (temp == 'y' || temp == 'Y')
		{
			printf("Terima kasih %s Telah Bermain !\n", pemain[0].nama);
		}
		else
		{

			printf("Terima kasih %s Telah Bermain !\n", pemain[0].nama);
		}
	}
}
int session()
{
	int turn = 0;
	char temp;
	int player = 1;
	grabtxt();

	while (turn < 10)
	{
		grabtxt();
		if (kotakkosong == 16)
		{

			isi();
			saveFile();
			grabtxt();
		}
		printisikotak();
		printf("Sisa Putaran = %d\n", 16 - turn);
		printf("\nApakah anda siap ? [y/n]\n");
		scanf(" %c", &temp);
		if (temp == 'y')
		{
			system("cls");
			if (turn == 0)
			{
				char namapemain[50];
				printf("Masukan Nama Anda :\n");
				scanf(" %s", &namapemain);
				strcpy(pemain[0].nama, namapemain);
			}
			system("cls");
			bot();
			printf("Score:\n");
			printf("%s [%-2d] | [%-2d] %s\n", pemain[0].nama, pemain[0].score, pemain[1].score,pemain[1].nama);
			printf("=========================\n");
			printkotakangka();
						printf("=========================\n");
			printf("Sisa Putaran = %d\n", 16 - turn);
			printf("=========================\n");
			int soalnow = soal();
			printf("Dimana letak [ %s ] ?\n", isikotak[soalnow].isi);

			if (player == 1)
			{
				printf("Giliran %s : ", pemain[0].nama);
				if (ambiljawab(1, soalnow) == 1)
				{
					pemain[0].score += 10;
					printf("Score +10\n");
					turn++;
					continue;
				}
				else
				{
					player = 2;
					turn++;
				}
			}
			if (player == 2)
			{
				if (ambiljawab(2, soalnow) == 1)
				{
					pemain[1].score += 10;
					printf("Score +10\n");
					printf("\n");
					continue;
				}
				else
				{
					player = 1;
					printf("\n");
				}
			}
		}
		else
		{
			return 0;
		}
	}
	if (turn == 10)
	{
		printf("\nGAME OVER\n");
		endScreen();
	}
}

int main()
{
	int menu;
	while (menu == 0)
	{
		printf("\n======[Selamat Datang]=====\n");
		printf("[1] Generate Box\n");
		printf("[2] Mulai Main\n");
		printf("[3] Rank\n");
		printf("[99] Exit\n");
		int printer = 0, input = 0;
		printf("===============================\n");
		printf("Pilih Menu : ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			char yes;
			do
			{
				isi();
				printisikotak();
				printf("Apakah Anda Siap [(y)es/(n)o/(q)uit] ?\n");
				scanf(" %c", &yes);
				if (yes == 'q')
				{
					break;
					system("cls");
				}
				if (yes == 'n')
				{
					system("cls");
					continue;
				}
				if (yes == 'y')
				{
					saveFile();
					system("cls");
				}

			} while (yes != 'y');

			break;
		case 2:
			system("cls");
			session();
			break;

		case 99:
			menu = 1;
			break;
		default:
			printf("Invalid Input\n");
			break;
		}
	}
}
