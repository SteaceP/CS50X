#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Promt the user for a number between 1 and 8 inclusive, re-prompt if it's not
    int n;
    do
    {
        n = get_int("Number between 1 and 8 inclusive: ");
    }
    while (n < 1 || n > 8);

    // Loop throught the height
    for (int i = 0; i < n; i++)
    {
        // Print spaces
        for (int j = 0; j < n - 1 - i; j++)
        {
            printf(" ");
        }
        // Print #
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        // Return each line
        printf("\n");
    }
}
