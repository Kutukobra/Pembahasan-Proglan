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

typedef struct Node Node;
struct Node
{
	char name[10];
	Node *next;
	int score;
};

typedef struct List
{
	Node *head;
	Node *tail;
	int count;
} List;

void insert_node(List *list, Node *temp)
{
	//printf("Inserting: %s\n", temp->name);
	temp->next = NULL;

	if (list->head == NULL)
		list->head = temp;
	
	if (list->tail != NULL)
		list->tail->next = temp;
	
	list->tail = temp;
}

void input_pemain(List *list){

	list->count++;
	Node *temp = malloc(sizeof(Node));

	printf("INPUT PEMAIN\n");
	printf("Masukan Nama : ");
	scanf("%s", temp->name);

	temp->score = 0;
	temp->next = NULL;

	insert_node(list, temp);
}

void urutan_pemain(List *list){
	// Silahkan buat code untuk menampilkan seluruh pemain, nama dan skornya berdasarkan urutan mendaftar pemain
	printf("URUTAN PEMAIN\n");
	printf("-%3s | %10s | %4s-\n", "No", "Nama", "Skor");

	Node *head = list->head;
	int i = 0;
	while (head != NULL)
	{
		++i;
		printf("[%3d | %10s | %4d]\n", i, head->name, head->score);
		head = head->next;
	}
}

void move_to_end(List *list, Node *player, Node *temp)
{
	printf("Pemain Salah!\n");
	//printf("Previous: %s, Current %s\n", player->name, player->next->name);

	if (player == temp)
	{
		//printf("Mati di kepala\n");
		list->head = list->head->next;
		insert_node(list, player);
		return;
	}

	if (temp->next == NULL)
	{
		//printf("Mati di akhir\n");
		return;
	}

	player->next = temp->next;

	temp->next = NULL;

	insert_node(list, temp);

	//printf("%s\n", list->tail->name);
}

void permainan(List *list){
	// Mulai Permainan
	if (list->count < 5)
	{
		printf("Jumlah pemain kurang!\n");
		printf("Dibutuhkan minimum %d pemain lagi.", 5 - list->count);
		return;
	}
	printf("Permainan\n");
	char input[10];

	Node *turn = list->head;
	Node *prev = turn;

	int i = 0;
	while (turn != NULL)
	{
		++i;
		printf("%10s: ", turn->name);
		scanf("%s", input);

		if (strcmp(input, "Boom") == 0)
		{
			if (i % 3 == 0)
			{
				turn->score++;
			}
			else
			{
				turn->score--;
				move_to_end(list, prev, turn);
				break;
			}
		}
		else
		{
			int num = -1;
			sscanf(input, "%d", &num);
			if ((num == i) && (i % 3 != 0))
			{
				turn->score++;
			}
			else
			{
				turn->score--;
				move_to_end(list, prev, turn);
				break;
			}
		}
		prev = turn;
		turn = turn->next;
	}
	printf("Selesai\n");
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

	List *list = malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	list->count = 0;

	while (1){
		int option = menu();
		switch (option){
			case 1: input_pemain(list); break;
			case 2: urutan_pemain(list); break;
			case 3: permainan(list); break;
			default: printf("Invalid Input"); break;
		}
		printf("\n\n");
		PAUSE
		CLEAR
	}

	return 0;
}