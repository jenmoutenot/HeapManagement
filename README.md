# asn5 heapier

## Analysis
In this assignment we will be exploring 3 different heap management options
We will see which one is the most efficient by comparing CPU time and wall-clock time
1. Spongebob 
- All memory blocks should be the same size
- Wrote with a specific constant-size allocator, multiple of 8 

2. Patrick
- Memory blocks that are manually built and are randomly sized, built using C programming

3. Squidward
- Memory blocks that are manually built and are randomly sized, built using Java programming
- Implicit heap manager: determines what parts of the memory are garbage, aka no longer accessible

We will be using regular Heap Memory
From research: The heap is memory set aside for dynamic allocation. You can allocate a block and free it  at any time. This makes it much more complex to keep track of which parts of the heap are allocated or free at any given time; there are many custom heap allocators available to tune heap performance for different usage patterns.


## Analysis Questions
1. For Patrick, when you say his memory blocks are built in SEA, are we talking C programming? 
2. Will the constant size allocator be a multiple of 8? But can be any size? What is a max size amount?
3. So if a memory block was previously allocated, it is no longer accessible? Why is this? Is this only in Java?
4. Are we iterating just through the heap?
5. How is a random memory block selected/ picked in the heap without user interface? Just need a random number generator?
6. Is Heap Memory linear in 366?
7. Do we only need to write one main function that checks if a randomly selected memory block is allocated or not?
8. Do we want to code and hand in the CPU time function and wall-clock time function? Or is that more for us to see which heap management option is the most efficient?

## Design
[[ note that BLOCK_COUNT, ITERATIONS, and BLOCK_SIZE should only be defined in
main.c.  they should not be defined in allocator.[ch]. (once you grok, you can
delete this comment.) ]]

## Plateau Schedule

## Empirical Investigation

[[ each of my programs prints out
  @@ block_count ... iterations ... block size ..., 
and then let's /usr/bin/time print
  max resident memory ..., times: user ... elapse ..., context switches ....
see the Makefile for the command line options I used with /usr/bin/time .
(once you grok, you can delete this comment.) ]]




