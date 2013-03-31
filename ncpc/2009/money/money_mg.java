import java.util.*;

public class money_mg 
{
    static Scanner in = new Scanner(System.in);    
    int[] o, p, r; /* owe, parent (Union Find), rank (Union Find) */

    public static void main(String[] a) 
    {
	System.out.println( new money_mg().run() ? "POSSIBLE" : "IMPOSSIBLE");
    }

    int find(int i) 
    {
	if (p[i] == i) return i;
	else  return p[i] = find(p[i]);
    }

    void link(int i, int j) 
    {
	if (r[i] < r[j]) link(j, i);
	else if (i != j) {
	    p[j] = i;
	    o[i] += o[j];
	    if (r[i] == r[j]) ++r[i];
	}
    }
    
    boolean run() 
    {
	int n = in.nextInt();
	int m = in.nextInt();
	o = new int[n];
	p = new int[n];
	r = new int[n];
	for (int i = 0; i < n; ++i) o[i] = in.nextInt();
	for (int i = 0; i < n; ++i) p[i] = i;
	for (int i = 0; i < n; ++i) r[i] = 0;	    
	for (int i = 0; i < m; ++i) link(find(in.nextInt()), find(in.nextInt()));
	for (int i = 0; i < n; ++i) if (p[i] == i && o[i] != 0) return false;
	return true;	
    }
}
