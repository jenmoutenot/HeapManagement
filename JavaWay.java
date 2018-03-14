import java.util.Random;

// To use class Random.  Once do
//   Random rand = new Random();
// than to create a random number between 0 and N call
//   int x = rand.nextInt(N);


public class JavaWay
{

  ...

  /* purpose: run the experiment timing the random allocation and
   *          deallocation of blocks of memory.
   * input:   nothing
   * returns: nothing
   */
  public void runit()
  {
    Random rand = new Random();
    ...
  }
  
  public static void main(String [] args)
  {
    JavaWay test = new JavaWay();
    test.runit();
  }
}
