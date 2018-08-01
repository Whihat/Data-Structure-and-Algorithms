/*
  read a txt file -> scan each line -> counts words length totally
*/

import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;

public class l05_p21{
  public static void main(String[] args){

    try(BufferedReader br = new BufferedReader(new FileReader("test.txt"))){
      String txt;
      int count = 0;

      while((text = br.readLine()) != null){
        String words[] = text.split(" ");

        count += words.length;
      }
      System.out.println("# words = "+count);
    }catch(Exception e){
      e.printStackTrace();
    }
  }
}
