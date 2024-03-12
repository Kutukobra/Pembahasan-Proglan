#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Pelamar
{
    char nama[30];
    float IPK;
} Pelamar;

void scanPelamar(Pelamar *pelamar)
{
    scanf(" %[^\n]", pelamar->nama);
    scanf("%f", &pelamar->IPK);
}

void printPelamar(const Pelamar *pelamar)
{
    printf("%s\n", pelamar->nama);
    printf("%.2f\n", pelamar->IPK);
}

void findPrintIPK(const Pelamar* pelamar_array, const int n, const float target)
{

    // Penyimpanan upper_bound saat ini
    float upper_bound;

    // Difference sebagai jarak bilangan, mulai dari 4 (jarak terbesar)
    float difference_lowest = 4;

    // Cari upper_bound
    for (int i = 0; i < n; i++)
    {
        float difference = pelamar_array[i].IPK - target;

        // Jika di atas target dan lebih mendekati dari sebelumnya
        if ((pelamar_array[i].IPK >= target) && (difference < difference_lowest))
        {
            // Tetapkan jadi upper bound
            upper_bound = pelamar_array[i].IPK;
            difference_lowest = difference;
        }
    }
    

    // Print setiap pelamar dengan IPK upper_bound
    for (int i = 0; i < n; i++)
    {
        if (pelamar_array[i].IPK == upper_bound)
        {
            printPelamar(&pelamar_array[i]);
        }
    }
}

void findPrintNama(const Pelamar* pelamar_array, const int n, const char* target)
{
    for (int i = 0; i < n; i++)
    {
        if (strstr(pelamar_array[i].nama, target))
        {
            printPelamar(&pelamar_array[i]);
        }
    }
}

int main()
{

    int N;
    union
    {
        char nama[30];
        float IPK;
    } target;

    scanf("%d", &N);
    Pelamar *pelamar_array = (Pelamar*)malloc(sizeof(Pelamar) * N);
    
    for (int i = 0; i < N; i++)
    {
        scanPelamar(&pelamar_array[i]);
    }

    int option;
    
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        scanf(" %[^\n]", target.nama);
        findPrintNama(pelamar_array, N, target.nama);
        break;
    
    case 2:
        scanf("%f", &target.IPK);
        findPrintIPK(pelamar_array, N, target.IPK);
        break;
    }
    char *test = malloc(300);
    scanf("%300s", test);
    printf(test);

    free(pelamar_array);
    return 0;
}