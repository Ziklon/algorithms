public class playfair_jmv {
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		String key = in.nextLine();
		String msg = in.nextLine();
		final int n = msg.length();
		int[][] pos = new int[25][];
		char[][] tab = new char[5][5];
		int x = -1, y = -1;
		for (int i = 0; i < key.length(); i++) {
			int c = c2i(key.charAt(i));
			if (c < 0 || c >= 25 || pos[c] != null)
				continue;
			y += (x = (x + 1) % 5) == 0 ? 1 : 0;
			pos[c] = new int[]{y, x};
		}
		for (int i = 0; i < 25; i++)
			if (pos[i] == null) {
				y += (x = (x + 1) % 5) == 0 ? 1 : 0;
				pos[i] = new int[]{y, x};
			}
		for (int i = 0; i < 25; i++) 
			tab[pos[i][0]][pos[i][1]] = i2c(i);

		String res = "";
		for (int i = 0; i < n; ) {
			int a = -1, b = -1;
			while (i < n && (a < 0 || a >= 25))
				a = c2i(msg.charAt(i++));
			while (i < n && (b < 0 || b >= 25))
				b = c2i(msg.charAt(i++));
			if (a == -1) break;
			if (b == -1) b = 22;
			else if (a == b) {b = 22; i--;}
			int ax = pos[a][1], ay = pos[a][0], bx = pos[b][1], by = pos[b][0];
			if (ay == by) {
				ax = (ax + 1) % 5;
				bx = (bx + 1) % 5;
			}
			else if (ax == bx) {
				ay = (ay + 1) % 5;
				by = (by + 1) % 5;
			}
			else {
				int t = ax;
				ax = bx;
				bx = t;
			}
			res += tab[ay][ax] + "" + tab[by][bx];
		}
		System.out.println(res.toUpperCase());
	}

	private static int c2i(char c) {
		return c - 'a' - (c > 'q' ? 1 : 0);
	}

	private static char i2c(int i) {
		return (char) (i + 'a' + (i + 'a' >= 'q' ? 1 : 0));
	}
}
