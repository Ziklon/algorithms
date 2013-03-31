// BEGIN CUT HERE
// PROBLEM STATEMENT
// A series of brackets is complete if we can pair off each left bracket '[' with a right 
// bracket ']' that occurs later in the series. Every bracket must participate in exactly 
// one such pair.
// 
// Given a String text add the minimal number of brackets to the beginning and/or end of 
// text to make it complete. Return the result.
// 
// DEFINITION
// Class:CompletingBrackets
// Method:complete
// Parameters:String
// Returns:String
// Method signature:String complete(String text)
// 
// 
// CONSTRAINTS
// -text will have between 1 and 50 characters inclusive.
// -text will contain only the characters '[' and ']'.
// 
// 
// EXAMPLES
// 
// 0)
// "[["
// 
// Returns: "[[]]"
// 
// Add two ']' to the end to make this complete.
// 
// 1)
// "]["
// 
// Returns: "[][]"
// 
// Add one to the beginning and one to the end.
// 
// 2)
// "[[[[]]]]"
// 
// Returns: "[[[[]]]]"
// 
// This is already complete.
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

public class CompletingBrackets {
	public String complete(String text) {
		String ans = "";
		
		int res = 0;
		for (int i = 0; i < text.length(); i++) {
			if (text.charAt(i) == ']')
				res--;
			else res++;
			ans += text.charAt(i);
			if (res < 0) {
				ans = "[" + ans;
				res++;
			}
			
		}

		for (int i = 0; i < res; i++)
			ans += "]";
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
			CompletingBracketsHarness.run_test(-1);
		} else {
			for (int i = 0; i < args.length; ++i)
				CompletingBracketsHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class CompletingBracketsHarness {
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
				String text = "[[";
				String expected__ = "[[]]";
				
				return verifyCase(casenum, expected__,
						new CompletingBrackets().complete(text));
			}
			case 1: {
				String text = "][";
				String expected__ = "[][]";
				
				return verifyCase(casenum, expected__,
						new CompletingBrackets().complete(text));
			}
			case 2: {
				String text = "[[[[]]]]";
				String expected__ = "[[[[]]]]";
				
				return verifyCase(casenum, expected__,
						new CompletingBrackets().complete(text));
			}
			
			// custom cases
			
			/*
			 * case 3: { String text = ; String expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * CompletingBrackets().complete(text)); }
			 */
			/*
			 * case 4: { String text = ; String expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * CompletingBrackets().complete(text)); }
			 */
			/*
			 * case 5: { String text = ; String expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * CompletingBrackets().complete(text)); }
			 */
			default:
				return -1;
		}
	}
}

// END CUT HERE
