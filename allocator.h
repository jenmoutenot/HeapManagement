// This is my code
// Jen Moutenot
// CS 366

#include "stdio.h"
#include "stddef.h"

#ifdef MYWAY
#define get_mem() my_alloc()
#define free_mem() my_free()
#define BLOCK_SIZE 8
#endif

#ifndef MYWAY
#define get_mem() malloc()
#define free_mem() free()
#define BLOCK_SIZE sizeof(struct sBlock)
#endif

struct sHeap{
  int size;
  int free;
  struct sHeap *next;
};

void initialize();
void *my_alloc(int size);
void my_free(void* block1);
