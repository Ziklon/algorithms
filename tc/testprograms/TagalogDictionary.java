// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// In the first half of the 20th century, around the time that Tagalog became the national 
// language of the Philippines, a standardized alphabet was introduced to be used in 
// Tagalog school books (since then, the national language has changed to a hybrid 
// "Pilipino" language, as Tagalog is only one of several major languages spoken in the 
// Philippines).
// 
// 
// Tagalog's 20-letter alphabet is as follows:
// 
// a b k d e g h i l m n ng o p r s t u w y
// 
// Note that not all letters used in English are present, 'k' is the third letter, and 'ng' 
// is a single letter that comes between 'n' and 'o'.
// 
// 
// You are compiling a Tagalog dictionary, and for people to be able to find words in it, 
// the words need to be sorted in alphabetical order with reference to the Tagalog 
// alphabet.  Given a list of Tagalog words as a String[], return the same list in Tagalog 
// alphabetical order.
// 
// 
// DEFINITION
// Class:TagalogDictionary
// Method:sortWords
// Parameters:String[]
// Returns:String[]
// Method signature:String[] sortWords(String[] words)
// 
// 
// NOTES
// -Any 'n' followed followed by a 'g' should be considered a single 'ng' letter (the one 
// that comes between 'n' and 'o').
// 
// 
// CONSTRAINTS
// -words will contain between 1 and 50 elements, inclusive.
// -Each element of words will contain between 1 and 50 characters, inclusive.
// -Each character of each element of words will be a valid lowercase letter that appears 
// in the Tagalog alphabet.
// -Each element of words will be distinct.
// 
// 
// EXAMPLES
// 
// 0)
// {"abakada","alpabet","tagalog","ako"}
// 
// Returns: {"abakada", "ako", "alpabet", "tagalog" }
// 
// The tagalog word for "alphabet", a Tagalogization of the English word "alphabet", the 
// name of the language, and the word for "I".
// 
// 1)
// {"ang","ano","anim","alak","alam","alab"}
// 
// Returns: {"alab", "alak", "alam", "anim", "ano", "ang" }
// 
// A few "A" words that are alphabetically close together.
// 
// 2)
// {"siya","niya","kaniya","ikaw","ito","iyon"}
// 
// Returns: {"kaniya", "ikaw", "ito", "iyon", "niya", "siya" }
// 
// Common Tagalog pronouns.
// 
// 3)
// {"kaba","baka","naba","ngipin","nipin"}
// 
// Returns: {"baka", "kaba", "naba", "nipin", "ngipin" }
// 
// 4)
// {"knilngiggnngginggn","ingkigningg","kingkong","dingdong","dindong","dingdont","ingkblot"}
// 
// Returns: {"kingkong", "knilngiggnngginggn", "dindong", "dingdont", "dingdong", 
// "ingkblot", "ingkigningg" }
// 
// 5)
// {"silangang", "baka", "bada", "silang"}
// 
// Returns: {"baka", "bada", "silang", "silangang" }
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

public class TagalogDictionary {
	
	String letters="abkdeghilmncoprstuwy";
	public String[] sortWords(String[] words) {
		for(int i=0;i<words.length;i++)
			words[i]=words[i].replaceAll("ng", "c");
		
		Arrays.sort(words,new myCompare());		
		for(int i=0;i<words.length;i++)
			words[i]=words[i].replaceAll("c", "ng");
		return words;
	}
	
	class myCompare implements Comparator<String>{

		
		public int compare(String a, String b) {
			if(a.equals(b))return 0;
			int m=min(a.length(),b.length());
			for(int i=0;i<m;i++){
				int p=letters.indexOf(a.charAt(i));
				int q=letters.indexOf(b.charAt(i));
				if(p<q)return -1;
				if(p>q)return 1;
				
			}
			if(a.length()<b.length())return -1;
			return 1;
		}
		
		
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
			TagalogDictionaryHarness.run_test(-1);
		} else {
			for (int i = 0; i < args.length; ++i)
				TagalogDictionaryHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class TagalogDictionaryHarness {
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
	
	static boolean compareOutput(String[] expected, String[] result) {
		if (expected.length != result.length) return false;
		for (int i = 0; i < expected.length; ++i)
			if (!expected[i].equals(result[i])) return false;
		return true;
	}
	
	static String formatResult(String[] res) {
		String ret = "";
		ret += "{";
		for (int i = 0; i < res.length; ++i) {
			if (i > 0) ret += ",";
			ret += String.format(" \"%s\"", res[i]);
		}
		ret += " }";
		return ret;
	}
	
	static int verifyCase(int casenum, String[] expected, String[] received) {
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
				String[] words = { "abakada", "alpabet", "tagalog", "ako" };
				String[] expected__ = { "abakada", "ako", "alpabet", "tagalog" };
				
				return verifyCase(casenum, expected__,
						new TagalogDictionary().sortWords(words));
			}
			case 1: {
				String[] words = { "ang", "ano", "anim", "alak", "alam", "alab" };
				String[] expected__ = { "alab", "alak", "alam", "anim", "ano",
						"ang" };
				
				return verifyCase(casenum, expected__,
						new TagalogDictionary().sortWords(words));
			}
			case 2: {
				String[] words = { "siya", "niya", "kaniya", "ikaw", "ito",
						"iyon" };
				String[] expected__ = { "kaniya", "ikaw", "ito", "iyon",
						"niya", "siya" };
				
				return verifyCase(casenum, expected__,
						new TagalogDictionary().sortWords(words));
			}
			case 3: {
				String[] words = { "kaba", "baka", "naba", "ngipin", "nipin" };
				String[] expected__ = { "baka", "kaba", "naba", "nipin",
						"ngipin" };
				
				return verifyCase(casenum, expected__,
						new TagalogDictionary().sortWords(words));
			}
			case 4: {
				String[] words = { "knilngiggnngginggn", "ingkigningg",
						"kingkong", "dingdong", "dindong", "dingdont",
						"ingkblot" };
				String[] expected__ = { "kingkong", "knilngiggnngginggn",
						"dindong", "dingdont", "dingdong", "ingkblot",
						"ingkigningg" };
				
				return verifyCase(casenum, expected__,
						new TagalogDictionary().sortWords(words));
			}
			case 5: {
				String[] words = { "silangang", "baka", "bada", "silang" };
				String[] expected__ = { "baka", "bada", "silang", "silangang" };
				
				return verifyCase(casenum, expected__,
						new TagalogDictionary().sortWords(words));
			}
			
			// custom cases
			
			/*
			 * case 6: { String[] words = ; String[] expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * TagalogDictionary().sortWords(words)); }
			 */
			/*
			 * case 7: { String[] words = ; String[] expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * TagalogDictionary().sortWords(words)); }
			 */
			/*
			 * case 8: { String[] words = ; String[] expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * TagalogDictionary().sortWords(words)); }
			 */
			default:
				return -1;
		}
	}
}

// END CUT HERE
