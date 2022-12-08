// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Pointer to traverse the linked lists
    // Table[hash(word)] checks if the word is on the list and already situates trav on right spot
    node *trav = table[hash(word)];
    // While there are still elements in the list, continue searching for the word
    while (trav != NULL)
    {
        // Checks if the word we are looking for is in the current node (case insensitive)
        if (strcasecmp(trav->word, word) == 0)
        {
            return true;
        }
        // If it isn't, go to the next node in the list
        trav = trav->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // I kept it simple
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Opens the dictionary file
    FILE *file = fopen(dictionary, "r");

    // Returns false if the given file is invalid
    if (file == NULL)
    {
        return false;
    }

    // Stores words momentarily
    char word[LENGTH];

    // Loops through the file untill it gets to the end of it
    while (fscanf(file, "%s", word) != EOF)
    {
        // Allocates memory for a new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // Copy the current word into the node
        strcpy(n->word, word);

        // Checks if it is the first element of the linked list to assign the next pointer
        if (table[hash(word)] == NULL)
        {
            n->next = NULL;
        }
        else
        {
            n->next = table[hash(word)];
        }

        // Puts the current node in the start of the list
        table[hash(word)] = n;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int count = 0;
    // Loops through the array of linked lists
    for (int i = 0; i < 26; i++)
    {
        // Traversal pointer
        node *trav = table[i];
        // Loops through each linked list
        while (trav != NULL)
        {
            count++;
            trav = trav->next;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Loops through the array of linked lists
    for (int i = 0; i < 26; i++)
    {
        // Traversal pointer
        node *trav = table[i];
        // Loops through each linked list
        while (trav != NULL)
        {
            // Temporary pointer to be freed
            node *tmp = trav;
            trav = trav->next;
            free(tmp);
        }
    }
    return true;
}
