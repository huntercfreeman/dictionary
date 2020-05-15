#include "dictionary.h"
#include "stringBuilder.h"
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

static char* ToString(dictionaryStruct* dictionary)
{
  if(dictionary == NULL) return "";

  stringBuilder* stringBuilder = stringBuilderAPI.Constructor();

  for(int i = 0; i < DICTIONARY_SIZE; i++)
  {
    singlyLinkedListNode* temporary = dictionary->map[i];
    stringBuilderAPI.AppendChars(stringBuilder, singlyLinkedListAPI.ToString(temporary));
  }

  return stringBuilder->string;
}

dictionaryAPIStruct const dictionaryAPI =
{
  Add, MapKey, ToString
};
