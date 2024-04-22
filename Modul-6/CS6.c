#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __linux__
#define CLEAR system("clear");
#define PAUSE getchar();getchar();
#else
#define CLEAR system("cls");
#include <conio.h>
#define PAUSE system("pause");
#endif


void input_pemain(){
	printf("INPUT PEMAIN\n");
	printf("Masukan Nama : ");
}

void urutan_pemain(){
	// Silahkan buat code untuk menampilkan seluruh pemain, nama dan skornya berdasarkan urutan mendaftar pemain
	printf("URUTAN PEMAIN\n");

}

void permainan(){

}


// Anda tidak perlu mengubah bagian ini
int menu() {
    printf("====================\n");
    printf("===     Menu     ===\n");
    printf("====================\n\n");

    printf("1. Input Pemain \n");
    printf("2. Lihat Urutan Pemain \n");
    printf("3. Mulai Permainan \n\n");

    printf("Select Input: ...");
    int option = getchar(); 

    switch (option) {
        case '1': break;
        case '2': break;
        case '3': break;
        default: 
            printf("\nInvalid Input\n"); 
            option = menu();
            break;
    }

    CLEAR
    return option - '0';
}

int main()
{
	// Anda dapat membuat Dynamic Memory Allocation disini

	while (1){
		int option = menu();
		switch (option){
			case 1: input_pemain(); break;
			case 2: urutan_pemain(); break;
			case 3: permainan(); break;
			default: printf("Invalid Input"); break;
		}
		printf("\n\n");
		PAUSE
		CLEAR
	}

	return 0;
}