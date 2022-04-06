#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


//Data Vaksin
char namaVaksin[51];	//Menampung Nama Vaksin yang terdiri dari 51 karakter
char batch[1];			//Menampung nomer batch yang terdiri dari 2 karakter
int used = 0;			//Menampung status apakah vaksin sudah digunakan yang merupakan boolean
int exp[2];				//Menampung tanggal expired Vaksin yang terdiri dari 3 integer
//Data Peserta
char NIK[11];			//Menampung NIK peserta yang terdiri dari 11 karakter
char nama[150];			//Menampung Nama peserta yang terdiri dari 150 karakter
char alamat[1][300];	//Menampung 2 alamat dari peserta yang terdiri dari 300 karakter
char medis[1][200];		//Menampung 2 data dari petugas (Nama dan Kode) terdiri dari 200 karakter
char phone[15];			//Menampung No telp peserta yang terdiri dari 15 karakter
//Combo Vaksin
char vaksin[1][100];	//Menampung 2 Nama Vaksin yang digunakan untuk batch 1 dan 2 terdiri dari 100 karakter
int batchVaksin;		//Menampung batch vaksin yang digunakan yang merupakan integer
char lokVaksin[1][300];	//Menampung 2 Nama tempat vaksinasi terdiri dari 300 karakter
char sertif[1][30];


void vaksinSertGen(int gel, char nikPasien[11]) {
	//Menggabungkan huruf depan(VKS) kemudian mengambil batch vaksinasi(variabel gel)
	//menambah tahun,bulan,tanggal menggunakan time.h
	//menambah nik dengan mengambil variabel NIK
	struct tm *Sys_T;
	time_t Tval;
	Tval = time(NULL);
	Sys_T = localtime(&Tval);
	sprintf(sertif[gel], "VKS%d-%d%d%d-%s", gel + 1, 1900 + Sys_T->tm_year, Sys_T->tm_mon + 1, Sys_T->tm_mday + 3, NIK);//Menyimpan sertifikat
	printf("%s\n", sertif); //tampilkan sertifikat

}

void saveVaksin(int gel) {
	struct tm *Sys_T;
	time_t Tval;
	Tval = time(NULL);
	Sys_T = localtime(&Tval);
	printf("=====================================================\n");
	printf("Sertifikat Vaksin Anda :\n");
	vaksinSertGen(gel, NIK);
	if (gel == 0)
	{
		printf("\n\nVaksinasi Berikutnya pada tanggal\n %d %d %d\n", Sys_T->tm_mday, Sys_T->tm_mon + 2, 1900 + Sys_T->tm_year);
	}
	else if (gel == 1)
	{
		printf("\nVaksinasi Berikutnya pada tanggal %d %d %d\n", Sys_T->tm_mday, Sys_T->tm_mon + 1, 1901 + Sys_T->tm_year);
	}
	printf("=====================================================\n\n");

}

void vaksinasi(int gel) {
	printf("=============================\n");
	printf("VAKSINASI\n");
	printf("=============================\n\n");
	printf("Input Nama Vaksin = ");
	scanf("%s", &vaksin[gel]);
	printf("Anda berada di batch - %d\n", gel + 1);
	batchVaksin = gel;
	printf("Input Tempat Lokasi Vaksin :\n");
	scanf("%s", &lokVaksin);
	system("cls");
	saveVaksin(gel);
}


void InputDataPeserta() {
	char temp1;
	printf("=============================\n");
	printf("INPUT DATA PESERTA\n");
	printf("=============================\n\n");
	printf(" Input NIK = ");
	scanf("%s", &NIK);
	printf(" Input Nama = ");
	scanf("%s", &nama);
	printf(" Input Alamat\n");
	scanf("%s", &alamat[0]);

	printf(" Apakah Anda ingin menambah alamat ? [y/t]");
	scanf(" %c", &temp1);
	if (temp1 == 'y' || temp1 == 'Y')
	{
		printf(" Input Alamat kedua\n");
		fgets(alamat[1], 300, stdin);
	}
	printf(" No Telp Aktif = ");
	char tempNumb[100];
	int valid = 0;
	while (valid == 0)
	{
		scanf("%s", &tempNumb);
		if (strlen(tempNumb) < 11 || strlen(tempNumb) > 12)
		{
			printf("Cek Kembali Nomor Telp Anda!\n");
			valid = 0;
		}
		else
		{
			phone == tempNumb;
			break;
		}
	}
	printf(" Masukan Nama petugas Medis = ");
	scanf("%s", &medis[0]);
	printf("    Masukan No Petugas = ");
	scanf("%s", &medis[1]);
	printf("Apakah anda sudah mendapat vaksin pertama ? [y/t]\n");
	scanf(" %c", &temp1);
	if (temp1 == 'y' || temp1 == 'Y')
	{
		system("cls");
		vaksinasi(1);
	}
	else if (temp1 == 't' || temp1 == 't');
	{
		system("cls");
		vaksinasi(0);
	}


}

