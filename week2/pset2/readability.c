#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int coleman_index(int word, int sentence, int letter);

int main(void)
{
    // Ask for a string of text
    string text = get_string("Text: ");

    // Declare counters
    int letter_counter = 0;
    int word_counter = 1;
    int sentence_counter = 0;

    // Count the number of letters, words, and sentences in the text, Any ponctuation is considered end of sentence
    // Accept only letters A to Z, capital or not
    for (int i = 0, n = strlen(text); i < n; i++)\
    {
        if (isalnum(text[i]))
        {
            letter_counter++;
        }

        else if (text[i] == ' ')
        {
            word_counter++;
        }

        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_counter++;
            // printf("%i", sentence_counter);
        }

    }

    // Gather the index calculation
    int index = coleman_index(word_counter, sentence_counter, letter_counter);

    // print the Coleman-Liau index
    // if it's 16 or more, print 16+. If it's less than 1, print "Befeore Grade 1"
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index >= 1 && index <= 15)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

// Calculate the Coleman-Liau index per the text
int coleman_index(int word, int sentence, int letter)
{
    float L = ((float) letter / (float) word) * 100;
    float S = ((float) sentence / (float) word) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    return rint(index);
}
