import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;

public class l05_p22{
  public static void main(String args[]){
    try(BufferedReader br = new BufferedReader(new FileReader("test.html"))){
      String text;

      int count = 0;

      while((text = br.readLine() != null){
        count = text.contains("<h1>") ? count + 1: count;
      }

      System.out.println("# header : "+count);
    }catch (Exception e){
      e.printStackTrace();
    }
  }
}
