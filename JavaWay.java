// This is my code
// Jen Moutenot
// CS 366
import java.util.Random;

public class JavaWay
{
  private static final int ITERATIONS = 
  private static final int BLOCK_SIZE =
  private static final int BLOCK_COUNT =   
 
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
      int x = rand.nextInt(BLOCK_COUNT)
    }
  
  public static void main(String [] args)
  {
    JavaWay test = new JavaWay();
    test.runit();
  }

}
