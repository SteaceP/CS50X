#include <stdio.h>
#include <math.h>
#include <cs50.h>

float askPositiveFloat(void);
int coinNum();

int main(void)
{
    printf("%i\n", coinNum());
}

// Function to retreive the change owed
float askPositiveFloat(void)
{
    float positiveFloat;
    // on/off switch
    bool negative = true;

    while (negative)
    {
        positiveFloat = get_float("Change Owed: ");

        if (positiveFloat > 0)
        {
            // Sets to false if number is positive
            negative = false;
        }
    }
    return positiveFloat;
}

//Track counted coins and return it as an int
int coinNum()
{
    // Total cents
    int totalCents = round(askPositiveFloat() * 100);
    // Coin count
    int numOfCoins = 0;
    // Remainders
    int remainder;
    // Temporary number
    int tempNum;

    // Declaring Coins variable
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    // Deal quarters
    if (totalCents >= quarter)
    {
        remainder = totalCents % quarter;
        tempNum = totalCents - remainder;

        numOfCoins = numOfCoins + (tempNum / quarter);

        totalCents = remainder;
    }

    // Deal dimes
    if (totalCents >= dime)
    {
        remainder = totalCents % dime;
        tempNum = totalCents - remainder;

        numOfCoins = numOfCoins + (tempNum / dime);

        totalCents = remainder;
    }

    // Deal nickels
    if (totalCents >= nickel)
    {
        remainder = totalCents % nickel;
        tempNum = totalCents - remainder;

        numOfCoins = numOfCoins + (tempNum / nickel);

        totalCents = remainder;
    }

    // Deal pennys
    if (totalCents >= penny)
    {
        remainder = totalCents % penny;
        tempNum = totalCents - remainder;

        numOfCoins = numOfCoins + (tempNum / penny);

        totalCents = remainder;
    }

    return numOfCoins;
}
