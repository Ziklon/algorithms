import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class NetworkXOneTimePad
{
	public int crack(String[] plaintexts, String[] ciphertexts)
	{
		long[] in=parse(plaintexts);
		long[] out=parse(ciphertexts);
		int ans=0;
		for(long cur : in){
			long key=cur^out[0];
			boolean ok=true;
			for(long na : out){
				if(Arrays.binarySearch(in,(key^na))<0)
					ok=false;
			}
			if(ok)ans++;
		}
		return ans;
		
	}
	private long[] parse(String[] as){
		long ans[]=new long[as.length];
		int index=0;
		for(String cur : as)
			ans[index++]=Long.parseLong(cur,2);
		Arrays.sort(ans);
		return ans;			
	}
	
	

}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
