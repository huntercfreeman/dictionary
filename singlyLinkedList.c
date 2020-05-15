#include <stdio.h>
#include <stdlib.h>
#include "singlyLinkedList.h"
#include "stringBuilder.h"

static singlyLinkedListNode* AddNodeAfter(singlyLinkedListNode* current, singlyLinkedListNode* node)
{
  if(current == NULL) return NULL;

  node->next = current->next;

  current->next = node;

  return current;
}

static singlyLinkedListNode* AddValueAfter(singlyLinkedListNode* current, int value)
{
  if(current == NULL) return NULL;

  singlyLinkedListNode* temporary = (singlyLinkedListNode*)malloc(sizeof(singlyLinkedListNode));
  temporary->next = current->next;
  temporary->value = value;

  current->next = temporary;

  return current;
}

static singlyLinkedListNode* AddNodeStart(singlyLinkedListNode* head, singlyLinkedListNode* node)
{
  node->next = head;

  return node;
}

static singlyLinkedListNode* AddValueStart(singlyLinkedListNode* head, int value)
{
  singlyLinkedListNode* temporary = (singlyLinkedListNode*)malloc(sizeof(singlyLinkedListNode));
  temporary->value = value;
  temporary->next = head;

  return temporary;
}

static singlyLinkedListNode* AddNodeEnd(singlyLinkedListNode* head, singlyLinkedListNode* node)
{
  if(head == NULL) return NULL;

  if(head->next == NULL)
  {
    node->next = NULL;

    head->next = node;

    return head;
  }

  singlyLinkedListNode* currentNode = head;
  while(currentNode->next != NULL)
  {
    currentNode = currentNode->next;
  }

  node->next = NULL;

  currentNode->next = node;

  return head;
}

static singlyLinkedListNode* AddValueEnd(singlyLinkedListNode* head, int value)
{
  if(head == NULL) return NULL;

  if(head->next == NULL)
  {
    singlyLinkedListNode* temporary = (singlyLinkedListNode*)malloc(sizeof(singlyLinkedListNode));
    temporary->value = value;
    temporary->next = NULL;

    head->next = temporary;

    return head;
  }

  singlyLinkedListNode* currentNode = head;
  while(currentNode->next != NULL)
  {
    currentNode = currentNode->next;
  }

  singlyLinkedListNode* temporary = (singlyLinkedListNode*)malloc(sizeof(singlyLinkedListNode));
  temporary->value = value;
  temporary->next = NULL;

  currentNode->next = temporary;

  return head;
}

static singlyLinkedListNode* Clear(singlyLinkedListNode* head)
{
  if(head == NULL) return NULL;

  if(head->next == NULL)
  {
    free(head);
    head = NULL;

    return NULL;
  }

  singlyLinkedListNode* temporary1 = head;
  singlyLinkedListNode* temporary2 = head->next;
  free(temporary1);
  temporary1 = NULL;

  while(temporary2->next != NULL)
  {
    temporary1 = temporary2;
    temporary2 = temporary1->next;
    free(temporary1);
    temporary1 = NULL;
  }

  free(temporary2);
  temporary2 = NULL;

  return NULL;
}

static int Contains(singlyLinkedListNode* head, int value)
{
  if(head == NULL) return 0;

  if(head->value == value) return 1;

  singlyLinkedListNode* temporary = head;
  while(temporary->next != NULL)
  {
    temporary = temporary->next;

    if(temporary->value == value) return 1;
  }

  return 0;
}

static singlyLinkedListNode* CopyToArray(singlyLinkedListNode* head, int startingIndex)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return NULL;
}

static int Equal(singlyLinkedListNode* headOne, singlyLinkedListNode* headTwo)
{
  if((headOne == NULL) && (headTwo == NULL)) return 1;
  if((headOne == NULL) || (headTwo == NULL)) return 0;

  int equivalence = 1;

  singlyLinkedListNode* temporary1 = headOne;
  singlyLinkedListNode* temporary2 = headTwo;

  if(temporary1->value != temporary2->value) equivalence = 0;

  while(equivalence && (temporary1->next != NULL) && (temporary2->next != NULL))
  {
    temporary1 = temporary1->next;
    temporary2 = temporary2->next;

    if(temporary1->value != temporary2->value) equivalence = 0;
  }

  if(equivalence != 0)
  {
    if((temporary1->next == NULL) && (temporary2->next == NULL)) return 1;
    if((temporary1->next == NULL) || (temporary2->next == NULL)) return 0;
  }

  return equivalence;
}

static int Count(singlyLinkedListNode* head)
{
  if(head == NULL) return 0;

  int count = 1;

  singlyLinkedListNode* temporary = head;
  while(temporary->next != NULL)
  {
    temporary = temporary->next;

    count++;
  }

  return count;
}

static singlyLinkedListNode* FindFirst(singlyLinkedListNode* head, int value)
{
  if(head == NULL) return NULL;

  if(head->value == value) return head;

  singlyLinkedListNode* temporary = head;
  while(temporary->next != NULL)
  {
    temporary = temporary->next;
    if(temporary->value == value) return temporary;
  }

  return NULL;
}

static singlyLinkedListNode* FindLast(singlyLinkedListNode* head, int value)
{
  if(head == NULL) return NULL;

  singlyLinkedListNode* foundNode = NULL;

  if(head->value == value) foundNode = head;

  singlyLinkedListNode* temporary = head;
  while(temporary->next != NULL)
  {
    temporary = temporary->next;
    if(temporary->value == value) foundNode = temporary;
  }

  return foundNode;
}

