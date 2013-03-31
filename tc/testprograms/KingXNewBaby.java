// BEGIN CUT HERE
// PROBLEM STATEMENT
// King Dengklek is the perfect king of Kingdom of Ducks, where slimes and ducks live 
// together in peace and harmony.
// 
// After several years of waiting, King Dengklek and the queen finally had a baby. Now he 
// is looking for a name for the newborn baby. According to the private rule of Kingdom of 
// Ducks, the name of each member of the royal family must be such that:
// 
// 
// It must consist of exactly eight letters. All letters must be lowercase ('a'-'z').
// It must have exactly two vowels and six consonants. (Vowels are the letters 'a', 'e', 
// 'i', 'o', and 'u'; the rest are consonants.)
// The two vowels must be equal.
// 
// 
// For example, "dengklek" is a valid name because it consists of exactly eight letters: 
// six consonants and two identical vowels, 'e'.
// 
// You are given a String name. Please help the kingdom determine whether name is valid. 
// Return "YES" if it is a valid name for King Dengklek's newborn baby, or "NO" otherwise.
// 
// DEFINITION
// Class:KingXNewBaby
// Method:isValid
// Parameters:String
// Returns:String
// Method signature:String isValid(String name)
// 
// 
// CONSTRAINTS
// -name will contain between 1 and 50 characters, inclusive.
// -Each character of name will be one of 'a'-'z'.
// 
// 
// EXAMPLES
// 
// 0)
// "dengklek"
// 
// Returns: "YES"
// 
// 
// 
// 1)
// "gofushar"
// 
// Returns: "NO"
// 
// It has more than two vowels.
// 
// 2)
// "dolphinigle"
// 
// Returns: "NO"
// 
// It has more than eight letters.
// 
// 3)
// "mystictc"
// 
// Returns: "NO"
// 
// It has only one vowel.
// 
// 4)
// "rngringo"
// 
// Returns: "NO"
// 
// It has exactly two vowels, but they are not equal.
// 
// 5)
// "misof"
// 
// Returns: "NO"
// 
// It has less than eight letters.
// 
// 6)
// "metelsky"
// 
// Returns: "YES"
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

public class KingXNewBaby {
	public String isValid(String name) {
		String ans = "";
		String vocals="aeiou";
		if(name.length()!=8)return "NO";
		int nv=0;
		HashSet<Character> hs=new HashSet<Character>();		
		for(int i=0;i<name.length();i++){
			if(vocals.indexOf(name.charAt(i))!=-1){
				hs.add(name.charAt(i));
				nv++;
			}
		}
		if(nv==2 && hs.size()==1)return "YES";
		return "NO";
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
			KingXNewBabyHarness.run_test(-1);
		} else {
			for (int i = 0; i < args.length; ++i)
				KingXNewBabyHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class KingXNewBabyHarness {
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
				String name = "dengklek";
				String expected__ = "YES";
				
				return verifyCase(casenum, expected__,
						new KingXNewBaby().isValid(name));
			}
			case 1: {
				String name = "gofushar";
				String expected__ = "NO";
				
				return verifyCase(casenum, expected__,
						new KingXNewBaby().isValid(name));
			}
			case 2: {
				String name = "dolphinigle";
				String expected__ = "NO";
				
				return verifyCase(casenum, expected__,
						new KingXNewBaby().isValid(name));
			}
			case 3: {
				String name = "mystictc";
				String expected__ = "NO";
				
				return verifyCase(casenum, expected__,
						new KingXNewBaby().isValid(name));
			}
			case 4: {
				String name = "rngringo";
				String expected__ = "NO";
				
				return verifyCase(casenum, expected__,
						new KingXNewBaby().isValid(name));
			}
			case 5: {
				String name = "misof";
				String expected__ = "NO";
				
				return verifyCase(casenum, expected__,
						new KingXNewBaby().isValid(name));
			}
			case 6: {
				String name = "metelsky";
				String expected__ = "YES";
				
				return verifyCase(casenum, expected__,
						new KingXNewBaby().isValid(name));
			}
			
			// custom cases
			
			/*
			 * case 7: { String name = ; String expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * KingXNewBaby().isValid(name)); }
			 */
			/*
			 * case 8: { String name = ; String expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * KingXNewBaby().isValid(name)); }
			 */
			/*
			 * case 9: { String name = ; String expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * KingXNewBaby().isValid(name)); }
			 */
			default:
				return -1;
		}
	}
}

// END CUT HERE
