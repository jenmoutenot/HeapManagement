// This is my code
// Jen Moutenot
// CS 366
import java.util.Random;

public class JavaWay
{
  private static final int BLOCK_COUNT = 20000000;
  private static final int BLOCK_SIZE = 8;
  private static final int ITERATIONS = 200000000;  
 
  /* purpose: creates an array of all the memory blocks and loops through
   *          all the blocks. If free, allocates. If allocated, frees it.
   * input:   nothing
   * returns: nothing
   */
  public void runit()
  {
    Random rand = new Random();
    Integer[] list_array = new Integer[BLOCK_SIZE];
    for (int i = 0; i< ITERATIONS; i++)
    {
      int num = rand.nextInt(BLOCK_COUNT);
      if(list_array[num] == null)
      {
        list_array = new Integer[BLOCK_SIZE];
      }
      else
      {
        list_array[num] = null;
      } 
    }
  }
  public static void main(String [] args)
  {
    JavaWay test = new JavaWay();
    test.runit();
  }

}
