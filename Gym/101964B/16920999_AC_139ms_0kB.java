import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.StringTokenizer;

import javax.security.auth.Subject;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		BigInteger a, b, c, n;
		a = reader.nextBigInteger();
		b = reader.nextBigInteger();
		c = reader.nextBigInteger();
		n = reader.nextBigInteger();
		
		if(a.compareTo(b) == 1) {
			BigInteger tmp = b;
			b = a;
			a = tmp;
		}
		if(a.compareTo(c) == 1) {
			BigInteger tmp = c;
			c = a;
			a = tmp;
		}
		if(b.compareTo(c) == 1) {
			BigInteger tmp = c;
			c = b;
			b = tmp;
		}
		
		BigInteger p = BigInteger.ONE;
//		System.out.println("~");
		if(a.compareTo(c) == 0) {
			p = new BigInteger("6");
		}else if(a.compareTo(b) == 0 || b.compareTo(c) == 0) {
			p = new BigInteger("2");
		}
		
		BigInteger ans;
		if(n.mod(BigInteger.valueOf(2)).compareTo(BigInteger.ZERO) == 0) {
			ans = n.divide(BigInteger.valueOf(2));
			ans = ans.add(n.divide(BigInteger.valueOf(2)).multiply(n.divide(BigInteger.valueOf(2))));
			ans = ans.add(n.subtract(BigInteger.valueOf(4)));
		}else {
			ans = n.divide(BigInteger.valueOf(2));
			ans = ans.add(n.divide(BigInteger.valueOf(2)).multiply(n.divide(BigInteger.valueOf(2))));
		}
		BigInteger mod = new BigInteger("2");
		mod = mod.pow(64);
		ans = ans.multiply(n).divide(p).mod(mod);
		System.out.println(ans);
	}

	static class InputReader {
		BufferedReader buf;
		StringTokenizer tok;

		InputReader() {
			buf = new BufferedReader(new InputStreamReader(System.in));
		}

		boolean hasNext() {
			while (tok == null || !tok.hasMoreElements()) {
				try {
					tok = new StringTokenizer(buf.readLine());
				} catch (Exception e) {
					return false;
				}
			}
			return true;
		}

		String next() {
			if (hasNext())
				return tok.nextToken();
			return null;
		}

		String nextLine() throws IOException {
			return buf.readLine();
		}

		char nextChar() {
			return next().charAt(0);
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}
}
