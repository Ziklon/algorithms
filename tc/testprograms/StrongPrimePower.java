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

public class StrongPrimePower {
   private boolean isPrime(long n){
       if(n<=1)return false;
       if(n==2)return true;
       if(n%2==0)return false;
       for(long i=3;i*i<=n;i+=2)
           if(n%i==0)return false;
       return true;
   }
   public int[] baseAndExponent(String n) {
	int[] dev;
        int c;
        long m= Long.parseLong(n),a,b;
        for(int i=2;i<70;i++){
            b=(long)pow(m, 1.0/i);
            for(long j=b-30;j<b+30;j++){
                if(isPrime(j)){
                    a=j;
                    c=1;
                    while(a*j<=m){
                        c++;
                        a*=j;
                    }
                    if(a==m && c>1)
                        return new int[]{(int)j,c};
                }
             
            }
        }
	return new int[]{};	
   }
   //Powered by [Ziklon]
}


// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
