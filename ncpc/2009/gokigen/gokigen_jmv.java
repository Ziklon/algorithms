public class gokigen_jmv {
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		int n = in.nextInt();
		in.nextLine();
		int[][] c = new int[n+1][n+1];
		boolean[][] b = new boolean[n][n];
		for (int i = 0; i <= n; i++) {
		    String s = in.nextLine().trim();
		    for (int j = 0; j <= n; j++)	//Fill in constraints. 10 means no contraint. 
			c[i][j] = s.charAt(j) == '.' ? 10 : s.charAt(j) - '0';
		}
		go(0, 0, c, b, n);
	}

	private static void go(int i, int j, int[][] c, boolean[][] b, int n) {
		if (i == n) {
			if (check(b, n))	
				print(b, n);
			return;
		}
		
		//Check backslash in position i, j.
		//Subtract from constraints. Valid moves keep constraints above 0. In addition, when
		//a square is the last to affect a constraint, that constraint must become exactly 0.
		//Or in case an intersection has no constraint, the value will always stay above 4.
		b[i][j] = true;
		c[i][j]--;
		c[i + 1][j + 1]--;
		if (	(c[i][j] == 0 || c[i][j] > 4) &&
				(c[i][j + 1] >= 0 && (c[i][j + 1] == 0 || c[i][j + 1] > 4 || j < n - 1)) &&
				(c[i + 1][j] >= 0 && (c[i + 1][j] == 0 || c[i + 1][j] > 4 || i < n - 1)) &&
				(c[i + 1][j + 1] >= 0 && (c[i + 1][j + 1] == 0 || c[i + 1][j + 1] > 4 || i < n - 1 || j < n - 1))
			) {
			if (j == n - 1)
				go(i + 1, 0, c, b, n);
			else 
				go(i, j + 1, c, b, n);
		}
		c[i][j]++;
		c[i + 1][j + 1]++;
		
		//Board restored, and now checking a slash at i, j.
		b[i][j] = false;
		c[i + 1][j]--;
		c[i][j + 1]--;
		if (	(c[i][j] == 0 || c[i][j] > 4) &&
				(c[i][j + 1] >= 0 && (c[i][j + 1] == 0 || c[i][j + 1] > 4 || j < n - 1)) &&
				(c[i + 1][j] >= 0 && (c[i + 1][j] == 0 || c[i + 1][j] > 4 || i < n - 1)) &&
				(c[i + 1][j + 1] >= 0 && (c[i + 1][j + 1] == 0 || c[i + 1][j + 1] > 4 || i < n - 1 || j < n - 1))
			) {
			if (j == n - 1)
				go(i + 1, 0, c, b, n);
			else 
				go(i, j + 1, c, b, n);
		}
		c[i + 1][j]++;
		c[i][j + 1]++;
	}

	private static boolean check(boolean[][] b, int n) {
		boolean[][] d = new boolean[n + 1][n + 1];
		for (int i = 0; i < n + 1; i++)
			for (int j = 0; j < n + 1; j++)
				if (!d[i][j] && !dfs(i, j, b, d, n))
					return false;
		return true;
	}

	private static boolean dfs(int i, int j, boolean[][] b, boolean[][] d, int n) {
		d[i][j] = true;								//i,j marked as done
		boolean f = false, ok = true;				//f denotes if parent (a seen node) has been found
		if (i > 0 && j > 0 && b[i - 1][j - 1]) {
			if (d[i - 1][j - 1]) f = true;
			else ok &= dfs(i - 1, j - 1, b, d, n);
		}
		if (ok && i < n && j < n && b[i][j]) {
			if (d[i + 1][j + 1]) {
				if (f) return false;				//If two neighbors are seen, we have a loop.
				else f = true;
			}
			else ok &= dfs(i + 1, j + 1, b, d, n);
		}
		if (ok && i > 0 && j < n && !b[i - 1][j]) {
			if (d[i - 1][j + 1]) {
				if (f) return false;
				else f = true;
			}
			else ok &= dfs(i - 1, j + 1, b, d, n);
		}
		if (ok && i < n && j > 0 && !b[i][j - 1]) {
			if (d[i + 1][j - 1]) {
				if (f) return false;
				else f = true;
			}
			else ok &= dfs(i + 1, j - 1, b, d, n);
		}
		return ok;
	}

	private static void print(boolean[][] b, int n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				System.out.print(b[i][j] ? '\\' : '/');
			System.out.println();
		}
	}
}
