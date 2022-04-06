#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>


// Global Variable
char combinedOutput[50];

struct barang
{
	char nama[50];
	char jenis[50];
	int harga;
	int stok;
} barang[40];

int totalBarang;
struct beli
{
	char kodebeli[20];
	int tgl, bln, thn, jam, menit;
	char pembeli[20];
	// Item
	char jenis[50];
	char barang[50];
	int harga;
	int jumlah;
	int totalbarang;

} pembeli[50];

int totalPembeli;
int totalJual;

void grabData()
{
	totalPembeli = 0;
	totalBarang = 0;
	totalJual = 0;
	char tempNama[20];
	char tempBarang[50];
	char tempJenis[50];
	int tjmlh, tharga;
	char tempKode[50];
	int ttgl, tbln, tthn, tjam, tmenit, ttotal;
	int line = 0;
	FILE *fp = fopen("barang.txt", "r");
	FILE *fp2 = fopen("sales.txt", "r");
	if (fp == NULL)
	{
		printf("uhh missing Something");
	}
	else
	{
		// Ambil Data Barang
		while (fscanf(fp, "%s %s %d %d", &tempNama, &tempJenis, &tharga, &tjmlh) != EOF)
		{
			strcpy(barang[line].nama, tempNama);
			strcpy(barang[line].jenis, tempJenis);
			barang[line].harga = tharga;
			barang[line].stok = tjmlh;
			line++;
			totalBarang++;
		}
		line = 0;

		// Ambil Data Penjualan
		while (fscanf(fp2, "%s %d/%d/%d[%d:%d] %s %s %s %d %d %d", &tempKode, &ttgl, &tbln, &tthn, &tjam, &tmenit, &tempNama, &tempJenis, &tempBarang, &tharga, &tjmlh, &ttotal) != EOF)
		{
			strcpy(pembeli[line].kodebeli, tempKode);
			pembeli[line].tgl = ttgl;
			pembeli[line].bln = tbln;
			pembeli[line].thn = tthn;
			pembeli[line].jam = tjam;
			pembeli[line].menit = tmenit;
			pembeli[line].totalbarang = ttotal;
			strcpy(pembeli[line].jenis, tempJenis);
			strcpy(pembeli[line].pembeli, tempNama);
			strcpy(pembeli[line].barang, tempBarang);
			pembeli[line].jumlah = tjmlh;
			pembeli[line].harga = tharga;
			line++;
			totalPembeli++;
			totalJual = totalJual + ttotal;
		}
	}
}

void displayData()
{
	grabData();
	setlocale(LC_NUMERIC, "");
	printf("===============================================================\n");
	printf("|No| Nama            | Jenis           | Harga        | Stok \n");
	printf("===============================================================\n");
	if (totalBarang == 0)
	{
		printf("Barang Kosong !\n");
	}

	for (int i = 0; i < totalBarang; i++)
	{

		float nominal = (float)barang[i].harga / 1000;
		printf("|%d | %-15s | %-15s | Rp.%-9.3f | %d \n", i + 1, barang[i].nama, barang[i].jenis, nominal, barang[i].stok);
	}
	printf("===============================================================\n");
}
void displaySales()
{
	grabData();
	system("cls");
	printf("=====================================================================================================================\n");
	printf("|No| Kode | Waktu             | Nama            | Jenis      | Barang          | Harga         | T | Total Harga  \n");
	printf("=====================================================================================================================\n");
	if (totalPembeli == 0)
	{
		printf("Data Sales Kosong !\n");
	}
	for (int i = 0; i < totalPembeli; i++)
	{

		float nominal = (float)pembeli[i].harga / 1000;
		float nominal2 = (float)pembeli[i].totalbarang / 1000;
		printf("|%d | %s | %02d/%02d/%d[%02d:%02d] | %-15s | %-10s | %-15s | Rp. %-9.3f | %d | %-9.3f \n", i + 1, pembeli[i].kodebeli, pembeli[i].tgl, pembeli[i].bln, pembeli[i].thn, pembeli[i].jam, pembeli[i].menit, pembeli[i].pembeli, pembeli[i].jenis, pembeli[i].barang, nominal, pembeli[i].jumlah, nominal2);
	}
	printf("=====================================================================================================================\n");
	float nominal = (float)totalJual / 1000;
	printf("Total Jual : Rp.%-9.3f\n", nominal);
}

