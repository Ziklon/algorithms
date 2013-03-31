// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// You are given an int N.  The factorial of N is defined as N*(N-1)*(N-2)*...*1.  Compute 
// the factorial of N and remove all of its rightmost zero digits.  If the result is more 
// than K digits long, return the last K digits as a string.  Otherwise, return the entire 
// result as a string.  
// 
// 
// DEFINITION
// Class:KLastNonZeroDigits
// Method:getKDigits
// Parameters:int, int
// Returns:String
// Method signature:String getKDigits(int N, int K)
// 
// 
// CONSTRAINTS
// -N will be between 1 and 20, inclusive.
// -K will be between 1 and 9, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 10
// 3
// 
// Returns: "288"
// 
// You would first compute the factorial of 10, which is 10*9*8*7*6*5*4*3*2*1=3628800. You 
// would then remove all rightmost zeros to get 36288. Finally, you would return the last 3 
// digits as a string: "288".
// 
// 1)
// 6
// 1
// 
// Returns: "2"
// 
// The factorial of 6 is 720.
// 
// 2)
// 6
// 3
// 
// Returns: "72"
// 
// 
// 
// 3)
// 7
// 2
// 
// Returns: "04"
// 
// The factorial of 7 is 5040. We remove the last zero to get "504". The last 2 digits of 
// "504" are "04".
// 
// 4)
// 20
// 9
// 
// Returns: "200817664"
// 
// 
// 
// 5)
// 1
// 1
// 
// Returns: "1"
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

public class KLastNonZeroDigits {
	public String getKDigits(int N, int K) {
		String ans = "";
		long num = 1;
		for (int i = 2; i <= N; i++) {
			num *= i;
			while (num % 10 == 0)
				num /= 10;
		}
		ans = num + "";
		if (ans.length() <= K) return ans;
		return ans.substring(ans.length() - K);
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
			KLastNonZeroDigitsHarness.run_test(-1);
		} else {
			for (int i = 0; i < args.length; ++i)
				KLastNonZeroDigitsHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class KLastNonZeroDigitsHarness {
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
				int N = 10;
				int K = 3;
				String expected__ = "288";
				
				return verifyCase(casenum, expected__,
						new KLastNonZeroDigits().getKDigits(N, K));
			}
			case 1: {
				int N = 6;
				int K = 1;
				String expected__ = "2";
				
				return verifyCase(casenum, expected__,
						new KLastNonZeroDigits().getKDigits(N, K));
			}
			case 2: {
				int N = 6;
				int K = 3;
				String expected__ = "72";
				
				return verifyCase(casenum, expected__,
						new KLastNonZeroDigits().getKDigits(N, K));
			}
			case 3: {
				int N = 7;
				int K = 2;
				String expected__ = "04";
				
				return verifyCase(casenum, expected__,
						new KLastNonZeroDigits().getKDigits(N, K));
			}
			case 4: {
				int N = 20;
				int K = 9;
				String expected__ = "200817664";
				
				return verifyCase(casenum, expected__,
						new KLastNonZeroDigits().getKDigits(N, K));
			}
			case 5: {
				int N = 1;
				int K = 1;
				String expected__ = "1";
				
				return verifyCase(casenum, expected__,
						new KLastNonZeroDigits().getKDigits(N, K));
			}
			
			// custom cases
			
			/*
			 * case 6: { int N = ; int K = ; String expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * KLastNonZeroDigits().getKDigits(N, K)); }
			 */
			/*
			 * case 7: { int N = ; int K = ; String expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * KLastNonZeroDigits().getKDigits(N, K)); }
			 */
			/*
			 * case 8: { int N = ; int K = ; String expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * KLastNonZeroDigits().getKDigits(N, K)); }
			 */
			default:
				return -1;
		}
	}
}

// END CUT HERE
