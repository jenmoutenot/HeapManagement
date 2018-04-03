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

#define BLOCK_COUNT 100000
#define ITERATIONS (300*1000*1000/1000)
#define BLOCK_SIZE 4096

int main()
{
  struct sHeap sBlock[BLOCK_COUNT];
  srand(time(NULL));
  for (int i = 0; i < ITERATIONS; i++)
  {
    int num = rand() % BLOCK_COUNT;
    if(sBlock[num] == NULL)
    {
      get_mem();
    }
    else
    {
      free_mem();
    }
  }
  return 0;
}
