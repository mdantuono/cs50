/**
 * Implements a dictionary's functionality.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

// variable declarations
const int hash_size = 26;
int word_count = 0;
int hash_num = 0;

// make struct of node and set properties for linked list
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// create hash table
node* list[hash_size];

// hash function from cs50 study website
int hash(const char* word)
{
    hash_num = toupper(word[0] - 'A');
    return hash_num % hash_size;
}

// universal to-lower function
// char lowercase(const char* word)
// {
//     char lower_word[LENGTH + 1];

//     // loop to make all letters in word lowercase
//     for (int n = 0; n < strlen(word); n++)
//     {
//         lower_word[n] = tolower(word[n]);
//     }

//     return lower_word;
// }

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    char lower_word[LENGTH + 1] = "";

    // loop to make all letters in word lowercase
    for (int n = 0; n < strlen(word); n++)
    {
        lower_word[n] = tolower(word[n]);
    }

    int index = hash(lower_word);

    node* cursor = list[index];

    while (cursor != NULL)
    {
        if (strcmp(cursor->word, lower_word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }

    return false;

}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // open dictionary file
    FILE *dict = fopen(dictionary, "r");

    if (dict == NULL)
    {
        fprintf(stderr, "Dictionary file not loaded.\n");
        return 1;
    }
    // else fprintf(stderr, "File opened.\n");

    // initially set all pointers in hash table to NULL
    for (int i = 0; i < hash_size; i++)
    {
        list[i] = NULL;
    }

    // set variable word
    char file_word[LENGTH + 1];

    // scan the dictionary until the end of the file
    while (fscanf(dict, "%s\n", file_word) != EOF)
    {
        hash_num = hash(file_word);

        // allocate memory for each new word
        node* new_node = malloc(sizeof(node));

        // make sure malloc worked, return false if it finds NULL
        if (new_node == NULL)
        {
            return false;
        }

        // increment counter for every word found
        word_count++;

        strcpy(new_node->word, file_word);

        // insert into hash table linked list
        if (list[hash_num] == NULL)
        {
            list[hash_num] = new_node;
        }
        else
        {
            new_node-> next = list[hash_num];
            list[hash_num] = new_node;
        }

    }
    fclose(dict);
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

    for (int j = 0; j < hash_size; j++)
    {
        free(list[j]);
    }

    return true;

}
