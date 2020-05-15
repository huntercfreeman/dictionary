#ifndef dictionaryLibrary
#define dictionaryLibrary
#include "singlyLinkedList.h"
#define DICTIONARY_SIZE 10

/*
  Maps a string to a linked list.
*/

typedef struct {
  unsigned int count;
  singlyLinkedListNode* map[DICTIONARY_SIZE];
} dictionaryStruct;

typedef struct dictionaryAPIStruct {
  singlyLinkedListNode* (* const Add)(dictionaryStruct* dictionary, char* key, int value);
  unsigned int (* const MapKey)(dictionaryStruct* dictionary, char* key);
  char* (* const ToString)(dictionaryStruct* dictionary);
} dictionaryAPIStruct;

dictionaryAPIStruct const dictionaryAPI;

#endif
