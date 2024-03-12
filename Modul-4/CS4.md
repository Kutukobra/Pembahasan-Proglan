# Case Study 4 - Searching
## Soal 1 (85%)
Pada suatu hari di perusahaan Kim Dokja Company, sedang mengadakan proses perekrutan pekerja baru. Tentu karena ini pertama kalinya dalam sejarah perusahaan untuk membuka lamaran pekerjaan, banyak pelamar yang hadir. Karena hal tersebut, Kim Dokja, selaku pemilik perusahaan, meminta anda (sebagai bawahan IT-nya) untuk **membuat sebuah program** yang dapat menginput biodata pelamar dan menambahkan fitur searching database pelamar tersebut. 
Pada 1 (satu) hari terdapat batasan untuk jumlah input biodata per harinya. Ia meminta program tersebut dapat melakukan searching berdasarkan **nama atau IPK**. Namun, karena satu dan dua hal, ia ingin anda membuat menu dimana ia dapat menentukan kapan menggunakan searching berdasarkan nama atau IPK. Jika memilih nama, maka program akan mencari nama yang sama persis (case sensitive). Jika memilih IPK, maka program akan mencari yang sama persis. kalau tidak ada, cari yang mendekati. Dengan kondisi berikut:
- Yang paling mendekati dari atas dengan IPK yang diinput
- Apabila ditemukan lebih dari satu data yang paling mendekati IPK tersebut, maka program dapat menampilkan semuanya

### Batasan
1. Banyaknya jumlah input biodata pelamar per hari adalah N, dimana **2 ≤ N ≤ 100**
2. Atribut objek `pelamar` berupa `nama` dan `IPK`
3. Program meminta menu untuk memilih searching berdasarkan nama atau IPK, dengan input berupa angka 1 atau 2
4. Program meminta input nama atau IPK yang akan dicari
5. Minimal terdapat 1 (satu) buah fungsi selain fungsi utama atau `main()`
6. Rentang `IPK` adalah **0.00 ≤ IPK ≤ 4.00**
7. Atribut `nama` berupa nama panjang, bisa lebih dari 1 (satu) kata
8. Program dikerjakan pada file `.c` yang sudah disediakan


## Soal Bonus (15%)
Kim Dokja ingin program tersebut membuat UX (User Experience) yang ramah pengguna, sehingga ia terpikirkan akan suatu fitur. Adapun fitur fitur tersebut adalah
- Jika user ingin mencari nama, maka input nama dapat case-insensitive. Sehingga, jika user menginput "kim dokja" atau "KIM DOKJA" atau "Kim Dokja", program akan tetap menemukannya. 
- Apabila rentang `IPK` diluar batasan, maka program akan meminta input ulang hingga sesuai dengan batasan. Contoh bilangan negatif
- Apabila `N` diluar batasan, maka program akan meminta input ulang hingga sesuai dengan batasan. Contoh bilangan negatif

| Input | Output | Input | Output | Input | Output |
|---|---|---|---|---|---|
| 5<br>Kim Dokja<br>3.7<br>Yoo Joonghyuk<br>4<br>Yoo Sanggah<br>3.4<br>Secretive Plotter<br>3.9<br>Oldest Dream<br>3.55<br>2<br>4 | Yoo Joonghyuk<br>4.00 | 5<br>Kim Dokja<br>3.7<br>Yoo Joonghyuk<br>4<br>Yoo Sanggah<br>3.4<br>Secretive Plotter<br>3.9<br>Oldest Dream<br>3.55<br>2<br>2 | Yoo Sanggah<br>3.40 | 5<br>Kim Dokja<br>3.7<br>Yoo Joonghyuk<br>4<br>Yoo Sanggah<br>3.4<br>Secretive Plotter<br>3.9<br>Oldest Dream<br>3.55<br>1<br>Kim | Kim Dokja<br>3.70 |
| 5<br>Kim Dokja<br>3.7<br>Yoo Joonghyuk<br>4<br>Yoo Sanggah<br>3.4<br>Secretive Plotter<br>3.9<br>Oldest Dream<br>3.55<br>2<br>3.85 | Secretive Plotter<br>3.90 | 5<br>Kim Dokja<br>3.7<br>Yoo Joonghyuk<br>4<br>Yoo Sanggah<br>3.4<br>Secretive Plotter<br>3.9<br>Oldest Dream<br>3.55<br>1<br>Kim Dokja | Kim Dokja<br>3.70 | 5<br>Kim Dokja<br>3.7<br>Yoo Joonghyuk<br>4<br>Yoo Sanggah<br>3.4<br>Secretive Plotter<br>3.9<br>Oldest Dream<br>3.55<br>1<br>Yoo | Yoo Joonghyuk<br>4.00<br>Yoo Sanggah<br>3.40 |
| 5<br>Kim Dokja<br>3.7<br>Yoo Joonghyuk<br>4<br>Yoo Sanggah<br>3.4<br>Secretive Plotter<br>3.9<br>Oldest Dream<br>3.55<br>1<br>Yoo Sanggah | Yoo Sanggah<br>3.40 | 9<br>Kim Dokja<br>3.7<br>Yoo Joonghyuk<br>4<br>Yoo Sanggah<br>3.4<br>Secretive Plotter<br>3.9<br>Oldest Dream<br>3.55<br>Lee Gilyoung<br>2.3<br>Lee Jihye<br>3.2<br>Lee Sookyung<br>4.0<br>Lee Hyunsung<br>1.3<br>1<br>Lee | Lee Gilyoung<br>2.30<br>Lee Jihye<br>3.20<br>Lee Sookyung<br>4.00<br>Lee Hyunsung<br>1.30 | 9<br>Kim Dokja<br>3.7<br>Yoo Joonghyuk<br>4<br>Yoo Sanggah<br>3.4<br>Secretive Plotter<br>3.9<br>Oldest Dream<br>3.55<br>Lee Gilyoung<br>2.3<br>Lee Jihye<br>3.2<br>Lee Sookyung<br>4.0<br>Lee Hyunsung<br>1.3<br>2<br>3.5 | Oldest Dream<br>3.55 |

