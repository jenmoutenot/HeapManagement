// This is my code
// Jen Moutenot
// CS 366

#include "stdio.h"
#include "memwatch.h"
#include "stddef.h"
#include "allocator.h"

struct sHeap *initial=(void*)memory;

/* purpose: initializes the linked list's memory block
 * input:   nothing
 * returns: nothing
 */
void initialize()
{
 initial->size=20000-sizeof(struct sHeap);
 initial->free=1;
 initial->next=NULL;
}

/* purpose: run the experiment timing the random allocation and
 *          deallocation of blocks of memory.
 * input:   nothing
 * returns: nothing
 */
void *my_alloc(int noOfBytes)
{
  struct sHeap *curr,*prev;
  void *result;
  if(!(initial->size))
  {
    initialize();
  }
  curr=initial;
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
  else if((curr->size)>(noOfBytes+sizeof(struct sHeap)))
  {
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
    struct sHeap* curr=ptr;
    --curr;
    curr->free=1;
    //merge();
  }
  else printf("Please provide a valid pointer allocated by MyMalloc\n");
}

