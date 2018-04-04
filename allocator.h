// This is my code
// Jen Moutenot
// CS 366

#include "stdio.h"
#include "stddef.h"
#include "stdlib.h"
#include "unistd.h"
#include "malloc.h"
#include "memwatch.h"

struct sHeap{
  int size;
  int free;
  struct sHeap *next;
}tAllocator;

static int max_list_depth_used = 0;
static void *check_malloc(int size);
tAllocator *initialize_allocator;
tAllocator *my_alloc(int size);
tAllocator my_free(void* block1);
