#include "dictionary.h"
#include <stdlib.h>
#include <stdio.h>



static unsigned int MapKey(dictionaryStruct* dictionary, char* key)
{
  return 0;
}

static singlyLinkedListNode* Add(dictionaryStruct* dictionary, char* key, int value)
{
  if(key == NULL) return NULL;

  unsigned int index = dictionaryAPI.MapKey(dictionary, key);

  singlyLinkedListNode* temporary = dictionary->map[index];

  if(temporary == NULL)
  {
    temporary = singlyLinkedListAPI.Constructor(value);

    dictionary->map[index] = temporary;
  }
  else
  {
    temporary = singlyLinkedListAPI.InsertInOrder(temporary, value);
    dictionary->map[index] = temporary;
  }

  return temporary;
}

dictionaryAPIStruct const dictionaryAPI =
{
  Add, MapKey
};
