// BEGIN CUT HERE
// PROBLEM STATEMENT
// A string X is an ordered superstring of the String[] words if
// 
//   Each element of words is a substring of X.
//   There exists a sequence of indices x_1 <= x_2 <= ... <= x_n, where n is the number of 
// elements in words. For each element k of words, where k is a 1-based index, there is an 
// occurrence of words[k] that starts at the x_k-th letter of X.
//   
// 
// For example "abca" is an ordered superstring of {"abc", "ca"}, but "cabc" is not.
// 
// 
// Given a String[] words, return the length of its shortest ordered superstring.
// 
// 
// DEFINITION
// Class:OrderedSuperString
// Method:getLength
// Parameters:String[]
// Returns:int
// Method signature:int getLength(String[] words)
// 
// 
// CONSTRAINTS
// -words will contain between 1 and 50 elements, inclusive.
// -Each element of words will contain between 1 and 50 lowercase letters ('a'-'z'), 
// inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {"abc","ca"}
// 
// Returns: 4
// 
// This is the example from the problem statement. The shortest ordered superstring is 
// "abca". The sequence of indices is {0, 2}. There is an occurrence of "abc" starting at 
// character 0 of "abca", and there is an occurrence of "ca" starting at character 2 of 
// "abca".
// 
// 1)
// {"a","a","b","a"}
// 
// Returns: 3
// 
// Although the given words are all substrings of "ab", they do not appear in the proper 
// order. The shortest ordered superstring is "aba".
// 
// 2)
// {"abcdef", "ab","bc", "de","ef"}
// 
// Returns: 6
// 
// 
// 
// 3)
// {"ab","bc", "de","ef","abcdef"}
// 
// Returns: 12
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

public class OrderedSuperString {
	public int getLength(String[] words) {
		int ans=0;
		sort(words);
		
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
			OrderedSuperStringHarness.run_test(-1);
		} else {
			for (int i = 0; i < args.length; ++i)
				OrderedSuperStringHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class OrderedSuperStringHarness {
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
				String[] words = { "abc", "ca" };
				int expected__ = 4;
				
				return verifyCase(casenum, expected__,
						new OrderedSuperString().getLength(words));
			}
			case 1: {
				String[] words = { "a", "a", "b", "a" };
				int expected__ = 3;
				
				return verifyCase(casenum, expected__,
						new OrderedSuperString().getLength(words));
			}
			case 2: {
				String[] words = { "abcdef", "ab", "bc", "de", "ef" };
				int expected__ = 6;
				
				return verifyCase(casenum, expected__,
						new OrderedSuperString().getLength(words));
			}
			case 3: {
				String[] words = { "ab", "bc", "de", "ef", "abcdef" };
				int expected__ = 12;
				
				return verifyCase(casenum, expected__,
						new OrderedSuperString().getLength(words));
			}
			
			// custom cases
			
			/*
			 * case 4: { String[] words = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * OrderedSuperString().getLength(words)); }
			 */
			/*
			 * case 5: { String[] words = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * OrderedSuperString().getLength(words)); }
			 */
			/*
			 * case 6: { String[] words = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * OrderedSuperString().getLength(words)); }
			 */
			default:
				return -1;
		}
	}
}

// END CUT HERE
