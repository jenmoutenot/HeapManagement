// This is my code
// Jen Moutenot
// CS 366
// Some courtesy to Dr. Binkley

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "malloc.h"
#include "memwatch.h"

#ifdef MYWAY
#include "allocator.h"
#endif

#define BLOCK_COUNT 100000
#define ITERATIONS (300*1000*1000)
#define BLOCK_SIZE 4096

#define INITIAL_LIST_SIZE 1000

#ifdef MYWAY
#define get_mem(x,A) my_malloc(x, A)
#define free_mem(x,A) my_free(x, A)
#else 
#define get_mem(x,A) malloc(x)
#define free_mem(x,A) free(x)
#endif

/* purpose: dump the address assignment to each block
 * input: the block array
 * returns nothing (side effect: prints block addresses)
 */
static void dump_addresses(void *blocks[])
{
  int i;
  for (i = 0; i< BLOCK_COUNT; i++)
    if (blocks[i] != NULL)
      printf("%p\n", blocks[i]);
}

int main()
{
#ifdef MYWAY
  tAllocator *alloc = initialize_allocator(INITIAL_LIST_SIZE);
#endif 
  int i;
  char *blocks[BLOCK_COUNT] = {0};
  for (i = 0; i < BLOCK_COUNT; i++)
  {
    blocks[i] = NULL;
  }
  for (i = 0; i < ITERATIONS; i++)
  {
    int b = rand() % BLOCK_COUNT;
    if (blocks[b] == NULL)
    {
      #ifdef MYWAY
      #else
      blocks[b] = malloc(BLOCK_SIZE);
      if (blocks[b] == NULL)
      {
        printf("new returned null at iteration %d ", i);
        exit(-1);
      }
      #endif
    }
    else
    {
      #ifdef MYWAY
      #else
      blocks[b] = NULL;
      #endif
    }
  }
  for (i = 0; i < BLOCK_COUNT; i++)
  {
    if (blocks[i] != NULL)
    {
      blocks[i] = NULL;
    }
  }
  printf("@ @ blockcount %d iterations %d block size %d \n",
          BLOCK_COUNT, ITERATIONS, BLOCK_SIZE);
  #ifdef MYWAY
  free_allocator(alloc);
  #endif
  return 0;
}
