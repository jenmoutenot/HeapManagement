// What I needed to know to get from the assignment sheet to 
// the code in JavaWay.java is to realize that Java's heap
// manager is like a garbage collector.
// Java objects reside in an area called the heap. When the heap
// becomes full, garbage is collected. During the garbage
// collection objects that are no longer used are cleared, 
// thus making space for new objects.
// As Java's heap manager stacks up, it loops though iterations
// and picks a random block.

/rning: push.default is unset; its implicit value has changed in
Git 2.0 from 'matching' to 'simple'. To squelch this message
and maintain the traditional behavior, use:

  git config --global push.default matching

To squelch this message and adopt the new behavior now, use:

  git config --global push.default simple

When push.default is set to 'matching', git will push local branches
to the remote branches that already exist with the same name.

Since Git 2.0, Git defaults to the more conservative 'simple'
behavior, which only pushes the current branch to the corresponding
remote branch that 'git pull' uses to update the current branch.

See 'git help config' and search for 'push.default' for further information.
(the 'simple' mode was introduced in Git 1.7.11. Use the similar mode
'current' instead of 'simple' if you sometimes use older versions of Git)

X11 forwarding request failed on channel 0
To git@github.com:LoyolaCS366SP18/heapier-jenmoutenot.git
 ! [rejected]        master -> master (fetch first)
error: failed to push some refs to 'git@github.com:LoyolaCS366SP18/heapier-jenmoutenot.git'
hint: Updates were rejected because the remote contains work that you do
hint: not have locally. This is usually caused by another repository pushing
hint: to the same ref. You may want to first integrate the remote changes
hint: (e.g., 'git pull ...') before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
/ This is my code
// Jen Moutenot
// CS 366

#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

#define BLOCK_COUNT 100000
#define ITERATIONS (300*1000*100000/1000)
#define BLOCK_SIZE 4096

int main()
{
  int i;
  char *blocks[BLOCK_COUNT] = {0};
  for (i = 0; i < BLOCK_COUNT; i++)
  {
    blocks[i] = NULL;
  }
  for(i = 0; i < ITERATIONS; i++)
  {
    int b = rand() % BLOCK_COUNT;
    if(blocks[b] == NULL)
    {
      blocks[b] = malloc(BLOCK_SIZE);
      if(blocks[b] == NULL)
      {
      printf("new returned null at iteration ");
      return -1;
      }
    }
    else
    {
      blocks[b] = NULL;
    }
  }
  for (i = 0; i < BLOCK_COUNT; i++)
  {
    if(blocks[i] != NULL)
    {
      blocks[i] = NULL;
    }
  }
  return 0;
}
