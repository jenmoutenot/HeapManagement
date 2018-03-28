// This is my code
// Jen Moutenot
// CS 366

#include <stdio.h>
#include <stddef.h>
#include "allocator.h"

struct block *freeList=(void*)memory;
/* purpose: run the experiment timing the random allocation and
 *          deallocation of blocks of memory.
 * input:   nothing
 * returns: nothing
 */
void initialize()
{
 freeList->size=20000-sizeof(struct block);
 freeList->free=1;
 freeList->next=NULL;
}

/* purpose: run the experiment timing the random allocation and
 *          deallocation of blocks of memory.
 * input:   nothing
 * returns: nothing
 */
void *get_mem(int noOfBytes)
{
  struct block *curr,*prev;
  void *result;
  if(!(freeList->size))
  {
    initialize();
  }
  curr=freeList;
  while((((curr->size)<noOfBytes)||((curr->free)==0))&&(curr->next!=NULL))
  {
    prev=curr;
    curr=curr->next;
  }
  if((curr->size)==noOfBytes)
  {
    curr->free=0;
    result=(void*)(++curr);
    return result;
  }
  else if((curr->size)>(noOfBytes+sizeof(struct block)))
  {
    //split(curr,noOfBytes);
    result=(void*)(++curr);
    return result;
  }
  else
  {
    result=NULL;
    return result;
  }
}

/* purpose: run the experiment timing the random allocation and
 *          deallocation of blocks of memory.
 * input:   nothing
 * returns: nothing
 */
void my_free(void* ptr)
{
  if(((void*)memory<=ptr)&&(ptr<=(void*)(memory+20000)))
  {
    struct block* curr=ptr;
    --curr;
    curr->free=1;
    //merge();
  }
  else printf("Please provide a valid pointer allocated by MyMalloc\n");
}

