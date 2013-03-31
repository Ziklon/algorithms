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

public class AvoidRoads {
   public long numWays(int width, int height, String[] bad) {
		long dp[][]=new long[110][110];
		sort(bad);
		dp[0][0]=1;
		for(int i=0;i<=height;i++)
			for(int j=0;j<=width;j++){
				if(i>0 && check(bad,j,i,j,i-1))dp[i][j]+=dp[i-1][j];
				if(j>0 && check(bad,j,i,j-1,i))dp[i][j]+=dp[i][j-1];
			}
		return dp[height][width];
   }
   private boolean check(String[] bad,int a, int b, int c, int d){
	   String sa=a+" "+b+" "+c+" "+d;
	   String sb=c+" "+d+" "+a+" "+b;
	   return (binarySearch(bad, sa)<0 && binarySearch(bad, sb)<0);
   }
}


// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
