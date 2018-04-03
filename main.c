// This is my code
// Jen Moutenot
// CS 366
// Some courtesy to Dr. Binkley

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include "memwatch.h"

#ifdef MYWAY
#include "allocator.h"
#endif

#define BLOCK_COUNT 100000
#define ITERATIONS (300*1000*1000)
#define BLOCK_SIZE 4096

#define INITIAL_STACK_SIZE 1000

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
#ifdef MYWAY/usr/bin/time -f "$TIME_FORMAT" stepping-stone
  tAllocator *alloc = initialize_allocator(INITIAL_STACK_SIZE);
#endif 

...

      blocks[b] = get_mem(BLOCK_SIZE, alloc);

...

  printf("@@ block_count %d iterations %d block size %d, ", 
         BLOCK_COUNT, ITERATIONS, BLOCK_SIZE);

  free_allocator(alloc);

  return 0;
}

