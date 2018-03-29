// This is my code
// Jen Moutenot
// CS 366

#include "stdio.h"
#include "allocator.h"
#include "malloc.h"

#define BLOCK_COUNT 20000000
#define BLOCK_SIZE 8
#define ITERATIONS 200000000

int main()
{
  struct tHeap sBlock[BLOCK_COUNT];
  srand(time(NULL));
  for (int i = 0; i < ITERATIONS; i++)
  {
      int num = rand() % BLOCK_COUNT;
      printf("%i\n", num);
      if(sBlock[num] == NULL);
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
