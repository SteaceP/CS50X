#include <cs50.h>
#include <stdio.h>

int calc(int n);

int main(void)
{
    // Minimum lama population size
    int min_pop_size = 9;

    // TODO: Prompt for start size
    int start_pop_size;
    do
    {
        start_pop_size = get_int("Starting lama population size?: ");
    }
    while (start_pop_size < min_pop_size);

    // TODO: Prompt for end size
    int end_pop_size;
    do
    {
        end_pop_size = get_int("What's your end goal for lama population?: ");
    }
    while (end_pop_size < start_pop_size);

    // TODO: Calculate number of years until we reach threshold

    int pop_counter = start_pop_size;
    int years_counter = 0;

    while (pop_counter < end_pop_size)
    {
        pop_counter += calc(pop_counter);
        years_counter++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years_counter);
}

// Calculate the growth of lama with  n = n + (n / 3) - (n / 4) minus the initial population
int calc(int n)
{

    n = n + ((int) n / 3) - ((int) n / 4) - n;
    return n;
}
