# Tugas Pendahuluan 5
Nama:   Muhammad Nadzhif Fikri <br> 
NPM:    2306210102

## 1. Jelaskan apa itu File Handling dan bagaimana cara menggunakannya menurut pemahaman kalian! Lalu coba tanya Chat GPT (atau AI lainnya) pertanyaan yang sama. Analisis kedua jawaban tersebut, apakah sama atau terdapat perbedaan. Menurut kalian jawaban yang lebih informatif yang mana? Yang lebih dapat dipercaya yang mana? <span style="color:red">(40poin)</span>

**Jawaban Anda:**

File Handling adalah metode untuk membuat, mengakses, dan mengubah file eksternal melalui program C. Dalam library `stdio.h` terdapat tipe data FILE yang dapat digunakan untuk mengakses fungsionalitas tersebut. File handling umumnya digunakan untuk menyimpan data permanen yang tersimpan bahkan ketika program selesai. Dengan begini, data pada jalannya program dapat digunakan kembali pada jalan program selanjutnya.

Untuk mengakses sebuah file, file dapat dibuka dengan fungsi 

```c
FILE *fopen(const char *pathname, const char *mode)
````

fungsi ini mengembalikan pointer dari tipe data FILE yang berupa stream yang dapat digunakan untuk memanfaatkan file tersebut kedepannya. Fungsi menerima string pathname yang berupa path ke file yang ingin dibuka. Fungsi juga menerima string mode yang berupa jenis akses yang dapat dilakukan program terhadap file tersebut. Beberapa opsi mode di antaranya:

- "r"    
Membaca dari file
- "w"    
Menulis ke file
- "a"    
Menambahkan data ke akhir file
- "r+"<br>Membaca dan menulis file
- "a+"<br> Membaca dan menambahkan data ke akhir file

tidak hanya itu, tersedia mode untuk mengakses file binary umumnya dengan menambahkan 'b' seperti "rb", "wb", "rb+", dst.

Fungsi-fungsi input output seperti `printf` dan `scanf` sebenarnya mengakses sejenis file stream khusus bernama `stdout` dan `stdin`, dalam kasus FILE HANDLING, fungsi input output dapat dilakukan dengan cara serupa namun menggunakan fungsi-fungsi khusus yang menspesifikasikan file input outputnya:

```c 
int fprintf(FILE *stream, const char *format, ...)
/*
serupa seperti `printf()` namun FILE yang digunakan sebagai output dispesifikasikan dalam parameter stream.
*/

int fscanf(FILE *stream, const char *format, ...)
/*
serupa seperti `scanf()` namun FILE yang digunakan sebagai input dispesifikasikan dalam parameter stream.
*/

