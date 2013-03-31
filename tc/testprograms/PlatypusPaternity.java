// BEGIN CUT HERE
// PROBLEM STATEMENT
// Our lab has just run into a dilemma. All our data about the lab's platypus population 
// seems to have gotten mixed up. Each platypus in the lab is either a male adult, a female 
// adult, or a child. The children are divided into several sibling groups. We know this 
// division exactly. What we are missing are the parent-child relations. In order to 
// reconstruct these, we conducted some genetic tests. We are going to do what some other 
// lab did 4 years ago and hire you to make a program to help us fix the situation. You 
// will be given three String[]s containing the results of these tests and the description 
// of all sibling groups. The three String[]s are:
// 
// femaleCompatibility: The j-th character of the i-th element of femaleCompatibility is 
// 'Y' if the i-th female adult is genetically compatible with the j-th child (i.e., the i-
// th female adult may be the mother of the j-th child). Otherwise, it is 'N'.
// maleCompatibility: The j-th character of the i-th element of maleCompatibility is 'Y' if 
// the i-th male adult is genetically compatible with the j-th child (i.e., the i-th male 
// adult may be the father of the j-th child). Otherwise, it is 'N'.
// siblingGroups: The j-th character of the i-th element of siblingGroups is 'Y' if the j-
// th child belongs to the i-th sibling group. Otherwise, it is 'N'. Each child belongs 
// into exactly one sibling group. Two children are siblings if and only if they belong to 
// the same sibling group.
// 
// The lab has defined a valid family as a set containing one female adult (mother), one 
// male adult (father), and one sibling group. The mother and the father must be 
// genetically compatible with each of the children in the sibling group. Return the 
// maximum size of a family that follows these conditions or 0 if no such family exists.
// 
// 
// DEFINITION
// Class:PlatypusPaternity
// Method:maxFamily
// Parameters:String[], String[], String[]
// Returns:int
// Method signature:int maxFamily(String[] femaleCompatibility, String[] maleCompatibility, 
// String[] siblingGroups)
// 
// 
// CONSTRAINTS
// -The input will represent data for F females, M males, C children and S sibling groups, 
// with F, M, C and S each being between 1 and 50, inclusive.
// -femaleCompatibility will contain F elements.
// -maleCompatibility will contain M elements.
// -siblingGroups will contain S elements.
// -Each element of femaleCompatibility, maleCompatibility and siblingGroups will contain C 
// characters.
// -Each character of femaleCompatibility, maleCompatibility and siblingGroups will be 'Y' 
// or 'N' (quotes for clarity).
// -For each child j there will be exactly one sibling group i such that siblingGroups[i]
// [j] is 'Y'.
// -For each sibling group i, there will exist at least one child that belongs to that group.
// 
// 
// EXAMPLES
// 
// 0)
// {"YYYY", "YYYY"}
// {"NNYN", "YYYN"}
// {"YYYN", "NNNY"}
// 
// Returns: 5
// 
// One possible family is formed by the female adult 0 (0-indexed), the male adult 1, and 
// the sibling group 0 (containing children 0, 1, and 2).
// The size of this family is: 1 female + 1 male + 3 children = 5 platypuses.
// There is no family of size more than 5.
// Another valid family of size 5 contains the female adult 1 instead of the female adult 0.
// 
// 1)
// {"NNYYY"}
// {"YYNNN"}
// {"YYNNN", "NNYYY"}
// 
// Returns: 0
// 
// Each adult is compatible with a different sibling group. There is no couple that is 
// compatible with the same sibling group
// 
// 2)
// {"YYYYYYYYN"}
// {"YYYYYYYYY"}
// {"YNYNYNYNY",
//  "NNNYNYNNN",
//  "NYNNNNNYN"}
// 
// Returns: 4
// 
// The largest sibling group has size 5. However, there is no valid family that contains 
// this sibling group, as the only available female adult is not compatible with one of the 
// children in this group.
// 
// 3)
// {"YY"}
// {"YY"}
// {"YN", "NY"}
// 
// Returns: 3
// 
// 
// 
// 4)
// {"YYNNYYNNYYNN",
//  "YNYNYNYNYNYN",
//  "YYYNNNYYYNNN"}
// {"NYYNNYYNNYYN",
//  "YYNYYYNYYYNY",
//  "NNNNNNYYYYYY"}
// {"NYNNNYNNNNNN",
//  "NNNNNNNNYNNN",
//  "NNYNNNNNNNYN",
//  "YNNNNNNYNNNN",
//  "NNNNNNNNNYNY",
//  "NNNYYNYNNNNN"}
// 
// Returns: 4
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

public class PlatypusPaternity {
	public int maxFamily(String[] femaleCompatibility,
			String[] maleCompatibility, String[] siblingGroups) {
		int ans=0;
		int C=siblingGroups[0].length();
		for(int i=0;i<siblingGroups.length;i++){
					
			for(int j=0;j<femaleCompatibility.length;j++)
				for(int k=0;k<maleCompatibility.length;k++){
					
					boolean ok=false;
					int cnt=0;
					for(int m=0;m<C;m++){
						ok|=(femaleCompatibility[j].charAt(m)=='N' && 
								siblingGroups[i].charAt(m)=='Y');
						ok|=(maleCompatibility[k].charAt(m)=='N' && 
								siblingGroups[i].charAt(m)=='Y');
						
						if(siblingGroups[i].charAt(m)=='Y')cnt++;
					}
					if(!ok)					
						ans=max(ans,cnt+2);					
				}			
			
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
			PlatypusPaternityHarness.run_test(-1);
		} else {
			for (int i = 0; i < args.length; ++i)
				PlatypusPaternityHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class PlatypusPaternityHarness {
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
				String[] femaleCompatibility = { "YYYY", "YYYY" };
				String[] maleCompatibility = { "NNYN", "YYYN" };
				String[] siblingGroups = { "YYYN", "NNNY" };
				int expected__ = 5;
				
				return verifyCase(casenum, expected__,
						new PlatypusPaternity().maxFamily(femaleCompatibility,
								maleCompatibility, siblingGroups));
			}
			case 1: {
				String[] femaleCompatibility = { "NNYYY" };
				String[] maleCompatibility = { "YYNNN" };
				String[] siblingGroups = { "YYNNN", "NNYYY" };
				int expected__ = 0;
				
				return verifyCase(casenum, expected__,
						new PlatypusPaternity().maxFamily(femaleCompatibility,
								maleCompatibility, siblingGroups));
			}
			case 2: {
				String[] femaleCompatibility = { "YYYYYYYYN" };
				String[] maleCompatibility = { "YYYYYYYYY" };
				String[] siblingGroups = { "YNYNYNYNY", "NNNYNYNNN",
						"NYNNNNNYN" };
				int expected__ = 4;
				
				return verifyCase(casenum, expected__,
						new PlatypusPaternity().maxFamily(femaleCompatibility,
								maleCompatibility, siblingGroups));
			}
			case 3: {
				String[] femaleCompatibility = { "YY" };
				String[] maleCompatibility = { "YY" };
				String[] siblingGroups = { "YN", "NY" };
				int expected__ = 3;
				
				return verifyCase(casenum, expected__,
						new PlatypusPaternity().maxFamily(femaleCompatibility,
								maleCompatibility, siblingGroups));
			}
			case 4: {
				String[] femaleCompatibility = { "YYNNYYNNYYNN",
						"YNYNYNYNYNYN", "YYYNNNYYYNNN" };
				String[] maleCompatibility = { "NYYNNYYNNYYN", "YYNYYYNYYYNY",
						"NNNNNNYYYYYY" };
				String[] siblingGroups = { "NYNNNYNNNNNN", "NNNNNNNNYNNN",
						"NNYNNNNNNNYN", "YNNNNNNYNNNN", "NNNNNNNNNYNY",
						"NNNYYNYNNNNN" };
				int expected__ = 4;
				
				return verifyCase(casenum, expected__,
						new PlatypusPaternity().maxFamily(femaleCompatibility,
								maleCompatibility, siblingGroups));
			}
			
			// custom cases
			
			/*
			 * case 5: { String[] femaleCompatibility = ; String[]
			 * maleCompatibility = ; String[] siblingGroups = ; int expected__ =
			 * ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * PlatypusPaternity().maxFamily(femaleCompatibility,
			 * maleCompatibility, siblingGroups)); }
			 */
			/*
			 * case 6: { String[] femaleCompatibility = ; String[]
			 * maleCompatibility = ; String[] siblingGroups = ; int expected__ =
			 * ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * PlatypusPaternity().maxFamily(femaleCompatibility,
			 * maleCompatibility, siblingGroups)); }
			 */
			/*
			 * case 7: { String[] femaleCompatibility = ; String[]
			 * maleCompatibility = ; String[] siblingGroups = ; int expected__ =
			 * ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * PlatypusPaternity().maxFamily(femaleCompatibility,
			 * maleCompatibility, siblingGroups)); }
			 */
			default:
				return -1;
		}
	}
}

// END CUT HERE
