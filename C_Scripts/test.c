// test some functions

// #include <cs50.h>
#include <stdio.h>

// int main()
// {
//     printf("hello\n");
//     printf("I'm learning C");
//     return 0;
// }

// int main()
// {
//     printf("Hello\nI'm learning C");
//     return 0;
// }

// int main()
// {
//     printf("hello\n\n");
//     printf("I'm learning C");
//     return 0;
// }

// int main()
// {
//     int myNum = 15;
//     printf("%d", myNum);  // Outputs 15
//     return 0;
// }

// int main()
// {
//     // Create variables
//     int myNum = 15;            // Integer (whole number)
//     float myFloatNum = 5.99;   // Floating point number
//     char myLetter = 'D';       // Character
//     // Print variables
//     printf("%d\n", myNum);
//     printf("%f\n", myFloatNum);
//     printf("%c\n", myLetter);
// }

// int main()
// {
// int myNum = 15;
// printf("My favorite number is: %d", myNum);
// }

// int main()
// {
//     int myNum = 15;
//     char myLetter = 'D';
//     printf("My number is %d and my letter is %c", myNum, myLetter);
// }

// int myNum = 15;  // myNum is 15
// myNum = 10;  // Now myNum is 10

// int main ()
// {
//     int myNum = 15;
//     int myOtherNum = 23;
//     // Assign the value of myOtherNum (23) to myNum
//     myNum = myOtherNum;
//     // myNum is now 23, instead of 15
//     printf("%d", myNum);
// 

// int main()
// {
//     // Create a variable and assign the value 15 to it
//     int myNum = 15;
//     // Declare a variable without assigning it a value
//     int myOtherNum;
//     // Assign the value of myNum to myOtherNum
//     myOtherNum = myNum;
//     // myOtherNum now has 15 as a value
//     printf("%d", myOtherNum);
// }

// int main()
// {
//     int x = 5;
//     int y = 6;
//     int sum = x + y;
//     printf("%d", sum);
// }

// int main()
// {
//     int x = 5, y = 6, z = 50;
//     printf("%d", x + y + z);
// }

// int main()
// {
//     int x, y, z;
//     x = y = z = 50;
//     printf("%d", x + y + z);
// }

// int main()
// {
//     // Good
//     int minutesPerHour = 60;
//     // OK, but not so easy to understand what m actually is
//     int m = 60;
// }

// The general rules for naming variables are:

// Names can contain letters, digits and underscores
// Names must begin with a letter or an underscore (_)
// Names are case sensitive (myVar and myvar are different variables)
// Names cannot contain whitespaces or special characters like !, #, %, etc.
// Reserved words (such as int) cannot be used as names

// int main()
// {
//     // Student data
//     int studentID = 15;
//     int studentAge = 23;
//     float studentFee = 75.25;
//     char studentGrade = 'B';

//     // Print variables
//     printf("Student id: %d\n", studentID);
//     printf("Student age: %d\n", studentAge);
//     printf("Student fee: %f\n", studentFee);
//     printf("Student grade: %c", studentGrade);
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>



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
    while (ptr) {
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

int main()
{
    char IpAddress[16];

    printf("Enter IP address: ");
    scanf("%s", IpAddress);

    if (IsValidIpAddress(IpAddress))
    {
        printf("%s is a valid IPv4 IP.\n", IpAddress);
    }
    else
    {
        printf("%s is not a valid IPv4 IP.\n", IpAddress);
    }
    return 0;
}


