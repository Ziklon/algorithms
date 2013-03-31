import java.util.LinkedList;

public class flight_jmv {
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		int n = in.nextInt();
		int[] neighborcount = new int[n];
		LinkedList<Integer>[] neighbors = new LinkedList[n];
		int[][] nbs = new int[n][];
		for (int i = 0; i < neighbors.length; i++)
			neighbors[i] = new LinkedList<Integer>();
		int[][] edges = new int[n - 1][];
		for (int i = 0, k, l; i < n - 1; i++) {
			k = in.nextInt() - 1;
			l = in.nextInt() - 1;
			edges[i] = new int[]{k, l};
			neighborcount[k]++;
			neighborcount[l]++;
			neighbors[k].add(l);
			neighbors[l].add(k);
		}
		for (int i = 0; i < n; i++) {
			nbs[i] = new int[neighbors[i].size()];
			int k = 0;
			for (Integer j : neighbors[i])
				nbs[i][k++] = j;
		}

		int best = widthAndMid(neighborcount.clone(), nbs, new int[]{-1, -1}).poll()[0];
		int[][] bestSwap = null;
		for (int[] edge : edges) {	//Remove each edge to form two components, and check best merge of these.  
			neighborcount[edge[0]]--;
			neighborcount[edge[1]]--;
			//neighbors[edge[0]].remove(new Integer(edge[1]));
			//neighbors[edge[1]].remove(new Integer(edge[0]));

			LinkedList<int[]> res = widthAndMid(neighborcount.clone(), nbs, edge);
			//Width is max of width of each component and of the sum of half the width (rounded up) of each + joining edge.  
			int width = Math.max(Math.max(res.get(0)[0], res.get(1)[0]), (res.get(0)[0] + 1) / 2 + (res.get(1)[0] + 1) / 2 + 1);
			if (width < best) {
				best = width;
				bestSwap = new int[][]{edge, new int[]{res.get(0)[1], res.get(1)[1]}};
			}

			neighborcount[edge[0]]++;
			neighborcount[edge[1]]++;
			//neighbors[edge[0]].add(edge[1]);
			//neighbors[edge[1]].add(edge[0]);
		}
		if (bestSwap != null) {
			System.out.println(best);
			System.out.println((bestSwap[0][0] + 1) + " " + (bestSwap[0][1] + 1));
			System.out.println((bestSwap[1][0] + 1) + " " + (bestSwap[1][1] + 1));
		}
		else System.out.println("no improvement");
	}

	//Returns width and midpoint of each component of the given graph, as a list of such pairs. 
	//Uses a topological sort to find the midpoint. Finding the width is also easy this way. 
	static LinkedList<int[]> widthAndMid(int[] neighborcount, int[][] neighbors, int[] f) {
		LinkedList<int[]> res = new LinkedList<int[]>();		//Stores result pairs.
		int[] level = new int[neighborcount.length];			//Length of longest path away from midpoint.
		java.util.Arrays.fill(level, -1);
		IntArrayQueue queue = new IntArrayQueue(neighborcount.length);
		for (int m = 0; m < neighborcount.length; m++) {
			if (neighborcount[m] == 1) {						//Add leaf nodes.
				queue.add(m);
				level[m] = 0;
			}
			else if (neighborcount[m] == 0) {					//Node is a component on its own.
				res.add(new int[]{0, m});
			}
		}
		while (!queue.isEmpty()) {
			int n = queue.poll();
			for (int m : neighbors[n]) {
				if (n == f[0] && m == f[1] || m == f[0] && n == f[1]) continue;
				if (level[m] == -1 || level[m] >= level[n]) {	//m is not queued, or the last node left.
					neighborcount[m]--;
					if (neighborcount[m] > 0) {
						if (neighborcount[m] == 1) {			//m is ready to be added to queue.
							level[m] = level[n] + 1;
							queue.add(m);
						}
					}
					else if (neighborcount[m] == 0) {			//m is the last node left, and therefore a midpoint.
						queue.remove(m); 
						res.add(new int[]{level[m] + level[n] + 1, m});	 
					}
				}
			}
		}
		return res;
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