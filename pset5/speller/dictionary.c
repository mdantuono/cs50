/**
 * Implements a dictionary's functionality.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

const int hash_size = 27;
int word_count = 0;

// make struct of node and set properties for linked list
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// create hash table
node *list[hash_size];

// hash function from cs50 study website
int hash_function(const char* word)
{
     int hash = toupper(word[0] - 'A');
     return hash % 27;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    FILE* dict = fopen(dictionary, "r");

    char word[LENGTH + 1];

    // scan the dictionary until the end of the file
    while (fscanf(dict, "%s\n", word) != EOF)
    {
        int hash = hash_function(word);

        // allocate memory for each new word
        node *new_word = malloc(sizeof(node));

        // make sure malloc worked, return false if it finds NULL
        if (new_word == NULL)
        {
            unload();
            return false;
        }

        // increment counter
        word_count++;

        strcpy(new_word-> word, word);

        // insert into hash table linked list
        new_word-> next = list[hash];

        list[hash] = new_word;

    }

    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return word_count;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
