// This is my code
// Jen Moutenot
// CS 366
// Courtesy of Dr. Binkley

// allocation challenge!  assuming that only blocks of a fixed size are
// allocated, test how java's heap manager "stacks" up.

import java.util.Random;

public class JavaWay
{
  final static int BLOCK_COUNT = 100000;
  final static int ITERATIONS = (300*1000*1000/1000);
  final static int BLOCK_SIZE = 4096;

  /* purpose: run the experiment timing the random allocation and 
   *          deallocation of blocks of memory.
   * input:   nothing 
   * returns: nothing
   */
  public void runit()
  {
    Random rand = new Random();
    Byte [][] blocks = new Byte[BLOCK_COUNT][];

    int i;
    for(i=0; i<BLOCK_COUNT; i++)  
      blocks[i] = null;
  
    for(i=0; i<ITERATIONS; i++)
    {
      int b = rand.nextInt(BLOCK_COUNT);
      if (blocks[b] == null)
      {
        blocks[b] = new Byte[BLOCK_SIZE];
        if (blocks[b] == null)
        {
          System.out.println("new returned null at iteration " + i +" ... bye");
          System.exit(-1);
        }
      }
      else
      {
        blocks[b] = null;
      }
    }
  
    for(i=0; i<BLOCK_COUNT; i++)   
      if (blocks[i] != null)       
        blocks[i] = null;          // "free" all (allocated) blocks 

  }
  
  public static void main(String [] args)
  {
    System.out.print("@@ block_count " + BLOCK_COUNT + " iterations " +
                     ITERATIONS + " block size " + BLOCK_SIZE + " ");
    JavaWay test = new JavaWay();
    test.runit();
    System.exit(0);
  }
}

