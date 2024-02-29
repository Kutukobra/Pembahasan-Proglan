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

## Nomor 1

Case Study ini meminta pengurutan (sorting) dan karena google boleh digunakan (makasih aslab tercinta), berikut algoritma sorting dari GeeksforGeeks. [Bubblesort](https://youtu.be/xli_FI7CuzA?si=xyZX3mUe_N2o3ANe) digunakan karena algoritmanya sederhana dan pada kasus ini karena jumlah data sedikit, kecepatan algoritma tidak terlalu penting. Algoritma Bubble Sort sendiri tidak akan dibahas di sini.

![Bubble sort](https://upload.wikimedia.org/wikipedia/commons/5/54/Sorting_bubblesort_anim.gif)

```c
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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
    *b = temp;
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

Solusinya sederhana, jika kita ingin membandingkan rarity-nya maka tinggal diberi .rarity untuk membandingkan data rarity di dalam struct tersebut.
```c
...
if (arr[j].rarity > arr[j + 1].rarity) // Jika array pada j lebih besar dari j + 1,
{
    swap(&arr[j], &arr[j + 1]); // maka tukar
}
...
```
Hampir semua algoritma sorting memiliki satu bagian dari kodenya yang membandingkan konten array yang disortir, pada bagian itu hubungan data dalam array mempengaruhi proses yang dijalankan algoritma selanjutnya (seperti swapping).

Dalam kasus bubble sort ini, kita bisa membayangkan bahwa jika rarity arr[j] lebih besar dari rarity arr[j + 1], maka kita tukar. 
Hal ini dilakukan karena jika data pada j lebih besar dari j + 1, urutanya belum dari terkecil ke terbesar. 
Karena kita ingin mengurutkan rarity servant dari yang terbesar ke terkecil, maka tinggal kita balik saja tandanya sehingga keseluruhan kode menjadi
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct servant
{
    char name[30];
    char class[30];
    int rarity;
} Servant;

void swap(Servant *a, Servant *b) // Fungsi penukar konten
{
    Servant temp = *a;
    *a = *b;
    *b = temp;
}

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
            }
        }
    }
}

void scanServants(Servant *servants, int n) // Fungsi untuk menginput array servant
{
    for (int i = 0; i < n; i++)
    {
        scanf(" %[^\n]s", servants[i].name);
        scanf("%s", &servants[i].class);
        scanf("%d", &servants[i].rarity);
    }
}

void printServants(Servant *servants, int n) // Fungsi untuk mengoutput array servant
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
    int n; // Jumlah servant
    scanf("%d", &n);
    
    Servant *servants = malloc(sizeof(Servant) * n); //  Alokasi dinamis array servant

    scanServants(servants, n);

    printf("Unsorted servants:\n"); // Print servant sebelum diurutkan
    printServants(servants, n);

    bubbleSort(servants, n); // Urutkan servant dari rarity terbesar

    printf("\n");
    printf("Sorted servants:\n"); // Print servant terurut
    printServants(servants, n);
    
    return 0;
}
```

Hore, nomor 1 sudah selesai 🎉.

## Nomor 2
Nomor 2 sama saja dengan nomor 1, namun kali ini jika ada 2 Servant dengan rarity yang sama, diurutkan lagi berdasarkan namanya.
Untuk mengurutkan nama, sebuah string, kita dapat menggunakan fungsi strcmp(char *a, char *b) dari library <string.h>.
```c
strcmp(const char *str1, const char *str2);
```
strcmp menerima 2 buah string (char array) dan akan menghasilkan output:
```
0                jika kedua string sama
> 0 (positif)    jika str1 lebih "besar" dari str2
< 0 (negatif)    jika str1 lebih "kecil" dari str2
```

maka dengan menggunakan fungsi tersebut di porsi perbandingan dari nomor 1
```c
...
for (j = 0; j < n - i - 1; j++) 
{
    if (strcmp(arr[j].name, arr[j + 1].name) > 0) // Jika nama pada arr[j] lebih besar dari nama pada arr[j + 1]
    {
        swap(&arr[j], &arr[j + 1]); // Tukar karena kita ingin terurut dari paling "kecil" (alfabetikal)
    }
}
...
```
kita dapat mengurutkan array berdasarkan namanya.

Masalahnya yang diminta soal nomor 2 itu mengurutkan berdasarkan nama JIKA rarity-nya sama. Kita bisa saja menggunakan if 2 kali seperti ini:
```c
void bubbleSort(Servant *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j].rarity == arr[j + 1].rarity) // Jika rarity pada j sama dengan j + 1
            {
                if (strcmp(arr[j].name, arr[j + 1].name) > 0) // Bandingkan stringnya
                {
                    swap(&arr[j], &arr[j + 1]); // Tukar karena kita ingin terurut dari paling "kecil" (alfabetikal)
                }
            }
            else if (arr[j].rarity > arr[j + 1].rarity) // Jika ternyata tidak sama
            {
                swap(&arr[j], &arr[j + 1]); // Tukar berdasarkan rarity
            }
        }
    }
}
```
Solusi ini tidak salah, secara teknis nomor 2 sudah selesai, tapi cara seperti ini tidak efisien, tidak elegan, tidak cakep, jelek, buruk secara long term karena bayangin kalau persyaratannya lebih kompleks lagi, kita harus bikin if else lebih banyak lagi. 

Solusi yang dapat digunakan untuk permasalahan ini adalah dengan menggunakan fungsi terpisah. 
```c
int fungsi_perbandingan(Servant a, Servant b)
{
    if (a.rarity == b.rarity) // Jika rarity sama
    {
        return strcmp(a.name, b.name) < 0; // Mengembalikan 0 jika hasil nama a lebih besar dari b dan 1 jika a lebih kecil
    }
    else
    {
        return a.rarity > b.rarity; // Mengembalikan 0 jika rarity a lebih kecil dari b dan 1 jika lebih besar
    }
}

void bubbleSort(Servant *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (fungsi_perbandingan(arr[j], arr[j + 1]) == 0) // Jika fungsi pengecek menghasilkan 0 (kondisi belum terpenuhi)
            {
                swap(&arr[j], &arr[j + 1]); // Tukar
            }
        }
    }
}
```
hmm, ya , sangat modular, Pak Dodi approve ini (mungkin).

fungsi_perbandingan() akan mengembalikan 0 jika kondisi urutan array belum sesuai keinginan. Bahasa lebih manusiawinya begini:
```c
int fungsi_perbandingan(Servant a, Servant b)
{
    if (a.rarity == b.rarity) // Jika rarity sama
    {
        if (strcmp(a.name, b.name) < 0) // Bandingkan berdasarkan nama
        {
            return 1; // Kembalikan 1 jika sudah sesuai
        } 
        else
        {
            return 0;
        }
    }
    else
    {
        if (a.rarity > b.rarity)
        {
            return 1; // Kembalikan 1 jika sudah sesuai
        }
        else
        {
            return 0;
        }
    }
}
```
Kode komplit untuk nomor 2:
```c
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

int fungsi_perbandingan(Servant a, Servant b)
{
    if (a.rarity == b.rarity) // Jika rarity sama
    {
        return strcmp(a.name, b.name) < 0; // Mengembalikan 0 jika hasil nama a lebih besar dari b dan 1 jika a lebih kecil
    }
    else
    {
        return a.rarity > b.rarity; // Mengembalikan 0 jika rarity a lebih kecil dari b dan 1 jika lebih besar
    }
}

void bubbleSort(Servant *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (fungsi_perbandingan(arr[j], arr[j + 1]) == 0) // Jika fungsi pengecek menghasilkan 0 (kondisi belum terpenuhi)
            {
                swap(&arr[j], &arr[j + 1]); // Tukar
            }
        }
    }
}

void scanServants(Servant *servants, int n) // Fungsi untuk menginput array servant
{
    for (int i = 0; i < n; i++)
    {
        scanf(" %[^\n]s", servants[i].name);
        scanf("%s", &servants[i].class);
        scanf("%d", &servants[i].rarity);
    }
}

void printServants(Servant *servants, int n) // Fungsi untuk mengoutput array servant
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
    int n; // Jumlah servant
    scanf("%d", &n);
    
    Servant *servants = malloc(sizeof(Servant) * n); //  Alokasi dinamis array servant

    scanServants(servants, n);

    printf("Unsorted servants:\n");
    printServants(servants, n);

    bubbleSort(servants, n);
    printf("\n");
    printf("Sorted servants:\n");
    printServants(servants, n);
    
    return 0;
}
```
Hore, nomor 2 selesai juga 🎉🎉.

##Nomor 3
Untuk nomor 3, kali ini pengguna program dapat memilih untuk melakukan sorting berdasarkan rarity, nama, atau class. Kita bisa saja membuat fungsi bubblesort yang berbeda-beda untuk setiap kondisi, tapi kalau begitu caranya tidak efektif karena sebenarnya algoritmanya sama semua, kondisinya saja yang beda. 

```Di nomor 2 tadi kita misahin kondisi penentu ke fungsi terpisah, kira-kira bisa nggak itu aja yang berubah???```

BISA BANGET, ayo kenalan sama ✨function pointer✨.

Misalkan ada sebuah fungsi A yang di dalamnya memanggil fungsi lain, kita bisa mengubah-ubah fungsi yang dipanggil di dalam A dengan menggunakan function pointer.
```c
void fungsiB()
{
    printf("Alex IPK 4\n");
}

void fungsiC()
{
    printf("Nadzhif bau ketek\n");
}

void fungsiA(void (*fungsiLain)()) // fungsiA menerima pointer dari sebuah fungsi void
{
    printf("Fungsi: "); // Kelakuannya fungsiA
    fungsiLain();   // Memanggil fungsi lain yang dioper
}

int main()
{
    fungsiA(&fungsiB); // Memasukan pointer dari fungsiB ke dalam fungsiA
    /*
        Output: Fungsi: Alex IPK 4
    */

    fungsiA(&fungsiC); // Memasukan pointer dari fungsiC ke dalam fungsiA
    /*
        Output: Fungsi: Nadzhif bau ketek
    */
}
```

Dengan begini, kita bisa menggunakan fungsi-fungsi berbeda sebagai fungsi perbandingan dalam fungsi sorting.
```c
// Fungsi-fungsi pembanding
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
```

Dengan begini, nomor 3 dapat diselesaikan dengan function pointer serta switch case untuk memilihnya.

```c
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
```
SELESAI SEMUA HORE 🎉🎉🎉


Makasih ya udah mau baca, kalo lu baca semua sampe sini berarti lu punya kemauan untuk belajar dan gua apresiasi itu. 

Orang bodoh itu bukan mereka yang belum mampu, tapi mereka yang tidak mau belajar dan berubah. Jadi just go for it 💪💪💪


Kritik dan saran saya terima.

Bikin pembahasan >>> duduk di lantai sampe tengah malem 

------
Muhammad Nadzhif Fikri, 29  Februari 2024