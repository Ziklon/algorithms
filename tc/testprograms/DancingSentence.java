// BEGIN CUT HERE
// PROBLEM STATEMENT
// A sentence is called dancing if its first letter is uppercase and the case of each 
// subsequent letter is the opposite of the previous letter. Spaces should be ignored when 
// determining the case of a letter.  For example, "A b  Cd" is a dancing sentence because 
// the first letter ('A') is uppercase, the next letter ('b') is lowercase, the next letter 
// ('C') is uppercase, and the next letter ('d') is lowercase.
// You will be given a String sentence. Turn the sentence into a dancing sentence by 
// changing the cases of the letters where necessary.  All spaces in the original sentence 
// must be preserved.
// 
// DEFINITION
// Class:DancingSentence
// Method:makeDancing
// Parameters:String
// Returns:String
// Method signature:String makeDancing(String sentence)
// 
// 
// CONSTRAINTS
// -sentence will contain between 1 and 50 characters, inclusive.
// -Each character in sentence will be a letter ('A'-'Z','a'-'z') or a space (' ').
// -sentence will contain at least one letter ('A'-'Z','a'-'z').
// 
// 
// EXAMPLES
// 
// 0)
// "This is a dancing sentence"
// 
// Returns: "ThIs Is A dAnCiNg SeNtEnCe"
// 
// 1)
// " This   is         a  dancing   sentence  "
// 
// Returns: " ThIs   Is         A  dAnCiNg   SeNtEnCe  "
// 
// Spaces should be ignored when determining the cases of the letters, but they should be 
// preserved in the return value.
// 
// 2)
// "aaaaaaaaaaa"
// 
// Returns: "AaAaAaAaAaA"
// 
// 3)
// "z"
// 
// Returns: "Z"
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
import static java.lang.Character.*;
import static java.lang.Long.*;
import static java.lang.Double.*;
import static java.util.Collections.*;

public class DancingSentence {
	public String makeDancing(String sentence) {
		String ans = "";
		boolean bit=true;		
		for(char cur: sentence.toCharArray()){
			if(Character.isLetter(cur)){
				ans+=(bit)?toUpperCase(cur):toLowerCase(cur);
				bit=bit^true;
					
			}else
				ans+=cur;
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
			DancingSentenceHarness.run_test(-1);
		} else {
			for (int i = 0; i < args.length; ++i)
				DancingSentenceHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class DancingSentenceHarness {
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
				String sentence = "This is a dancing sentence";
				String expected__ = "ThIs Is A dAnCiNg SeNtEnCe";
				
				return verifyCase(casenum, expected__,
						new DancingSentence().makeDancing(sentence));
			}
			case 1: {
				String sentence = " This   is         a  dancing   sentence  ";
				String expected__ = " ThIs   Is         A  dAnCiNg   SeNtEnCe  ";
				
				return verifyCase(casenum, expected__,
						new DancingSentence().makeDancing(sentence));
			}
			case 2: {
				String sentence = "aaaaaaaaaaa";
				String expected__ = "AaAaAaAaAaA";
				
				return verifyCase(casenum, expected__,
						new DancingSentence().makeDancing(sentence));
			}
			case 3: {
				String sentence = "z";
				String expected__ = "Z";
				
				return verifyCase(casenum, expected__,
						new DancingSentence().makeDancing(sentence));
			}
			
			// custom cases
			
			/*
			 * case 4: { String sentence = ; String expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * DancingSentence().makeDancing(sentence)); }
			 */
			/*
			 * case 5: { String sentence = ; String expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * DancingSentence().makeDancing(sentence)); }
			 */
			/*
			 * case 6: { String sentence = ; String expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * DancingSentence().makeDancing(sentence)); }
			 */
			default:
				return -1;
		}
	}
}

// END CUT HERE
