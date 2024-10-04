import java.util.Scanner;
import java.math.BigInteger;

// Reading from STDIN
// BigInteger bi = sc.nextBigInteger();
// BigInteger bi = new BigInteger(sc.next());

// Constructors
// BigInteger(String val)
// BigInteger(String val, int radix)

// Constants
// BigInteger.ZERO;
// BigInteger.ONE;
// BigInteger.TWO;
// BigInteger.TEN;

// BI.valueOf(int);
// BI.intValue();

// BI.add(BI b); ................. a + b
// BI.subtract(BI b); ............ a - b
// BI.multiply(BI b); ............ a * b
// BI.divide(BI b); .............. a / b
// BI.sqrt(); .................... /*$\sqrt{a}$*/
// BI.pow(int p); ................ /*$a^p$*/
// BI.remainder(BI m); ........... a % m
// BI.mod(BI m); ................. a % m
// BI.modInverse(BI m); .......... /*$ a^{-1} \mod m $*/
// BI.modPow(BI p, BI m); ........ /*$ a^p \mod m $*/
// BI.negate(); .................. -a

// BI.not(); ..................... ~a
// BI.and(BI b); ................. a & b
// BI.andNot(BI b); .............. a & ~b
// BI.or(BI b); .................. a | b
// BI.xor(BI b); ................. a ^ b
// BI.shiftLeft(int n); .......... a << n
// BI.shiftRight(int n); ......... a >> n

// BI.max(BI b); ................. max(a, b)
// BI.min(BI b); ................. min(a, b)

// BI.toString(int b); ........... base convertor
// BI.nextProbablePrime(); ....... Integer greater than a probably prime.
// BI.isProbablePrime(int c); .... /*$1-\frac{1}{2}^c$*/ c = 10 is enough
// BI.gcd(BI b); ................. gcd(a, b)

class Main { // Usage example
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int b = sc.nextInt();
            if (b == 0)
                break;
            BigInteger p = sc.nextBigInteger(b);
            BigInteger m = sc.nextBigInteger(b);
            System.out.println((p.mod(m)).toString(b));
        }
        sc.close();
    }
}