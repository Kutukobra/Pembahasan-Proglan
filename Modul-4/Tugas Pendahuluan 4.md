# Tugas Pendahuluan 
Nama: Muhammad Nadzhif Fikri
NPM: 2306210102

## 1. Jelaskan mengenai beberapa jenis algoritma searching yang ada pada pemrograman, cara menggunakannya, cara kerjanya, dan contoh kasus yang cocok untuk algoritma tersebut. Jelaskan juga mengenai batasan batasan yang ada pada tiap algoritma tersebut, beserta nilai kompleksitasnya (30 poin)
- Linear Search
    Linear search adalah algoritma searching paling intuitif. Algoritma melakukan pengecekan elemen array satu per satu hingga target ditemukan. Algoritma memiliki kompleksitas O(N) karena setiap elemen array diperiksa hingga target ditemukan.

- Binary Search
    Binary search adalah algoritma searching efisien untuk array yang tersortir. Algoritma pertama-tama mengecek elemen tengah dari array lalu dilakukan partisi dan algoritma melakukan pengecekan bagian tengah partisi tersebut. Partisi dilakukan dengan membandingkan elemen tengah dengan target. Karena sifat array terurut, relasi target dan elemen yang diperiksa punya sifat tertentu. Jika elemen yang diperiksa lebih besar dari target, posisi target dipastikan berada di sebelah kiri dari elemen tersebut karena array terurut dari terkecil ke terbesar. Hal ini juga berlaku sebaliknya, jika elemen yang diperiksa lebih kecil, target berada di sebelah kanan.
    Setiap dilakukan pengecekan, algoritma melakukan partisi pada sisi yang sesuai dengan relasi target terhadap elemen yang diperiksa. Hal ini dilakukan hingga target ditemukan atau ketika array tidak dapat dilakukan partisi lagi yang menandakan bahwa target tidak berada di array. Algoritma melakukan partisi mempersempit daerah pencarian untuk setiap iterasi sehingga kompleksitas waktu rata-rata Binary Search berupa O(logN).

- Interpolation Search
    Serupa dengan binary search, interpolation juga menggunakan partisi berdasarkan titik tengah. Namun berbeda dengan binary search, titik tengah yang digunakan bukan berarti di tengah. Pada interpolation search, titik tengah ditentukan melalui interpolasi linear. Interpolasi linear merupakan metode aproksimasi data pada suatu fungsi linear menggunakan kemiringan data yang ada. 
    Rumus dari titik partisi adalah 
    mid = Lo + (Hi − Lo) ∗ (X − A[Lo])/ (A[Hi] − A[Lo])
    dengan X berupa target, A berupa array, Lo indeks kiri dan Hi indeks kanan dari partisi pada saat itu.
    Dengan interpolasi, algoritma dapat menerka posisi target dengan aproksimasi sehingga mungkin menjadi lebih efisien dibandingkan binary search yang titik partisinya selalu di tengah.
    Karena diberlakukan interpolasi pada partisi yang membelah panjang array, kompleksitas rata-rata algoritma merupakan O(log(logN)).

- Hashmap
    Hashmap merupakan struktur data yang memungkinkan penyimpanan dan pengambilan data pada sebuah array menggunakan indeks non-tradisional sebagai _key_. Hashmap menggunakan sebuah fungsi hashing yang mengubah jenis input indeks menjadi angka indeks tradisional sehingga data dapat disimpan menggunakan input tersebut. Meskipun begitu, hashmap dapat mengalami _collision_, kondisi di mana dua atau lebih _key_ menghasilkan indeks yang sama setelah melalui fungsi hashing sehingga dapat menyebabkan tabrakan pada indeks tersebut di dalam array. Dalam kondisi seperti itu, perlu dilakukan penyesuaian seperti dengan mengambil indeks lain jika indeks awal sudah terpenuhi, namun hal ini dapat memperlamban algoritma.
    Dengan fungsi hashing yang efektif dengan meminimalisir collision, hashmap mampu menyimpan serta mencari data dengan kompleksitas waktu konstan O(1), namun pada kondisi terburuk ketika terjadi collision berkali-kali, algoritma dapat mencapai kompleksitas waktu O(N).

