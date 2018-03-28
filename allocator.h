// This is my code
// Jen Moutenot
// CS 366

#include "stdio.h"
#include "stddef.h"

#ifndef MYWAY
#define MYWAY

char memory[20000];

struct block{
  int size;
  int free;
  struct block *next;
} blocks;

//struct block *freeList=(void*)memory;

void initialize();
void *get_mem(int noOfBytes);
//void merge();
void my_free(void* ptr);

#endif
