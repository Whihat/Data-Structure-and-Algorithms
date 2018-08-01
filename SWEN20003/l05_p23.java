import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.Random;

public class l05_p24{
  public static void main(String args[]){
    final int MAX_NUM = 10000;
    final int ITERATIONS = 1000000;

    Random rand = new Random();

    try(PrintWriter pw = new PrintWriter(new FileWriter("test.txt"))){
      int nums[] = new int[MAX_NUM];

      for(int i = 0; i<ITERATIONS;i++){
        nums[rand.nextInt(MAX_NUM)] += 1;
      }
      for(int i = 0; i<nums.length; i++){
        pw.format("%4d: %4d\n",i, nums[i]);
      }
    }catch(IOException e){
      e.printStackTrace();
    }
  }
}
