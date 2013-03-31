import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Collections;

public class allergy_mg {
    
    static class Pair implements Comparable<Pair> {
	int x,y;
	Pair(int x, int y) { this.x = x; this.y = y; }
	public int compareTo(Pair o) {
	    if (x == o.x) return y - o.y;
	    return x - o.x;
	}
    }

    static int next(int t) {
	// return next larger int with same hamming weight as t
	int b = t & (-t);
	int s = t/b + 1;
	int c = s & (-s);
	return s * b + c/2 - 1;
    }

    static int solve(int[] D) {
	int k = D.length;
	Arrays.sort(D);
	int end = 1<<k;
	ArrayList<Pair>[] tab = (ArrayList<Pair>[]) new ArrayList[end];
	for (int s = 0; s < end; ++s)
	    tab[s] = new ArrayList<Pair>();
	tab[0].add(new Pair(0,0));
	for (int j = 0; j < k; ++j)
	    tab[1<<j].add(new Pair(0, D[j]));
	for (int i = 2; i <= k; ++i) {
	    //System.err.println("Doing size " + i);
	    for (int s = (1<<i) - 1; s < end; s = next(s)) {
		boolean is_new = true;
		for (int j=1; is_new && j < k; ++j) {
		    if (D[j] == D[j-1]
			&& (((1<<j) & s) != 0)
			&& (((1<<(j-1)) & s) == 0)) {
			is_new = false;
			tab[s] = tab[s - (1<<j) + (1 << (j-1))];
		    }
		}
		if (! is_new) continue;
		ArrayList<Pair> tabs = new ArrayList<Pair>();
		int last_D = -1;
		for (int j = 0; j < k; ++j) {
		    if (((1<<j) & s) != 0) {
			if (last_D == D[j]) continue;
			int t = s - (1<<j);
			for (Iterator<Pair> pi = tab[t].iterator();
			     pi.hasNext(); ) {
			    Pair p = pi.next();
			    int ts = p.x;
			    int os = p.y;
			    int ns = Math.max(ts + 1 + D[j], os + 1);
			    tabs.add(new Pair(os, ns));
			}
			last_D = D[j];
		    }
		}
		Collections.sort(tabs);
		// prune tabs and put in tab[s]
		int last_y = 1<<30;
		for (Iterator<Pair> pi = tabs.iterator(); pi.hasNext(); ){
		    Pair p = pi.next();
		    if (last_y <= p.y) continue;
		    last_y = p.y;
		    tab[s].add(p);
		}
	    }
	}
	int res = 1 << 30;
	for (Iterator<Pair> pi = tab[end-1].iterator(); pi.hasNext(); )
	    res = Math.min(res, pi.next().y);
	return res;
    }
    
    static Scanner in = new Scanner(System.in);
    public static void main(String[] args) {
	int k = in.nextInt();
	int[] D = new int[k];
	for (int i=0; i < k; ++i) D[i] = in.nextInt();
	System.out.println(solve(D));
    }
}
