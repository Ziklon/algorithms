public class rain_jmv {
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		double L = in.nextDouble(), K = in.nextDouble(), 
		    T1 = in.nextDouble(), T2 = in.nextDouble(), H = in.nextDouble();
		if (K == 0) {System.out.println(H + " " + H); return;}
		double a = K, b = -K * (T1 + T2) - H, c = L * T1, 
		    T0 = (-b - Math.sqrt(b * b - 4 * a * c)) / (2 * a), D = K * (T1 + T2 - T0), 
		    min = H + (H <= L ? 0 : D), max = H + (H < L ? 0 : D);
		System.out.println(min + " " + max);
	}
}