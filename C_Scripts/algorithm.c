// Algorithm to show a menu with the following options:
// - Determine if a value is a valid IPv4
// - Convert a number to ASCII
// - Generate a random number between 1 and 6
// - Concatenate two words
// 
// Author: Gian Mazo

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>

// Function1: Check if input is a valid IP
bool IsValidIpAddress(char *IpAddress)
{
    int num, dots = 0;
    char *ptr;
    char CopyIpAddress[strlen(IpAddress)];

    strcpy(CopyIpAddress, IpAddress);
    if (IpAddress == NULL || (strlen(IpAddress) > 15))
    {
        return false;
    }
    ptr = strtok(CopyIpAddress, ".");
    if (ptr == NULL)
    {
        return false;
    } 
    while (ptr)
    {
        if (!isdigit(*ptr))
        {
            return false;
        }
        num = atoi(ptr);
        if (num < 0 || num > 255)
        {
            return false;
        }
        ptr = strtok(NULL, ".");
        if (ptr != NULL)
        {
            dots++;
        }
    }
    if (dots != 3)
    {
        return false;
    }
    return true;
}

void CheckForValidIp()
{
    char IpAddress[16];
    printf("Enter IP address: ");
    scanf(" %s", IpAddress);
    if (IsValidIpAddress(IpAddress))
    {
        printf("%s is a valid IPv4.\n\n", IpAddress);
    }
    else
    {
        printf("%s is not a valid IPv4.\n\n", IpAddress);
    }
}

// Function2: Convert value to ASCII
void ToAscii()
{
    printf("Type a number between 0 and 255 to convert it to ASCII: ");
    int interger;
    scanf(" %i", &interger);
    if (interger >= 0 && interger <= 255)
    {
        char asciichar = interger;
        printf("This number represents: %c \n\n", asciichar);
    }
    else
    {
        printf("You must enter a number between 0 and 255\n\n");
    }
}

// Function3: Random number between 1 - 6
void random_number()
{
    srand(time(NULL));
    int random = rand() % 6 + 1;
    printf("Your lucky number is %i\n\n", random);
}

// Function4: Concatenate two words
void concatenate()
{
    char Word1[100];
    char Word2[100];
    printf("Please enter the first word: ");
    scanf(" %99s", Word1);
    printf("Please enter the second word: ");
    scanf(" %99s", Word2);

    char Result[strlen(Word1)+strlen(Word2)+1];
    strcpy(Result, Word1);
    strcat(Result , Word2);
    printf("Your new word is: %s\n\n", Result);
}


// MAIN FUNTION
int main()
{
    int Selection[2];
    bool Execution = true;
    char WantToContinue = '\0';
    
    system("cls");
    printf("Welcome to algorithm of training session 2.\n");

    while (Execution)
    {
        printf("\n\nPlease enter the number of the action you preferr to execute:\n1 - Determine if a value is a valid IPv4 IP\n2 - Convert a number to ASCII\n3 - Generate a random number between 1 and 6\n4 - Concatenate two words\n\n");
    
        scanf(" %d", Selection);
        
        if(*Selection == 1)
        {
            CheckForValidIp();
            printf("script 1 has done!\n");
        }
        else if (*Selection == 2)
        {
            ToAscii();
            printf("script 2 has done!\n");
        }
        else if (*Selection == 3)
        {
            random_number();
            printf("script 3 has done!\n");
        }
        else if (*Selection == 4)
        {
            concatenate();
            printf("script 4 has done!\n");
        }
        else
        {
            printf("Please enter a valid option.\n");
        }
        while (WantToContinue != 'y' && WantToContinue != 'n')
        {
            printf("Do you want to continue the execution? (Y/N): ");
            scanf(" %c", &WantToContinue);
            WantToContinue = tolower(WantToContinue);
            // consume any leftover characters in the input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
        } 
                
        if(WantToContinue == 'n')
        {
            Execution = false;
            printf("\n");

        }
        WantToContinue = ' ';
    }
    return 0;
}