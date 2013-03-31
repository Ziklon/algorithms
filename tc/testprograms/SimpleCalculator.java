import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class SimpleCalculator
{
	public int calculate(String input)
	{
		char[] ch=input.toCharArray();
		String a="",b="";
		char op='a';
		for(int i=0;i<ch.length;i++){
			if((ch[i]=='+') || (ch[i]=='-') || (ch[i]=='/') || (ch[i]=='*')){
				op=ch[i];
				a=b;
				b="";
			}else{
				b+=ch[i];			
			}
			
		}
		System.out.println(a+" "+op+" "+b);
		int rpt=0;
		switch(op){
			case '+':
				rpt=Integer.parseInt(a)+Integer.parseInt(b);
				break;
			case '-':
				rpt=Integer.parseInt(a)-Integer.parseInt(b);
				break;
			case '*':
				rpt=Integer.parseInt(a)*Integer.parseInt(b);
				break;
			case '/':
				rpt=Integer.parseInt(a)/Integer.parseInt(b);
				break;
		}
		return rpt;
	}
	

}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
