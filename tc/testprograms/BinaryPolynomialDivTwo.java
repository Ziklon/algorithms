// BEGIN CUT HERE
// PROBLEM STATEMENT
// Warning: This problem statement contains superscripts and/or subscripts. It may not 
// display properly outside of the applet.
// 
// In this problem we will consider binary polynomials. A binary polynomial can be written 
// in the following form:
// 
// 
// P(x) = a[0] * x0 + a[1] * x1 + ... + a[n] * xn
// 
// 
// The values a[i] are integer constants (called coefficients). For a binary polynomial we 
// must have a[n] = 1 and each other a[i] must be either 0 or 1. The number n is called the 
// degree of the polynomial.
// 
// 
// Several examples:
// 
//  P(x) = 1 * x0 + 0 * x1 + 1 * x2 is a binary polynomial of degree 2. 
//  P(x) = 0 * x0 + 1 * x1 + 0 * x2 + 1 * x3 is a binary polynomial of degree 3. 
//  P(x) = 1 * x0 is a binary polynomial of degree 0. 
//  P(x) = 0 * x0 + 3 * x1 - 1 * x2 is not a binary polynomial, because each coefficient 
// must be a 0 or a 1. 
//  P(x) = 0 * x0 is not a valid binary polynomial, because the last of the values a[i] 
// must be 1. 
// 
// We can evaluate a binary polynomial for the inputs x = 0 and x = 1. In order to do so, 
// we just have to substitute 0 or 1 for x in the above expression, compute the value of 
// the expression and take the remainder it gives when divided by two. For example, if P(x) 
// = 1 * x0 + 0 * x1 + 1 * x2, then P(0) = 1 * 00 + 0 * 01 + 1 * 02 = 1 and P(1) = 1 * 10 + 
// 0 * 11 + 1 * 12 = 0 (modulo 2). Note that in this problem we assume that x0 = 1 for all 
// x. In particular, also 00 = 1.
// 
// 
// We call an integer x (where x is 0 or 1) a root of the binary polynomial P if P(x) = 0. 
// You are given a binary polynomial P as the array a of its coefficients. Return the 
// number of roots of that binary polynomial.
// 
// DEFINITION
// Class:BinaryPolynomialDivTwo
// Method:countRoots
// Parameters:int[]
// Returns:int
// Method signature:int countRoots(int[] a)
// 
// 
// CONSTRAINTS
// -The degree of P will be between 0 and 49, inclusive.
// -a will contain exactly n+1 elements, where n is the degree of P.
// -Each element of a will be either 0 (zero) or 1 (one).
// -a[n] will be equal to 1 (one).
// 
// 
// EXAMPLES
// 
// 0)
// {1, 0, 1}
// 
// Returns: 1
// 
// The example from the problem statement. The only root of this binary polynomial is 1.
// 
// 1)
// {0, 1, 0, 1}
// 
// Returns: 2
// 
// This is the maximum possible answer; both 0 and 1 are roots of this binary polynomial.
// 
// 2)
// {1}
// 
// Returns: 0
// 
// This binary polynomial has no roots - it always evaluates to 1.
// 
// 3)
// {1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1}
// 
// Returns: 0
// 
// 
// 
// 4)
// {1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0,
//  0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1}
// 
// Returns: 1
// 
// 
// 
// END CUT HERE
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Long.*;
import static java.lang.Double.*;
import static java.util.Collections.*;

public class BinaryPolynomialDivTwo {
	public int countRoots(int[] a) {
		int ans = 0;
		for(int x=0;x<2;x++){
			int sum=0;
			for(int i=0;i<a.length;i++){
				sum=(sum+(a[i]*pow(x,i)))%2;
			}
			if(sum==0)ans++;
			
		}
		return ans;
	}
	
	public int pow(int a, int b){
		if(b==0)return 1;
		return a;
	}
	
	// BEGIN CUT HERE
	public void print(String s) {
		System.err.print("   " + s);
	}
	
	public void println(String s) {
		print(s + "\n");
	}
	
	public static void main(String[] args) {
		if (args.length == 0) {
			BinaryPolynomialDivTwoHarness.run_test(-1);
		} else {
			for (int i = 0; i < args.length; ++i)
				BinaryPolynomialDivTwoHarness
						.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class BinaryPolynomialDivTwoHarness {
	public static void run_test(int casenum) {
		if (casenum != -1) {
			if (runTestCase(casenum) == -1)
				System.err.println("Illegal input! Test case " + casenum
						+ " does not exist.");
			return;
		}
		
		int correct = 0, total = 0;
		for (int i = 0;; ++i) {
			int x = runTestCase(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			System.err.println("No test cases run.");
		} else if (correct < total) {
			System.err.println("Some cases FAILED (passed " + correct + " of "
					+ total + ").");
		} else {
			System.err.println("All " + total + " tests passed!");
		}
	}
	
	static boolean compareOutput(int expected, int result) {
		return expected == result;
	}
	
	static String formatResult(int res) {
		return String.format("%d", res);
	}
	
	static int verifyCase(int casenum, int expected, int received) {
		System.err.print("Example " + casenum + "... ");
		if (compareOutput(expected, received)) {
			System.err.println("PASSED");
			return 1;
		} else {
			System.err.println("FAILED");
			System.err.println("    Expected: " + formatResult(expected));
			System.err.println("    Received: " + formatResult(received));
			return 0;
		}
	}
	
	static int runTestCase(int casenum) {
		switch (casenum) {
			case 0: {
				int[] a = { 1, 0, 1 };
				int expected__ = 1;
				
				return verifyCase(casenum, expected__,
						new BinaryPolynomialDivTwo().countRoots(a));
			}
			case 1: {
				int[] a = { 0, 1, 0, 1 };
				int expected__ = 2;
				
				return verifyCase(casenum, expected__,
						new BinaryPolynomialDivTwo().countRoots(a));
			}
			case 2: {
				int[] a = { 1 };
				int expected__ = 0;
				
				return verifyCase(casenum, expected__,
						new BinaryPolynomialDivTwo().countRoots(a));
			}
			case 3: {
				int[] a = { 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1 };
				int expected__ = 0;
				
				return verifyCase(casenum, expected__,
						new BinaryPolynomialDivTwo().countRoots(a));
			}
			case 4: {
				int[] a = { 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0,
						0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1,
						1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1 };
				int expected__ = 1;
				
				return verifyCase(casenum, expected__,
						new BinaryPolynomialDivTwo().countRoots(a));
			}
			
			// custom cases
			
			/*
			 * case 5: { int[] a = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * BinaryPolynomialDivTwo().countRoots(a)); }
			 */
			/*
			 * case 6: { int[] a = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * BinaryPolynomialDivTwo().countRoots(a)); }
			 */
			/*
			 * case 7: { int[] a = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * BinaryPolynomialDivTwo().countRoots(a)); }
			 */
			default:
				return -1;
		}
	}
}

// END CUT HERE
