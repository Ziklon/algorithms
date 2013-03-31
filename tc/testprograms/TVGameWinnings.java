// BEGIN CUT HERE
// PROBLEM STATEMENT
// A domino is a rectangular tile with a number on each end.
// 
// On a TV game show, a player is presented with a NxN board containing N^2 dominoes.  The 
// domino in row i, column j (both 1-based indices) contains the numbers i and j.  The 
// player must choose exactly N dominoes from the board such that no two dominoes are from 
// the same column and no two are from the same row.  He is then required to join all pairs 
// of dominoes that contain the same number.  For example, if he picks (1,3), (3,2), (2,4) 
// and (4,1), he must join them all together in a cycle.
// 
// At this point, there are one or more groups of connected dominoes (a single domino 
// counts as a group).  Because the player is not allowed to choose dominoes from the same 
// column or row, there will always be a single way to join the dominoes together.
// 
// Each domino has a hidden number on its back.  Compute the product of the hidden numbers 
// of all the selected dominoes.  If there is an even number of connected domino groups, 
// multiply this product by -1.  The final product is the outcome of the game, and if it is 
// positive, the player wins money, and if it's negative, he loses money.
// 
// You are given a String[] board containing the hidden numbers of all the dominoes on the 
// board.  The j-th character of the i-th element of board is a character representing the 
// hidden number of the domino in row i, column j.  Digits '0' to '9' represent the numbers 
// 0 to 9.  Letters 'A' to 'I' represent the numbers -1 to -9. Return a int[] containing 
// exactly two elements.  The first element is the minimum possible outcome of the game, 
// and the second element is the maximum possible outcome.
// 
// DEFINITION
// Class:TVGameWinnings
// Method:getMinMax
// Parameters:String[]
// Returns:int[]
// Method signature:int[] getMinMax(String[] board)
// 
// 
// CONSTRAINTS
// -board will contain between 1 and 6 elements, inclusive.
// -Each element of board will contain exactly n characters, where n is the number of 
// elements in board.
// -board will contain only digits '0'-'9' and uppercase letters 'A'-'I'.
// 
// 
// EXAMPLES
// 
// 0)
// {"35",
//  "44"}
// 
// Returns: {-12, 20 }
// 
// There are two possible ways to select the dominoes:
// 
// 1) Select (1,1) and (2,2).  You can't join them together, so you have two groups of 
// dominoes (each containing a single domino).  The product of their hidden numbers is 3x4 
// = 12.  Since there's an even number of groups, you then multiply by -1 to get -12.
// 
// 2) Select (1,2) and (2,1).  You must join these two together, so you have one connected 
// group of dominoes.  The product of their hidden numbers is 4x5 = 20.
// 
// The minimum outcome is -12 and the maximum is 20.
// 
// 1)
// {"00200",
//  "0B000",
//  "00020",
//  "10000",
//  "00001"}
// 
// Returns: {-8, 0 }
// 
// Every choice leads to 0 earnings except (1,3), (2,2), (3,4), (4,1), (5,5).  When we 
// choose those, we get three groups of connected dominoes:
// 
// (1,3) - (3,4) - (4,1)
// (2,2)
// (5,5)
// 
// The outcome here is 2*(-2)*2*1*1 = -8.
// 
// 2)
// {"12A",
//  "A12",
//  "2A1"}
// 
// Returns: {-1, 8 }
// 
// There are 6 possible ways to select the dominoes, and their outcomes are: -1, 1, 2, 2, 
// 2, 8.
// 
// 3)
// {"AAAA",
//  "BBBB",
//  "CCCC",
//  "DDDD"}
// 
// Returns: {-24, 24 }
// 
// Here, no matter how we choose the dominoes, the outcome will always be either 24 or -24.
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

public class TVGameWinnings {
   public int[] getMinMax(String[] board) {
	int[] ans;
	return ans;
   }
// BEGIN CUT HERE
   public void print(String s){
         System.err.print("   "+s);
   }
   public void println(String s){
         print(s+"\n");
   }
   public static void main(String[] args) {
		if (args.length == 0) {
			TVGameWinningsHarness.run_test(-1);
		} else {
			for (int i=0; i<args.length; ++i)
				TVGameWinningsHarness.run_test(Integer.valueOf(args[i]));
		}
	}
// END CUT HERE
}
// BEGIN CUT HERE
class TVGameWinningsHarness {
	public static void run_test(int casenum) {
		if (casenum != -1) {
			if (runTestCase(casenum) == -1)
				System.err.println("Illegal input! Test case " + casenum + " does not exist.");
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
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
			System.err.println("Some cases FAILED (passed " + correct + " of " + total + ").");
		} else {
			System.err.println("All " + total + " tests passed!");
		}
	}
	
	static boolean compareOutput(int[] expected, int[] result) { if (expected.length != result.length) return false; for (int i=0; i<expected.length; ++i) if (expected[i] != result[i]) return false; return true; }

	static String formatResult(int[] res) {
		String ret = "";
		ret += "{";
		for (int i=0; i<res.length; ++i) {
			if (i > 0) ret += ",";
			ret += String.format(" %d", res[i]);
		}
		ret += " }";
		return ret;
	}
	
	static int verifyCase(int casenum, int[] expected, int[] received) { 
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
		switch(casenum) {
		case 0: {
			String[] board            = {"35",  "44"};
			int[] expected__          = {-12, 20 };

			return verifyCase(casenum, expected__, new TVGameWinnings().getMinMax(board));
		}
		case 1: {
			String[] board            = {"00200",  "0B000",  "00020",  "10000",  "00001"};
			int[] expected__          = {-8, 0 };

			return verifyCase(casenum, expected__, new TVGameWinnings().getMinMax(board));
		}
		case 2: {
			String[] board            = {"12A",  "A12",  "2A1"};
			int[] expected__          = {-1, 8 };

			return verifyCase(casenum, expected__, new TVGameWinnings().getMinMax(board));
		}
		case 3: {
			String[] board            = {"AAAA",  "BBBB",  "CCCC",  "DDDD"};
			int[] expected__          = {-24, 24 };

			return verifyCase(casenum, expected__, new TVGameWinnings().getMinMax(board));
		}

		// custom cases

/*      case 4: {
			String[] board            = ;
			int[] expected__          = ;

			return verifyCase(casenum, expected__, new TVGameWinnings().getMinMax(board));
		}*/
/*      case 5: {
			String[] board            = ;
			int[] expected__          = ;

			return verifyCase(casenum, expected__, new TVGameWinnings().getMinMax(board));
		}*/
/*      case 6: {
			String[] board            = ;
			int[] expected__          = ;

			return verifyCase(casenum, expected__, new TVGameWinnings().getMinMax(board));
		}*/
		default:
			return -1;
		}
	}
}

// END CUT HERE