| Input | Output | Input | Output |
|---|---|---|---|
| -3<br>-5<br>6<br>Yuji Itadori<br>2.3<br>Gojo Satoru<br>5.3<br>4<br>Ryomen Sukuna<br>-1<br>3.9<br>Yuta Okkotsu<br>3.6<br>Suguru Geto<br>3<br>Nobara Kugisaki<br>3.8<br>2<br>3.75 | Nobara Kugisaki<br>3.80 | 9<br>Kim Dokja<br>3.7<br>Yoo Joonghyuk<br>4<br>Yoo Sanggah<br>3.4<br>Secretive Plotter<br>3.9<br>Oldest Dream<br>3.55<br>Lee Gilyoung<br>2.3<br>Lee Jihye<br>3.2<br>Lee Sookyung<br>4.0<br>Lee Hyunsung<br>1.3<br>1<br>lee | Lee Gilyoung<br>2.30<br>Lee Jihye<br>3.20<br>Lee Sookyung<br>4.00<br>Lee Hyunsung<br>1.30 |
| 9<br>Kim Dokja<br>3.7<br>Yoo Joonghyuk<br>4<br>Yoo Sanggah<br>3.4<br>Secretive Plotter<br>3.9<br>Oldest Dream<br>3.55<br>Lee Gilyoung<br>2.3<br>Lee Jihye<br>3.2<br>Lee Sookyung<br>4.0<br>Lee Hyunsung<br>1.3<br>1<br>dokja | Kim Dokja<br>3.70 | 5<br>Kim Dokja<br>3.7<br>Yoo Joonghyuk<br>4<br>Yoo Sanggah<br>3.4<br>Secretive Plotter<br>3.9<br>Oldest Dream<br>3.55<br>1<br>ol | Oldest Dream<br>3.55 |

----------

<font size="5">
“Failure is only the opportunity to begin again. Only this time, more wisely.” 
<br>- Uncle Iroh
</font>

---------
# Pembahasan:
Untuk memudahkan, kita bakal pakai struct untuk "memaketkan" data.
```c
typedef struct Pelamar
{
    char nama[30];
    float IPK;
} Pelamar;
```
yang dapat disajikan menggunakan
```c
void printPelamar(const Pelamar *pelamar)
{
    printf("%s\n", pelamar->nama);
    printf("%.2f\n", pelamar->IPK);
}
```
----------
## Bagian 1: Cari IPK
Pada kasus pertama, aslab meminta kita untuk mencari upper bound dari data. Upper bound, sesuai dengan soal berupa data yang lebih besar atau sama dengan dari target. Jika data ditemukan maka indeks target dikembalikan, tetapi jika data tidak ditemukan maka yang dikembalikan berupa data pertama yang lebih besar dari target tersebut. Sederhananya upper bound itu angka yang setidaknya lebih dari target tapi ga jauh-jauh amat.

Untuk menemukan upper bound dari data tidak terurut, linear search sederhana dapat menjadi solusi sederhana yang efisien.

