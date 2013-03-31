// BEGIN CUT HERE
// PROBLEM STATEMENT
// You used to have only 30 rocks, but now you have plenty of them. In fact, we will assume 
// that you have a potentially infinite supply of rocks. You would like to show that you 
// own over 9000 rocks.
// You have a set of boxes. You will choose a subset of those boxes and fill them with 
// rocks so that the total number of rocks will be over 9000. Each box has a lower and an 
// upper bound on the number of rocks it may contain.
// 
// You are given the int[]s lowerBound and upperBound. For each i, the values lowerBound[i] 
// and upperBound[i] have the following meaning: If you decide to use box i, the number of 
// rocks you may put inside the box must be between lowerBound[i] and upperBound[i], 
// inclusive.
// 
// X is a positive integer that has two properties:
// 
// X is over 9000.
// It is possible to select some of the boxes and fill them with appropriate numbers of 
// rocks in such a way that the total number of rocks used is exactly X.
// 
// Compute and return the number of possible values of X.
// 
// DEFINITION
// Class:Over9000Rocks
// Method:countPossibilities
// Parameters:int[], int[]
// Returns:int
// Method signature:int countPossibilities(int[] lowerBound, int[] upperBound)
// 
// 
// CONSTRAINTS
// -lowerBound will contain between 1 and 15, elements, inclusive.
// -upperBound will contain the same number of elements as lowerBound.
// -Each element of lowerBound will be between 1 and 1,000,000 (10^6), inclusive.
// -Each element i of upperBound will be between lowerBound[i] and 1,000,000 (10^6), 
// inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {9000}
// {9001}
// 
// Returns: 1
// 
// You can place 9000 or 9001 rocks in the single box. Of the allowed values, only 9001 is 
// over 9000.
// 
// 1)
// {9000, 1, 10}
// {9000, 2, 20}
// 
// Returns: 15
// 
// You have to choose box 0 and at least one other box, otherwise you have no chance of 
// placing over 9000 rocks.
// If you only choose boxes 0 and 1, you can place 9001 or 9002 rocks.
// If you only choose boxes 0 and 2, you can place between 9010 and 9020 rocks, inclusive.
// If you choose all three boxes, you can place between 9011 and 9022 rocks, inclusive.
// Hence all possible values of X are 9001, 9002, and everything from 9010 to 9022, 
// inclusive.
// 
// 2)
// {1001, 2001, 3001, 3001}
// {1003, 2003, 3003, 3003}
// 
// Returns: 9
// 
// 
// 
// 3)
// {9000,90000,1,10}
// {9000,90000,3,15}
// 
// Returns: 38
// 
// 
// 
// 4)
// {1,1,1,1,1,1}
// {3,4,5,6,7,8}
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

public class Over9000Rocks {
	
	public class Segment implements Comparable<Segment> {
		int	p, q;		
		public Segment(int p, int q) {
			this.p = p;
			this.q = q;			
		}
		
		public int compareTo(Segment o) {			
			return p - o.p;
		}
		
	}
	
	public int countPossibilities(int[] lowerBound, int[] upperBound) {
		int ans = 0;
		int L = 1 << lowerBound.length;
		ArrayList<Segment> lis = new ArrayList<Segment>();
		for (int mask = 0; mask < L; mask++) {			
			int suma = 0;
			int posi = 0;
			int otro = 0;
			for (int i = 0; i < lowerBound.length; i++) {
				if ((mask & 1 << i) == 0) {
					suma += lowerBound[i];
					posi += upperBound[i] - lowerBound[i];
				}				
			}
			otro = suma + posi;
			if (otro >= 9001) {
				suma = max(9001, suma);
				lis.add(new Segment(suma, otro));				
			}
			
		}
		sort(lis);
		int voy = 0;
		for (Segment s : lis) {
			if (voy >= s.q) continue;
			ans += s.q - max(voy, s.p) + 1;
			if (voy >= s.p) ans--;
			voy = max(voy, s.q);
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
			Over9000RocksHarness.run_test(-1);
		} else {
			for (int i = 0; i < args.length; ++i)
				Over9000RocksHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class Over9000RocksHarness {
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
				int[] lowerBound = { 9000 };
				int[] upperBound = { 9001 };
				int expected__ = 1;
				
				return verifyCase(casenum, expected__,
						new Over9000Rocks().countPossibilities(lowerBound,
								upperBound));
			}
			case 1: {
				int[] lowerBound = { 9000, 1, 10 };
				int[] upperBound = { 9000, 2, 20 };
				int expected__ = 15;
				
				return verifyCase(casenum, expected__,
						new Over9000Rocks().countPossibilities(lowerBound,
								upperBound));
			}
			case 2: {
				int[] lowerBound = { 1001, 2001, 3001, 3001 };
				int[] upperBound = { 1003, 2003, 3003, 3003 };
				int expected__ = 9;
				
				return verifyCase(casenum, expected__,
						new Over9000Rocks().countPossibilities(lowerBound,
								upperBound));
			}
			case 3: {
				int[] lowerBound = { 9000, 90000, 1, 10 };
				int[] upperBound = { 9000, 90000, 3, 15 };
				int expected__ = 38;
				
				return verifyCase(casenum, expected__,
						new Over9000Rocks().countPossibilities(lowerBound,
								upperBound));
			}
			case 4: {
				int[] lowerBound = { 1, 1, 1, 1, 1, 1 };
				int[] upperBound = { 3, 4, 5, 6, 7, 8 };
				int expected__ = 0;
				
				return verifyCase(casenum, expected__,
						new Over9000Rocks().countPossibilities(lowerBound,
								upperBound));
			}
			case 5: {
				int[] lowerBound = { 9000 };
				int[] upperBound = { 9001 };
				int expected__ = 1;
				
				return verifyCase(casenum, expected__,
						new Over9000Rocks().countPossibilities(lowerBound,
								upperBound));
			}
			
			// custom cases
			
			/*
			 * case 5: { int[] lowerBound = ; int[] upperBound = ; int
			 * expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * Over9000Rocks().countPossibilities(lowerBound, upperBound)); }
			 */
			/*
			 * case 6: { int[] lowerBound = ; int[] upperBound = ; int
			 * expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * Over9000Rocks().countPossibilities(lowerBound, upperBound)); }
			 */
			/*
			 * case 7: { int[] lowerBound = ; int[] upperBound = ; int
			 * expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * Over9000Rocks().countPossibilities(lowerBound, upperBound)); }
			 */
			default:
				return -1;
		}
	}
}

// END CUT HERE
