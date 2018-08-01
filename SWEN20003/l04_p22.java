import java.util.Scanner;
import java.util.Arrays;
 
public class l04_p22{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    System.out.print("Input n: ");
    int num = sc.nextInt();

    String[] result = new String[num];

    //make sure we eat the new line charcter
    sc.nextLine();

    for(int i=0; i<num;i++){
      System.out.print("Input some text: ");
      result[i] = sc.nextLine();
    }

    System.out.println(Arrays.toString(result));
    Arrays.sort(result);
    System.out.println(Arrays.toString(result));
  }
}
