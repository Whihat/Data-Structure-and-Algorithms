public class l04_p17{
  public static void main(String args[]){
    int HEIGHT = 5;

    int[][] triangleArray = new int[Height][];

    for(int i = 0; i < HEIGHT;i++){
      triangleArray[i] = new int[HEIGHT-1];

      for(int j = 0;j<HEIGHT-i;j++){
        triangleArray[i][j] = i + j + 1;
      }
    }
  }
}
