public class l03_p12{
  public static void main(String args[]){
    //Argument set : Run -> Run as -> Run Configuration -> set argument
    // The first argument, in all upper case characters
    System.out.println(args[0].toUpperCase());

    // The middle character of the third argument
    int mid_index = args[2].length()/2;
    System.out.println(args[2].charAt(mid_index));

    // The second argument, with 8 characters, to four decimal places, and left justified
    double num = Double.parseDouble(args[1]);
    System.out.format("%-8.4f\n", num);

  }
}
