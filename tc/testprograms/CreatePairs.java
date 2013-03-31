// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// You are given a list of integers, and you are allowed to group elements into pairs.  
// Each element must either belong to a single pair or remain unpaired.  Sum the products 
// of the pairs with the values of the unpaired elements.  Your goal is to maximize this sum.
// 
// 
// For example, consider the list {0, 1, 2, 4, 3, 5}.  If you make the pairs (2, 3) and (4, 
// 5), the sum is 0 + 1 + (2 * 3) + (4 * 5) = 27.
// 
// 
// You are given a int[] data containing the list of integers.  Return the maximum possible 
// sum.
// 
// 
// 
// DEFINITION
// Class:CreatePairs
// Method:maximalSum
// Parameters:int[]
// Returns:int
// Method signature:int maximalSum(int[] data)
// 
// 
// CONSTRAINTS
// -data will contain between 1 and 50 elements, inclusive.
// -Each element of data will be between -1000 and 1000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {0, 1, 2, 4, 3, 5}
// 
// Returns: 27
// 
// The example from the problem statement.
// 
// 1)
// {-1, 1, 2, 3}
// 
// Returns: 6
// 
// If we create a pair (2, 3) we get the sum (-1) + 1 + (2 * 3) = 6.
// 
// 2)
// {-1}
// 
// Returns: -1
// 
// No pairs can be created, so the answer is -1.
// 
// 3)
// {-1, 0, 1}
// 
// Returns: 1
// 
// In this case we can create a pair (-1, 0) to make the sum equal to (-1) * 0 + 1 = 1.
// 
// 4)
// {1, 1}
// 
// Returns: 2
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

public class CreatePairs {
	public int maximalSum(int[] data) {
		int ans = 0;
		sort(data);
		int i, j;
		for (i = 0; i + 1 < data.length; i += 2) {
			if (max(data[i], data[i + 1]) <= 0)
				ans += (data[i] * data[i + 1]);
			else break;
			
		}
		for (j = data.length - 1; j >= 1; j-=2) {
			if (min(data[j], data[j - 1]) > 1)
				ans += (data[j] * data[j - 1]);
			else break;
		}
		
		for(;i<=j;i++)ans+=data[i];				
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
			CreatePairsHarness.run_test(-1);
		} else {
			for (int i = 0; i < args.length; ++i)
				CreatePairsHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class CreatePairsHarness {
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
				int[] data = { 0, 1, 2, 4, 3, 5 };
				int expected__ = 27;
				
				return verifyCase(casenum, expected__,
						new CreatePairs().maximalSum(data));
			}
			case 1: {
				int[] data = { -1, 1, 2, 3 };
				int expected__ = 6;
				
				return verifyCase(casenum, expected__,
						new CreatePairs().maximalSum(data));
			}
			case 2: {
				int[] data = { -1 };
				int expected__ = -1;
				
				return verifyCase(casenum, expected__,
						new CreatePairs().maximalSum(data));
			}
			case 3: {
				int[] data = { -1, 0, 1 };
				int expected__ = 1;
				
				return verifyCase(casenum, expected__,
						new CreatePairs().maximalSum(data));
			}
			case 4: {
				int[] data = { 1, 1 };
				int expected__ = 2;
				
				return verifyCase(casenum, expected__,
						new CreatePairs().maximalSum(data));
			}
			
			// custom cases
			
			/*
			 * case 5: { int[] data = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * CreatePairs().maximalSum(data)); }
			 */
			/*
			 * case 6: { int[] data = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * CreatePairs().maximalSum(data)); }
			 */
			/*
			 * case 7: { int[] data = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * CreatePairs().maximalSum(data)); }
			 */
			default:
				return -1;
		}
	}
}

// END CUT HERE
