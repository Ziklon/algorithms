// BEGIN CUT HERE
// PROBLEM STATEMENT
// Professor Smith teaches a logic class. One day, he writes some statements on the 
// blackboard:
// Exactly a of these statements are true.
// Exactly b of these statements are true.
// Exactly c of these statements are true.
// .
// .
// .
// Each of a, b, c and so on is a number. He then asks the class how many of the statements 
// are true.
// You will be given a int[] statements, containing the numbers written in Professor 
// Smith's statements. Return the number of the statements that are true. If there is more 
// than one possible answer, return the largest one. If there are no possible answers, 
// return -1.
// 
// DEFINITION
// Class:TrueStatements
// Method:numberTrue
// Parameters:int[]
// Returns:int
// Method signature:int numberTrue(int[] statements)
// 
// 
// CONSTRAINTS
// -statements will contain between 1 and 50 elements, inclusive.
// -Each element of statements will be between 0 and 50, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {0, 1, 2, 3}
// 
// Returns: 1
// 
// The 2nd statement is true (there is one true statement) and the others are false.
// 
// 1)
// {0}
// 
// Returns: -1
// 
// This is the Epimedes paradox: if the statement is true then it claims to be false, but 
// if it is false then it must be true.
// 
// 2)
// {0, 3, 1, 3, 2, 3}
// 
// Returns: 3
// 
// One solution is that the 3rd statement is the only true statement. However, it is also 
// possible that the 2nd, 4th and 6th statements are true (all of which say that 3 
// statements are true), and the largest solution must be returned.
// 
// 3)
// {1, 1}
// 
// Returns: 0
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

public class TrueStatements {
	public int numberTrue(int[] statements) {
		int ans = -1;
		int A[] = new int[55];
		for (int n : statements)
			A[n]++;

		for (int i = 0; i < 55; i++){
			if (i == A[i]) ans = i;
			
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
			TrueStatementsHarness.run_test(-1);
		} else {
			for (int i = 0; i < args.length; ++i)
				TrueStatementsHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class TrueStatementsHarness {
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
				int[] statements = { 0, 1, 2, 3 };
				int expected__ = 1;
				
				return verifyCase(casenum, expected__,
						new TrueStatements().numberTrue(statements));
			}
			case 1: {
				int[] statements = { 0 };
				int expected__ = -1;
				
				return verifyCase(casenum, expected__,
						new TrueStatements().numberTrue(statements));
			}
			case 2: {
				int[] statements = { 0, 3, 1, 3, 2, 3 };
				int expected__ = 3;
				
				return verifyCase(casenum, expected__,
						new TrueStatements().numberTrue(statements));
			}
			case 3: {
				int[] statements = { 1, 1 };
				int expected__ = 0;
				
				return verifyCase(casenum, expected__,
						new TrueStatements().numberTrue(statements));
			}
			
			// custom cases
			
			/*
			 * case 4: { int[] statements = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * TrueStatements().numberTrue(statements)); }
			 */
			/*
			 * case 5: { int[] statements = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * TrueStatements().numberTrue(statements)); }
			 */
			/*
			 * case 6: { int[] statements = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * TrueStatements().numberTrue(statements)); }
			 */
			default:
				return -1;
		}
	}
}

// END CUT HERE
