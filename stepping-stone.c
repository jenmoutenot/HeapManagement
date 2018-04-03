// What I needed to know to get from the assignment sheet to 
// the code in JavaWay.java is to realize that Java's heap
// manager is like a garbage collector.
// Java objects reside in an area called the heap. When the heap
// becomes full, garbage is collected. During the garbage
// collection objects that are no longer used are cleared, 
// thus making space for new objects.
// As Java's heap manager stacks up, it loops though iterations
// and picks a random block.

// This is my code
// Jen Moutenot
// CS 366

#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

#define BLOCK_COUNT 100000
#define ITERATIONS (300*1000*100000/1000)
#define BLOCK_SIZE 4096

int main()
{
  int i;
  char *blocks[BLOCK_COUNT] = {0};
  for (i = 0; i < BLOCK_COUNT; i++)
  {
    blocks[i] = NULL;
  }
  for(i = 0; i < ITERATIONS; i++)
  {
    int b = rand() % BLOCK_COUNT;
    if(blocks[b] == NULL)
    {
      blocks[b] = malloc(BLOCK_SIZE);
      if(blocks[b] == NULL)
      {
      printf("new returned null at iteration ");
      return -1;
      }
    }
    else
    {
      blocks[b] = NULL;
    }
  }
  for (i = 0; i < BLOCK_COUNT; i++)
  {
    if(blocks[i] != NULL)
    {
      blocks[i] = NULL;
    }
  }
  return 0;
}
