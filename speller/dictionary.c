// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 18278;
unsigned int word_counter = 0;
// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // numerical hash value or index
    //int hash_value = hash(word);
    // Point a cursor
    node *cursor = table[hash(word)];

    // Loop while cursor is not empty
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    // add ascii values of the letters
    unsigned int ascii_sum = 0;
    /*
    for (int i = 0; i < strlen(word); i++)
    {
        ascii_sum = ascii_sum + tolower(word[i]);
    }
    return ascii_sum % N; // jimmy buckets */
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    // Open dictionary file
    FILE *dfile = fopen(dictionary, "r");

    // null checker
    if (dfile == NULL)
    {
        printf("empty!\n");
        return false;
    }
    // Read strings from file

    char word[LENGTH + 1];
    while (fscanf(dfile, "%s", word) != EOF)
    {
        // Create a new node
        node *n = malloc(sizeof(node));

        // null checker
        if (n == NULL)
        {
            printf("n-pty!\n");
            return false;
        }
        strcpy(n->word, word);

        // Hash word
        unsigned int hash_brown = hash(word);

        // Insert node into Hash table
        n->next = table[hash_brown];
        table[hash_brown] = n;
        // counts the number of words
        word_counter++;
    }
    fclose(dfile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        // Point a cursor
        node *cursor = table[i];

        // Loop while cursor is not emptye
        while (cursor != NULL)
        {
            // point tmp cursor to cursor address, or the word it points into
            node *tmp = cursor;
            // move the cursor to point to the next one
            cursor = cursor->next;
            // the next words won't be orphaned because cursor is not affected due to cursor->next
            free(tmp);
        }
    }
    return true;
}
