import java.util.*;

public class test{
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n, m, a;
    n = in.nextInt(), m = in.nextInt(), a = in.nextInt();
    System.out.println(ceil(n/a) + ceil(m /a));
  }
}