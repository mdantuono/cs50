/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"

const int hash_size = 27;

// make struct of node and set properties for linked list
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// create hash table
node *list[hash_size];

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

    // scan the dictionary until the end of the file
    while (fscanf(dictionary, "%s" word) != EOF)
    {
        // hash function from cs50 study website
        int hash_function(const char* word)
        {
             int hash = toupper(word[0] - 'A');
             return hash % 27;
        }

        // allocate memory for each new word
        node *new_word = malloc(sizeof(node));

        // return false if it finds NULL
        if (new_word == NULL)
        {
            unload();
            return false;
        }

        strcpy(new_word-> word, word);

        insert()





    }

    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
