#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int compute_score(string word);

// Points assigned to each letter of the alphabet
// 0 to 25
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};


int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Get score from the compute_scrore function for both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner or tie
    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Compute and return score
int compute_score(string word)
{
    // Keep track of scores
    int counter = 0;

    // Iterate over each letters and get the score for each one's.
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isupper(word[i]))
        {
            counter += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            counter += POINTS[word[i] - 'a'];
        }
    }
    return counter;
}
