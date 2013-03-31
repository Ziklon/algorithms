import java.util.ArrayList;
import java.util.TreeSet;
import java.util.Comparator;

public class beacons_jmv {
	private static final Thingy MIN = new Thingy(-4.0, 1 << 31), MAX = new Thingy(4.0, 1 << 31 - 1),
	LOW = new Thingy(1 << 31 + 1), HIGH = new Thingy(1 << 31 - 2);
	private static final Comparator<Thingy> acomp = new Comparator<Thingy>() {
		public int compare(Thingy a, Thingy b) {
			return a.a == b.a ? a.id - b.id : a.a < b.a ? -1 : 1;
		}
	}, dcomp = new Comparator<Thingy>() {
		public int compare(Thingy a, Thingy b) {
			return (int) Math.signum(a.d - b.d);
		}
	};

	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		int n = in.nextInt(), m = in.nextInt();
		int[][] nodes = new int[n][], circles = new int[m][];
		Thingy[] cs = new Thingy[circles.length], ns = new Thingy[nodes.length];
		boolean[] done = new boolean[n];
		int components = 0;
		for (int i = 0; i < n; i++)
			nodes[i] = new int[]{in.nextInt(), in.nextInt()};
		for (int i = 0; i < m; i++)
			circles[i] = new int[]{in.nextInt(), in.nextInt(), in.nextInt()};
		for (int i = 0; i < cs.length; i++)
			cs[i] = new Thingy(-i - 1);
		for (int i = 0; i < ns.length; i++)
			ns[i] = new Thingy(i);

		IntArrayQueue q = new IntArrayQueue(1000);
		for (int x = 0; x < n; x++) {
			if (!done[x]) {
				q.add(x);
				done[x] = true;
				while (!q.isEmpty()) {
					int i = q.poll();
					TreeSet<Thingy> nss = new TreeSet<Thingy>(acomp);
					for (int k = 0; k < cs.length; k++)
						cs[k].setData(circles[k][0] - nodes[i][0], circles[k][1] - nodes[i][1], circles[k][2]);
					for (int k = 0; k < nodes.length; k++) 
						if (!done[k]) {
							ns[k].setData(nodes[k][0] - nodes[i][0], nodes[k][1] - nodes[i][1]);
							nss.add(ns[k]);
						}
					java.util.Arrays.sort(cs, dcomp);
					double dist = 0;
					for (Thingy c : cs) {
						dist = c.d;
						LOW.a = c.a;
						HIGH.a = c.b;
						ArrayList<Thingy> l = new ArrayList<Thingy>();
						if (c.a < c.b) {
							for (Thingy t : nss.subSet(LOW, HIGH)) {
								if (t.d < dist && !done[t.id]) {
									q.add(t.id);
									done[t.id] = true;
								}
								l.add(t);
							}
						}
						else {
							for (Thingy t : nss.subSet(MIN, HIGH)) {
								if (t.d < dist && !done[t.id]) {
									q.add(t.id);
									done[t.id] = true;
								}
								l.add(t);
							}
							for (Thingy t : nss.subSet(LOW, MAX)) {
								if (t.d < dist && !done[t.id]) {
									q.add(t.id);
									done[t.id] = true;
								}
								l.add(t);
							}
						}
						nss.removeAll(l);
						if (nss.isEmpty()) break;
					}
					for (Thingy t : nss) { 
						q.add(t.id);
						done[t.id] = true;
					}
				}
				components++;
			}
		}

		System.out.println(components - 1);
	}

	public static double angle(double x, double y) {
		if (y == 0) return x > 0 ? 0 : Math.PI;
		return Math.acos(x / Math.sqrt(x * x + y * y)) * Math.signum(y);
	}

	private static class Thingy {
		private double d, a, b;
		private final int id;

		private Thingy(int id) {
			this.id = id;
		}

		private Thingy(double a, int id) {
			this.a = a;
			this.id = id;
		}

		private void setData(int x, int y, int r) {
			d = Math.sqrt(x * x + y * y - r * r);
			double th = angle(x, y);
			double ph = angle(d, r);
			a = th - ph;
			if (a <= -Math.PI) a += 2 * Math.PI;
			b = th + ph;
			if (b > Math.PI) b -= 2 * Math.PI;
		}

		private void setData(int x, int y) {
			d = Math.sqrt(x * x + y * y);
			a = angle(x, y);
		}
	}

	static class IntArrayQueue {
		private final int[] es;
		private final int c;
		private int l, h, s;

		public IntArrayQueue(int capacity) {
			es = new int[capacity];
			c = capacity;
			l = h = c - 1;
		}

		public void add(int e) {
			h = (++h) % c;
			es[h] = e;
			s++;
		}

		public int poll() {
			l = (++l) % c;
			s--;
			return es[l];
		}

		public int pop() {
			int res = es[h];
			h = (--h + c) % c;
			s--;
			return res;
		}

		public boolean isEmpty() {
			return s == 0;
		}

		public int size() {
			return s;
		}

		public void remove(int e) {
			int i = l;
			while ((i = (++i) % c) != h)
				if (es[i] == e) break;
			if (es[i] != e) throw new RuntimeException(e + " was not present in the list.");
			while (i != h) {
				es[i] = es[(i = (++i) % c)];
			}
			h = (--h + c) % c;
			s--;
		}
	}
}