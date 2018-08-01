import java.util.Scanner;

public class Program {
  public static void main(String[] args){
    final int N_OPTIONS = 3;

    final int ORIGINAL = 0;
    final int NEW = 1;
    final int OTHER = 2;

    int results[] = new int[N_OPTIONS];

    Scanner scanner = new Scanner(System.in);

    while (scanner.hasNextInt()) {

      int vote = scanner.nextInt();

      results[vote] += 1;
    }

    System.out.println("Original Trilogy: " + results[ORIGINAL]);
    System.out.println("New Trilogy: " + results[NEW]);
    System.out.println("Other Trilogy: " + results[OTHER]);
  }
}
