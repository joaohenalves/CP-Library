import java.util.*;
import java.math.BigInteger;

public class Main {

    static StringBuilder m, n;

    public static void search_y(int i) {
        if(i == n.length()) {
            BigInteger xnum = new BigInteger(m.toString(), 2);
            BigInteger ynum = new BigInteger(n.toString(), 2);
            if(xnum.mod(ynum).equals(BigInteger.ZERO)) {
                System.out.println(m);
                System.exit(0);
            }
        } else {
            if(n.charAt(i) == '*') {
                n.setCharAt(i, '0');
                search_y(i + 1);
                n.setCharAt(i, '1');
                search_y(i + 1);
                n.setCharAt(i, '*');
            } else {
                search_y(i + 1);
            }
        }
    }

    public static void search_x(int i) {
        if(i == m.length()) {
            search_y(0);
        } else {
            if(m.charAt(i) == '*') {
                m.setCharAt(i, '0');
                search_x(i + 1);
                m.setCharAt(i, '1');
                search_x(i + 1);
                m.setCharAt(i, '*');
            } else {
                search_x(i + 1);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        m = new StringBuilder(scan.next());
        n = new StringBuilder(scan.next());
        search_x(0);
    }
}