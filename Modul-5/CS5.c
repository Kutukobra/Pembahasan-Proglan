// Muhammad Nadzhif Fikri
// 2306210102

// Saya pake linux
#ifdef __linux__ 
#define CLEAR system("clear");
#define PAUSE getchar();getchar();

#else
#define CLEAR system("cls");
#define PAUSE system("pause");
#endif


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CODE_LENGTH 20

// Function to read initial primogem value from file
int readPrimogemsFromFile(const char *filename) {
    FILE *fh = fopen(filename, "r");

    // Jika gagal, maka keluar fungsi -1
    if (fh == NULL)
    {
        printf("Failed to fetch data.\n");
        return -1;
    }

    int primogems;

    // Membaca primogems dari file
    fscanf(fh, "%d", &primogems);
    
    fclose(fh);

    return primogems;
}

// Function to write primogem value to file
void writePrimogemsToFile(const char *filename, int primogems) {
    FILE *fh = fopen(filename, "w");

    // Jika gagal, maka wallahualam program crash aja sekalian
    if (fh == NULL)
    {
        printf("Failed to fetch data.\n");
        exit(1);
        return;
    }

    // Menyimpan primogems ke file
    fprintf(fh, "%d", primogems);
    fclose(fh);
    return;
}

// Function to generate a random top-up code
void generateTopUpCode(char *code, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    // Mengambil karakter random untuk token
    for (int i = 0; i < length; i++) {
        int index = rand() % (int)(sizeof(charset) - 1);
        code[i] = charset[index];
    }

    FILE *fh = fopen("code.txt", "r");

    // Jika gagal, maka WALLAHI program crash aja sekalian
    if (fh == NULL)
    {
        printf("Failed to fetch data.\n");
        exit(1);
    }

    code[length] = '\0';

    // Memeriksa jika token sudah ada di file
    char buffer[MAX_CODE_LENGTH + 1];
    int none;
    while(fscanf(fh, "%s %d", buffer, &none) != EOF)
    {
        // Jika ternyata ada token dengan code sama
        if (strcmp(buffer, code) == 0)
        {
            fclose(fh);
            // Panggil ulang fungsi
            generateTopUpCode(code, length);
        }
    }

}

// Function to top up primogems with a new code
void topUpPrimogems(const char *filename, int amount) {
    char code[MAX_CODE_LENGTH + 1];
    
    // Generate code
    generateTopUpCode(code, MAX_CODE_LENGTH);


    // Buka file code untuk di-append
    FILE *fh = fopen("code.txt", "a");

    // Jika gagal buka file, wallahi idk anymore bro
    if (fh == NULL)
    {
        printf("Failed to fetch data.\n");
        return;
    }


    // Append code token serta jumlah primogemnya ke file
    fprintf(fh, "%s %d\n", code, amount);
    // Print code token
    printf("TOP UP SUCCESSFUL! \nCODE: %s\n", code);
    fclose(fh);
}

// Function to redeem primogems with a code
int redeemPrimogems(const char *filename, const char *code) {
    char buffer[MAX_CODE_LENGTH + 10];

    // Jumlah primogem yang akan dibaca, -1 sebagai default error
    int amount, redeemedPrimogems = -1;

    FILE *fh = fopen("code.txt", "r");

    // Lagi-lagi, jika gagal buka file tinggal berdoa
    if (fh == NULL)
    {
        printf("Failed to fetch data.\n");
        return -1;
    }


    // Mencari line pada file dengan token yang sesuai
    int whichLine = -1, i = 0;
    while(fscanf(fh, "%s %d", buffer, &amount) != EOF)
    {
        if (strcmp(buffer, code) == 0)
        {
            whichLine = i;
            redeemedPrimogems = amount;
        }
        i++;
    }

    // Jika tidak ditemukan
    if (whichLine == -1)
    {
        printf("CODE UNAVAILABLE\n");
        return -1;
    }


    // Membuat file temporer
    FILE *temp = fopen("temp.txt", "a");

    // Mengembalikan buffer file code ke awal
    rewind(fh);


    i = 0;
    while(fgets(buffer, sizeof(char) * (MAX_CODE_LENGTH + 10), fh) != NULL)
    {
        // Baca setiap line dari code
        if (i != whichLine)
        {
            // Copy line ke temp jika bukan line yang mengandung code diredeem
            puts(buffer);
            fputs(buffer, temp);
        }
        i++;
    }


    fclose(fh);
    // Menghapus file code lama
    remove("code.txt");

    // Menjadikan file temp menjadi code yang baru
    rename("temp.txt", "code.txt");
    fclose(temp);

    // Jika tidak valid, return -1
    return redeemedPrimogems;
}