int addStock()
{
	FILE *fileptr;
	char name[60], jenis[20];
	int harga, jumlah;

	fileptr = fopen("barang.txt", "a");
	if (fileptr == NULL)
	{
		printf("Kosong");
	}
	printf("[Menambah Data Barang (ketik cancel untuk batal)]\n");
	printf("\nNama Barang : ");
	scanf("%15s", &name);
	if (strcmp(name, "cancel") == 0 || strcmp(name, "Cancel") == 0)
	{
		system("cls");
		return 0;
	}

	for (int i = 0; i < totalBarang; i++)
	{
		if (strcmp(name, barang[i].nama) == 0)
		{
			FILE *fileptr2;
			int stok;
			printf("Masukan Jumlah Stok Baru :\n");
			scanf(" %d", &stok);

			if (stok == 0)
			{
				char temp = 'n';
				printf("Anda Ingin Menghapus %s ? [y/t]\n", name);
				scanf(" %c", &temp);

				if (temp == 'y' || temp == 'Y')
				{
					fileptr2 = fopen("barang.txt", "w");
					for (int i = 0; i < totalBarang; i++)
					{
						if (strcmp(name, barang[i].nama) == 0)
						{
							continue;
						}

						fprintf(fileptr2, "%s %s %d %d\n", barang[i].nama, barang[i].jenis, barang[i].harga, barang[i].stok);
					}
					fclose(fileptr2);
					system("cls");
					printf("%s Berhasil Dihapus !", name);
					return 0;
				}
				else
				{
					system("cls");
					printf("Proses Hapus Barang Dibatalkan\n");
					return 0;
				}
			}
			else
			{
				barang[i].stok = stok;
				fileptr2 = fopen("barang.txt", "w");
				for (int i = 0; i < totalBarang; i++)
				{
					fprintf(fileptr2, "%s %s %d %d\n", barang[i].nama, barang[i].jenis, barang[i].harga, barang[i].stok);
				}
				fclose(fileptr2);
				displayData();
				printf("\nStok Sudah DiUpdate !\n");
				return 0;
			}
		}
	}

	while (strlen(name) > 15)
	{

		if (strlen(name) < 15)
		{
			break;
		}
		else
		{
			printf("Terlalu Banyak karakter ! (Maks 15)");
			printf("\nNama Barang : ");
			scanf("%s", &name);
		}
	}

	printf("\nJenis Barang : ");
	scanf(" %s", &jenis);
	if (strcmp(jenis, "cancel") == 0 || strcmp(jenis, "Cancel") == 0)
	{
		system("cls");
		return 0;
	}

	while (strlen(jenis) > 15)
	{
		if (strlen(jenis) < 15)
		{
			break;
		}
		else
		{
			printf("Terlalu Banyak karakter ! (Max 15)");
			printf("\nJenis Barang : ");
			scanf(" %s", &jenis);
		}
	}

	printf("\nHarga Barang (Ketik 0 untuk batal):\n");
	scanf("%d", &harga);
	if (harga == 0)
	{
		system("cls");
		return 0;
	}

	printf("\nJumlah Barang :\n");
	scanf("%d", &jumlah);
	if (jumlah == 0)
	{
		system("cls");
		return 0;
	}
	fprintf(fileptr, "%s %s %d %d\n", name, jenis, harga, jumlah);
	fclose(fileptr);
	system("cls");
	printf("Barang Berhasil DiTambahkan !");
	return 0;
}

