// BEGIN CUT HERE
// PROBLEM STATEMENT
// Fox Ciel has stumbled upon a new problem: In this problem you will visit some points 
// with integer coordinates in the Cartesian plane. Initially, you are located at the point 
// (0,0). In each step, you can move from your current point to one of the four directly 
// adjacent points.
// I.e., if you are at (x,y), you can move to one of the points (x,y+1), (x,y-1), (x+1,y), 
// and (x-1,y).
// 
// You are given two int[]s x and y, each containing N elements.
// Together, x and y describe N distinct points in the Cartesian plane:
// for 0 <= i < N, point i has the coordinates (x[i],y[i]).
// 
// The goal is to find a sequence of steps that satisfies the following criteria:
// The starting point is (0,0).
// The sequence visits each of the N given points at least once.
// The sequence finishes in one of the given points.
// 
// 
// Mr. K claims to have solved this problem but Ciel does not believe him. Ciel has 
// prepared a method to verify Mr. K's claims. Given an int wantedParity, the parity of the 
// number of steps in the sequence found by Mr. K, Ciel will find if it is possible to find 
// a sequence that follows the previously mentioned conditions and a new one:
// 
// The parity of the total number of steps is wantedParity. In other words, if 
// wantedParity=0 then the total number of steps must be even, and if wantedParity=1 then 
// the total number of steps must be odd.
// 
// 
// Return "CAN" (quotes for clarity) if at least one such sequence of steps exists, and 
// "CANNOT" otherwise.
// 
// DEFINITION
// Class:EvenRoute
// Method:isItPossible
// Parameters:int[], int[], int
// Returns:String
// Method signature:String isItPossible(int[] x, int[] y, int wantedParity)
// 
// 
// CONSTRAINTS
// -wantedParity will be 0 or 1.
// -x will contain between 1 and 50 elements, inclusive.
// -y will contain the same number of elements as x.
// -Each element of x and y will be between -1000000 and 1000000, inclusive.
// -No point in the input will be equal to (0,0).
// -No pair of points in the input will be equal.
// 
// 
// EXAMPLES
// 
// 0)
// {-1,-1,1,1}
// {-1,1,1,-1}
// 0
// 
// Returns: "CAN"
// 
// A possible sequence containing an even number of steps:
// 2 steps: (0,0) -> (-1,-1).
// 2 steps: (-1,-1) -> (-1,1).
// 2 steps: (-1,1) -> (1,1).
// 2 steps: (1,1) -> (1,-1).
// 
// 
// 1)
// {-5,-3,2}
// {2,0,3}
// 1
// 
// Returns: "CAN"
// 
// A possible sequence containing an odd number of steps:
// 
// 7 steps: (0,0) -> (-5,2).
// 4 steps: (-5,2) -> (-3,0).
// 8 steps: (-3,0) -> (2,3).
// 
// 
// 
// 2)
// {1001, -4000}
// {0,0}
// 1
// 
// Returns: "CAN"
// 
// The shortest sequence that visits all the given points is the sequence that first goes 
// to (1001,0) and then to (-4000,0).
// Note that this sequence does not have an odd amount of steps.
// However, there is a longer sequence with an odd number of steps: (0,0) -> (-4000,0) -> 
// (1001, 0).
// 
// 3)
// {11, 21, 0}
// {-20, 42, 7}
// 0
// 
// Returns: "CANNOT"
// 
// 
// 
// 4)
// {0, 6}
// {10, -20}
// 1
// 
// Returns: "CANNOT"
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

public class EvenRoute {
	public String isItPossible(int[] x, int[] y, int wantedParity) {
		int a=0;
		int b=0;
		for(int i=0;i<x.length;i++)
			for(int j=i+1;j<x.length;j++){
				if((abs(x[i]-x[j])+abs(y[i]-y[j]))%2==0){
					a++;
				}else
					b++;
			}
		println(a+"   "+b+"     "+wantedParity);
		if(wantedParity==0){
			
			
		}else{
			
			
		}
		
		String ans="";
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
			EvenRouteHarness.run_test(-1);
		} else {
			for (int i = 0; i < args.length; ++i)
				EvenRouteHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class EvenRouteHarness {
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
				int[] x = { -1, -1, 1, 1 };
				int[] y = { -1, 1, 1, -1 };
				int wantedParity = 0;
				String expected__ = "CAN";
				
				return verifyCase(casenum, expected__,
						new EvenRoute().isItPossible(x, y, wantedParity));
			}
			case 1: {
				int[] x = { -5, -3, 2 };
				int[] y = { 2, 0, 3 };
				int wantedParity = 1;
				String expected__ = "CAN";
				
				return verifyCase(casenum, expected__,
						new EvenRoute().isItPossible(x, y, wantedParity));
			}
			case 2: {
				int[] x = { 1001, -4000 };
				int[] y = { 0, 0 };
				int wantedParity = 1;
				String expected__ = "CAN";
				
				return verifyCase(casenum, expected__,
						new EvenRoute().isItPossible(x, y, wantedParity));
			}
			case 3: {
				int[] x = { 11, 21, 0 };
				int[] y = { -20, 42, 7 };
				int wantedParity = 0;
				String expected__ = "CANNOT";
				
				return verifyCase(casenum, expected__,
						new EvenRoute().isItPossible(x, y, wantedParity));
			}
			case 4: {
				int[] x = { 0, 6 };
				int[] y = { 10, -20 };
				int wantedParity = 1;
				String expected__ = "CANNOT";
				
				return verifyCase(casenum, expected__,
						new EvenRoute().isItPossible(x, y, wantedParity));
			}
			
			// custom cases
			
			/*
			 * case 5: { int[] x = ; int[] y = ; int wantedParity = ; String
			 * expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * EvenRoute().isItPossible(x, y, wantedParity)); }
			 */
			/*
			 * case 6: { int[] x = ; int[] y = ; int wantedParity = ; String
			 * expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * EvenRoute().isItPossible(x, y, wantedParity)); }
			 */
			/*
			 * case 7: { int[] x = ; int[] y = ; int wantedParity = ; String
			 * expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * EvenRoute().isItPossible(x, y, wantedParity)); }
			 */
			default:
				return -1;
		}
	}
}

// END CUT HERE
