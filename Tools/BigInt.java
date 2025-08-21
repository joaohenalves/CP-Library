import java.io.IOException;
import java.util.Scanner;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;

public class Main {
 
    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        BigInteger fact[] = new BigInteger[1001];
        BigInteger b;
        Map<Character, Integer> cr = new HashMap();
        char c;
        String str;
        fact[0] = BigInteger.valueOf(1);
        for(int i = 1; i < 1001; i++) {
            fact[i] = fact[i - 1].multiply(BigInteger.valueOf(i));
        }
        while(true) {
            try {
                str = scan.nextLine();
                b = BigInteger.valueOf(1);
                for (int k = 0; k < str.length(); k++) {
                    c = str.charAt(k);
                    cr.put(c, cr.getOrDefault(c, 0) + 1);
                }
                for (Map.Entry<Character, Integer> entry : cr.entrySet()) {
                    if(entry.getValue() > 1) {
                        b = b.multiply(fact[entry.getValue()]);
                    }
                }
                System.out.println(fact[str.length()].divide(b).mod(BigInteger.valueOf(1000000007)));
            } catch(Exception e) {
                break;
            }
            cr.clear();
        }
    }
}