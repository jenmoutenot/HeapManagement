// This is my code
// Jen Moutenot
// CS 366

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "malloc.h"
#include "memwatch.h"
#include "stddef.h"
#include "allocator.h"

#define max(a,b) ((a) > (b) ? (a) : (b))

static int max_list_depth_used = 0;

struct tAllocator *empty_list = void* memory;

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
void *my_malloc(int size)
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
    new_block = void* ++block;
  }
  else((block->memory) > (sizeof(struct sHeap)))
  {
    new_block = void* ++block;
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
  if(block1 <= void* memory)
  {
    struct sHeap* block = block1;
    --block;
    block->flag = 1;
  }
}

