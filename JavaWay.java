import java.util.Random;

// To use class Random.  Once do
//   Random rand = new Random();
// than to create a random number between 0 and N call
//   int x = rand.nextInt(N);


public class JavaWay
{

  
  /* purpose:
   * input:
   * returns:
   */
 // public void allocator()
 // {
   // int [] x = new int [100];
    //for ITERATIONS iterations
     //pick a random bock- rand.nextInt() % 100 
     //if the block is allocated, free it
     //otherwise allocate that specific block by setting the array index to a new int 
 // }

  /* purpose: run the experiment timing the random allocation and
   *          deallocation of blocks of memory.
   * input:   nothing
   * returns: nothing
   */
  public void runit()
  {
    Random rand = new Random();
 
  }
  
  public static void main(String [] args)
  {
    JavaWay test = new JavaWay();
    test.runit();
  }
}
