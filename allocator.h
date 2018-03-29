// This is my code
// Jen Moutenot
// CS 366

#include "stdio.h"
#include "stddef.h"

#ifdef MYWAY
#define get_mem  my_alloc
#define free_mem my_free
#define BLOCK_SIZE 10
#endif

#ifndef MYWAY
#define get_mem malloc
#define free_mem free
#define BLOCK_SIZE sizeof(struct sBlock)
#endif

char memory[20000];

struct sHeap{
  int size;
  int free;
  struct block *next;
} blocks;

//struct block *freeList=(void*)memory;

void initialize();
void *get_mem(int noOfBytes);
//void merge();
void my_free(void* ptr);
