#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct servant
{
    char name[30];
    char class[30];
    int rarity;
} Servant;

void swap(Servant *a, Servant *b)
{
    Servant temp = *a;
    *a = *b;
    *b = temp;
}

int urutkanRarity(Servant a, Servant b) // Bandingkan berdasarkan rarity, sama seperti nomor 2
{
    if (a.rarity == b.rarity)
    {
        return (strcmp(a.name, b.name) < 0);
    }
    else
    {
        return a.rarity > b.rarity;
    }
}

int urutkanName(Servant a, Servant b) // Bandingankan berdasarkan nama
{
    if (strcmp(a.name, b.name) == 0) // Jika nama sama, bandingkan berdasarkan rarity
    {
        return (a.rarity > b.rarity);
    }
    else
    {
        return (strcmp(a.name, b.name) < 0); // Mengembalikan 0 jika nama a lebih "besar" dari nama b
    }
}

int urutkanClass(Servant a, Servant b) // Bandingankan berdasarkan nama
{
    if (strcmp(a.class, b.class) == 0) // Jika class sama, bandingkan berdasarkan rarity
    {
        return (a.rarity > b.rarity);
    }
    else
    {
        return (strcmp(a.class, b.class) < 0); // Mengembalikan 0 jika class a lebih "besar" dari class b
    }
}

void bubbleSort(Servant *arr, int n, int (*fungsi_perbandingan)(Servant, Servant)) // Bubblesort menerima fungsi int yang menerima 2 buah parameter Servant
{
    int i, j;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (fungsi_perbandingan(arr[j], arr[j + 1]) == 0) // Jika fungsi perbandingan mengembalikan 0 (kondisi terurut belum terpenuhi)
            {
                swap(&arr[j], &arr[j + 1]); // Tukar
            }
        }
    }
}

void scanServants(Servant *servants, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf(" %[^\n]s", servants[i].name);
        scanf("%s", &servants[i].class);
        scanf("%d", &servants[i].rarity);
    }
}

void printServants(Servant *servants, int n)
{
    printf("Name Class Rarity\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s ", servants[i].name);
        printf("%s ", servants[i].class);
        printf("%d\n", servants[i].rarity);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    Servant *servants = malloc(sizeof(Servant) * n);
    
    scanServants(servants, n);

    printf("Unsorted servants:\n");
    printServants(servants, n);

    printf("Choose the sorting mode: \n");
    printf("1. Sort by rarity: \n");
    printf("2. Sort by name: \n");
    printf("3. Sort by class: \n");
    printf("Enter the soritng mode: ");
    int option;
    scanf("%d", &option);

    switch (option)
    {
        case 1:
            bubbleSort(servants, n, &urutkanRarity);
            break;
        
        case 2:
            bubbleSort(servants, n, &urutkanName);
            break;
        
        case 3:
            bubbleSort(servants, n, &urutkanClass);
            break;
    }

    
    printf("\n");
    printf("Sorted servants:\n");
    printServants(servants, n);

    return 0;
}