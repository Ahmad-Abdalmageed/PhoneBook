#include <stdio.h>
#include "Include/CSV.h"
#include "Include/Dtypes.h"

#define DATA "./Data.csv"

void PrintIntro(void);
void CheckCommand(int16_t command);
int32_t main(void);

int32_t main(void){
    int16_t command;
    PrintIntro();
    while (1){
        printf("Enter Command:");
        scanf("%hd", &command);
        if (command == 6) {
            printf("Good Bye \n");
            break;
        }
        CheckCommand(command);
    }

    return 0;
}

void PrintIntro(void){
    printf("*******************************************\n");
    printf("-----------------Phone Book----------------\n");
    printf("*******************************************\n");

    printf("This is an easy access Database,\nYour Personal Phone Book\n");
    printf("Commands: \n");
    printf("0 - Show Database.\n");
    printf("1 - Add new Entry.\n");
    printf("2 - Delete old Entry(By name or By Phone).\n");
    printf("3 - Edit old Entry.\n");
    printf("4 - Print Instance\n");
    printf("5 - Show Commands\n");
    printf("6 - Exit Program.\n");

    printf("\n");
    printf("Field Numbers are :\n");
    printf("0 - Name.\n");
    printf("1 - Email.\n");
    printf("2 - Phone.\n");

    printf("*******************************************\n");
    printf("*******************************************\n");

}

void CheckCommand(int16_t command){
    struct BookInstance temp = {};
    char_t temp_str[BUFFER_SIZE] = {};
    char_t temp_char[BUFFER_SIZE] = {};
    int16_t temp_int = 0;

    switch (command) {
        case 0:
            PrintFile(DATA);
            break;

        case 1:
            printf("Enter Name:");
            scanf("%s", temp.Name);
            printf("Enter Email:");
            scanf("%s", temp.Email);
            printf("Enter Phone:");
            scanf("%s", temp.Phone);
            AddInstance(DATA, temp);
            break;
        case 2:
            printf("Enter Name or Phone: ");
            scanf("%s", temp_str);
            DeleteInstance(DATA, temp_str);
            break;
        case 3:
            printf("Enter Name or Phone: ");
            scanf("%s", temp_str);
            printf("Enter Field Number: ");
            scanf("%hd", &temp_int);
            printf("Enter Edits: ");
            scanf("%s", temp_char);
            EditInstance(DATA, temp_str, temp_int, temp_char);
            break;
        case 4:
            printf("Enter a Name or Phone: ");
            scanf("%s", temp_char);
            GetInstance(DATA, temp_char);
            break;
        case 5:
            PrintIntro();
            break;
        default:
            printf("NO Such Command !!");
            break;
    }
}