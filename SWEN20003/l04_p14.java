import java.util.Scanner;

public class l03_p14{
  public static void main(String args[]){
    System.out.println("Input String:");
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();

    double[] nums = new double[n];


    for(int i = 0; i<n; i++){
      nums[i] = Math.pow(2,i);
      // For sanity checking
      System.out.println(nums[i]);
    }

  }
}
