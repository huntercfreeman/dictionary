#include <stdlib.h>
#include <stdio.h>
#include "singlyLinkedList.h"
#include "dictionary.h"

int main()
{
  dictionaryStruct* myDictionary = malloc(sizeof(dictionaryStruct));



  singlyLinkedListNode* temporary = dictionaryAPI.Add(myDictionary, "Natalie", 5);
  printf("%s\n", dictionaryAPI.ToString(myDictionary));

  temporary = dictionaryAPI.Add(myDictionary, "Sara", 10);
  printf("%s\n", dictionaryAPI.ToString(myDictionary));

  temporary = dictionaryAPI.Add(myDictionary, "Mpho", 1);
  printf("%s\n", dictionaryAPI.ToString(myDictionary));

}
