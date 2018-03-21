# asn5 heapier

## Analysis
In this assignment we will be exploring 3 different heap management options.
We will see which one is the most efficient by comparing CPU time and wall-clock time
1. Spongebob 
- All memory blocks should be the same size
- Wrote with a specific constant-size allocator, multiple of 8 

2. Patrick
- Memory blocks that are manually built and are randomly sized, built using C programming

3. Squidward
- Memory blocks that are manually built and are randomly sized, built using Java programming
- Implicit heap manager: determines what parts of the memory are garbage, aka no longer accessible

We will be using regular Heap Memory:
From research: The heap is memory set aside for dynamic allocation. You can allocate a block and free it  at any time. This makes it much more complex to keep track of which parts of the heap are allocated or free at any given time; there are many custom heap allocators available to tune heap performance for different usage patterns.


## Analysis Questions
1. For Patrick, when you say his memory blocks are built in SEA, are we talking C programming? 
-- yes

2. Will the constant size allocator be a multiple of 8? But can be any size? What is a max size amount?
-- unknown ... all you know is that all calls will request the same amount of memory

3. So if a memory block was previously allocated, it is no longer accessible? Why is this? Is this only in Java?

-- reread this
-- Java uses an implicit heap manager that attempts to determine what, if any, of
-- the memory that was previously allocated is no longer accessible, which is
-- referred to as ``garbage''.

4. Are we iterating just through the heap?
-- no you are iterating the pseudo code given on the assignment

5. How is a random memory block selected/ picked in the heap without user interface? Just need a random number generator?
-- man random[3]

6. Is Heap Memory linear in 366?
-- yes, but i don't think you need to know this??

7. Do we only need to write one main function that checks if a randomly selected memory block is allocated or not?
-- yup ... your function implements the pseudo code on the assignment sheet

8. Do we want to code and hand in the CPU time function and wall-clock time function? Or is that more for us to see which heap management option is the most efficient?
-- no, no code needed for timing ... it is done in the makefile.
-- yes to see which option is most efficient

## Design
The design of my program is geared toward developing 3 different heap management options and understanding their influence.
There will be 4 files:
1. main.c 
- Purpose of this is to free and malloc up memory using either Spongebob's or Patrick's heap management option
- Will include the the following pseudocode to interchange from Spongebob to Patrick:
- #ifdef MYWAY
- #define freemem(p) my_free(p)...
- #else
- #define freemem(p) free(p)
- #endif

- Where MYWAY is for Spongebob since he has a constant-size allocator
- And #else is for Patrick and the generic heap management option using malloc() and free() found in man 3 malloc 
- This code will then help the main c file know when we are using Spongebob's heap management option or when we are using Patrick's, depending on whose is defined or not
- Then if it is not defined, it will do regular C's free(p) and free up the memory, aka follow Patrick's heap management option. 
- Also, will be preforming actions like this for Patrick:
- getmem(10) // gets the amount of memory
- p = malloc(s1)
- q = malloc(s2)
- free(p)
- malloc(s3) // this memory can only be reused when s3 is less than s1
- Will also include the following pseudo code:
- create and array of BLOCK_COUNT entries
- for ITERATIONS iterations
- pick a random block
- if that block is allocated, free it
- otherwise allocate BLOCK_SIZE bytes and assign it to the block
- BLOCK_COUNT, ITERATIONS and BLOCK_SIZE will also be defined only in here

2. allocator.c
- Where you write the functions for the constant size allocator 
- This is for Spongebob's MYWAY
- All memory blocks should be the same size
- The constant-size allocator can be any size

3. allocator.h
- Where you define the functions and their fields from allocator.c
- For Spongebob's MYWAY

4. JavaWay.java
- Write functions for an implicit heap manager and has a "garbage collector" when anything is equal to NULL and that will free up memory
- The following pseudocode will be implemented for Squidward's heap management option:
- Integer[] x = new Integer[100]
- x = NULL

- This creates an array of 100 integers

## Plateau Schedule
1. Create my main.c file first 
- Define BLOCK_COUNT, ITERATIONS, and BLOCK_SIZE here
- Translate the pseudo code from the assignment handout into C 
- Write out my #ifdef #else #define and #endif in order to interchange between Spongebob's MYWAY and Patrick's generic malloc() and free()
- Write out the functions for Patrick...which should just include C's free() and malloc()
- Write code that tests to see if these are working correctly
2. Create my allocator.c file
- Write all of Spongebob's 3 functions
- a my_malloc() function, a my_free() function, and a function that checks if a piece of memory has been allocated or not 
- Write code that tests to see if these are working correctly
3. Create my allocator.h file
- Holds the 3 functions and their fields from the allocator.c file for Spongebob
- my_malloc(), my_free(), and the checker function
4. Create the JavaWay.java file
- In here, write functions for the implicit heap manager
- Create an array called x and set it equal to a certain size
- Make x = NULL when you want to free memory

## Empirical Investigation

[[ each of my programs prints out
  @@ block_count ... iterations ... block size ..., 
and then let's /usr/bin/time print
  max resident memory ..., times: user ... elapse ..., context switches ....
see the Makefile for the command line options I used with /usr/bin/time .
(once you grok, you can delete this comment.) ]]




