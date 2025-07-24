// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *cursor = table[index];
    while(cursor != NULL)
    {
        if(strcasecmp(word, cursor -> word) == 0)
        {
            return true;
        }
        cursor = cursor-> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //打開dictonary檔
    FILE *source = fopen(dictionary, "r");
    if(source == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }
    // 準備存讀進來的單字
    char word[LENGTH + 1];
    // 每次讀入一個字
    while(fscanf(source, "%s", word)!=EOF)
    {
        //造新node給每個string
        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            printf("No memory\n");
            fclose(source);
            return false;
        }
        // 將字複製進節點
        strcpy(n->word, word);

        //hash word to obtain a hash value
        int index = hash(word);
        // 插入到對應的 hash bucket
        n->next = table[index];  // 頭插法：新節點的 next 指向目前的頭
        table[index] = n;        // 將新節點設為新的頭

        word_count++;
    }

    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while(cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
