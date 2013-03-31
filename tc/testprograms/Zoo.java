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

import static java.util.Collections.*;

public class Zoo {
	public long theCount(int[] answers) {
		long dev=0;
		int[] A=new int[55];
		for(int cur : answers)A[cur]++;
		if(A[0]>2)return 0;
		for(int i=1;i<55;i++){
			if(A[i]>2)return 0;
			if(A[i]>A[i-1])return 0;				
		}
		int two=0,one=0;
		for(int i=0;i<55;i++){
			if(A[i]==2)two++;
			if(A[i]==1)one++;
		}
		dev=1L<<two;
		if(one!=0)dev*=2;
		
		return dev;	
   	}
   	//Powered by [Ziklon]
}


// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
