import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Double.*;
import static java.util.Collections.*;

public class TheLuckyNumbersLevelOne {
	private HashSet<Long> hs=new HashSet<Long>();
	private long low,higth;
	private void dfs(long n){
		if(n>higth)return;
		if(n>=low && n<=higth)hs.add(n);
		dfs(n*10+4);
		dfs(n*10+7);
	} 
	public boolean isPal(long n){
		StringBuilder sb=new StringBuilder(n+"");
		return sb.reverse().toString().equals(n+"");
	}
	public long find(long a, long b) {
		low=a;
		higth=b;
		dfs(0);
		long dev=0;
		for(long cur : hs){
			if(isPal(cur))
				dev++;
		}
		return dev;	
   	}
   	//Powered by [Ziklon]
}


// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
