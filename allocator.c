// This is my code
// Jen Moutenot
// CS 366

#include "stdio.h"
#include "memwatch.h"
#include "stddef.h"
#include "allocator.h"

struct sHeap *empty_list=(void*)memory;

/* purpose: initializes the linked list's memory block
 *          and sets a free flag to 1 
 * input:   nothing
 * returns: nothing
 */
void initialize()
{
 empty_list->memory = sizeof(struct sHeap);
 empty_list->flag = 1; 
 empty_list->next = NULL;
}

/* purpose: allocates memory by obtaining the starting address
 *          of the allocated block of memory
 * input:   size of the memory block
 * returns: nothing
 */
void *my_alloc(int size)
{
  struct sHeap *block;
  struct sHeap *previous; 
  void *new_block;
  block = empty_list;

  while(((block->flag) == 0) && (block->next != NULL))
  {
    previous = block;
    block = block->next;
  }
  if((block->memory) == size)
  {
    block->flag = 0;
    new_block = (void*)(++block);
    return new_block;
  }
  else((block->memory) > (size + sizeof(struct sHeap)))
  {
    new_block = (void*)(++block);
    return new_block;
  }
  new_block = NULL;
  return new_block;
  }
}

/* purpose: frees memory if a block is not allocated.
 *          If the starting address of the memory block lies
 *          within the range of the memory list, then set a free
 *          flag to 1 and iterate through
 * input:   a pointer
 * returns: nothing
 */
void my_free(void* block1)
{
  if((block1 <= (void*)(memory + 10000000)))
  {
    struct sHeap* block = block1;
    --block;
    block->flag = 1;
  }
}

