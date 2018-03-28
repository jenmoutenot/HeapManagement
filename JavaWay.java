// This is my code
// Jen Moutenot
// CS 366
import java.util.Random;

public class JavaWay
{
  private static final int BLOCK_COUNT = 20;
  private static final int BLOCK_SIZE = 8;
  private static final int ITERATIONS = 20;  
 
  /* purpose: run the experiment timing the random allocation and
   *          deallocation of blocks of memory.
   * input:   nothing
   * returns: nothing
   */
  public void runit()
  {
    Random rand = new Random();
    Integer[] list_array = new Integer[BLOCK_SIZE];
    for (int i = 0; i< ITERATIONS; i++)
    {
      int x = rand.nextInt(BLOCK_COUNT);
      if(list_array[x] == null)
      {
        list_array = new Integer[BLOCK_SIZE];
      }
      else
      {
        list_array[x] = null;
      } 
    }
  }
  public static void main(String [] args)
  {
    JavaWay test = new JavaWay();
    test.runit();
  }

}
