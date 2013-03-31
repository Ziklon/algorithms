// BEGIN CUT HERE
// PROBLEM STATEMENT
// The Will Rogers phenomenon is the apparent paradox which occurs when, upon moving an 
// element from one set of numbers to another set, the means (averages) of both sets 
// increase.
// 
// For example, the sets { 1, 2, 3 } and { 4, 5, 6 } have means 2 and 5, respectively. 
// Moving the 4 to the first set would increase its mean to 2.5, while also increasing the 
// mean of the second set to 5.5.
// 
// More precisely, we will consider the phenomenon to have occured if, upon moving a number 
// between sets, the mean of both of the sets has strictly increased. An element may be 
// moved from a set only if the set contains at least two elements.
// 
// You are to move exactly one number from one of the sets to the other. Given the initial 
// configuration of the sets as two int[]s, set1 and set2, return the number of elements 
// which trigger the phenomenon when chosen to be moved.
// 
// 
// DEFINITION
// Class:RogersPhenomenon
// Method:countTriggers
// Parameters:int[], int[]
// Returns:int
// Method signature:int countTriggers(int[] set1, int[] set2)
// 
// 
// NOTES
// -The sets may contain duplicate elements, all of which should be included when 
// calculating averages.
// 
// 
// CONSTRAINTS
// -Both set1 and set2 will contain between 1 and 50 elements, inclusive.
// -Each element in set1 and set2 will be between -1000 and 1000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// { 1, 2, 3 }
// { 4, 5, 6 }
// 
// Returns: 1
// 
// This is the example from the problem statement. The number 4 from the second set is the 
// only one which triggers the Rogers phenomenon.
// 
// 1)
// { 3, 100, 90 }
// { 5, 1, 18, 29 }
// 
// Returns: 0
// 
// 2)
// { 1, 1, 1, 1, 1, 5 }
// { -10, -9, -8, -7, -6 }
// 
// Returns: 5
// 
// The sets may contain duplicate elements. Moving any of the 1's from the first set 
// increases the means of both sets.
// 
// 3)
// { 12, 94, 53, 43, 58, 85, 55, 83, 47, 57 }
// { 23, 100, 98, 27, 9, 70, 39, 39, 54 }
// 
// Returns: 4
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

public class RogersPhenomenon {
	public int countTriggers(int[] set1, int[] set2) {
		int ans = 0;
		int A = 0;
		int B = 0;
		for (int val : set1)
			A += val;
		for (int val : set2)
			B += val;
		
		double pA=A/(double)set1.length;
		double pB=B/(double)set2.length;
		
		for(int i=0;i<set1.length;i++){
			double p=(A-set1[i]+0.0)/(set1.length-1.0);
			double q=(B+set1[i])/(set2.length+1.0);			
			if(p>pA && q>pB)ans++;
		}
		
		for(int i=0;i<set2.length;i++){
			double p=(A+set2[i]+0.0)/(set1.length+1.0);
			double q=(B-set2[i])/(set2.length-1.0);			
			if(p>pA && q>pB)ans++;
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
			RogersPhenomenonHarness.run_test(-1);
		} else {
			for (int i = 0; i < args.length; ++i)
				RogersPhenomenonHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class RogersPhenomenonHarness {
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
				int[] set1 = { 1, 2, 3 };
				int[] set2 = { 4, 5, 6 };
				int expected__ = 1;
				
				return verifyCase(casenum, expected__,
						new RogersPhenomenon().countTriggers(set1, set2));
			}
			case 1: {
				int[] set1 = { 3, 100, 90 };
				int[] set2 = { 5, 1, 18, 29 };
				int expected__ = 0;
				
				return verifyCase(casenum, expected__,
						new RogersPhenomenon().countTriggers(set1, set2));
			}
			case 2: {
				int[] set1 = { 1, 1, 1, 1, 1, 5 };
				int[] set2 = { -10, -9, -8, -7, -6 };
				int expected__ = 5;
				
				return verifyCase(casenum, expected__,
						new RogersPhenomenon().countTriggers(set1, set2));
			}
			case 3: {
				int[] set1 = { 12, 94, 53, 43, 58, 85, 55, 83, 47, 57 };
				int[] set2 = { 23, 100, 98, 27, 9, 70, 39, 39, 54 };
				int expected__ = 4;
				
				return verifyCase(casenum, expected__,
						new RogersPhenomenon().countTriggers(set1, set2));
			}
			
			// custom cases
			
			/*
			 * case 4: { int[] set1 = ; int[] set2 = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * RogersPhenomenon().countTriggers(set1, set2)); }
			 */
			/*
			 * case 5: { int[] set1 = ; int[] set2 = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * RogersPhenomenon().countTriggers(set1, set2)); }
			 */
			/*
			 * case 6: { int[] set1 = ; int[] set2 = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * RogersPhenomenon().countTriggers(set1, set2)); }
			 */
			default:
				return -1;
		}
	}
}

// END CUT HERE