Fungsi memeriksa setiap Pelamar dengan IPK yang sama dengan atau lebih dari target (>=), lalu menyimpan besaran IPK tersebut jika jaraknya paling kecil dari target.

Diketahui sebuah fungsi yang menerima array dari setiap pelamar, n sebagai jumlah pelamar, dan float target IPK, dibentuk fungsi sebagai berikut:

```c

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
```

```c
...    
    // Penyimpanan upper_bound saat ini
    float upper_bound;

    // Difference sebagai jarak bilangan, mulai dari 4 (jarak terbesar)
    float difference_lowest = 4;
...
```
Fungsi memiliki float ```upper_bound``` untuk menyimpan upper bound sejauh itu dan ```difference lowest``` untuk menyimpan jarak yang paling kecil dengan value permulaan 4 karena IPK 4 (Alexander Christhian) adalah jarak terbesar yang mungkin ada di data ini. Jika jarak data pada saat Pelamar 
```c
    ...
    // Cari upper_bound
    for (int i = 0; i < n; i++)
    {
        float difference = pelamar_array[i].IPK - target;
    ...
``` 
lebih kecil dari jarak-jarak sebelumnya, ```difference_lowest```, maka jarak terkecil diganti menjadi ```difference``` tersebut.
```c
...
    // Jika di atas target dan lebih mendekati dari sebelumnya
    if ((pelamar_array[i].IPK >= target) && (difference < difference_lowest))
    {
        // Tetapkan jadi upper bound
        upper_bound = pelamar_array[i].IPK;
        difference_lowest = difference;
    }
...
```
Karena soal meminta setiap data yang sesuai, maka fungsi melakukan looping ulang namun kali ini melakukan printing untuk setiap data dengan IPK yang sama dengan upper bound.
```c
...
    // Print setiap pelamar dengan IPK upper_bound
    for (int i = 0; i < n; i++)
    {
        if (pelamar_array[i].IPK == upper_bound)
        {
            printPelamar(&pelamar_array[i]);
        }
    }
...
```

Hore fungsi pertama selesai, sit back, relax, enjoy, buka puasa, tidur siang, atau apapun itu tapi ini baru permulaan.

-----

## Bagian 2: Cari Nama

Pada bagian opsi ke-2 dari program, kali ini user dapat memasukan sederet string dan menampilkan data setiap pelamar yang mengandung string tersebut di namanya.

```Alamak bro, ini bagaimana caranya?? Sulit sekali.```
Benar, kalau dicari pakai fungsi manual sebenarnya bisa. Kita bisa aja cocok-cocokin setiap karakter terus kalo ada string itu kita ambil, tapi ini bakal repot banget dan nggak efisien.
```Terus gimana??```
Kebetulan sekali para sesepuh developer C pendahulu udah bikin suatu library penuh berkah 🆙 ```string.h```🆙.

Di dalam string.h terdapat suatu fungsi bernama `strstr` yang tepat berfungsi untuk ini.
Berikut manual page dari strstr:

### strstr man page:
```
SYNOPSIS
       #include <string.h>

       char *strstr(const char *haystack, const char *needle);

       #define _GNU_SOURCE         /* See feature_test_macros(7) */

       #include <string.h>

       char *strcasestr(const char *haystack, const char *needle);

DESCRIPTION
       The strstr() function finds the first occurrence of the substring needle in the string haystack.  The terminating null bytes ('\0') are not compared.

       The strcasestr() function is like strstr(), but ignores the case of both arguments.

RETURN VALUE
       These functions return a pointer to the beginning of the located substring, or NULL if the substring is not found.          
    ...
```
Berdasarkan informasi di atas, strstr() menerima dua buah char* (string), haystack dan needle. strstr() akan mengembalikan pointer pada string haystack yang menunjukan posisi pertama kemunculan string needle. Jika ternyata string needle tidak ditemukan di dalam haystack, fungsi akan mengembalikan NULL atau 0. Dengan begini kita dapat memanfaatkan fungsi ini untuk melakukan pencarian.

```c
...
void findPrintNama(const Pelamar* pelamar_array, const int n, const char* target)
{
    for (int i = 0; i < n; i++)
    {
        // Jika target ada di dalam nama pelamar
        if (strstr(pelamar_array[i].nama, target) != NULL)
        {
            // Print pelamar
            printPelamar(&pelamar_array[i]);
        }
    }
}
...
```
Fungsi findPrintNama menerima array dari pelamar, n sebagai jumlah pelamar, dan string target. Fungsi melakukan looping untuk setiap member dari array pelamar dan melakukan pencarian string target di dalam nama pelamar. Jika ternyata fungsi strstr tidak mengembalikan 0/NULL, berarti target ditemukan pada nama pelamar tersebut dan program melakukan printing data pelamar tersebut.

