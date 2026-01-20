#include <stdio.h>
#include <stdlib.h>

/* ---------- FUNCTION PROTOTYPES ---------- */
int menu(void);
void mainLoop(int option);
void writeFile(void);
void readFile(void);
void firstCalculation(int a, int b);
void secondCalculation(int a, int b);

/* ---------- MENU FUNCTION ---------- */
int menu(void)
{
    int choice;

    system("cls");  // use "clear" on Linux/Mac

    printf("===== MAIN MENU =====\n");
    printf("1. First Calculation\n");
    printf("2. Second Calculation\n");
    printf("3. Write to File\n");
    printf("4. Read from File\n");
    printf("5. Exit\n");
    printf("\nSelect an option: ");

    scanf("%d", &choice);
    return choice;
}

/* ---------- OPTION SELECTOR ---------- */
void mainLoop(int option)
{
    int x, y;

    switch (option)
    {
        case 1:
            printf("Enter two integers: ");
            scanf("%d %d", &x, &y);
            firstCalculation(x, y);
            break;

        case 2:
            printf("Enter two integers: ");
            scanf("%d %d", &x, &y);
            secondCalculation(x, y);
            break;

        case 3:
            writeFile();
            break;

        case 4:
            readFile();
            break;

        case 5:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid option.\n");
    }

    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

/* ---------- WRITE FILE FUNCTION ---------- */
void writeFile(void)
{
    FILE *fp = fopen("data.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(fp, "Hello from writeFile function!\n");
    fprintf(fp, "This data was written successfully.\n");

    fclose(fp);
    printf("Data written to file successfully.\n");
}

/* ---------- READ FILE FUNCTION ---------- */
void readFile(void)
{
    FILE *fp = fopen("data.txt", "r");
    char ch;

    if (fp == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(fp);
}

/* ---------- CALCULATION FUNCTIONS ---------- */
void firstCalculation(int a, int b)
{
    int result = a + b;
    printf("First Calculation (Addition): %d\n", result);
}

void secondCalculation(int a, int b)
{
    int result = a * b;
    printf("Second Calculation (Multiplication): %d\n", result);
}

/* ---------- MAIN FUNCTION ---------- */
int main(void)
{
    int option;

    do
    {
        option = menu();
        mainLoop(option);
    }
    while (option != 5);

    return 0;
}

