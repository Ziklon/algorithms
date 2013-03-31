// BEGIN CUT HERE
// PROBLEM STATEMENT
// Short message service (SMS) has become a fast and quick method for communication. Most 
// service providers place a restriction on the size of messages and hence it is important 
// to write concise messages. Mobile phone users have found methods for compressing their 
// messages such that the content of the messages remains unaltered. One such method is to 
// take the original message and remove all interior vowels from each word. A vowel is 
// interior if there is at least one consonant to the left and right (not necessarily 
// adjacent) of the vowel in the same word.
// 
// Given a String originalMessage with words separated by spaces return the compressed 
// version of the message.
// 
// 
// DEFINITION
// Class:SMS
// Method:compress
// Parameters:String
// Returns:String
// Method signature:String compress(String originalMessage)
// 
// 
// NOTES
// -Vowels are 'a', 'e', 'i', 'o' and 'u' (in both upper and lower cases).
// 
// 
// CONSTRAINTS
// -originalMessage will contain between 0 and 50 characters inclusive.
// -originalMessage will contain only letters ('a'-'z', 'A'-'Z') and spaces.
// 
// 
// EXAMPLES
// 
// 0)
// "Lets meet tomorrow"
// 
// Returns: "Lts mt tmrrw"
// 
// "Lets" becomes "Lts". "meet" becomes "mt". "tomorrow" becomes "tmrrw".
// 
// 1)
// "Please come to my party"
// 
// Returns: "Plse cme to my prty"
// 
// Note that vowels on the end of words are not compressed.
// 
// 2)
// " I  like your   style "
// 
// Returns: " I  lke yr   style "
// 
// Note that 'y' is always considered a consonant in this problem.
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

public class SMS {
	
	
	String vowel="aeiou";
	
	boolean isVowel(char c){
		c=Character.toLowerCase(c);
		return vowel.indexOf(c)>=0;		
	}
	String removeVowel(String s){
		if(s.length()==1)return s;
		String ans="";
		String left="";
		int i=0,j=s.length()-1;
		while(i<s.length() && isVowel(s.charAt(i))){
				ans+=s.charAt(i);
				i++;
		}
		while(j>i && isVowel(s.charAt(j))){
			left=s.charAt(j)+left;
			j--;
		}
		for(;i<=j;i++)if(!isVowel(s.charAt(i)))ans+=s.charAt(i);
		
		return ans+left;
	}
	
	boolean isAlpha(char c){
		//return (c>='a'&& c<='z') ||( c>='A'&&c<='Z');
		return Character.isLetter(c);
	}
	
	
	
	public String compress(String originalMessage) {
		String ans="";
		for(int i=0;i<originalMessage.length();i++){
			if(originalMessage.charAt(i)==' '){
				ans+=originalMessage.charAt(i);		
			}else{
				int j=i;
				while(j<originalMessage.length() && isAlpha(originalMessage.charAt(j)))j++;
				ans+=removeVowel(originalMessage.substring(i, j));
				i=j-1;
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
			SMSHarness.run_test(-1);
		} else {
			for (int i = 0; i < args.length; ++i)
				SMSHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class SMSHarness {
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
				String originalMessage = "Lets meet tomorrow";
				String expected__ = "Lts mt tmrrw";
				
				return verifyCase(casenum, expected__,
						new SMS().compress(originalMessage));
			}
			case 1: {
				String originalMessage = "Please come to my party";
				String expected__ = "Plse cme to my prty";
				
				return verifyCase(casenum, expected__,
						new SMS().compress(originalMessage));
			}
			case 2: {
				String originalMessage = " I  like your   style ";
				String expected__ = " I  lke yr   style ";
				
				return verifyCase(casenum, expected__,
						new SMS().compress(originalMessage));
			}
			
			// custom cases
			
			/*
			 * case 3: { String originalMessage = ; String expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * SMS().compress(originalMessage)); }
			 */
			/*
			 * case 4: { String originalMessage = ; String expected__ = ;
			 * 
			 * return verifyCase(casenum, expected__, new
			 * SMS().compress(originalMessage)); }
			 */
			
			  case 5: { String originalMessage ="aaaa"; String expected__ ="aaaa" ;
			
			  return verifyCase(casenum, expected__, new
			 SMS().compress(originalMessage)); }
			 
			default:
				return -1;
		}
	}
}

// END CUT HERE
