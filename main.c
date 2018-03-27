// This is my code
// Jen Moutenot
// CS 366

#include "stdio.h"
#include "allocator.h"


//#ifdef MYWAY
//#define freemem(p) my_free(p)  //freemem = alias name
//#define mallocmem(p) my_malloc(p)
//#else
//#define freemem(p) free(p)
//#define mallocmem(p) malloc(p)
//#endif

#define BLOCK_COUNT 21
#define BLOCK_SIZE 8
#define ITERATIONS 10

int main()
{
  int ARRAY[BLOCK_COUNT];
    for (int i = 0; i < ITERATIONS; i++)
    {
      int r = rand() % BLOCK_SIZE;
      
    }   
  return 0;

}