void printerByMonth(int month)
{
	FILE *fileptr;
	fileptr = fopen("OutputLaporan.txt", "w");
	int found = 0;
	for (int i = 0; i < totalPembeli; i++)
	{
		if (month == pembeli[i].bln)
		{
			printf("%s %02d/%d/%d [%02d:%02d] %s %s %s\n", pembeli[i].kodebeli, pembeli[i].tgl, pembeli[i].bln, pembeli[i].thn, pembeli[i].jam, pembeli[i].menit, pembeli[i].pembeli, pembeli[i].jenis, pembeli[i].barang);
			found++;
		}
	}
	if (found == 0)
	{
		system("cls");
		printf("Tidak Ada Pembelian Bulan ini !\n");
	}
	else
	{
		char user;
		printf("Terdapat %d Data, Cetak Data Pada Bulan Ke-%d ? [y/t]\n", found, month);
		scanf(" %c", &user);
		if (user == 'Y' || user == 'y')
		{
			fprintf(fileptr, "Laporan Data Penjualan Per Bulan ke-%d\n", month);
			for (int i = 0; i < totalPembeli; i++)
			{
				if (month == pembeli[i].bln)
				{
					fprintf(fileptr, "%s %02d/%d/%d [%02d:%02d] %s %s %s\n", pembeli[i].kodebeli, pembeli[i].tgl, pembeli[i].bln, pembeli[i].thn, pembeli[i].jam, pembeli[i].menit, pembeli[i].pembeli, pembeli[i].jenis, pembeli[i].barang);
				}
			}
			fclose(fileptr);
		}
	}
}
int belibarang()
{
	grabData();
	FILE *fileptr;
	FILE *fileptr2;

	char nama[60], namaBarang[20], temp[60], kodeBeli[5];
	int harga, jumlah = 0, line;
	int valid = 0;
	printf("\nNama Pembeli : ");
	scanf("%15s", &temp);
	strcpy(nama, temp);
	while (strcmp(temp, nama) == 0)
	{
		displayData();
		printf("\nMasukan No Barang (Ketik 0 Untuk Batal) : ");
		scanf("%d", &line);
		if (line == 0)
		{
			printf("Terima Kasih Telah Mampir %s !", nama);
			return 0;
		}
		line = line - 1;
		if (line < totalBarang)
		{
			char yes;
			printf("\n%s %s Rp. %d\n", barang[line].nama, barang[line].jenis, barang[line].harga);
			printf("Masukan Jumlah Barang Yang akan dibeli (ketik 0 untuk batal) :\n");
			scanf("%d", &jumlah);
			if (jumlah == 0)
			{
				system("cls");
				continue;
			}
			else if (jumlah > barang[line].stok)
			{
				system("cls");
				printf("Pemesanan Anda Melebihi Stok !\n");
				continue;
			}
			harga = jumlah * barang[line].harga;
			printf("Total Harga Adalah Rp. %d\napakah anda yakin ?[y/t] ", harga);
			scanf(" %c", &yes);
			if (yes == 'y' || yes == 'Y')
			{
				int code = 0;
				int tgl, bln, thn, jam, menit;
				srand(time(NULL));
				kodeBeli[0] = rand() % 9 + '0';
				for (int i = 0; i < 5; i++)
				{
					code = rand() % 9;
					kodeBeli[i - 1] = code + '0';
				}

				fileptr = fopen("sales.txt", "a");
				if (fileptr == NULL)
				{
					printf("Mana filenya ?");
				}
				else
				{
					time_t t = time(NULL);
					struct tm tm = *localtime(&t);
					tgl = tm.tm_mday;
					bln = tm.tm_mon + 1;
					thn = tm.tm_year + 1900;
					jam = tm.tm_hour;
					menit = tm.tm_min;
					fprintf(fileptr, "%s %02d/%02d/%d[%02d:%02d] %s %s %s %d %d %d\n", kodeBeli, tgl, bln, thn, jam, menit, nama, barang[line].jenis, barang[line].nama, barang[line].harga, jumlah, harga);
					fclose(fileptr);
					barang[line].stok = barang[line].stok - jumlah;
					fileptr2 = fopen("barang.txt", "w");
					for (int i = 0; i < totalBarang; i++)
					{
						fprintf(fileptr2, "%s %s %d %d\n", barang[i].nama, barang[i].jenis, barang[i].harga, barang[i].stok);
					}
					fclose(fileptr2);

					printf("Pembelian Telah Dicatat! apakah anda ingin membeli barang yang lain ??[y/n]\n");
					scanf(" %c", &yes);
					if (yes == 'y' || yes == 'Y')
					{
						system("cls");
						continue;
					}
					else
					{
						printf("Terima Kasih Telah Berbelanja %s !", nama);
						break;
						return 0;
					}
				}
			}
			else
			{
				system("cls");
				printf("Pembelian Dibatalkan !\n");
			}
		}
		else
		{
			system("cls");
			printf("Inputan Tidak Valid !\n");
		}
	}
}