void InputDataVaksin() {
	char temp1; //menyiapkan variabel untuk menampungan sementara
	int tgl, bln, thn; //Menyiapkan 3 variabel untuk menampung tanggal, bulan dan tahun
	char batch[3]; //menyiapkan variabel untuk menampung batch
	printf("=============================\n");
	printf("INPUT DATA VAKSIN\n");
	printf("=============================\n\n");
	printf(" Nama Vaksin = ");
	scanf("%s", &namaVaksin); //menerima nama yang diinput user
	printf(" Kode Batch = ");
	scanf("%s", &batch); //menerima inputan nomer batch dari user
	printf(" Sudah Digunakan [y/t] = ");
	scanf(" %c", &temp1); //menanyakan user apakah vaksin sudah digunakan
	if (temp1 == 'y')
		used = 1; // jika iya maka menggandi variabel 'used' menjadi true

	else
		used = 0; // jika tidak maka mengganti variabel 'used' menjadi false

	printf(" Masukan Tanggal Expired [dd mm yyyy]\n");
	int valid = 0; // menyiapkan integer untuk validasi tanggal
	while (valid == 0) // melakukan perulangan selama validasi bernilai 0
	{
		scanf("%d %d %d", &tgl, &bln, &thn); // user memasukan tgl, bulan, tahun
		if (tgl <= 31 && bln <= 12 && thn >= 2021) // melakukan pengecekan apakah format tanggal sudah benar
		{
			break; // jika format sudah benar (tanggal tidak melebihi 31, bulan tidak melebihi 12 tahun tidak kurang dari 2021)
			// maka keluar dari perulangan
		}
		else
		{ // jika format tidak sesuai maka tampilkan pesan dan lanjutkan perulangan
			printf(" Format tanggal salah Harap input Kembali\n");
		}
	}
	// memasukan isi dari variabel bulan, tgl ,tahun ke Array exp
	exp[0] = tgl;
	exp[1] = bln;
	exp[2] = thn;
	system("cls"); // membersihkan layar dan menampilkan pesan berhasil
	printf("==================================\n");
	printf("Semua Data berhasil di input\n");
	printf("==================================\n");
}

void displayVaksin() {
	if (namaVaksin != "") //pengecekan apakah nama vaksin tidak kosong
	{
		system("cls");// membersihkan menu dan menampilkan data
		printf("\n===================================\n");
		printf("  Menampilkan Data Vaksin Yang Ada\n");
		printf("  Nama Vaksin : %s\n", namaVaksin); //tampilkan nama
		printf("  Batch Vaksin : %s\n", batch); // tampilkan batch vaksin
		if (used == 1) // pengecekan variabel 'used'
		{
			//jika bernilai true maka tampilkan status ini
			printf("  Status : Sudah Digunakan\n");
		}
		else
		{
			//jika bernilai false tampilkan pesan ini
			printf("  Status : Belum Digunakan\n");
		}
		//menampilkan tanggal expired dengan memanggil array exp
		printf("  Expired : %d %d %d\n", exp[0], exp[1], exp[2]);
		printf("===================================\n\n");

	}
	else //jika kosong maka tampilkan pesan ini
	{
		printf("Belum Ada Vaksin Yang Di Input\n");
	}

}


int main() {
	//Time ? is it about that time ?

	////////////////////////////////
	int menu = 0;
	int gel;
	while (menu != 5)
	{
		printf("Selamat Datang Di Aplikasi Vaksin\n");
		printf("Silahkan Pilih Menu Dibawah :\n");
		printf("[1] Input Data Vaksin\n[2] Vaksin Peserta\n[3] Data Vaksin\n[4] Sertifikat Vaksin\n[5] Exit\n");
		scanf("%d", &menu);
		if (menu == 1) {
			system("cls");
			InputDataVaksin();

		}
		if (menu == 2)
		{
			system("cls");
			InputDataPeserta();

		}
		if (menu == 3) {
			displayVaksin();
		}
		if (menu == 4)
		{
			system("cls");
			printf("Masukan Batch Anda [1/2]");
			scanf("%d", &gel);
			saveVaksin(gel);
		}
	}

}
