import java.util.Scanner;

public class l04_p01{
  public static void main(String args[]){

	  	System.out.println("input string:");
	    int nLower = 0;
	    int nUpper = 0;
	    int nSpace = 0;

	    Scanner sc = new Scanner(System.in);
	    String text = sc.nextLine();

	    for(int i=0;i<text.length();i++) {
	    	char c = text.charAt(i);

	    	if(Character.isLowerCase(c)) {
	    		nLower++;
	    	}
	    	else if(Character.isUpperCase(c)) {
	    		nUpper++;
	    	}
	    	else if(c == ' '){
	    		nSpace++;
	    	}
	    }

	    System.out.format("%d %d %d",nLower, nUpper, nSpace);
	}
}
