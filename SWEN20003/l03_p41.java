import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.Scanner;

public class l03_p41{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    System.out.println("the unit of measurement: ");
    String measurement =  sc.next();

    System.out.println("the number of units: ");
    int number = sc.nextInt();

    System.out.println("the ingredient in a recipe: ");
    String ingredient = sc.next();

    try (PrintWriter pw = new PrintWriter(new FileWriter("recipe.txt"))){
      pw.format("- Add %d %s of %s", number, measurement, ingredient);
    } catch (IOException e){
      e.printStackTrace();
    }

  }
}
