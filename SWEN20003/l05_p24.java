import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.Scanner;

public class l05_p24{
  public void class main(String args[]){
    Scanner sc = new Scanner(System.in);
    try (PrintWriter pw = new PrintWriter(new FileWriter("test.html"))){
      pw.println("<h1> The CHronicles of SWEN20003 </h1>");

      while(sc.hasNext()){
        String text = sc.nextLine();

        pw.println("<p>" + text + "</p>");
      }
    }catch(IOException e){
      e.printStackTrace();
    }
  }
}
