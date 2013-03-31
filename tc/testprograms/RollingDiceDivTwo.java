// BEGIN CUT HERE
// PROBLEM STATEMENT
// Byteasar is playing a tabletop role-playing game with his friends. To determine the 
// effectiveness of their heroes' actions the players use a rather unique set of dice which 
// may have nonequal number of faces. Each die has between 1 and 9 faces, inclusive. If a 
// die has m faces, they contain precisely all the values between 1 and m, inclusive. More 
// precisely, for each k between 1 and m, inclusive, there is one face that shows exactly k 
// pips. When a die is cast, every face has equal probability to come out on top.
// 
// 
// Every time all the dice were thrown at once, Byteasar wrote down the numbers of pips 
// visible on each of the topmost faces (in any order). The results of the i-th throw are 
// given in throws[i]; the length of throws[i] is equal to the number of dice and each 
// character of throws[i] denotes the number of pips visible on one of the topmost faces. 
// For example, if throws[3][0]='7', this means that in throw 3 (0-based index) one of the 
// dice showed exactly 7 pips on the top. Please note that the ordering of dice may be 
// different for different throws.
// 
// 
// Given the String[] throws containing Byteasar's notes, return the minimum possible total 
// number of faces of all dice.
// 
// DEFINITION
// Class:RollingDiceDivTwo
// Method:minimumFaces
// Parameters:String[]
// Returns:int
// Method signature:int minimumFaces(String[] rolls)
// 
// 
// NOTES
// -Please note that a die can have as few as one or two faces.
// 
// 
// CONSTRAINTS
// -rolls will contain between 1 and 50 elements, inclusive.
// -rolls[0] will contain between 1 and 50 characters, inclusive.
// -All elements of rolls will contain the same number of characters.
// -Each character in each element of rolls will be one of '1'-'9'.
// 
// 
// EXAMPLES
// 
// 0)
// {"137", "364", "115", "724"}
// 
// Returns: 14
// 
// In the first throw the numbers of pips on the topmost faces of the dice were 1, 3 and 7; 
// in the second throw they were 3, 6 and 4, in the third they were 1, 1 and 5 and in the 
// fourth roll they were 7, 2 and 4. The players may have used dice with 3, 4 and 7 faces, 
// giving a total of 14 faces. No other possible set of dice has less faces in total.
// 
// 1)
// {"1112", "1111", "1211", "1111"}
// 
// Returns: 5
// 
// The players could have used three dice with one face each and one die with two faces.
// 
// 2)
// {"24412", "56316", "66666", "45625"}
// 
// Returns: 30
// 
// The players could have used five dice with six faces each.
// 
// 3)
// {"931", "821", "156", "512", "129", "358", "555"}
// 
// Returns: 19
// 
// 
// 
// 4)
// {"3", "7", "4", "2", "4"}
// 
// Returns: 7
// 
// 
// 
// 5)
// {"281868247265686571829977999522", "611464285871136563343229916655", 
// "716739845311113736768779647392", "779122814312329463718383927626",
// "571573431548647653632439431183", "547362375338962625957869719518", 
// "539263489892486347713288936885", "417131347396232733384379841536"}
// 
// Returns: 176
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
import static java.lang.Double.*;
import static java.util.Collections.*;

public class RollingDiceDivTwo {
	public int minimumFaces(String[] rolls) {
		int ans = 0;
		char[][] data = new char[rolls.length][];
		for (int i = 0; i < rolls.length; i++) {
			data[i] = rolls[i].toCharArray();
			sort(data[i]);
		}
		for (int i = 0; i < rolls[0].length(); i++) {
			int mx = -1 << 30;
			for (int j = 0; j < rolls.length; j++)
				mx = max(mx, data[j][i]);
			ans += (mx - '0');
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
			RollingDiceDivTwoHarness.run_test(-1);
		} else {
			for (int i = 0; i < args.length; ++i)
				RollingDiceDivTwoHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class RollingDiceDivTwoHarness {
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
				String[] rolls = { "137", "364", "115", "724" };
				int expected__ = 14;
				
				return verifyCase(casenum, expected__,
						new RollingDiceDivTwo().minimumFaces(rolls));
			}
			case 1: {
				String[] rolls = { "1112", "1111", "1211", "1111" };
				int expected__ = 5;
				
				return verifyCase(casenum, expected__,
						new RollingDiceDivTwo().minimumFaces(rolls));
			}
			case 2: {
				String[] rolls = { "24412", "56316", "66666", "45625" };
				int expected__ = 30;
				
				return verifyCase(casenum, expected__,
						new RollingDiceDivTwo().minimumFaces(rolls));
			}
			case 3: {
				String[] rolls = { "931", "821", "156", "512", "129", "358",
						"555" };
				int expected__ = 19;
				
				return verifyCase(casenum, expected__,
						new RollingDiceDivTwo().minimumFaces(rolls));
			}
			case 4: {
				String[] rolls = { "3", "7", "4", "2", "4" };
				int expected__ = 7;
				
				return verifyCase(casenum, expected__,
						new RollingDiceDivTwo().minimumFaces(rolls));
			}
			case 5: {
				String[] rolls = { "281868247265686571829977999522",
						"611464285871136563343229916655",
						"716739845311113736768779647392",
						"779122814312329463718383927626",
						"571573431548647653632439431183",
						"547362375338962625957869719518",
						"539263489892486347713288936885",
						"417131347396232733384379841536" };
				int expected__ = 176;
				
				return verifyCase(casenum, expected__,
						new RollingDiceDivTwo().minimumFaces(rolls));
			}
			
			// custom cases
			
			/*
			 * case 6: { String[] rolls = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * RollingDiceDivTwo().minimumFaces(rolls)); }
			 */
			/*
			 * case 7: { String[] rolls = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * RollingDiceDivTwo().minimumFaces(rolls)); }
			 */
			/*
			 * case 8: { String[] rolls = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * RollingDiceDivTwo().minimumFaces(rolls)); }
			 */
			default:
				return -1;
		}
	}
}

// END CUT HERE
