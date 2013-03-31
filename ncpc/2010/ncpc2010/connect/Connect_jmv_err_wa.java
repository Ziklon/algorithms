public class Connect_jmv_wa {
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		int X = in.nextInt(), Y = in.nextInt();
		Point a1 = new Point(in.nextInt() - 1, in.nextInt() - 1), 
			a2 = new Point(in.nextInt() - 1, in.nextInt() - 1), 
			b1 = new Point(in.nextInt() - 1, in.nextInt() - 1), 
			b2 = new Point(in.nextInt() - 1, in.nextInt() - 1); 

		if (a1.y > a2.y) swap(a1, a2);
		if (b1.y > b2.y) swap(b1, b2);
		if (a1.x > a2.x) swap(a1, a2);
		if (b1.x > b2.x) swap(b1, b2);
		if (a1.x > b1.x || (a1.x == b1.x && a1.y > b1.y)) {swap(a1, b1); swap(a2, b2);}
		if (b1.y > b2.y) swap(b1, b2);

		if ((a1.x == 0 && a1.y == 0 && b2.x == 0 && b2.y == 1 && b1.x == 1 && b1.y == 0) ||
			(a1.x == 0 && a1.y == Y - 2 && ((b2.x == 0 && b2.y == Y - 1) || (b1.x == 0 && b1.y == Y - 1)) && a2.x == 1 && a2.y == Y -1) ||
			(a1.x == X - 2 && a1.y == 0 && b1.x == X - 1 && b1.y == 0 && a2.x == X - 1 && a2.y == 1) ||
			(b1.x == X - 1 && b1.y == Y - 2 && b2.x == X - 2 && b2.y == Y - 1 && a2.x == X - 1 && a2.y == Y - 1) ||
		(a1.x + 1 == b1.x && a1.y == b1.y && a1.x == b2.x && a1.y + 1 == b2.y && a1.x + 1 == a2.x && a1.y + 1 == a2.y)) {
			System.out.println("IMPOSSIBLE");
			return;
		}

		if (onBorder(a1.x, a1.y, X, Y) && onBorder(a2.x, a2.y, X, Y) && onBorder(b1.x, b1.y, X, Y) && onBorder(b2.x, b2.y, X, Y)) {
			double a1a = angle(a1.x, a1.y, X, Y), a2a = angle(a2.x, a2.y, X, Y), b1a = angle(b1.x, b1.y, X, Y), b2a = angle(b2.x, b2.y, X, Y);
			if (a1a > a2a) {
				double t = a1a;
				a1a = a2a;
				a2a = t;
			}
			if (b1a > b2a) {
				double t = b1a;
				b1a = b2a;
				b2a = t;
			}
			if (a1a < b1a && b1a < a2a && a2a < b2a) {
				System.out.println("IMPOSSIBLE");
				return;
			}
			if (b1a < a2a && a1a < b2a && b2a < a2a) {
				System.out.println("IMPOSSIBLE");
				return;
			}
		}

		if ((a1.x == a2.x && a1.x == b1.x && a1.x == b2.x) || (a1.y == a2.y && a1.y == b1.y && a1.y == b2.y)) {
			System.out.println((a1.y < b1.y && b1.y < a2.y && a2.y < b2.y) || (a1.x < b1.x && b1.x < a2.x && a2.x < b2.x) ? 8 : 6);
			return;
		}

		int xe = 0 + a1.x == b1.x ? 1 : 0 + a1.x == a2.x ? 1 : 0 + a1.x == b2.x ? 1 : 0 + b1.x == a1.x ? 1 : 0 + b1.x == b2.x ? 1 : 0 + a2.x == b2.x ? 1 : 0,
			ye = 0 + a1.y == b1.y ? 1 : 0 + a1.y == a2.y ? 1 : 0 + a1.y == b2.y ? 1 : 0 + b1.y == a1.y ? 1 : 0 + b1.y == b2.y ? 1 : 0 + a2.y == b2.y ? 1 : 0;
		if ((a1.x <= b1.x && a1.x <= b2.x && a2.x >= b1.x && a2.x >= b2.x && a1.y >= b1.y && a1.y <= b2.y && a2.y >= b1.y && a2.y <= b2.y) ||
		xe >= 3 || ye >= 3) {
			int min = Integer.MAX_VALUE;
			min = Math.min(min, 2 + md(a1.x, a1.y, b1.x - 1, b1.y - 1, X, Y) + md(b1.x + 1, b1.y - 1, a2.x, a2.y, X, Y) + md(b1.x, b1.y, b2.x, b2.y, X, Y));
			min = Math.min(min, 2 + md(a1.x, a1.y, b2.x - 1, b2.y + 1, X, Y) + md(b2.x + 1, b2.y + 1, a2.x, a2.y, X, Y) + md(b1.x, b1.y, b2.x, b2.y, X, Y));
			min = Math.min(min, 2 + md(b1.x, b1.y, a1.x - 1, a1.y - 1, X, Y) + md(a1.x - 1, a1.y + 1, b2.x, b2.y, X, Y) + md(a1.x, a1.y, a2.x, a2.y, X, Y));
			min = Math.min(min, 2 + md(b1.x, b1.y, a2.x + 1, a2.y - 1, X, Y) + md(a2.x + 1, a2.y + 1, b2.x, b2.y, X, Y) + md(a1.x, a1.y, a2.x, a2.y, X, Y));
			System.out.println(min);
			return;

		}
		System.out.println(md(a1.x, a1.y, a2.x, a2.y, X, Y) + md(b1.x, b1.y, b2.x, b2.y, X, Y));
	}

	static void swap(Point a, Point b) {
		int t = a.x; a.x = b.x; b.x = t;
		t = a.y; a.y = b.y; b.y = t;
	}

	static boolean onBorder(int x, int y, int X, int Y) {
		return x == 0 || y == 0 || x == X - 1 || y == Y - 1;
	}

	static double angle(int x, int y, int X, int Y) {
		double cos = (x - X / 2)  / Math.sqrt((x - X / 2) * (x - X / 2) + (y - Y / 2) * (y - Y / 2));
		return Math.acos(cos) * Math.signum(Y / 2 - y + 0.5);
	}

	static int md(int rx, int ry, int sx, int sy, int X, int Y) {
		if (rx < 0 || rx >= X || ry < 0 || ry >= Y || sx < 0 || sx >= X || sy < 0 || sy >= Y) return Integer.MAX_VALUE / 4;
		return Math.abs(rx - sx) + Math.abs(ry - sy);
	}

	static class Point {
		int x, y;

		Point(int x, int y) {this.x = x; this.y = y;}
	}
}