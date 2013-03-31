import java.util.ArrayList;

public class permutations_jmv {
	public static final int MAX = 100;
	public static final long[] fac = new long[MAX + 1];
	public static final long mod = (1 << 31) - 1;
	public static final java.util.HashMap<Long, Long> inv = new java.util.HashMap<Long, Long>();
	static {
		long f = fac[0] = 1;
		for (int i = 1; i < fac.length; fac[i] = f = (f * i++) % mod);
	}

	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		int n = in.nextInt(), k = in.nextInt();
		int[][][] d = divisors(k, n);
		System.out.println(k == 1 ? 1 : d == null ? 0 : countAll(n, k, 0, d[0], d[1], 0, 0, 1));
	}

	/* Recursively add up all permutations of order given by c: c[i][1] tells how many cycles of 
	 * length c[i][0] are present in the permutation, and all cycles not explicitly given by c are of length 1. 
	 * i is the index of the cycle-length to try adding. 
	 * f is a bitmask for checking which highest order prime powers are present in the current cycle-combination.
	 * s is the sum of all cycle-lengths in the current combination.  
	 * m gives an upper limit for the sum so far, determined by which factors are missing but reachable, and their minimal sum.   
	 * t is the number of permutations of the "calling combination". Since the number of permutations of each 
	 * cycle compbination is dependant on the number of combinations of the "caller" the number of permutations of the 
	 * current combination can be calculated quicker by using t than if we were to use the full formula each time.  
	 */
	private static long countAll(int n, int k, int i, int[][] c, int[][] m, int f, int s, long t) {
		if (i == c.length || s > m[i][f]) return 0;
		long res = countAll(n, k, i + 1, c, m, f, s, t);
		f |= c[i][2];
		while (true) {
			s += c[i][0];
			c[i][1]++;
			if (s > m[i][f]) break;
			long p = fac[n - s + c[i][0]];
			long q = (fac[n - s] * c[i][0] * c[i][1]) % mod;
			t = ((t * p) % mod * modinv(q)) % mod;
			if (f == m[0].length - 1) 
				res += t;
			res += countAll(n, k, i + 1, c, m, f, s, t);
		}
		c[i][1] = 0;
		return res % mod;
	}

	/* Returns an array r with divisors of k leq. n and an array m giving some constraints for the recursion.
	 *  
	 * r contains: 
	 * In descending order, all divisors of k leq. n. For each of these:
	 * An int slot used for counting the number of cycles of this length. 
	 * A bitmask telling which highest order prime powers are present in this divisor.
	 * 
	 * m is a calculation of the sum of necessary remaining prime power factors, indexed by:
	 * The largest of the prime powers left to choose from.
	 * The LCM of the prime powers chosen so far. 
	 * 
	 * k is first factored into prime powers, and these are then used to determine bitmasks for the 
	 * LCM calculations of the divisors. The divisors are constructed from the prime powers dividing k.  
	 */
	private static int[][][] divisors(int k, int n) { 
		ArrayList<int[]> l = new ArrayList<int[]>();	//l contains the prime divisors of k and their power.  
		for (int i = 2, s = 0; i <= n && k > 1; i++) {
			int p = 1, c = 0;
			while (k % i == 0) {
				k /= i;
				p *= i;
				c++;
			}
			if (c > 0) {
				if ((s += p) > n) return null;		//No solution  if the sum of the necessary prime powers exceeds n.
				l.add(new int[]{i, c});
			}
		}
		if (k > 1) return null;						//No solution if k has prime factors greater than n. 

		ArrayList<int[]> d = new ArrayList<int[]>();
		fillDivs(d, l, n, 0, 1, 0);
		int[][] r = new int[d.size()][];
		for (int i = 0; i < r.length; i++)
			r[i] = d.get(i);
		java.util.Arrays.sort(r, new java.util.Comparator<int[]>() {	//Sort r in descending order.
			public int compare(int[] a, int[] b) {return b[0] - a[0];}
		});

		int[][] m = new int[r.length + 1][1 << l.size()];
		for (int i = r.length + 1; --i >= 0; ) 
			java.util.Arrays.fill(m[i], -1);
		m[r.length][(1 << l.size()) - 1] = n;	//Maximal sum allowed when all prime powers are present is n.
		for (int i = r.length; --i >= 0; ) 
			for (int b = 0; b < 1 << l.size(); b++) 
				m[i][b] = Math.max(m[i + 1][b], m[i + 1][b | r[i][2]] - r[i][0]);

		return new int[][][]{r, m};
	}

	private static void fillDivs(ArrayList<int[]> d, ArrayList<int[]> l, int n, int i, int f, int b) {
		if (i == l.size()) {
			if (f != 1)
				d.add(new int[]{f, 0, b});	//f is a divisor of k, with primes of maximal power as given by b.
			return;
		}
		fillDivs(d, l, n, i + 1, f, b);
		int[] p = l.get(i);
		for (int j = 0; j < p[1]; j++) {	//Try f multiplied by p to the (j+1)-th power. 
			f *= p[0];
			if (f <= n)						//No point in continuing if f is greater than n. 
				fillDivs(d, l, n, i + 1, f, b | (j + 1 == p[1] ? 1 << i : 0));	//Update b when j is maximal. 
		}
	}

	/* Computes the multiplicative inverse of a modulo mod, i.e. a * modinv(a) = 1 (modulo mod).
	 * Uses a HashMap for storing and retrieving values that have already been calculated.
	 */
	public static long modinv(long a) {
		if (a == 0) System.err.println("DIV BY ZERO!");
		if (inv.containsKey(a)) return inv.get(a);
		long i = (modinv(a, mod, 1, 0) + mod) % mod;
		inv.put(a, i);
		return i;
	}

	private static long modinv(long a, long b, long x, long y) {
		if (a == 0) return y;
		return modinv(b % a, a, y - b / a * x, x);
	}
	
	/* Alternative way of computing the multiplicative inverse of a modulo mod. Slightly slower.
	 */
	public static long modinv2(long a) {
		if (a == 0) System.err.println("DIV BY ZERO!");
		if (inv.containsKey(a)) return inv.get(a);
		long i = 1, b = a;
		for (int j = 0; j < 32; j++) {
			if (((1 << j) & (mod - 2)) != 0)
				i = (i * b) % mod;
			b = (b * b) % mod;
		}
		inv.put(a, i);
		return i;
	}
}
