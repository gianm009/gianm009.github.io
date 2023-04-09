// Algorithm to show a menu with the following options:
// - Convert a string to lowercase
// - Convert a string to UPPERCASE
// - Read a string and display the letters aLtErNaTeLy
// - Replace a letter in a string with another
// - Allow the user to execute a console command
// 
// Author: Gian Mazo

#include <stdbool.h> // Type bool
#include <stdio.h> // Functions printf(),scanf(),putchar(),fgets(),sizeof(),fflush()
#include <stdlib.h> // Functions system(),
#include <ctype.h> // Functions tolower(),toupper()

// Function 1. ToLower
void ToLower()
{
    fflush(stdin);
    int i = 0;
    char StringToWorkWith[100];

    printf("\nType the word you want to change to lowercase (maximum of 100 characters): ");
    fgets( StringToWorkWith, sizeof(StringToWorkWith), stdin); 

    while (StringToWorkWith[i])
    {
        putchar(tolower(StringToWorkWith[i]));
        i++;
    }
}

// Function 2. ToUpper
void ToUpper()
{
    fflush(stdin);
    int i = 0;
    char StringToWorkWith[101];
    
    printf("\nType the word you want into UPPERCASE (maximum of 100 characters): ");
    fgets(StringToWorkWith, sizeof(StringToWorkWith), stdin);    

    while (StringToWorkWith[i])
    {
        putchar(toupper(StringToWorkWith[i]));
        i++;
    }
}

// Function 3. Alternately lower-UPPER
void Alternately()
{
    fflush(stdin);
    int i = 0;
    char StringToWorkWith[100];
    
    printf("\nType the word you want into aLtErNaTlY (maximum of 100 characters): ");
    fgets(StringToWorkWith, sizeof(StringToWorkWith), stdin);

    while (StringToWorkWith[i])
    {
        if (i % 2 == 0)
        {
            putchar(tolower(StringToWorkWith[i]));
            i++;
        }
        else
        {
            putchar(toupper(StringToWorkWith[i]));
            i++;
        }
    }
}

// Function 4. Replace letter
void ReplaceLetter()
{
    fflush(stdin);
    int i = 0;
    char StringToWorkWith[100];
    char LetterToReplace[2];
    char NewLetter[2];

    printf("\nType the phrase you want to modify: ");
    fgets(StringToWorkWith, sizeof(StringToWorkWith), stdin);
    printf("Type the letter you want to replace: ");
    scanf(" %1c", LetterToReplace);
    printf("Type the letter you want to replace with: ");
    scanf(" %1c", NewLetter);

    while (StringToWorkWith[i])
    {
        if (StringToWorkWith[i] == *LetterToReplace)
        {
            StringToWorkWith[i] = *NewLetter;
            i++;
        }
        else
        {
            i++;
        }
    }
    printf("\nYour new word/phrase is: %s", StringToWorkWith);
}

// Function 5. Allow command
void Command()
{
    fflush(stdin);
    char StringToWorkWith[100];
    
    printf("\nAfter the \">>>\", write the cmdlet command you want to execute: \n>>> ");
    fgets(StringToWorkWith, sizeof(StringToWorkWith), stdin);
    system(StringToWorkWith);
    printf("\n");
}

// MAIN FUNCTION
int main()
{
    int Selection[2];
    bool Execution = true;
    char WantToContinue = '\0';

    system("cls");
    printf("\nWelcome to algorithm for training session 3.\n");

    while (Execution)
    {
        printf("\nPlease enter the number of the action you prefer to execute:\n1 - Convert a string to lowercase\n2 - Convert a string to UPPERCASE\n3 - Read a string and display the letters aLtErNaTeLy\n4 - Replace a letter in a string with another\n5 - Allow the user to execute a console command\nAny other key - Exit the script.\n\n-> ");
    
        scanf(" %d", Selection);
        
        if(*Selection == 1)
        {
            system("cls");
            ToLower();
            printf("\nScript 1 has done!\n");
        }
        else if (*Selection == 2)
        {
            system("cls");
            ToUpper();
            printf("\nScript 2 has done!\n");
        }
        else if (*Selection == 3)
        {
            system("cls");
            Alternately();
            printf("\nScript 3 has done!\n");
        }
        else if (*Selection == 4)
        {
            system("cls");
            ReplaceLetter();
            printf("\nScript 4 has done!\n");
        }
        else if (*Selection == 5)
        {
            system("cls");
            Command();
            printf("\nScript 5 has done!\n");
        }
        else
        {
            system("cls");
            printf("\nHave a nice day.\n");
            WantToContinue = 'n';
        }
        while (WantToContinue != 'y' && WantToContinue != 'n')
        {
            fflush(stdin);
            printf("Do you want to continue the execution? (Y/N): ");
            scanf(" %c", &WantToContinue);
            WantToContinue = tolower(WantToContinue);
            system("cls");
        } 
                
        if(WantToContinue == 'n')
        {
            Execution = false;
            printf("\n");
        }
        WantToContinue = '\n';
    }
    return 0;
}