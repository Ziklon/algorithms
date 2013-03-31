// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// Return the smallest non-negative integer that can be added to originalNumber such that 
// the resulting integer contains at least one digit k. All numbers should have no extra 
// leading zeroes.
// 
// 
// 
// DEFINITION
// Class:ObtainingDigitK
// Method:minNumberToAdd
// Parameters:String, int
// Returns:int
// Method signature:int minNumberToAdd(String originalNumber, int k)
// 
// 
// CONSTRAINTS
// -originalNumber will contain between 1 and 50 characters, inclusive.
// -originalNumber will contain only digits ('0'-'9').
// -originalNumber will represent a non-negative integer with no extra leading zeroes.
// -k will be between 0 and 9, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// "153"
// 7
// 
// Returns: 4
// 
// 153 + 4 = 157
// 
// 1)
// "158"
// 7
// 
// Returns: 9
// 
// 158 + 9 = 167
// 
// 2)
// "7853192"
// 2
// 
// Returns: 0
// 
// Digit '2' is already present in the number.
// 
// 3)
// "99999999999999999999999999999999999999999999999"
// 0
// 
// Returns: 1
// 
// Add 1 to get a lot of zeroes.
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

public class ObtainingDigitK {
	public int minNumberToAdd(String originalNumber, int k) {
		int ans = 0;
		int n=originalNumber.length();
		int val=originalNumber.charAt(n-1)-'0';
		for(int i=0;i<10;i++){
			int res=i;
			for(int j=n-1;j>=0;j--){
				val=originalNumber.charAt(j)-'0'+res;
				if(val%10==k)
					return i;
				res=val/10;				
			}
			if(res==k && k!=0)return i;
			
		}
		return ans;
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
			ObtainingDigitKHarness.run_test(-1);
		} else {
			for (int i = 0; i < args.length; ++i)
				ObtainingDigitKHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class ObtainingDigitKHarness {
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
				String originalNumber = "153";
				int k = 7;
				int expected__ = 4;
				
				return verifyCase(casenum, expected__,
						new ObtainingDigitK().minNumberToAdd(originalNumber, k));
			}
			case 1: {
				String originalNumber = "158";
				int k = 7;
				int expected__ = 9;
				
				return verifyCase(casenum, expected__,
						new ObtainingDigitK().minNumberToAdd(originalNumber, k));
			}
			case 2: {
				String originalNumber = "7853192";
				int k = 2;
				int expected__ = 0;
				
				return verifyCase(casenum, expected__,
						new ObtainingDigitK().minNumberToAdd(originalNumber, k));
			}
			case 3: {
				String originalNumber = "99999999999999999999999999999999999999999999999";
				int k = 0;
				int expected__ = 1;
				
				return verifyCase(casenum, expected__,
						new ObtainingDigitK().minNumberToAdd(originalNumber, k));
			}
			
			// custom cases
			
			/*
			 * case 4: { String originalNumber = ; int k = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * ObtainingDigitK().minNumberToAdd(originalNumber, k)); }
			 */
			/*
			 * case 5: { String originalNumber = ; int k = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * ObtainingDigitK().minNumberToAdd(originalNumber, k)); }
			 */
			/*
			 * case 6: { String originalNumber = ; int k = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * ObtainingDigitK().minNumberToAdd(originalNumber, k)); }
			 */
			default:
				return -1;
		}
	}
}

// END CUT HERE
