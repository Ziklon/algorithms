// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are given two positive integers, x and y, whose decimal representations contain the 
// same number of digits.  A digit-swap operation for an index i swaps the digits at the i-
// th positions in x and y.  After exactly swaps digit-swap operations, what is the maximal 
// possible value of x*y?  Return the String representation of this maximal product with no 
// leading zeroes.
// 
// DEFINITION
// Class:DigitsSwap
// Method:maximalProduct
// Parameters:String, String, int
// Returns:String
// Method signature:String maximalProduct(String x, String y, int swaps)
// 
// 
// CONSTRAINTS
// -x and y will each contain between 1 and 50 characters, inclusive.
// -x and y will contain only decimal digits ('0' to '9'), and will not start with a '0'.
// -x and y will contain the same number of characters. 
// -swaps will be between 0 and 1,000,000,000, inclusive. 
// 
// 
// EXAMPLES
// 
// 0)
// "123"
// "321"
// 2
// 
// Returns: "39483"
// 
// You can transform the numbers to "123", "321" (making two swaps at the same position) or 
// to "321", "123" (making swaps at positions 0 and 2) to produce the product 39483.
// 
// 1)
// "4531"
// "1332"
// 0
// 
// Returns: "6035292"
// 
// You are not allowed to make swaps, so the answer is just x * y.
// 
// 2)
// "13425"
// "87694"
// 99
// 
// Returns: "1476187680"
// 
// The optimal answer is 17695 * 83424.
// 
// 3)
// "2872876342876443222"
// "2309482482304823423"
// 5
// 
// Returns: "6669566046086333877050194232995188906"
// 
// 
// 
// 4)
// "940948"
// "124551"
// 4893846
// 
// Returns: "133434353148"
// 
// 5)
// "56710852"
// "18058360"
// 1
// 
// Returns: "1050671725722720"
// 
// 
// 
// 6)
// "9"
// "1"
// 1000000000
// 
// Returns: "9"
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
import static java.lang.Character.*;
import static java.lang.Double.*;
import static java.util.Collections.*;

public class DigitsSwap {
	char A[];
	char B[];
	public String maximalProduct(String x, String y, int swaps) {
		String ans = "";
		A=x.toCharArray();
		B=y.toCharArray();
		for(int i=0;i<A.length && swaps>0;i++){
			if(A[i]<B[i]){
				swap(i);
				swaps--;
			}
		}
		println(new String(A)+" - "+new String(B));
		BigInteger ba=new BigInteger(new String(A));
		BigInteger bb=new BigInteger(new String(B));
		return ba.multiply(bb).toString();
	}
	
	private void swap(int index){
		char aux=A[index];
		A[index]=B[index];
		B[index]=aux;
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
			DigitsSwapHarness.run_test(-1);
		} else {
			for (int i = 0; i < args.length; ++i)
				DigitsSwapHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class DigitsSwapHarness {
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
	
	static boolean compareOutput(String expected, String result) {
		return expected.equals(result);
	}
	
	static String formatResult(String res) {
		return String.format("\"%s\"", res);
	}
	
	static int verifyCase(int casenum, String expected, String received) {
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
				String x = "123";
				String y = "321";
				int swaps = 2;
				String expected__ = "39483";
				
				return verifyCase(casenum, expected__,
						new DigitsSwap().maximalProduct(x, y, swaps));
			}
			case 1: {
				String x = "4531";
				String y = "1332";
				int swaps = 0;
				String expected__ = "6035292";
				
				return verifyCase(casenum, expected__,
						new DigitsSwap().maximalProduct(x, y, swaps));
			}
			case 2: {
				String x = "13425";
				String y = "87694";
				int swaps = 99;
				String expected__ = "1476187680";
				
				return verifyCase(casenum, expected__,
						new DigitsSwap().maximalProduct(x, y, swaps));
			}
			case 3: {
				String x = "2872876342876443222";
				String y = "2309482482304823423";
				int swaps = 5;
				String expected__ = "6669566046086333877050194232995188906";
				
				return verifyCase(casenum, expected__,
						new DigitsSwap().maximalProduct(x, y, swaps));
			}
			case 4: {
				String x = "940948";
				String y = "124551";
				int swaps = 4893846;
				String expected__ = "133434353148";
				
				return verifyCase(casenum, expected__,
						new DigitsSwap().maximalProduct(x, y, swaps));
			}
			case 5: {
				String x = "56710852";
				String y = "18058360";
				int swaps = 1;
				String expected__ = "1050671725722720";
				
				return verifyCase(casenum, expected__,
						new DigitsSwap().maximalProduct(x, y, swaps));
			}
			case 6: {
				String x = "9";
				String y = "1";
				int swaps = 1000000000;
				String expected__ = "9";
				
				return verifyCase(casenum, expected__,
						new DigitsSwap().maximalProduct(x, y, swaps));
			}
			
			// custom cases
			
			/*
			 * case 7: { String x = ; String y = ; int swaps = ; String
			 * expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * DigitsSwap().maximalProduct(x, y, swaps)); }
			 */
			/*
			 * case 8: { String x = ; String y = ; int swaps = ; String
			 * expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * DigitsSwap().maximalProduct(x, y, swaps)); }
			 */
			/*
			 * case 9: { String x = ; String y = ; int swaps = ; String
			 * expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * DigitsSwap().maximalProduct(x, y, swaps)); }
			 */
			default:
				return -1;
		}
	}
}

// END CUT HERE
