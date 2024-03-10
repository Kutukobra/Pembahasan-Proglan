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
"Fairy tales are more than true: not because they tell us that dragons exist,
 but because they tell us that dragons can be beaten." 
 <br>- G.K. Chesterton
</font>

---------
# Pembahasan: