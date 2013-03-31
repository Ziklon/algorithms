// BEGIN CUT HERE
// PROBLEM STATEMENT
// The Very Heterogeneous State of Feudalia's army is designing a new spy robot. Currently, 
// the robot can only accept two commands: L and R. L moves the robot one unit of distance 
// to the left, and R moves the robot one unit to the right. A program for the robot is a 
// sequence of commands. For a given program, its reach is the distance between the 
// starting point and the farthest point visited during the execution of the program. For 
// example, the reach of the program "LLLR" is 3, because after the first three steps we 
// reach a location 3 units away from the starting point.
// 
// Unfortunately, Feudalia is world famous for the ineptitude of its public officials. Some 
// coffee was spilled all over the program before it could be installed to the robot. 
// Therefore, some of the commands may now be illegible.
// Your task is to repair the program by replacing each illegible command with an L or an R. 
// If there are multiple ways to repair the program, you have to pick one that maximizes 
// its reach.
// 
// You are given a String program which describes the program in its current state. The i-
// th character in program represents the i-th command that is executed and will be 'L', 
// 'R' or '?' (quotes for clarity). 'L' represents a legible move left, 'R' a legible move 
// right and '?' a command that is illegible so you can choose 'L' or 'R' in its place. 
// Return the largest reach a repaired program can have.
// 
// DEFINITION
// Class:LeftOrRight
// Method:maxDistance
// Parameters:String
// Returns:int
// Method signature:int maxDistance(String program)
// 
// 
// CONSTRAINTS
// -program will contain between 1 and 50 characters, inclusive.
// -Each character of program will be 'L', 'R' or '?' (quotes for clarity).
// 
// 
// EXAMPLES
// 
// 0)
// "LLLRLRRR"
// 
// Returns: 3
// 
// All commands are legible. The reach of this program is 3: both after three steps and 
// after five steps we are 3 units to the left of the starting location.
// 
// 1)
// "R???L"
// 
// Returns: 4
// 
// We can replace all of the question marks with a right command.
// 
// 2)
// "??????"
// 
// Returns: 6
// 
// 
// 
// 3)
// "LL???RRRRRRR???"
// 
// Returns: 11
// 
// 
// 
// 4)
// "L?L?"
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

public class LeftOrRight {
	public int maxDistance(String program) {
		int ans = 0;
		ans=max(ans,get(program.replace('?', 'R')));
		ans=max(ans,get(program.replace('?', 'L')));				
		return ans;
	}
	
	int get(String program){
		int ubi=0;
		int ans=0;
		for(int i=0;i<program.length();i++){
			ubi+=(program.charAt(i)=='R')?1:-1;
			ans=max(ans,abs(ubi));
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
			LeftOrRightHarness.run_test(-1);
		} else {
			for (int i = 0; i < args.length; ++i)
				LeftOrRightHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class LeftOrRightHarness {
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
				String program = "LLLRLRRR";
				int expected__ = 3;
				
				return verifyCase(casenum, expected__,
						new LeftOrRight().maxDistance(program));
			}
			case 1: {
				String program = "R???L";
				int expected__ = 4;
				
				return verifyCase(casenum, expected__,
						new LeftOrRight().maxDistance(program));
			}
			case 2: {
				String program = "??????";
				int expected__ = 6;
				
				return verifyCase(casenum, expected__,
						new LeftOrRight().maxDistance(program));
			}
			case 3: {
				String program = "LL???RRRRRRR???";
				int expected__ = 11;
				
				return verifyCase(casenum, expected__,
						new LeftOrRight().maxDistance(program));
			}
			case 4: {
				String program = "L?L?";
				int expected__ = 4;
				
				return verifyCase(casenum, expected__,
						new LeftOrRight().maxDistance(program));
			}
			
			// custom cases
			
			/*
			 * case 5: { String program = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * LeftOrRight().maxDistance(program)); }
			 */
			/*
			 * case 6: { String program = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * LeftOrRight().maxDistance(program)); }
			 */
			/*
			 * case 7: { String program = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * LeftOrRight().maxDistance(program)); }
			 */
			default:
				return -1;
		}
	}
}

// END CUT HERE
