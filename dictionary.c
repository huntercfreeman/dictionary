#include "dictionary.h"
#include "stringBuilder.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


static unsigned int MapKey(dictionaryStruct* dictionary, char* key)
{
  int length = strlen(key);
  unsigned int hash_value = 0;
  for(int i = 0; i < length; i++)
  {
    hash_value += key[i];
    hash_value = (hash_value * key[i]) % DICTIONARY_SIZE;
  }
  printf("%s:%i\n\n", key, hash_value);
  return hash_value;
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
    stringBuilderAPI.AppendInt(stringBuilder, i);
    stringBuilderAPI.AppendChars(stringBuilder, ":");
    singlyLinkedListNode* temporary = dictionary->map[i];
    stringBuilderAPI.AppendChars(stringBuilder, singlyLinkedListAPI.ToString(temporary));
    stringBuilderAPI.AppendChars(stringBuilder, "\n");
  }

  return stringBuilder->string;
}

dictionaryAPIStruct const dictionaryAPI =
{
  Add, MapKey, ToString
};
