# Case Study 4 - FIle Handling

## Latar Belakang

Januari 2017, dan sebuah Perusahaan Game dari Cina bernama Mihoyo sedang berencana untuk mengembangkan sebuah game Operworld terbarunya dengan nama `Genshin Impact`. Anda sebagai karyawan yang baru saja diterima diberikan tugas untuk mengembangkan sistem Gacha dari `Genshin Impact`.

Sistem Gacha yang akan diimplementasikan antara lain sebagai berikut:

1. Sistem Gacha akan menggunakan sebuah mata uang yang bernama `Primogem` untuk bermain.

2. Setiap player dapat menghabiskan `160 primogem` untuk bermain sekali, atau dengan kata lain melakukan `1 pull`.

3. Setiap player dapat menghabiskan `1600 primogem` untuk bermain sepuluh kali, atau dengan kata lain melakukan `10 pull`.

4. Setiap melakukan `1 Pull`, maka yang terjadi adalah Player akan berpeluang mendapatkan:

    - Karakter Bintang 5, dengan peluang 0.6%
    - Karakter Bintang 4, dengan peluang 5.1%
    - Item Bintang 3, dengan peluang 94.3%

Dikarenakan Sistem Gacha menggunakan mata uang `Primogem`, maka Player dapat mendapatkannya dengan cara berikutL

1. Melakukan `Top Up` dengan jumlah `Primogem` yang diinginkan.

2. Setelah melakukan `Top Up`, maka Player akan mendapatkan sebuah `Kode`.

3. `Kode` tersebut dapat di `Redeem` untuk mencairkan sejumlah `Primogem` agar dapat melakukan Gacha.

## Soal

Program untuk menjalankan Sistem Gacha sudah hampir selesai, hanya tersisa databasenya saja. Anda diminta untuk mengimplementasikan database pada sistem gacha tersebut dengan mengisi function-function yang masih kosong pada program `CS5.c`. Berikut merupakan penjelasan masing-masing function yang akan Anda buat:

### Function untuk Primogem
 
#### readPrimogemsFromFile

> Function ini digunakan untuk membaca jumlah Primogem milik Player dari database "primogem.txt".

#### writePrimogemsToFile

> Function ini digunakan untuk menyimpan sisa Primogem yang dimiliki Player setelah melakukan Gacha pada database "code.txt".

### Function untuk Top Up

#### topUpPrimogems

> Function ini digunakan untuk melakukan Top Up Primogem sesuai dengan jumlah yang diinginkan oleh Player. Setelah top up berhasil, sebuah kode akan diberikan ke Player untuk melakukan redeem. Kode tersebut juga perlu disimpan pada database "code.txt" agar sistem dapat mencari kode yang sesuai saat melakukan redeem.

#### redeemPrimogems

> Function ini digunakan oleh Player untuk melakukan redeem dari kode yang didapatkan saat proses Top Up, agar primogem dapat dicairkan pada akunnya. Function ini berjalan dengan mencari kode yang sesuai pada database "code.txt" dan mengembalikan jumlah primogem yang bersangkutan dengan kode tersebut.

## Soal Bonus

Melihat Anda adalah karyawan yang kompeten, CEO Mihoyo menawarkan Anda kerjaan tambahan. Kerjaan tersebut meliputi pengimplementasian `pity system` dan sebuah handling agar kode yang dihasilkan pada saat proses Top Up bersifat unik.

Untuk mengimplementasikan `Pity System`, maka Anda harus memodifikasi function `pullCharacter`, agar Player mendapatkan jaminan untuk

1. Mendapatkan 1 Karakter bintang 5, setelah 89 kali tidak mendapatkannya.

2. Mendapatkan 1 Karakter bintang 4, setelah 9 kali tidak mendapatkannya.

Agar kode yang dihasilkan untuk Top Up bersifat unik, Anda harus memodifikasi function `generateTopUpCode` dengan menambahkan sebuah handling. Handling tersebut berguna agar kode yang dihasilkan pada saat proses Top Up tidak mungkin sama dengan kode yang sudah ada pada database "code.txt"

## Rubrik Penilaian

| Kriteria | Skor |
|----------|------|
| Program dapat mengambil primogem dari database `primogem.txt` saat memulai program | 10 |
| Program dapat menyimpan primogem pada database `primogem.txt` saat exit program | 10 |
| Program dapat menyimpan kode beserta jumlah primogemnya pada database `code.txt` | 15 |
| Program dapat mencari kode pada database `code.txt` saat Top Up | 15 |
| Program memiliki handling ketika kode yang dicari tidak ada pada database saat Top Up | 5 |
| Program dapat mencairkan jumlah primogem yang benar saat Top Up | 10 |
| Program dapat menghapus kode yang sudah dicairkan pada database `code.txt` | 20 |
| Program dapat menambahkan jumlah primogem saat ini dengan jumlah primogem yang dicairkan saat proses redeem berhasil | 5 |
| Program dapat mengimplementasikan `pity system` | 10 |
| Program memilik handling agar kode yang dihasilkan saat Top Up tidak mungkin sama dengan kode yang ada di database `code.txt` | 5 |
| Program memiliki command untuk menjelaskan apa yang sedang terjadi | 5 |
| Program dapat di-compile | 5 |
| **Total** | **115** |

----------

<font size="5">

“To ask the right question is harder than to answer it.”
<br> - Georg Cantor

</font>

---------
# Pembahasan:
Untuk CS kali ini kita bahas per fungsi ya teman-teman.

