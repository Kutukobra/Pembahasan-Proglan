#CASE STUDY 3 - PEMROGRAMAN LANJUT
-----
## Soal 1 (60%)
Pada suatu hari, Romani Archaman dari Chaldea Security Organization meminta anda untuk membantunya dalam masalah yang sedang ia hadapi. Ia meminta anda untuk membantunya dalam mengklasifikasikan servant dari Fate/Grand Order berdasarkan rarity-nya. Ia meminta anda untuk membuatkan sebuah program yang dapat mengklasifikasikan servant berdasarkan rarity-nya. Berikut ketentuannya:
- Program dapat menyimpan dan menerima input sebanyak **N servant**, dengan isi servant berupa **nama**, **class**, dan **rarity** (Dengan menggunakan **struct**).
- Program dapat mengurutkan servant berdasarkan rarity-nya dari yang paling tinggi hingga yang paling rendah.
- Program harus mengimplementasikan **modular programming**, dengan minimal terdapat 1 buah fungsi, yaitu fungsi untuk mengurutkan servant berdasarkan rarity-nya.
- Program harus dapat menampilkan **output** berupa **nama**, **class**, dan **rarity** dari servant yang telah diurutkan. **OUTPUT TOLONG DISESUAIKAN**
Bantulah Romani Archaman dalam menyelesaikan masalahnya!

## Soal 2 (15%)
Setelah program yang kalian jadi, Ia meminta fitur tambahan, yaitu program bisa menerapkan error handling disaat terdapat **servant dengan rarity yang sama**, maka program harus mengurutkannya juga dengan **nama servant** dari **A-Z**.

## Soal 3 (25%)
Setelah selesai membantu Romani Archaman, anda kembali ke kantor untuk melanjutkan pekerjaan anda. Ternyata, tugas anda belum selesai. Kali ini, Romani Archaman meminta anda untuk membantunya dalam menyelesaikan masalah yang lebih kompleks. Ia meminta anda untuk membuatkan sebuah program yang dapat mengklasifikasikan servant dari Fate/Grand Order berdasarkan **nama dan class-nya**. Berikut ketentuannya:
- Ketentuan yang diberikan sama seperti soal 1, hanya saja program harus dapat mengurutkan servant berdasarkan **nama dan class-nya** dari **A-Z**.
- Terdapat 2 fungsi baru yang harus diimplementasikan, yaitu fungsi untuk mengurutkan servant berdasarkan **nama** dan fungsi untuk mengurutkan servant berdasarkan **class**.
- Membuat error handling untuk mengatasi **servant dengan nama atau class yang sama**.
- Program harus dapat menampilkan **output** berupa **nama**, **class**, dan **rarity** dari servant yang telah diurutkan. **OUTPUT TOLONG DISESUAIKAN**
-------------------------

<font size="5">
"Fairy tales are more than true: not because they tell us that dragons exist,
 but because they tell us that dragons can be beaten." 
 <br>- G.K. Chesterton
</font>

-------------------------

#Pembahasan:
Diketahui bahwa dalam soal ini ada klasifikasi karakter wibu yang terdiri atas integer rarity, string nama, dan string class. Untuk memudahkan proses, sebuah struct dapat digunakan sebagai tipe data Servant.
```c
typedef struct servant // Typedef agar dapat langsung dipanggil...
{
    char name[30];
    char class[30];
    int rarity;
} Servant; // ...sebagai servant
```
Dalam kasus ini untuk string digunakan array char dengan size default 30 untuk memudahkan.