...
dst
```

Setelah FILE stream digunakan, pointer dari file ditutup menggunakan fungsi
```c
int fclose(FILE *stream)
```



**Jawaban AI:**

Arrr, me hearty, listen close as I spin ye a tale of file handling in C, the language o' brave seafarers and code-savvy buccaneers!

In C, ye be dealin' with files by using a scurvy dog called a FILE pointer. First off, ye need to include the <stdio.h> header to set sail on this adventure.

Now, let's hoist the Jolly Roger and open a file for plunderin'! Ye do this by callin' the fopen() function, which takes two arguments: the name o' the file ye want to open and a string representin' how ye want to access it. There be options like "r" for readin', "w" for writin', and "a" for appendin'.

c

FILE *treasure_map = fopen("map.txt", "r");

Once ye have the file open, ye can read from it, write to it, or seek its treasures with fread(), fwrite(), and fseek(), respectively. When ye be done with the loot, ye should close the file with fclose() to let other scoundrels access it.

c

fclose(treasure_map);

But beware, matey! Watch for errors along the way. Always check if yer file pointer be null after callin' fopen() to make sure ye didn't hit rock bottom.

That be the basics of file handlin' in C, me hearties. Now go forth and plunder those files with the wisdom o' a seasoned captain! Arrr! 🏴‍☠️

Arrr, me hearty, the seas of programming be vast and treacherous, and file handling in C be like navigatin' those waters. Ye see, file handling be crucial for many a reason:

    Data Storage: Just as a pirate hoards treasures in a chest, programs store their data in files. Ye might be savin' game progress, loggin' messages, or storin' configuration settings.

    Data Retrieval: Like a map leads ye to buried treasure, files hold information ye can retrieve later. Ye can read from files to fetch data like user input or previously saved information.

    Data Sharing: Just as pirates share tales o' their exploits, programs share data via files. One program might write data to a file, and another might read from it, allowin' them to communicate without direct interaction.

    Persistence: Aye, just as the stars guide us on our journey, files provide persistence. They let ye save data beyond the lifetime of a program, so ye can pick up where ye left off when ye return.

    External Interactions: Like encounters with other ships on the high seas, programs often need to interact with external files. Whether ye be readin' from a text file, writin' to a database, or manipulatin' images, file handling be key.

So ye see, matey, file handling in C be as essential as a sturdy ship's hull. It be the means by which yer code interacts with the world beyond, navigatin' the turbulent waters of data with the skill of a seasoned captain. Hoist the sails, me hearties, and set forth on yer coding voyage! 🏴‍☠️

**Analisis kedua jawaban:**

Meskpun menggunakan bahasa yang lebih gaul, jawaban dari AI hanya memberikan overview penggunaan FILE handling secukupnya sementara saya menjelaskan lebih spesifik beberapa fungsi yang dapat digunakan untuk mengakses file. Jawaban AI cukup menjadi garis besar untuk dipelajari lebih lanjut, sementara jawaban saya lebih informatif karena berupa bentuk saya belajar juga.

**Reference:**

- fopen(3) - Linux manual page. Linux manual page. Available: https://man7.org/linux/man-pages/man3/fopen.3.html
- Basics of File Handling in C. GeeksforGeeks. [Online]. Available: https://www.geeksforgeeks.org/basics-file-handling-c/. [Accessed: 18 Mar 2024]

## 2. Kira-kira pada skenario apakah kita perlu mengimplementasikan File Handling pada program kita. Bisakah kita menghapus file handling dari program tersebut dan masih dapat berjalan dengan semestinya. Adakah alternatif lain selain menggunakan File Handling? Jelaskan. <span style="color:red">(30poin)</span>

FILE handling dapat digunakan ketika program membutuhkan data yang persisten tetap tersimpan meskipun program sudah ditutup. Salah satu implementasi (yang pernah saya coba tapi masih belum work sampai sekarang) adalah menggunakan file eksternal untuk menyimpan HIGH SCORE dari sebuah game. Dengan menyimpan HIGH SCORE secara eksternal, pemain dapat mencoba mengalahkan skor tertinggi sebelumnya dalam sesi yang terpisah sehingga dapat mengambil jeda terlebih dahulu.

FILE handling merupakan solusi sederhana untuk menyimpan data di dalam memori permanen (di luar RAM program berjalan) sehingga sepertinya ini merupakan solusi terbaik untuk kasus ini. Metode lain untuk menyimpan HIGH SCORE secara permanen adalah membuat program yang terus berjalan di background komputer hanya untuk menyimpan data tersebut, namun metode ini sangatlah tidak efisien karena menghabiskan sumber daya secara tidak penting.

**Referensi:**

- C/Persistence. Yale. [Online]. Available: https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Persistence.html. [Accessed: 18 Mar 2024]

## 3. Bayangkan kalian sedang membuat Cheatsheet untuk ProgLan dan sekarang kalian berada pada bagian File Handling. Apa saja informasi yang akan kalian masukkan pada Cheatsheet tersebut. <span style="color:red">(20poin)</span>

Cheatsheet akan mengandung fungsi-fungsi yang dibutuhkan untuk mengakses dan mengubah FILE.

```c
FILE* fopen(const char *file_name, const char *access_mode);
// Membuka File, file_name path menuju file, access_mode mode akses file.
/*
    access_mode:
        - "r"    Membaca dari file
        - "w"    Menulis ke file
        - "a"    Menambahkan data ke akhir file
        - "r+"   Membaca dan menulis file
        - "a+"   Membaca dan menambahkan data ke akhir file

    Tambahkan "b" dalam access_mode jika file yang dibuka berupa file binary.
*/

fclose(file_pointer);
// Menutup file pointer yang dibuka dengan fopen setelah selesai digunakan

int fprintf(FILE *stream, const char *format, ...)
// Menulis ke file layaknya printf, stream berupa pointer file dari fopen, format berupa string serta format untuk data yang dikeluarkan, ... berupa deretan data yang akan dikeluarkan dalam format.

char *fgets(char *s, int size, FILE *stream)
// Mengambil string dari stream sebesar kurang dari size ke string s

int fscanf(FILE *stream, const char *format, ...)
// Mengambil input dari FILE stream dengan format layaknya scanf

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
// Mengambil data sebanyak nmemb masing-masing sebesr size dari stream dan disimpan ke ptr

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
// Mengambil data sebanyak nmemb masing-masing sebesar size dari ptr ke FILE stream
```

**Reference:**

- fprintf(3p) - Linux manual page. Linux manual page. [Online]. Available: https://man7.org/linux/man-pages/man3/fprintf.3p.html. [Accessed: 18 Mar 2024]
- fgets(3p  ) - Linux manual page. Linux manual page. [Online]. Available: https://man7.org/linux/man-pages/man3/fgets.3p.html. [Accessed: 18 Mar 2024]
- fscanf(3p) - Linux manual page. Linux manual page. [Online]. Available: https://man7.org/linux/man-pages/man3/fscanf.3p.html. [Accessed: 18 Mar 2024]
- fread(3) - Linux manual page. Linux manual page. [Online]. Available: https://man7.org/linux/man-pages/man3/fread.3.html. [Accessed: 18 Mar 2024]

## 4. Jika kalian disuruh membuat sebuah proyek yang menerapkan File Handling, apa tema proyek yang akan kamu pilih? Kenapa kamu memilih tema tersebut dan apa peran File Handling dalam proyek yang kamu inginkan. (Tidak perlu Referensi) <span style="color:red">(10poin)</span>

Video game dengan sistem _score_ dan _high score_. FILE handling dapat digunakan untuk menyimpan _high score_ secara permanen agar tidak kembali menjadi nol setiap program dijalankan. Dengan begini _game_ dapat dimainkan dalam sesi-sesi terpisah tanpa harus khawatir _high score_ hilang. Hal ini dapat diterapkan lebih lanjut dalam _game_ lebih kompleks yang memerlukan sistem penyimpanan _progress_ seperti sebuah game RPG.