// Function to simulate pulling a character from the banner
int pullCharacter() {
    // Randomly generate a number from 1 to 1000 to determine the rarity of the character pulled
    int rarity = rand() % 1000 + 1;

    // Integer hitung jumlah pull yang bukan 5 dan 4
    int count5, count4;

    // Membaca dari file puty jumlah pull 
    FILE *pity = fopen("pity.txt", "r");
    fscanf(pity, "%d %d", &count4, &count5);
    fclose(pity);

    int ret;
    // Jika sudah 89 kali bukan 5 star (gacha bau), maka guaranteed 5 star
    if (rarity <= 6 || (count5 >= 89)) 
    { // 0.6% chance for a 5-star character
        count5 = -1;
        ret = 5;
    } // Jika sudah 9 kali bukan 4 star, maka guaranteed 4 star
    else if (rarity <= 57 || (count4 >= 9)) { // 5.1% chance for a 4-star character
        count4 = -1;
        ret = 4;
    } 
    else 
    {
        ret = 3; // 94.3% chance for a 3-star character
    }

    // Menambah count pity
    count4++;
    count5++;
    
    // Menulis ke file pity
    pity = fopen("pity.txt", "w");

    fprintf(pity, "%d %d", count4, count5);

    fclose(pity);

    return ret;
}

// Function to print text in rainbow colors
void printRainbowText(const char *text) {
    int text_length = strlen(text);
    int color_index = 0;

    // Define the ANSI escape codes for colors
    char *colors[] = {
        "\033[1;31m", // Red
        "\033[1;33m", // Yellow
        "\033[1;32m", // Green
        "\033[1;36m", // Cyan
        "\033[1;34m", // Blue
        "\033[1;35m", // Magenta
    };

    for (int i = 0; i < text_length; i++) {
        printf("%s%c\033[0m", colors[color_index], text[i]);

        // Increment the color index, loop back to 0 if we reach the end of the color array
        color_index = (color_index + 1) % (sizeof(colors) / sizeof(colors[0]));
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Initial value of primogems
    int primogems = readPrimogemsFromFile("primogem.txt");
    if (primogems == -1)
    {
        printf("ERROR: UNABLE TO FETCH DATA.\n");
        exit(1);
    }

    int choice;

    while (1) {
        
        CLEAR

        printf("Welcome to Genshin Impact Gacha Simulator!\n");
        printf("You have %d", primogems);
        printRainbowText(" primogems");
        printf(".\n");
        
        printf("\nOptions:\n");
        printf("0. Exit\n");
        printf("1. Perform 1 pull\n");
        printf("2. Perform 10 pulls\n");
        printf("3. Top up primogems\n");
        printf("4. Redeem code\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

         switch (choice) {
            case 0:
                printf("Exiting the simulator.\n");
                writePrimogemsToFile("primogem.txt", primogems); // Update primogems before exiting
                return 0;
            case 1:
            case 2: {
                int num_pulls = (choice == 1) ? 1 : 10;

                if (primogems < 160 * num_pulls) {
                    printf("Not enough primogems for this number of pulls.\n");
                    break;
                }

                primogems -= 160 * num_pulls; // Deduct primogems for each pull

                printf("\nPulling %d times...\n", num_pulls);

                for (int i = 0; i < num_pulls; i++) {
                    int character = pullCharacter();
                    if (character == 5) {
                        printf("\033[1;33m5-star character obtained!\033[0m\n");
                    } else if (character == 4) {
                        printf("\033[1;35m4-star character obtained!\033[0m\n");
                    } else {
                        printf("\033[1;34m3-star character obtained.\033[0m\n");
                    }
                }

                printf("You have %d", primogems);
                printRainbowText(" primogems");
                printf(" left.\n");
                break;
            }
            case 3: {
                int amount;
                printf("Enter the amount to top up: ");
                scanf("%d", &amount);
                topUpPrimogems("code.txt", amount);
                break;
            }
            case 4: {
                char code[MAX_CODE_LENGTH + 1];
                printf("Enter the code to redeem: ");
                scanf("%s", code);
                int redeemedAmount = redeemPrimogems("code.txt", code);
                if (redeemedAmount > 0) {
                    primogems += redeemedAmount;
                    printf("You now have %d", primogems);
                    printRainbowText(" primogems");
                    printf(".\n");
                } else {
                    printf("Invalid code or already redeemed.\n");
                }
                break;
            }
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }

        PAUSE
    }

    CLEAR
    printRainbowText("Thank you for using the Genshin Gacha Simulator!\n");

    return 0;
}
