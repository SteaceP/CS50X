#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
// iterate over the number of candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // handle error(s) or non-existent candidates by checking if the candidate name exist
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // iterate over the number of voters
    for (int i = 0; i < voter_count; i++)
    {
        int j = 0; // set "j" as the first rank
        // if the candidate is eliminated, pass to the second and so on
        while (candidates[preferences[i][j]].eliminated == true)
        {
            j++;
        }
        // update the number of vote the candidate has
        candidates[preferences[i][j]].votes++;
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // iterate over the number of candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // if a candidate have more than 50% of the vote, print the winner's name
        if (candidates[i].votes > voter_count / 2)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    // run if no winner is found
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min_vote = candidates[0].votes; // get a number of vote to be able to compare to others as a starting value

    // iterate over candidates
    for (int i = 1; i < candidate_count; i++)
    {
        // if candidate is not eliminated and candidate votes is bigger than "min_vote", make that candidate the less voted(min_vote)
        // why is it working? I was also asking me that! It was working in plurality but I needed to find that max, not the min...
        // well, I changed it so it make sense(get the candidate votes as min_vote when it's smaller than) but the contrary also work! weird...
        if (!candidates[i].eliminated && candidates[i].votes < min_vote)
        {
            min_vote = candidates[i].votes;
        }
    }
    return min_vote;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int eliminated = 0; // keep track of eliminated candidates
    int tie = 0; // keep track of tie
    // iterate over the number of candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // if the candidate is eliminated, add one to the counter
        if (!candidates[i].eliminated)
        {
            eliminated++;
        }
        // if it's tie, add one to the counter
        if (candidates[i].votes == min)
        {
            tie++;
        }
    }
    // if eliminated is equal to tie, return true as in, every candidate is tie, return false otherwise
    if (eliminated == tie)
    {
        return true;
    }
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // iterate through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // if candidate is not already eliminated && his vote == min (least popular vote)...
        if (candidates[i].eliminated == false && candidates[i].votes == min)
        {
            // ...eliminate that candidate
            candidates[i].eliminated = true;
        }
    }
    return;
}
