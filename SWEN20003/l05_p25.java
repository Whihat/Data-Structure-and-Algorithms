import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;

public class Program {
  public static void main(String[] args) {
    try (BufferedReader br = new BufferedReader(new FileReader("recipe.csv"))){
      String text;
      int count = 0;
      while ((text = br.readLine()) != null){
        String cells[] = text.split(",");
        String ingredient = cells[0];
        double cost = Double.parseDouble(cells[1]);
        int quantity = Integer.parseInt(cells[2]);

        System.out.format("%d %s will cost $%.2f\n",
        quantity, ingredient, cost*quantity);
      }
    }catch(Exception e){
      e.printStackTrace();
    }
  }
}
