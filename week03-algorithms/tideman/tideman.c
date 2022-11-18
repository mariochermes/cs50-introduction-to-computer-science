#include <math.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void merge_sort(int start, int end, pair *temp);
void sort_pairs(void);
bool has_cycle(int start, int end);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[j][i] > preferences[i][j])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Selection sort
// void selection_sort(void)
// {
//     for (int i = 0; i < pair_count; i++)
//     {
//         int max_index = i;
//         int highest_margin = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
//         for (int j = i + 1; j < pair_count; j++)
//         {
//             if (preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner] >= highest_margin)
//             {
//                 highest_margin = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];
//                 max_index = j;
//             }
//         }
//         pair aux = pairs[max_index];
//         pairs[max_index] = pairs[i];
//         pairs[i] = aux;
//     }
//     return;
// }

// Merge sort
void merge_sort(int start, int end, pair temp[])
{
    // If the end is higher than the start it means there are at least 2 pairs on the current array
    if (start < end)
    {
        int mid = (start + end) / 2;

        merge_sort(start, mid, temp);
        merge_sort(mid + 1, end, temp);

        // i is the current index in the left side of the array and j on the right side, k is the index in the temp array
        int i = start, j = mid + 1, k = i;
        while (i <= mid && j <= end)
        {
            // If the current pair on the right side of the array has a bigger or equal vote difference between it's candidates than the current left one temp[k] gets it
            if (preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner] > preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner])
            {
                temp[k] = pairs[i];
                i++, k++;
            }
            else
            {
                temp[k] = pairs[j];
                j++, k++;
            }
        }

        //If there are remaining pairs in either of the sides, they're atribuitted to temp[k]
        for (; i <= mid; i++, k++)
        {
            temp[k] = pairs[i];
        }

        for (; j <= end; j++, k++)
        {
            temp[k] = pairs[j];
        }

        // copy sorted array into original pair
        for (k = start; k <= end; k++)
        {
            pairs[k] = temp[k];
        }
    }
}

// Sort pairs in decreasing order by strength of victory
// There is one function for merge sort and one for selection sort
// Comment one of the sort functions and alter the bellow function accordingly for the code to work
void sort_pairs(void)
{
    pair temp[pair_count];
    merge_sort(0, pair_count - 1, temp);
    return;
}

// Checks recursively for cycles
bool has_cycle(int start, int end)
{
    if (locked[end][start])
    {
        return true;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[end][i])
        {
            if (has_cycle(start, i))
            {
                return true;
            }
        }
    }
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!has_cycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
}

// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        int false_count = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == false)
            {
                false_count++;
                if (false_count == candidate_count)
                {
                    printf("%s\n", candidates[i]);
                }
            }
        }
    }
    return;
}