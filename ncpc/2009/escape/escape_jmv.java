public class escape_jmv {
	private static final int MAXN = 100;
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		int n = in.nextInt(), m = in.nextInt(), e = in.nextInt(), s = 0;
		boolean[] ex = new boolean[n];
		int[][] g = new int[n][n];
		for (int i = 0; i < n; i++)
			java.util.Arrays.fill(g[i], -1);
		for (int i = 0; i < m; i++) {
			int k = in.nextInt() - 1, l = in.nextInt() - 1;
			int d = in.nextInt();
			if (g[k][l] < d && g[k][l] >= 0) continue;
			s += g[k][l] = g[l][k] = d;
		}
		for (int i = 0; i < e; i++)
			ex[in.nextInt() - 1] = true;
		int b = in.nextInt() - 1;
		int p = in.nextInt() - 1;

		int[] P = dist(p, g);
		double l = 0, h = s, k = h / 2;
		if (!escape(b, g, h, P, ex))
			System.out.println("IMPOSSIBLE");
		else { 
			while (h - l > 1e-9) {
				if (escape(b, g, k, P, ex)) h = k;
				else l = k;
				k = (l + h) / 2;
			}
			System.out.printf("%f\n", k * 160);
		}
	}

	public static int[] dist(int from, int[][] g) {
		int[] dist = new int[g.length];
		java.util.Arrays.fill(dist, Integer.MAX_VALUE);
		java.util.PriorityQueue<Pair> q = new java.util.PriorityQueue<Pair>();
		Pair[] m = new Pair[g.length];
		m[from] = new Pair(0, from);
		dist[from] = 0;
		q.add(m[from]);
		while (!q.isEmpty()) {
			Pair p = q.poll();
			dist[p.id] = p.p;
			for (int i = 0; i < g.length; i++) {
				int d = g[p.id][i];
				if (d >= 0) {
					if (m[i] == null) {
						m[i] = new Pair(p.p + d, i);
						q.add(m[i]);
					}
					else if (p.p + d < m[i].p) {
						q.remove(m[i]);
						m[i].p = p.p + d;
						q.add(m[i]);
					}
				}
			}
		}
		return dist;
	}

	public static boolean escape(int from, int[][] g, double s, int[] pdist, boolean[] e) {
		int[] dist = new int[g.length];
		java.util.Arrays.fill(dist, Integer.MAX_VALUE);
		java.util.PriorityQueue<Pair> q = new java.util.PriorityQueue<Pair>();
		Pair[] m = new Pair[g.length];
		m[from] = new Pair(0, from);
		dist[from] = 0;
		q.add(m[from]);
		while (!q.isEmpty()) {
			Pair p = q.poll();
			if (p.p > pdist[p.id] * s) {
				p.p = -1;
				continue;
			}
			dist[p.id] = p.p;
			if (e[p.id]) 
				return true;
			for (int i = 0; i < g.length; i++) {
				int d = g[p.id][i];
				if (d >= 0 && (m[i] == null || m[i].p >= 0)) {
					if (m[i] == null) {
						q.add(m[i] = new Pair(p.p + d, i));
					}
					else if (p.p + d < m[i].p) {
						q.remove(m[i]);
						m[i].p = p.p + d;
						q.add(m[i]);
					}
				}
			}
		}
		return false;
	}

	public static class Pair implements Comparable<Pair> {
		int p, id;

		public Pair(int p, int id) {
			this.p = p;
			this.id = id;
		}

		public int compareTo(Pair p) {
		    return this.p == p.p ? this.id - p.id : this.p - p.p;
		}
	}
}
