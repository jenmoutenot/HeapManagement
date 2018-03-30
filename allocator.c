// This is my code
// Jen Moutenot
// CS 366

#include "stdio.h"
#include "memwatch.h"
#include "stddef.h"
#include "allocator.h"

struct sHeap *empty_list=(void*)memory;

/* purpose: initializes the linked list's memory block
 * input:   nothing
 * returns: nothing
 */
void initialize()
{
 empty_list->memory = sizeof(struct sHeap);
 empty_list->flag = 1; 
 empty_list->next = NULL;
}

/* purpose: allocates memory by
 * input:   nothing
 * returns: nothing
 */
void *my_alloc(int noOfBytes)
{
  struct sHeap *block;
  struct sHeap *previous; 
  void *result;
  if(!(empty_list->memory))
  {
    initialize();
  }
  block = empty_list;
  while((((block->memory) < noOfBytes) || ((block->flag)==0)) && (block->next != NULL))
  {
    previous = block;
    block = block->next;
  }
  if((block->memory) == noOfBytes)
  {
    block->flag=0;
    result=(void*)(++block);
    return result;
  }
  else if((block->memory)>(noOfBytes + sizeof(struct sHeap)))
  {
    result=(void*)(++block);
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
  if(((void*)memory <= ptr) && (ptr <= (void*)(memory+20000)))
  {
    struct sHeap* block = ptr;
    --block;
    block->flag=1;
  }
}

