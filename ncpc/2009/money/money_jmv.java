import java.util.LinkedList;

public class money_jmv {
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		int n = in.nextInt(), m = in.nextInt();
		boolean[] done = new boolean[n];
		int[] debts = new int[n];
		LinkedList<Integer>[] graph = new LinkedList[n];
		for (int i = 0; i < n; i++) { 
			debts[i] = in.nextInt();
			graph[i] = new LinkedList<Integer>();
		}
		for (int i = 0; i < m; i++) {
			int j = in.nextInt(), k = in.nextInt();
			graph[j].add(k);
			graph[k].add(j);
		}
		boolean ok = true;
		for (int i = 0; i < n && ok; i++)
			ok = sum(i, debts, graph, done) == 0;
		System.out.println(ok ? "POSSIBLE" : "IMPOSSIBLE");
	}

	public static int sum(int i, int[] debts, LinkedList<Integer>[] graph, boolean[] done) {
		if (done[i]) return 0;
		int sum = debts[i];
		done[i] = true;
		for (int j : graph[i]) 
			sum += sum(j, debts, graph, done);
		return sum;
	}
}
