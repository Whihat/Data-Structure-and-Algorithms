import java.util.Scanner;

public class l04_p25{
  public static void main(String args[]){

    final int MaxLength = 10;
    int[] ints = new int[MaxLength+1];
    Scanner sc = new Scanner(System.in);
    //do...until...
    do {
      System.out.println("input text:");
      String tmp = sc.nextLine();
      String[] tmp_array = tmp.split(" ");

      for(int i = 0; i<tmp_array.length;i++) {
        ints[tmp_array[i].length()] += 1;

      }
    }while(!sc.hasNextLine());
    
    for(int j=1;j<=MaxLength;j++) {
      System.out.format("Length %02d words: %d\n",j,ints[j]);
    }
  }
}
