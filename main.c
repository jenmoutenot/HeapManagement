// This is my code
// Jen Moutenot
// CS 366

#include "stdio.h"
//#include "allocator.h"
#include "allocator.c"

//#ifdef MYWAY
//#define freemem(p) my_free(p)  //freemem = alias name
//#define mallocmem(p) my_malloc(p)
//#else
//#define freemem(p) free(p)
//#define mallocmem(p) malloc(p)
//#endif

int main()
{
 //Create an array of BLOCK_COUNT ENTRIES
 // for ITERATIONS iterations
   //pick a random block
   // if that block is allocated, free it
   // otherwise allocate BLOCK_SIZE bytes and assign it to the blocks 

 int *p=(int)MyMalloc(100*sizeof(int));
 char *q=(char)MyMalloc(250*sizeof(char));
 int *r=(int)MyMalloc(1000*sizeof(int));
 MyFree(p);
 char *w=(char)MyMalloc(700);
 MyFree(r);
 int *k=(int)MyMalloc(500*sizeof(int));
 printf("Allocation and deallocation is done successfully!");

// return 0;

}
