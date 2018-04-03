// allocation challenge!  assuming that only blocks of a fixed size are
// allocated, can you (and Sponge Bob) do better (be faster) than 
// malloc and free?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include "memwatch.h"
#include "allocator.h"

#define max(a,b) ((a) > (b) ? (a) : (b))

// [[ A file-scoped variable persists between calls and can thus
// be use to track statistics about a collection of calls.  don't
// be tempted to overuse or abuse file-scooped variables! ]]

static int max_stack_depth_used = 0;


/* purpose: allocate memory bailing if there is an error
 * input:   the size of the block of memory to allocate
 * returns: the address of the block
 */
static void *check_malloc(int size)
{
  void *mem = (void *) malloc(size);
  if (mem == NULL)
  {
    printf("malloc fails bye :(\n");
    exit(-1);
  }

  return mem;
}


// write the headers first then the code

/* purpose: initialize an allocator
 * input:   the initial stack size
 * returns: the initialized allocator
 */
tAllocator *initialize_allocator(int size)
{
...
}


...

