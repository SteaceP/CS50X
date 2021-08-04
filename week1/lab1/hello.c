#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask user for his/her name
    string name = get_string("What is your name?\n");

    // Print the result
    printf("hello, %s\n", name);
}