void sortThis(int printer)
{
	struct beli temp;
	FILE *fileptr;
	int low;
	fileptr = fopen("OutputLaporan.txt", "w");
	fprintf(fileptr, "Laporan Data Penjualan\n");
	system("cls");
	if (printer == 1) ////// Berdasar Bulan (Selection)
	{

		for (int i = 0; i < totalPembeli; i++)
		{
			low = i;
			for (int j = i + 1; j < totalPembeli; j++)
				if (pembeli[j].bln < pembeli[low].bln || pembeli[j].thn < pembeli[low].thn || pembeli[j].jam < pembeli[low].jam)
				{
					low = j;
				}
			temp = pembeli[low];
			pembeli[low] = pembeli[i];
			pembeli[i] = temp;
		}
		fprintf(fileptr, "=============================================================================================================================\n");
		fprintf(fileptr, "|No| Kode | Waktu              | Nama            | Jenis           | Barang          | Jlh | Pemasukan  \n");
		fprintf(fileptr, "=============================================================================================================================\n");
		for (int i = 0; i < totalPembeli; i++)
		{
			fprintf(fileptr, "|%d| %-15s | %02d/%02d/%d [%02d:%02d] | %-15s | %-15s | %-15s | %-3d | Rp. %-15d\n", i + 1, pembeli[i].kodebeli, pembeli[i].tgl, pembeli[i].bln, pembeli[i].thn, pembeli[i].jam, pembeli[i].menit, pembeli[i].pembeli, pembeli[i].jenis, pembeli[i].barang, pembeli[i].jumlah, pembeli[i].totalbarang);
		}
		fprintf(fileptr, "=============================================================================================================================\n");
		float nominal = (float)totalJual / 1000;
		fprintf(fileptr, "Total Jual : Rp.%-9.3f", nominal);
		fclose(fileptr);
		displaySales();
		printf("\nData Berhasil DiCetak !\n");
	}
	else if (printer == 3) //// perbulan
	{
		int month;
		printf("Masukan Nomer Bulan Anda Yang Ingin Anda Cetak\n");
		scanf("%d", &month);
		printerByMonth(month);
	}

	else /// Default (Barang)
	{
		for (int i = 0; i < totalPembeli; i++)
		{
			low = i;
			for (int j = i + 1; j < totalPembeli; j++)		 // Melakukan Perulangan
				if (pembeli[j].jumlah > pembeli[low].jumlah)
				{
					low = j;
				}
			temp = pembeli[low];
			pembeli[low] = pembeli[i];
			pembeli[i] = temp;
		}
		fprintf(fileptr, "=============================================================================================================================\n");
		fprintf(fileptr, "|No| Kode           | Waktu              | Nama            | Jenis           | Barang          | Jlh | Pemasukan  \n");
		fprintf(fileptr, "=============================================================================================================================\n");
		for (int i = 0; i < totalPembeli; i++)
		{
			fprintf(fileptr, "|%d| %-15s | %02d/%02d/%d [%02d:%02d] | %-15s | %-15s | %-15s | %-3d | Rp. %-15d\n", i + 1, pembeli[i].kodebeli, pembeli[i].tgl, pembeli[i].bln, pembeli[i].thn, pembeli[i].jam, pembeli[i].menit, pembeli[i].pembeli, pembeli[i].jenis, pembeli[i].barang, pembeli[i].jumlah, pembeli[i].totalbarang);
		}
		fprintf(fileptr, "=============================================================================================================================\n");
		float nominal = (float)totalJual / 1000;
		fprintf(fileptr, "Total Jual : Rp.%-9.3f", nominal);
		fclose(fileptr);
		displaySales();
		printf("\nData Berhasil DiCetak !\n");
	}
}

void cleaner(char ans) // Membersihkan sales.txt
{
	if (ans == 'y')
	{
		system("cls");
		FILE *fileptr;
		fileptr = fopen("sales.txt", "w");
		fprintf(fileptr, "");
		fclose(fileptr);
		printf("\nData Sudah Dibersihkan !\n");
	}
	else
	{
		system("cls");
		printf("\nOperasi hapus dibatalkan\n");
	}
}
void mainmenu(int akun)
{
	printf("================[Welcome To Toko Electronic]================\n");
	if (akun == 0)
	{
		belibarang();
	}
	else
	{
		grabData();
		int menu = 0;
		char temp = 'n';
		while (menu == 0)
		{
			printf("\nSelamat Datang [Petugas]\n");
			printf("[1] Daftar Barang\n");
			printf("[2] Tambah Barang\n");
			printf("[3] Daftar Semua Penjualan\n");
			printf("[4] Print Laporan\n");
			printf("[5] Hapus Semua Data Penjualan\n");
			printf("[99] Exit\n");
			int printer = 0, input = 0;
			scanf("%d", &input);
			switch (input)
			{
			case 2:
				system("cls");
				displayData();
				addStock();
				break;
			case 1:
				system("cls");
				displayData();
				break;
			case 3:
				system("cls");
				displaySales();
				break;
			case 4:
				if (totalPembeli == 0)
				{
					system("cls");
					printf("Masih Belum ada pembelian\n");
					break;
				}

				printf("Print Berdasar\n");
				printf("[1] Bulan | [2] Barang Terbanyak | [3] Per Bulan\n");
				scanf(" %d", &printer);
				sortThis(printer);
				break;
			case 5:
				if (totalPembeli == 0)
				{
					system("cls");
					printf("Data Masih Bersih !\n");
					break;
				}
				printf("Apakah Anda Yakin ?, Proses ini tidak bisa di undo [y/t]\n");

				scanf(" %c", &temp);
				cleaner(temp);
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
}

int main()
{
	printf("Welcome Exelectro\n");
	printf("Masukan Akun Anda :\n");
	printf("[1] Pembeli\n[2] Petugas\n");
	int akun = 3;
	while (akun > 1)
	{
		printf("Akun : \n");
		scanf("%d", &akun);
		if (akun == 1 || akun == 2)
		{
			system("cls");
			mainmenu(akun - 1);
			break;
		}
		else
		{
			printf("Invalid Input !\n");
			continue;
		}
	}
}
