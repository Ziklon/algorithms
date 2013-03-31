import java.util.*;
import java.io.*;

public class playfair_mg 
{
    static final String ALPH = "abcdefghijklmnoprstuvwxyz";
    static Scanner in = new Scanner(System.in);
    
    String squash(String s) 
    {
	StringBuffer b = new StringBuffer();
	for (int i=0; i < s.length(); ++i) {
	    char c = s.charAt(i);
	    if (ALPH.indexOf(c) >= 0)
		b.append(c);
	}
	return b.toString();
    }

    String x(String s) 
    {
	StringBuffer b = new StringBuffer();
	char [] c1 = s.toCharArray();	
	for (int i=0; i < c1.length; ++i) {
	    if ((b.length()&1)==1 && c1[i] == c1[i-1])
		b.append('x');
	    b.append(c1[i]);
	}
	if ((b.length() & 1) == 1) b.append('x');	
	return b.toString();
    }
    
    void solve() 
    {
	char[] key = (squash(in.nextLine()) + ALPH).toCharArray();
	String p = x(squash(in.nextLine()));
	int[] plain = new int[p.length()];
	for (int i = 0; i < plain.length; ++i)
	    plain[i] = ALPH.indexOf(p.charAt(i));
	int[][] board = new int[5][5];
	int j = 0;
	int[] row = new int[25];
	int[] col = new int[25];
	for (int i=0; i < key.length; ++i) {
	    if (key[i] != ' ') {
		board[j/5][j%5] = ALPH.indexOf(key[i]);
		row[board[j/5][j%5]] = j/5;
		col[board[j/5][j%5]] = j%5;
		++j;
		for (int k = i+1; k < key.length; ++k)
		    if (key[k] == key[i]) key[k] = ' ';
	    }
	}
	
	StringBuffer sb = new StringBuffer();
	for (int i = 0; i < plain.length; i += 2) {
	    int a,b;	    
	    if (row[plain[i]] == row[plain[i+1]]) {
		a = board[row[plain[i]]][(col[plain[i]]+1)%5];
		b = board[row[plain[i+1]]][(col[plain[i+1]]+1)%5];
	    }
	    else if (col[plain[i]] == col[plain[i+1]]) {
		a = board[(row[plain[i]]+1)%5][col[plain[i]]];
		b = board[(row[plain[i+1]]+1)%5][col[plain[i+1]]];
	    }
	    else {
		a = board[row[plain[i]]][col[plain[i+1]]];
		b = board[row[plain[i+1]]][col[plain[i]]];		
	    }
	    sb.append(ALPH.charAt(a));
	    sb.append(ALPH.charAt(b));
	}
	System.out.println(sb.toString().toUpperCase());	
    }
    public static void main(String[] s) 
    {
	new playfair_mg().solve();
    }
    
}

