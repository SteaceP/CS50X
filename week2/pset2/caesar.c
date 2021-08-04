#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, string argv[])
{
    // If there's more than one argument, explain how it works
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // store the argument as integer
    int argument = 0;

    // Check if the argument is a digit, when it is, store it, else, explain how it works
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isdigit(argv[1][i]))
        {
            argument = (int) atoi(argv[1]);
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert arguments to make sure everything works if user input an argument > 52
    argument = argument % 26;

    // Ask for text to decipher
    string plaintext = get_string("plaintext: ");

    // Iterate over each characters of plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Check if pleintext[i] is uppercase
        if (isupper(plaintext[i]))
        {
            // Check if we need to overflow Z to A
            if ((plaintext[i] + argument) > 90)
            {
                plaintext[i] = ((((plaintext[i] + argument) % 65) - 26) + 65);
            }
            // Simple calculation of the plaintext[i] + the argument if overflow is not needed
            else if (plaintext[i] >= 65)
            {
                plaintext[i] = plaintext[i] + argument;
            }
            // Print each character(s) that is not alphabetical as is
            else
            {
                plaintext[i] = plaintext[i];
            }
        }
        // Check if plaintext[i] is lowercase
        if (islower(plaintext[i]))
        {
            // Check if we need to overflow z to a
            if ((plaintext[i] + argument) > 122)
            {
                // calculate overflow from z to a
                plaintext[i] = ((((plaintext[i] + argument) % 97) - 26) + 97);
            }
            // Simple calculation of the plaintext[i] + the argument if overflow is not needed
            else if (plaintext[i] >= 97)
            {
                plaintext[i] = plaintext[i] + argument;
            }
            // Print each character(s) that is not alphabetical as is
            else
            {
                plaintext[i] = plaintext[i];
            }
        }
    }
    // Print the ciphertext
    printf("ciphertext: %s\n", plaintext);
    printf("\n");
    // Program exit correctly
    return 0;
}
