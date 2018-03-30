// This is my code
// Jen Moutenot
// CS 366

#include "stdio.h"
#include "allocator.h"
#include "memwatch.h"

#define BLOCK_COUNT 10000000
#define BLOCK_SIZE 8
#define ITERATIONS 100000000

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
