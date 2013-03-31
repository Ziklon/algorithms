import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Double.*;

public class BettingStrategy{
	public int finalSum(int initSum, String outcome){
		int n=1,dev=initSum;
		for(int i=0;i<outcome.length()&&dev>=n;i++){
			if(outcome.charAt(i)=='W'){
				dev+=n;
				n=1;
			}else{
				dev-=n;
				n*=2;			
			}		
		}
		return dev;		
	}
	//Powered by [Ziklon]

}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
