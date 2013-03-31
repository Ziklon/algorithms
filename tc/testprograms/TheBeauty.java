import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Double.*;

public class TheBeauty{
	public int find(int n){
		HashSet<Integer> st=new HashSet<Integer>();
		while(n>0){
		  st.add(n%10);
		  n/=10;
		}
		return st.size();		
	}
	//Powered by [Ziklon]
	
}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