- Binary Search Tree
    Binary search tree memanfaatkan sifat dari struktur data binary tree, yaitu struktur data node relasional yang masing-masing node memiliki tidak lebih dari dua anak. Data disimpan di dalam tree menggunakan aturan yang serupa dengan properti binary search. Pada anak sisi kiri disimpan data yang lebih kecil dari data pada node dan di sisi kanan disimpan yang lebih besar. Selama pencarian, algoritma cukup melakukan _transversing_ yang melakukan pengecekan. Ketika target lebih besar dari data pada node, maka algoritma akan melakukan berpindah ke anak sisi kanan (lebih besar) dari node tersebut dan begitu juga sebaliknya. Algoritma terus melintasi tree hingga target ditemukan atau node terakhir tidak lagi memiliki anak yang mendandakan bahwa data tidak ada di dalam tree tersebut. Algoritma cukup melakukan pengecekan sebanyak tinggi dari tree yang tidak lebih dari log2 jumlah data sehingga kompleksitas untuk memasukan data baru atau mencari data berupa O(logN).
    ![Binary Search Tree](https://upload.wikimedia.org/wikipedia/commons/thumb/d/da/Binary_search_tree.svg/1200px-Binary_search_tree.svg.png) 



**Referensi:**
- "Linear Search Algorithm - Data Structure and Algorithm Tutorials" GeeksforGeeks.  [Online]. Available: https://www.geeksforgeeks.org/linear-search/. [Accessed: 4-Mar-2024]
- "Binary Search - Data Structure and Algorithm Tutorials" GeeksforGeeks.  [Online]. Available: https://www.geeksforgeeks.org/binary-search/. [Accessed: 4-Mar-2024]    
- "Interpolation Search" GeeksforGeeks.  [Online]. Available: https://www.geeksforgeeks.org/interpolation-search/. [Accessed: 4-Mar-2024]
- "Interpolation Search Algorithm" tutorialspoint.  [Online]. Available: https://www.tutorialspoint.com/data_structures_algorithms/interpolation_search_algorithm.htm. [Accessed: 4-Mar-2024]
- "Internal Working of HashMap in Java" GeeksforGeeks.  [Online]. Available: https://www.geeksforgeeks.org/internal-working-of-hashmap-java/. [Accessed: 4-Mar-2024]
- "Binary Search Tree" GeeksforGeeks.  [Online]. Available: https://www.geeksforgeeks.org/binary-search-tree-data-structure/. [Accessed: 4-Mar-2024]

## 2. Jelaskan mengapa Binary Search merupakan salah satu algoritma searching yang terbaik? Mengapa tidak linear search? (10 poin)

Algoritma binary search melakukan pencarian pada sebuah array terurut dengan sangat efisien karena pencarian dapat dilakukan dengan melakukan pembelahan partisi hingga target ditemukan. Dengan pembelahan ini algoritma cukup melakukan pengecekan value sebanyak log2 dari panjang array lingkup pencarian sehingga binary search adalah algoritma yang sangat efisien pada array terurut. Meskipun begitu dalam kasus array yang tidak terurut binary search tidak dapat dilakukan sehingga dibutuhkan pengguanaan algoritma sorting terlebih dahulu yang biasanya dapat dilakukan secara efisien dengan kompleksitas O(NlogN) sehingga digabungkan dengan algoritma binary searchnya sendiri yang memiliki kompleksitas O(logN), kompleksitas keseluruhannya berupa O(NlogN).
Algoritma linear search sendiri memiliki kompleksitas O(N) yang lebih lamban dibandingkan O(logN), meskipun begitu linear search dapat dilaksanakan secara efisien dengan multicore/multithread processing. Multicore processing dapat dilakukan dengan membelah bagian-bagian array ke beberapa proses terpisah sehingga dapat dilakukan dengan sangat cepat melalui paralelisasi.
Meskipun begitu secara overall complexity, binary search lebih cepat (pada array terurut).
**Referensi:**
- "Binary Search - Data Structure and Algorithm Tutorials" GeeksforGeeks.  [Online]. Available: https://www.geeksforgeeks.org/binary-search/. [Accessed: 4-Mar-2024]
- "Linear search using Multi-threading" GeeksforGeeks.  [Online]. Available: https://www.geeksforgeeks.org/linear-search-using-multi-threading/?ref=next_article/. [Accessed: 4-Mar-2024]



## 3. Bandingkan Interpolation Search dengan Binary Search! Jelaskan mengapa Interpolation Search lebih cepat dari Binary Search, dan kapan Interpolation Search lebih cocok digunakan daripada Binary Search! (10 poin)
Interpolation search menggunakan aproksimasi melalui interpolasi linear sehingga dapat "menebak" posisi target dibandingkan dengan binary search yang selalu menggunakan titik tengah sebagai acuan. Interpolation terutama efektif pada array data terurut yang memiliki relasi konsisten mendekati linear sehingga aproksimasi lebih akurat.

**Referensi:**
- "Binary Search - Data Structure and Algorithm Tutorials" GeeksforGeeks.  [Online]. Available: https://www.geeksforgeeks.org/binary-search/. [Accessed: 4-Mar-2024]    
- "Interpolation Search" GeeksforGeeks.  [Online]. Available: https://www.geeksforgeeks.org/interpolation-search/. [Accessed: 4-Mar-2024]

## 4. Amati pseudocode dibawah ini. Jelaskan tipe algoritma searching apa yang digunakan, dan jelaskan bagaimana cara kerjanya! (20 poin)

```
HASH_SIZE = 10

Node:
    key: string
    value: integer
    next: Node

hashTable[HASH_SIZE]

function hash(key: string) -> integer:
    hashValue = 0
    for each character in key:
        hashValue += ASCII value of character
    return hashValue % HASH_SIZE

function insert(key: string, value: integer):
    index = hash(key)
    newNode = create a new Node
    newNode.key = key
    newNode.value = value
    newNode.next = NULL

    if hashTable[index] is NULL:
        hashTable[index] = newNode
    else:
        current = hashTable[index]
        while current.next is not NULL:
            current = current.next
        current.next = newNode

function search(key: string) -> integer:
    index = hash(key)
    current = hashTable[index]
    while current is not NULL:
        if current.key is equal to key:
            return current.value
        current = current.next
    return -1  # Key not found

function main():
    insert("apple", 5)
    insert("banana", 10)
    insert("orange", 15)

    print("Value of 'apple':", search("apple"))
    print("Value of 'banana':", search("banana"))
    print("Value of 'orange':", search("orange"))
    print("Value of 'grape':", search("grape"))

main()
```
Kode menggunakan algoritma hashing. Algoritma hashing adalah algoritma yang mengubah suatu jenis input menjadi suatu jenis output yang diinginkan. Dalam kasus ini, algoritma hashing melakukan konversi dari tipe data string (char array) menjadi integer modulus indeks sebuah array. Algoritma hashing di sini digunakan agar dapat menggunakan string sebagai indeks array sehingga data dapat disimpan di sana. Algoritma hashing yang digunakan adala jumlah dari besaran ascii setiap karakter lalu dimodulokan dengan ukuran array agar muat. 
Kelemahan dalam algoritma hashing adalah kemunkinan terjadinya collision, sebuah situasi di mana dua atau lebih input fungsi menghasilkan output yang sama sehingga dapat terjadi tabrakan pada indeks array tersebut. Oleh karena itu, kode ini melakukan handling pada algoritma insertion ke arraynya dengan mengecek jika isi dari indeks di sampingnya sudah terisi, jika belum maka data akan disimpan pada indeks tersebut namun jika ternyata sudah terisi juga, kode melakukan pergeseran indeks lagi.
Secara teoritis, algoritma hashing yang efektif dalam pencegahan collision dapat melakukan penyimpanan dan pencarian data dengan kompleksitas rata-rata konstan (O(1)) namun kondisi terburuk dari algoritma ini adalah O(N) ketika terjadi collision hingga akhir dari array.
**Referensi:**
- Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.; Stein, Clifford (2009). Introduction to Algorithms (3rd ed.). Massachusetts Institute of Technology. pp. 253–280. ISBN 978-0-262-03384-8.

## 5. Terdapat data nilai yang **belum terurut** sebagai berikut [28, 60, 26, 23, 98, 69, 61, 51, 27, 25]. Buatlah ilustrasi untuk menggambarkan skenario pencarian berikut:<br>a. Mencari nilai 51 pada array tersebut. Tentukan index ke berapa nilai 51 tersebut!<br>b. Mencari nilai 100 pada array tersebut. Tentukan index ke berapa nilai 100 tersebut!<br>Buatlah ilustrasi menggunakan algoritma searching selain **linear search**! (20 poin)
Data yang tidak terurut dapat disimpan dalam binary search tree (BST) sehingga pencarian data dapat dilakukan dengan sangat efisien. Binary search tree dapat menyimpan pointer terhadap posisi data pada array namun relasi BST menggunakan konten dari array tersebut sehingga BST dapat mengembalikan indeks data yang dicari. Pada kasus ini cukup dibuat sebuah BST cukup dibuat sekali lalu data dapat dengan mudah dicari dengan struktur tersebut.
### Binary Search Tree: 
![Binary Search Tree](https://media.discordapp.net/attachments/1197363074324250684/1214222731034361927/BST.jpeg?ex=65f8540a&is=65e5df0a&hm=8d6a15336d92186e06ee6d274c2b4ad1057ac61783492accd5d13cfc696042c1&=&format=webp)
Setiap data dari array dimasukan ke dalam tree dengan posisi yang sesuai dengan melakukan transversal. Tree sendiri sebenarnya menyimpan pointer dari data di dalam array, namun dalam kasus ini datanya yang ditulis agar memudahkan intepretasi.

a. 
![Mencari 51](https://cdn.discordapp.com/attachments/1160907770753720404/1214228014074695690/Cari51.jpg?ex=65f858f5&is=65e5e3f5&hm=67f9425a814312c2a3d75c7ee6b4aa61a69ca1dac13661ce00a9890ab2adaaf0&)
b. 
![Mencari 100](https://media.discordapp.net/attachments/1160907770753720404/1214229465685696632/Cari100.jpg?ex=65f85a4f&is=65e5e54f&hm=82f8643443fe9738ecb071e8955920f9855417f6469f5a665bab2b9ffca466a0&=&format=webp)


## 6. Realisasikan skenario tersebut dalam program bahasa C menggunakan algoritma searching yang sesuai! Berikan juga analisa terhadap program yang telah Anda buat! Buatlah pada file `TP4.c` yang telah tersedia, jangan ubah penamaan file! (10 poin)