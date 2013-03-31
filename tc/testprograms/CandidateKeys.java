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

public class CandidateKeys {
   public int[] getKeys(String[] table) {
	   int nk=table[0].length();
	   int nv=table.length;
	   ArrayList<Integer> lis=new ArrayList<Integer>();
	   for(int i=1;i<(1<<nk);i++){
		   String aux[]=new String[nv];
		   Arrays.fill(aux, "");
		   for(int j=0;j<nk;j++){
			   if((i&(1<<j))!=0){
				   for(int k=0;k<nv;k++)
					   aux[k]+=table[k].charAt(j);
			   }
		   }
		   HashSet<String> hs=new HashSet<String>();
		   for(String s: aux)hs.add(s);
		   if(hs.size()==nv)lis.add(i);		   
	   }
	   if(lis.size()==0)return new int[]{}; 
	   int x=1,y=1;
	   
	   System.out.println();
	   for(int i=0;i<lis.size();i++)
		   for(int j=i+1;j<lis.size();j++){
			   String a=bits(lis.get(i));
			   String b=bits(lis.get(j));
			   boolean ok=true;
			   for(int k=0;k<min(a.length(),b.length());k++){
				   if(a.charAt(k)==b.charAt(k))
					   ok=false;
			   }
			   if(ok){
				   x=min(bitCount(lis.get(i)),bitCount(j));
				   y=max(bitCount(lis.get(i)),bitCount(j));
			   }
		   }
	   return new int[]{x,y};
   }
   String bits(int n){
	   StringBuffer res=new StringBuffer();
	   while(n>0){
		   res.append(n%2);
		   n/=2;
	   }
	   //res=res.reverse();
	   return res.toString();
   }
}


// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
