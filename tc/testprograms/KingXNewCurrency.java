// BEGIN CUT HERE
// PROBLEM STATEMENT
// King Dengklek is the perfect king of Kingdom of Ducks, where slimes and ducks live 
// together in peace and harmony.
// 
// Kingdom of Ducks has a pretty strange currency system. There are only two coin types: 
// one with value A and one with value B, where A and B are different. This currency system 
// is denoted by {A, B}. These two coin types are sufficient for daily transactions, 
// because all prices in this kingdom are in the form of (A*p + B*q) for some non-negative 
// integers p and q. Therefore, slimes and ducks can pay for any goods with a combination 
// of the two coin types.
// 
// Bored with the current system, King Dengklek considered another currency system with two 
// coin types: one with value X and one with value Y, where X and Y are different. Of 
// course, with this new system, combinations of the two new coin types must make it 
// possible to pay all the prices one could pay with currency system {A, B}. (Note that the 
// new coin types may also make it possible to pay some additional prices.)
// 
// You are given ints A, B, and X. Return the number of different positive integers Y 
// (other than X) such that the currency system {X, Y} can be used to replace the currency 
// system {A, B}. If there is an infinite number of possible values for Y, return -1 instead.
// 
// DEFINITION
// Class:KingXNewCurrency
// Method:howMany
// Parameters:int, int, int
// Returns:int
// Method signature:int howMany(int A, int B, int X)
// 
// 
// CONSTRAINTS
// -A, B, and X will each be between 1 and 200, inclusive.
// -A and B will be different.
// 
// 
// EXAMPLES
// 
// 0)
// 5
// 8
// 5
// 
// Returns: 5
// 
// These are the 5 possible currency systems: {5, 1}, {5, 2}, {5, 3}, {5, 4}, and {5, 8}.
// 
// 1)
// 8
// 4
// 2
// 
// Returns: -1
// 
// All prices are multiples of four. Since a coin type with value 2 alone can pay any price 
// that is a multiple of four, there is an infinite number of possible values of Y.
// 
// 2)
// 7
// 4
// 13
// 
// Returns: 1
// 
// The only possible currency system is {13, 1}.
// 
// 3)
// 47
// 74
// 44
// 
// Returns: 2
// 
// The two possible currency systems are {44, 1} and {44, 3}.
// 
// 4)
// 128
// 96
// 3
// 
// Returns: 65
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

public class KingXNewCurrency {
	public int howMany(int A, int B, int X) {
		int ans = 1;
		if (A % X == 0 && B % X == 0) return -1;
		int M[]={A,B};
		int R[]={X,0};
		sort(M);
		int suma=A+B;
		int mx=max(A,B);
		for(int i=2;i<=mx;i++){			
			int ok=1;
			for(int p=0;p<i && ok==1;p++){
				for(int q=0;q<i && ok==1;q++){
					int T=(A*p)+(B*q);
					int ver=0;
					for(int r=0;r<i;r++){
						int S=(A*p)+(B*q)-(X*r);
						if(S<0)break;
						if(S%i==0)
							ver=1;
					}
					ok=min(ok,ver);
					
				}
			
			}
			ans+=ok;
		
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
			KingXNewCurrencyHarness.run_test(-1);
		} else {
			for (int i = 0; i < args.length; ++i)
				KingXNewCurrencyHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class KingXNewCurrencyHarness {
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
				int A = 5;
				int B = 8;
				int X = 5;
				int expected__ = 5;
				
				return verifyCase(casenum, expected__,
						new KingXNewCurrency().howMany(A, B, X));
			}
			case 1: {
				int A = 8;
				int B = 4;
				int X = 2;
				int expected__ = -1;
				
				return verifyCase(casenum, expected__,
						new KingXNewCurrency().howMany(A, B, X));
			}
			case 2: {
				int A = 7;
				int B = 4;
				int X = 13;
				int expected__ = 1;
				
				return verifyCase(casenum, expected__,
						new KingXNewCurrency().howMany(A, B, X));
			}
			case 3: {
				int A = 47;
				int B = 74;
				int X = 44;
				int expected__ = 2;
				
				return verifyCase(casenum, expected__,
						new KingXNewCurrency().howMany(A, B, X));
			}
			case 4: {
				int A = 128;
				int B = 96;
				int X = 3;
				int expected__ = 65;
				
				return verifyCase(casenum, expected__,
						new KingXNewCurrency().howMany(A, B, X));
			}
			
			case 5: {
				int A = 199;
				int B = 199;
				int X = 2;
				int expected__ = 65;
				
				return verifyCase(casenum, expected__,
						new KingXNewCurrency().howMany(A, B, X));
			}
			
			// custom cases
			
			/*
			 * case 5: { int A = ; int B = ; int X = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * KingXNewCurrency().howMany(A, B, X)); }
			 */
			/*
			 * case 6: { int A = ; int B = ; int X = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * KingXNewCurrency().howMany(A, B, X)); }
			 */
			/*
			 * case 7: { int A = ; int B = ; int X = ; int expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * KingXNewCurrency().howMany(A, B, X)); }
			 */
			default:
				return -1;
		}
	}
}

// END CUT HERE