static singlyLinkedListNode* RemoveNode(singlyLinkedListNode* head, singlyLinkedListNode* node, int (* predicate)(singlyLinkedListNode *node1, singlyLinkedListNode *node2))
{
  if(head == NULL) return NULL;
  if(predicate == NULL) return NULL;

  if(predicate(head, node))
  {
    singlyLinkedListNode* temporary = head->next;
    free(head);
    head = NULL;

    return temporary;
  }

  singlyLinkedListNode* temporary = head;
  while(temporary->next != NULL)
  {
    singlyLinkedListNode* previousNode = temporary;
    temporary = temporary->next;
    if(predicate(temporary, node))
    {
      previousNode->next = temporary->next;
      free(temporary);
      temporary = NULL;
      return head;
    }
  }

  return head;
}

static singlyLinkedListNode* RemoveFirst(singlyLinkedListNode* head, int value)
{
  if(head == NULL) return NULL;

  if(head->value == value)
  {
    singlyLinkedListNode* temporary = head->next;
    free(head);
    head = NULL;

    return temporary;
  }

  singlyLinkedListNode* temporary = head;
  while(temporary->next != NULL)
  {
    singlyLinkedListNode* previousNode = temporary;
    temporary = temporary->next;
    if(temporary->value == value)
    {
      previousNode->next = temporary->next;
      free(temporary);
      temporary = NULL;
      return head;
    }
  }

  return head;
}

static singlyLinkedListNode* RemoveLast(singlyLinkedListNode* head, int value)
{
  if(head == NULL) return NULL;

  singlyLinkedListNode* previousToRemoveNode = NULL;
  singlyLinkedListNode* removeNode = NULL;

  if(head->value == value)
  {
    removeNode = head;
  }

  singlyLinkedListNode* temporary = head;
  while(temporary->next != NULL)
  {
    singlyLinkedListNode* previousNode = temporary;
    temporary = temporary->next;
    if(temporary->value == value)
    {
      previousToRemoveNode = previousNode;
      removeNode = temporary;
    }
  }

  if(removeNode != NULL)
  {
    if(previousToRemoveNode == NULL)
    {
      // remove the head
      singlyLinkedListNode* newHead = head->next;
      free(head);
      head = NULL;

      return newHead;
    }
    else
    {
      previousToRemoveNode->next = removeNode->next;
      free(removeNode);
      removeNode = NULL;
      return head;
    }
  }

  return head;
}

static singlyLinkedListNode* RemoveStart(singlyLinkedListNode* head)
{
  if(head == NULL) return NULL;

  singlyLinkedListNode* newHead = head->next;
  free(head);
  head = NULL;

  return newHead;
}

static singlyLinkedListNode* RemoveEnd(singlyLinkedListNode* head)
{
  if(head == NULL) return NULL;

  singlyLinkedListNode* previousToRemoveNode = NULL;
  singlyLinkedListNode* removeNode = NULL;

  if(head->next == NULL)
  {
    free(head);
    head = NULL;

    return NULL;
  }

  singlyLinkedListNode* temporary = head;
  while(temporary->next != NULL)
  {
    previousToRemoveNode = temporary;
    temporary = temporary->next;
    removeNode = temporary;
  }

  previousToRemoveNode->next = removeNode->next;
  free(removeNode);
  removeNode = NULL;

  return head;
}

// Look into freeing the stringBuilder
static char* ToString(singlyLinkedListNode* head)
{
  if(head == NULL) return "";

  stringBuilder* stringBuilder = stringBuilderAPI.Constructor();
  stringBuilderAPI.AppendInt(stringBuilder, head->value);

  singlyLinkedListNode* temporary = head;

  while(temporary->next != NULL)
  {
    stringBuilderAPI.AppendChars(stringBuilder, "->");

    temporary = temporary->next;
    stringBuilderAPI.AppendInt(stringBuilder, temporary->value);
  }
  //stringBuilderAPI.AppendChars(stringBuilder, "\n");

  return stringBuilder->string;
}

static singlyLinkedListNode* InsertInOrder(singlyLinkedListNode *head, int value)
{
  if(head == NULL) return NULL;

  if(head->value >= value)
  {
    singlyLinkedListNode* temporary = (singlyLinkedListNode*)malloc(sizeof(singlyLinkedListNode));
    temporary->next = head;
    temporary->value = value;

    return temporary;
  }

  singlyLinkedListNode* temporary = head;
  while((temporary->next != NULL) && (temporary->next->value < value))
  {
    temporary = temporary->next;
  }

  singlyLinkedListNode* newNode = (singlyLinkedListNode*)malloc(sizeof(singlyLinkedListNode));
  newNode->next = temporary->next;
  newNode->value = value;

  temporary->next = newNode;

  return head;
}

static void Print(singlyLinkedListNode* head)
{
  if(head == NULL) return;

  printf("%d", head->value);
  singlyLinkedListNode* current = head;
  while(current->next != NULL)
  {
    current = current->next;
    printf("->%d", current->value);
  }
  printf("\n");
}

static singlyLinkedListNode* Constructor(int value)
{
  singlyLinkedListNode* temporary = (singlyLinkedListNode*)malloc(sizeof(singlyLinkedListNode));
  temporary->value = value;
  temporary->next = NULL;
}

singlyLinkedListAPIStruct const singlyLinkedListAPI =
{Print, InsertInOrder, AddNodeAfter, AddValueAfter,
AddNodeStart, AddValueStart, AddNodeEnd, AddValueEnd, Clear, Contains, CopyToArray,
Equal, Count, FindFirst, FindLast, RemoveNode, RemoveFirst, RemoveLast, RemoveStart,
RemoveEnd, ToString, Constructor};
