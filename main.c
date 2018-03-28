// This is my code
// Jen Moutenot
// CS 366

#include "stdio.h"
#include "allocator.h"
#include "malloc.h"

#define BLOCK_COUNT 20000000
#define BLOCK_SIZE 8
#define ITERATIONS 200000000

//#ifdef MYWAY
//#define freemem(p) my_free(p)  //freemem = alias name
//#define mallocmem(p) my_malloc(p)
//#else
//#define freemem(p) free(p)
//#define mallocmem(p) malloc(p)
//#endif

int main()
{
  struct block list_array[BLOCK_COUNT];
  srand(time(NULL));
  for (int i = 0; i < ITERATIONS; i++)
  {
      int num = rand() % BLOCK_COUNT;
      printf("%i\n", num);
      if(list_array[num] == NULL);
      {
        get_mem(); 
      }
      else
      { 
        my_free();
      }
  }   
  return 0;

}
