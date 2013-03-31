public class allergy_jmv {
        private static final int K = 7, N = 20, MIN = K * N;
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		final int n = in.nextInt();
		int[] s = new int[n];
		for (int i = 0; i < s.length; i++)
		    s[i] = in.nextInt() - 1;
		int[][] D = new int[1 << n][K];
		for (int k = 0; k < K; k++)
		    D[0][k] = k;
		for (int i = 1; i < 1 << n; i++) {
		    java.util.Arrays.fill(D[i], MIN);
		    for (int j = 0; j < n; j++) {
			int ij = i ^ (1 << j);
			if (ij < i) {
			    for (int k = 0; k < K; k++) {
				int stub = Math.max(s[j] - k, 0);
				D[i][stub] = Math.min(D[ij][k] + stub, D[i][stub]);
			    }
			}
		    }
		}
		int min = MIN;
		for (int k = 0; k < K; k++)
		    min = Math.min(min, D[(1 << n) - 1][k]);
		System.out.println(min + n);
	}
}