Warbiasah, kini program basic dapat diselesaikan dengan kedua fungsi tersebut sebagai berikut:
```c
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

    free(pelamar_array);
    return 0;
}
```

## Bonus:
Pada bonus terdapat beberapa tambahan ke dalam program yang sederhananya berupa:

1. Error Handling Input
2. Case insensitive (kapitalisasi doesn't matter)

Error handling input dapat dilakukan dengan menggunakan do while hingga input yang diterima bagian dari rentang yang diinginkan. 

Dalam batasan disebutkan dua buah rentang:
1. Banyaknya jumlah input biodata pelamar per hari adalah N, dimana 2 ≤ N ≤ 100
2. Rentang IPK adalah 0.00 ≤ IPK ≤ 4.00

Hal ini dapat diimplementasikan sebagai berikut:
```c
...
    do
    {
        scanf("%d", &N);
    } while (N < 2 || N > 100);
...
```
dengan menggunakan do .. while, program akan terus menerus meminta input JIKA N < 2 ATAU N > 100, kondisi ketika input tidak sesuai rentang.

Hal serupa dapat dilakukan dalam melakukan input IPK pada input IPK pelamar dan input IPK pencarian, namun jika diulang-ulang begitu kurang efisien ga sih? Kita sebagai programmer bisa bikin ini lebih rapi dengan modularisasi 🔥.

```c
float scanFloatRange(float minimum, float maximum)
{
    float ret;
    do 
    {
        scanf("%f", &ret);
    } while ((ret) < minimum || (ret) > maximum);
    return ret;
}
```
Fungsi scanFloatRange() ini hanya melakukan persis seperti yang diatas tadi, hanya saja kodenya "dibungkus" sehingga dapat digunakan berkali-kali.

```c
...
void scanPelamar(Pelamar *pelamar)
{
    scanf(" %[^\n]", pelamar->nama);
    pelamar->IPK = scanFloatRange(0, 4); // <----
}
...
...
N = scanFloatRange(2, 100); // <----
...
...
case 2:
        target.IPK = scanFloatRange(0, 4); // <----
        findPrintIPK(pelamar_array, N, target.IPK);
        break;
    }
...

```
------
Kini tinggal error handling satu lagi, pengecekan string yang tidak memedulikan kapitalisasi. Kita bisa saja mengubah setiap string yang dibandingkan menjadi kecil semua atau besar semua agar bisa dibandingkan, namun rupanya para sesepuh pendahulu LAGI-LAGI sudah punya fungsi untuk ini. Namanya `strcasestr()`. Berdasarkan man page yang sama dengan `strstr()`, `strcasestr()` melakukan hal yang sama dengan `strstr()` hanya saja kapitalisasi dari string tidak dipikirkan (enak sekali). 

`Ini compiler ngasih warning kalo make strcasestr gatau kenapa tapi work di gua jadi berdoa saja`.

Dengan menguasai semua elemen tadi, keseluruhan kode jadinya begini:
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Pelamar
{
    char nama[30];
    float IPK;
} Pelamar;

float scanFloatRange(float minimum, float maximum)
{
    float ret;
    do 
    {
        scanf("%f", &ret);
    } while ((ret) < minimum || (ret) > maximum);
    return ret;
}

void scanPelamar(Pelamar *pelamar)
{
    scanf(" %[^\n]", pelamar->nama);
    pelamar->IPK = scanFloatRange(0, 4);
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
        if (strcasestr(pelamar_array[i].nama, target))
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

    N = scanFloatRange(2, 100);
    
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
        target.IPK = scanFloatRange(0, 4);
        findPrintIPK(pelamar_array, N, target.IPK);
        break;
    }
    
    free(pelamar_array);
    return 0;
}
```

NB: variabel untuk target pakai union biar hemat memori karena target yang dicari bisa berbentuk string atau berbentuk float tergantung dengan apa yang dicari.
```c
union
    {
        char nama[30];
        float IPK;
    } target;
    ...
    findPrintNama(pelamar_array, N, target.nama);
    ...
    ...
    findPrintIPK(pelamar_array, N, target.IPK);
    ...
```

Hore luar biasa selesai semua. Maaf ngaret dikit (saya lelah).
------
Muhammad Nadzhif Fikri, 12 Maret 2024