// This is my code
// Jen Moutenot
// CS 366

#include "stdio.h"
#include "allocator.h"
#include "malloc.h"

//#ifdef MYWAY
//#define freemem(p) my_free(p)  //freemem = alias name
//#define mallocmem(p) my_malloc(p)
//#else
//#define freemem(p) free(p)
//#define mallocmem(p) malloc(p)
//#endif

#define BLOCK_COUNT 20
#define BLOCK_SIZE 8
#define ITERATIONS 20

int main()
{
  struct block list_array[BLOCK_COUNT];
  srand(time(NULL));
  for (int i = 0; i < ITERATIONS; i++)
    {
      int num = rand() % BLOCK_COUNT;
      printf("%i\n", num);
      if(list_array[num].free == 1)
      {
         free(*list_array[num]); 
      }
      else
      {
        //struct 
        //blocks *b = (blocks *) malloc(sizeof(BLOCK_SIZE));
      }
    }   
  return 0;

}
