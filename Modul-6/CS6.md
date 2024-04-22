# Case Study 6 - Linked List

Pada praktikum kali ini, kita akan membuat sebuah local multiplier game:

## Cara Bermain
1. Setiap pemain akan menyebutkan angka secara berurutan.
2. Setiap kali anda menemukan angka kelipatan 3, anda harus menyebut kata '**Boom**'.
3. Jika ada pemain yang salah menyebut, pemain tersebut akan dipindahkan ke urutan terakhir, program akan menuliskan '**Selesai**'
4. Apabila semua pemain berhasil menyebut dengan benar, maka program akan menuliskan '**Selesai**'
5. Apabila permainan selesai, kembali ke menu.

## Alur Program
1. Setiap pemain mendaftarkan nama. Yang disimpan pada program adalah nama pemain dan skor (default = 0)
2. Permainan dimulai dengan urutan yang sama dengan urutan pemain mendaftar.

## Perhitungan Poin
1. Pemain akan mendapat **penambahan** 1 poin apabila menyebut angka atau 'Boom' dengan **benar**.
2. Pemain akan mendapat **pengurangan** 1 poin apabila menyebut angka atau 'Boom' dengan **salah**.
3. Pemain **tidak** mendapat poin apabila tidak menyebut angka atau 'Boom'. *Dapat terjadi ketika pemain giliran sebelumnya melakukan kesalahan sehingga permainan berakhir sebelum giliran pemain tersebut*.

## Batasan
1. Tidak ada batasan jumlah pemain. Namun permainan hanya dapat dimainkan ketika minimal terdapat 5 pemain.
2. Atribut objek `Pemain` terdiri dari `Nama` dan `Skor`
3. Program meminta menu : 
- 1. Input Pemain
- 2. Lihat Urutan
- 3. Mulai Permainan
4. Minimal terdapat 1 (satu) buah fungsi selain fungsi utama atau `main()`
5. Atribut `Nama` maksimal 10 karakter


----------

<font size="5">

“To ask the right question is harder than to answer it.”
<br> - Georg Cantor

</font>

---------

# Pembahasan:

## Bagian 1: THE Game

Dalam CS kali ini, kita membuat sebuah game. Secara gameplay, gamenya sendiri sederhana:

1. Terdapat sebuah urutan pemain dengan skor awal 0.
2. Setiap pemain menulis angka urutannya, atau "Boom" jika angka urutannya kelipatan 3.
3. Jika seorang pemain salah menyebut, permainan selesai dan pemain tersebut dipindahkan ke urutan terakhir pada permainan selanjutnya.
4. Setiap pemain yang menyebutkan benar, skornya +1, jika salah skornya -1, dan jika tidak dapat kesempatan sama sekali (karena ada pemain salah sebelum dia), maka skor tidak berubah.
5. Permainan hanya dapat dimulai dengan minimum jumlah pemain 5.

![Game Linked List Illustration](Images/LinkedListGame.jpg)

`Jir bro gini mah gua juga ngerti, implementasinya gimana???`

## Bagian 2: Implementasi

Dalam sebuah program, tidak mungkin diciptakan lingkaran dan panah seperti di gambar sebagai representasi, namun #Alhamdulillah bisa direpresentasikan dengan cara lain.

Sebuah linked list didefinisikan dengan Node (bulet-bulet) yang mengandung data dan bagaimana mereka terhubung (linked) dengan satu sama lain. Hubungan antar node direpresentasikan menggunakan pointer.

Pointer, sesuai dengan namanya, "menunjuk" ke sebuah data. Dalam kasus ini, setiap Node memiliki pointer yang "menunjuk" ke Node lain. Dalam sebuah linked list, Node tersebut menunjuk ke Node selanjutnya yang dapat menunjuk lagi ke Node lainnnya sehingga terbentuklah sebuah rantai data.

Misalkan sebuah linked list yang mengandung data bertipe integer, maka Node dapat dibuat dengan `struct` sebagai berikut:

```c
typedef struct Node Node; // Prototype struct Node terlebih dahulu agar
                          // dapat digunakan di dalam dirinya sendiri. Typedef untuk kemudahan

struct Node
{
    int data; // Data yang disimpan.
    Node *next; // Pointer yang menyimpan Node lanjutannya.
};
```

Salah satu keuntungan dari menggunakan linked list adalah sifatnya yang menggunakan memori dinamis (`malloc` dkk) sehingga ukuran dan jumlahnya fleksibel pada _runtime_. Namun karena cara kerja malloc sendiri, isi dari struct yang diciptakannya sering mengandung data acak. Untuk kendali lebih terhadap penciptaannya, dapat dibuat sebuah fungsi yang mengembalikan pointer berisi sebuah Node.

```c
Node *Node_Init(int data)
{
    Node *temp = malloc(sizeof(Node)); // Mengalokasikan memori dinamis sebesar sebuah struct Node

    temp->data = data;      // Mengisi data sesuai dengan argumen fungsi.
    temp->next = NULL;      // Memastikan Node selanjutnya NULL (kosong) di awal.

    return temp;            // Mengembalikan pointer yang telah diisi.
}
```

Dengan begini, misalkan ingin dibuat sebuah Node dengan isi data 5, fungsi `Node_Init()` dapat dipanggil.

```c
Node *node_5 = Node_Init(5);
// Pointer node_5 menunjuk (berisi) ke sebuah Node dengan data 5.
```