Case Study ini meminta pengurutan (sorting) dan karena google boleh digunakan (makasih aslab tercinta), berikut algoritma sorting dari GeeksforGeeks. [Bubblesort](https://youtu.be/xli_FI7CuzA?si=xyZX3mUe_N2o3ANe) digunakan karena algoritmanya sederhana dan pada kasus ini karena jumlah data sedikit, kecepatan algoritma tidak terlalu penting. Algoritma Bubble Sort sendiri tidak akan dibahas di sini.
![Bubble sort](https://upload.wikimedia.org/wikipedia/commons/5/54/Sorting_bubblesort_anim.gif)

```c
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = *a;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
```

```Loh kan ini sorting buat integer?? Mank bisa???```

Ya tinggal diganti aja jadi menerima struct Servant kita tadi.
```c
void swap(Servant *a, Servant *b)
{
    Servant temp = *a;
    *a = *b;
    *b = *a;
}

void bubbleSortServants(Servant arr[], int n) // Menerima struct Servant
{
    int i, j;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
```
```LOH MALAH ERROR??```<br>
Dalam kasus ini Servant tidak  bisa dibandingkan, makanya akan error di bagian
```c 
...
if (arr[j] > arr[j + 1]) {
...
```
karena arr bertipe Servant, komputernya kebingungan bagian mana yang dibandingkan dari Servant, kita belum ngasih tahu secara spesifik apa yang mau dibandingkan.

Solusinya sederhana, jika kita ingin membandingkan raritynya maka tinggal diberi .rarity untuk membandingkan data rarity di dalam struct tersebut.
```c
...
if (arr[j].rarity > arr[j + 1].rarity) // Jika array pada j lebih besar dari j + 1,
{
    swap(&arr[j], &arr[j + 1]); // maka tukar
    swapped = true;
}
...
```
Hampir semua algoritma sorting memiliki satu bagian dari kodenya yang membandingkan konten array yang disortir, pada bagian itu hubungan data dalam array mempengaruhi proses yang dijalankan algoritma selanjutnya (seperti swapping).

Dalam kasus bubble sort ini, kita bisa membayangkan bahwa jika data pada posisi j lebih besar dari j + 1, kita tukar. Hal ini dilakukan karena data pada j lebih besar dari j + 1 bukanlah posisi yang benar bagi sebuah array terurut dari kecil ke terbesar. 
Karena kita ingin mengurutkan rarity servant dari yang terbesar ke terkecil, maka tinggal kita balik saja tandanya sehingga keseluruhan kode menjadi
```c
void bubbleSort(Servant *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j].rarity < arr[j + 1].rarity) // Jika rarity pada j lebih kecil dari j + 1
            {
                swap(&arr[j], &arr[j + 1]); // Tukar karena kita ingin terurut dari paling besar
                swapped = true;
            }
        }
    }
}
```

Hore, nomor 1 sudah selesai 🎉🎉🎉.



```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum bool
{
    false,
    true
} bool;



void swap(Servant *a, Servant *b)
{
    Servant temp = *a;
    *a = *b;
    *b = temp;
}

bool compRarity(Servant a, Servant b)
{
    if (a.rarity == b.rarity)
    {
        return (strcmp(a.name, b.name) < 0);
    }
    return a.rarity > b.rarity;
}

bool compName(Servant a, Servant b)
{
    return (strcmp(a.name, b.name) < 0);
}

bool compClass(Servant a, Servant b)
{
    return strcmp(a.class, b.class) < 0;
}

void bubbleSort(Servant *arr, int n, bool (*comp)(Servant, Servant))
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (!comp(arr[j], arr[j + 1])) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
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
    Servant *sort_servants = malloc(sizeof(Servant) * n);
    
    scanServants(servants, n);

    for (int i = 0; i < n; i++)
    {
        sort_servants[i] = servants[i];
    }



    printf("Unsorted servants:\n");
    printf("Name Class Rarity\n");
    printServants(servants, n);
    putchar('\n');

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
            bubbleSort(sort_servants, n, compRarity);
            break;
        
        case 2:
            bubbleSort(sort_servants, n, compName);
            break;
        
        case 3:
            bubbleSort(sort_servants, n, compClass);
            break;
    }

    
    putchar('\n');
    printf("Sorted servants:\n");
    printf("Name Class Rarity\n");
    printServants(sort_servants, n);

    return 0;
}
``


