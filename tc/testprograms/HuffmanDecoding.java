// BEGIN CUT HERE
// PROBLEM STATEMENT
// When text is encoded using Huffman codes, each symbol is replaced by a string of 0s and 
// 1s called a bit string representation.  The replacement is done in such a way that the 
// bit string representation of a symbol is never the prefix of the bit string 
// representation of any other symbol.  This property allows us to unambiguously decode the 
// encoded text.
// You will be given a String archive and a String[] dictionary. The i-th element of 
// dictionary will be the bit string representation of the i-th uppercase letter. Decode 
// archive using dictionary and return the result as a single String.
// 
// DEFINITION
// Class:HuffmanDecoding
// Method:decode
// Parameters:String, String[]
// Returns:String
// Method signature:String decode(String archive, String[] dictionary)
// 
// 
// CONSTRAINTS
// -archive will contain between 1 and 50 characters, inclusive. 
// -archive will contain only the characters '0' (zero) and '1' (one).
// -dictionary will contain between 1 and 26 elements, inclusive. 
// -Each element of dictionary will contain between 1 and 50 characters, inclusive. 
// -Each element of dictionary will contain only the characters '0' (zero) and '1' (one).
// -No element of dictionary will be a prefix of any other element of dictionary.
// -archive will be decodable using dictionary
// 
// 
// EXAMPLES
// 
// 0)
// "101101"
// {"00","10","01","11"}
// 
// Returns: "BDC"
// 
// Because there are no elements in dictionary that are prefixes of other elements, only 
// one element of dictionary will be a prefix of archive.  In this case, it is the second 
// element ("10") which represents 'B'.  The rest of the text can be decoded using the same 
// logic.
// 
// 1)
// "10111010"
// {"0","111","10"}
// 
// Returns: "CBAC"
// 
// Note that elements of dictionary can be of different lengths.
// 
// 2)
// "0001001100100111001"
// {"1","0"}
// 
// Returns: "BBBABBAABBABBAAABBA"
// 
// '1' is replaced by 'A', '0' is replaced by 'B'.
// 
// 3)
// "111011011000100110"
// {"010","00","0110","0111","11","100","101"}
// 
// Returns: "EGGFAC"
// 
// 4)
// "001101100101100110111101011001011001010"
// {"110","011","10","0011","00011","111","00010","0010","010","0000"}
// 
// Returns: "DBHABBACAIAIC"
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

public class HuffmanDecoding {
	public String decode(String archive, String[] dictionary) {
		String ans = "";
		
		while(archive.length()>0){
			for(int i=0;i<dictionary.length;i++){
				if(archive.startsWith(dictionary[i])){
					archive=archive.substring(dictionary[i].length());
					ans+=(char)('A'+i);
				}
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
			HuffmanDecodingHarness.run_test(-1);
		} else {
			for (int i = 0; i < args.length; ++i)
				HuffmanDecodingHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class HuffmanDecodingHarness {
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
				String archive = "101101";
				String[] dictionary = { "00", "10", "01", "11" };
				String expected__ = "BDC";
				
				return verifyCase(casenum, expected__,
						new HuffmanDecoding().decode(archive, dictionary));
			}
			case 1: {
				String archive = "10111010";
				String[] dictionary = { "0", "111", "10" };
				String expected__ = "CBAC";
				
				return verifyCase(casenum, expected__,
						new HuffmanDecoding().decode(archive, dictionary));
			}
			case 2: {
				String archive = "0001001100100111001";
				String[] dictionary = { "1", "0" };
				String expected__ = "BBBABBAABBABBAAABBA";
				
				return verifyCase(casenum, expected__,
						new HuffmanDecoding().decode(archive, dictionary));
			}
			case 3: {
				String archive = "111011011000100110";
				String[] dictionary = { "010", "00", "0110", "0111", "11",
						"100", "101" };
				String expected__ = "EGGFAC";
				
				return verifyCase(casenum, expected__,
						new HuffmanDecoding().decode(archive, dictionary));
			}
			case 4: {
				String archive = "001101100101100110111101011001011001010";
				String[] dictionary = { "110", "011", "10", "0011", "00011",
						"111", "00010", "0010", "010", "0000" };
				String expected__ = "DBHABBACAIAIC";
				
				return verifyCase(casenum, expected__,
						new HuffmanDecoding().decode(archive, dictionary));
			}
			
			// custom cases
			
			/*
			 * case 5: { String archive = ; String[] dictionary = ; String
			 * expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * HuffmanDecoding().decode(archive, dictionary)); }
			 */
			/*
			 * case 6: { String archive = ; String[] dictionary = ; String
			 * expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * HuffmanDecoding().decode(archive, dictionary)); }
			 */
			/*
			 * case 7: { String archive = ; String[] dictionary = ; String
			 * expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * HuffmanDecoding().decode(archive, dictionary)); }
			 */
			default:
				return -1;
		}
	}
}

// END CUT HERE
