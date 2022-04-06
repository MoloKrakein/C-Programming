#include <stdio.h>
// UNION

// union Job
// {
//     float gaji;
//     int noPegawai;
// } j;

// int main(){
//     j.gaji = 2.3;
//     j.noPegawai = 2;

//     printf("Gaji adalah = %.1f\n",j.gaji);
//     printf("%d",j.noPegawai);
// }


void arrPrinter(int array[],int s){
    for (int i = 0; i < s; i++)
    {
       printf("%d ",array[i]);
    }
    printf("\n");
}

void inserSort(int arr[],int s){
    for (int i = 0; i < s; i++)
    {
        int k = arr[i];
        int j = i -1;

        while (k<arr[j] && j>=0)
        {
            arr[j+1]=arr[j];
            --j;
        }
        arr[j+1]=k;
        
    }
    
}

int main(){
    int arrey[5];
    printf("Masukan 5 Angka");
    scanf("%d %d %d %d %d",&arrey[0],&arrey[1],&arrey[2],&arrey[3],&arrey[4]);
    int s = sizeof(arrey)/sizeof(arrey[0]);
    inserSort(arrey,s);
    arrPrinter(arrey,s);
}
