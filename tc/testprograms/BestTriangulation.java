// BEGIN CUT HERE
// PROBLEM STATEMENT
// You have a convex polygon. You select three consecutive vertices and create a triangle 
// with them.  Remove this triangle from the polygon (if you had a polygon with N vertices, 
// the resulting polygon would have N-1 vertices). Repeat this process until the remaining 
// polygon is a triangle.
// You are given a String[] vertices, representing the vertices of the polygon in clockwise 
// order. Each element will be formatted as "X Y", where X and Y are the coordinates of a 
// vertex. Return a double representing the area of the largest possible triangle that can 
// remain at the end.
// 
// DEFINITION
// Class:BestTriangulation
// Method:maxArea
// Parameters:String[]
// Returns:double
// Method signature:double maxArea(String[] vertices)
// 
// 
// NOTES
// -The returned value must be accurate to 1e-9 relative or absolute.
// 
// 
// CONSTRAINTS
// -vertices will contain between 3 and 35 elements, inclusive.
// -Each element of vertices will be formatted as "X Y", where X and Y are integers without 
// leading zeroes.
// -Each X and Y will be between 1 and 10000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {"1 1", "2 3", "3 2"}
// 
// Returns: 1.5
// 
// The polygon is already a triangle, so you cannot perform any cuts.
// 
// 1)
// {"1 1", "1 2", "3 3", "2 1"}
// 
// Returns: 1.5
// 
// Here you must perform one cut.
// If you cut vertices (3, 0, 1), a triangle of area 1.5 will remain.
// If you cut vertices (0, 1, 2), a triangle of area 1 will remain.
// If you cut vertices (1, 2, 3), a triangle of area 0.5 will remain.
// If you cut vertices (2, 3, 0), a triangle of area 1 will remain.
// Your best option is to cut (3, 0, 1).
// 
// 2)
// {"1 2", "1 3", "2 4", "3 4", "4 3", "4 2", "3 1", "2 1"}
// 
// Returns: 3.0
// 
// In such an 8-gon, you must cut the following triangles in order: (7, 0, 1), (7, 1, 2), 
// (2, 3, 4), (4, 5, 6), (4, 6, 7). Finally, a triangle with vertices (2, 4, 7) is left, 
// and its area is 3.
// 
// 3)
// {"6 2", "2 1", "1 2", "1 4", "2 6", "5 6", "6 5"}
// 
// Returns: 10.0
// 
// 4)
// {"10000 3469", "9963 712", "9957 634", "9834 271", "9700 165",
//  "9516 46", "8836 4", "1332 57", "229 628", "171 749",
//  "52 1269", "30 1412", "7 4937", "35 8676", "121 9917",
//  "2247 9960", "3581 9986", "6759 9995", "9486 9998", "9888 9890",
//  "9914 9318", "9957 8206", "9998 6402"} 
// 
// Returns: 4.8292483E7
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

public class BestTriangulation {
	public double maxArea(String[] vertices) {
		double ans = 0;
		
		for (int i = 0; i < vertices.length; i++)
			for (int j = i + 1; j < vertices.length; j++)
				for (int k = j + 1; k < vertices.length; k++) {
					double a=lado(vertices[i],vertices[j]);
					double b=lado(vertices[j],vertices[k]);
					double c=lado(vertices[i],vertices[k]);
					double S=(a+b+c)/2.0;
					ans=max(ans,sqrt(S*(S-a)*(S-b)*(S-c)));
				}
		return ans;
	}
	
	double lado(String a, String b){
		String as[]=a.split(" ");
		String bs[]=b.split(" ");
		return hypot(parseInt(as[0])-parseInt(bs[0]), parseInt(as[1])-parseInt(bs[1]));
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
			BestTriangulationHarness.run_test(-1);
		} else {
			for (int i = 0; i < args.length; ++i)
				BestTriangulationHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class BestTriangulationHarness {
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
	
	static final double	MAX_DOUBLE_ERROR	= 1E-9;
	
	static boolean compareOutput(double expected, double result) {
		if (Double.isNaN(expected)) {
			return Double.isNaN(result);
		} else if (Double.isInfinite(expected)) {
			if (expected > 0) {
				return result > 0 && Double.isInfinite(result);
			} else {
				return result < 0 && Double.isInfinite(result);
			}
		} else if (Double.isNaN(result) || Double.isInfinite(result)) {
			return false;
		} else if (Math.abs(result - expected) < MAX_DOUBLE_ERROR) {
			return true;
		} else {
			double min = Math.min(expected * (1.0 - MAX_DOUBLE_ERROR), expected
					* (1.0 + MAX_DOUBLE_ERROR));
			double max = Math.max(expected * (1.0 - MAX_DOUBLE_ERROR), expected
					* (1.0 + MAX_DOUBLE_ERROR));
			return result > min && result < max;
		}
	}
	
	static double relativeError(double expected, double result) {
		if (Double.isNaN(expected) || Double.isInfinite(expected)
				|| Double.isNaN(result) || Double.isInfinite(result)
				|| expected == 0) return 0;
		return Math.abs(result - expected) / Math.abs(expected);
	}
	
	static String formatResult(double res) {
		return String.format("%.10g", res);
	}
	
	static int verifyCase(int casenum, double expected, double received) {
		System.err.print("Example " + casenum + "... ");
		if (compareOutput(expected, received)) {
			System.err.print("PASSED");
			double rerr = relativeError(expected, received);
			if (rerr > 0) System.err.printf(" (relative error %g)", rerr);
			System.err.println();
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
				String[] vertices = { "1 1", "2 3", "3 2" };
				double expected__ = 1.5;
				
				return verifyCase(casenum, expected__,
						new BestTriangulation().maxArea(vertices));
			}
			case 1: {
				String[] vertices = { "1 1", "1 2", "3 3", "2 1" };
				double expected__ = 1.5;
				
				return verifyCase(casenum, expected__,
						new BestTriangulation().maxArea(vertices));
			}
			case 2: {
				String[] vertices = { "1 2", "1 3", "2 4", "3 4", "4 3", "4 2",
						"3 1", "2 1" };
				double expected__ = 3.0;
				
				return verifyCase(casenum, expected__,
						new BestTriangulation().maxArea(vertices));
			}
			case 3: {
				String[] vertices = { "6 2", "2 1", "1 2", "1 4", "2 6", "5 6",
						"6 5" };
				double expected__ = 10.0;
				
				return verifyCase(casenum, expected__,
						new BestTriangulation().maxArea(vertices));
			}
			case 4: {
				String[] vertices = { "10000 3469", "9963 712", "9957 634",
						"9834 271", "9700 165", "9516 46", "8836 4", "1332 57",
						"229 628", "171 749", "52 1269", "30 1412", "7 4937",
						"35 8676", "121 9917", "2247 9960", "3581 9986",
						"6759 9995", "9486 9998", "9888 9890", "9914 9318",
						"9957 8206", "9998 6402" };
				double expected__ = 4.8292483E7;
				
				return verifyCase(casenum, expected__,
						new BestTriangulation().maxArea(vertices));
			}
			
			// custom cases
			
			/*
			 * case 5: { String[] vertices = ; double expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * BestTriangulation().maxArea(vertices)); }
			 */
			/*
			 * case 6: { String[] vertices = ; double expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * BestTriangulation().maxArea(vertices)); }
			 */
			/*
			 * case 7: { String[] vertices = ; double expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * BestTriangulation().maxArea(vertices)); }
			 */
			default:
				return -1;
		}
	}
}

// END CUT HERE
