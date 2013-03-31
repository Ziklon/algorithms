import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Ziklon
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task solver = new Task();
		solver.solve(1, in, out);
		out.close();
	}
}

class Task {


    public int get(int N, int B, int A[]) {
        int ans = 0;
        while (N > 0) {
            ans += A[N % B];
            N /= B;
        }
        return ans;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int T = in.nextInt();
        int B[] = new int[38];
        int Q;
        for (int i = 0; i < T; i++) {
            for (int j = 0; j < 36; j++) B[j] = in.nextInt();
            Q = in.nextInt();
            out.printf("Case %d:\n", i + 1);
            for (int j = 0; j < Q; j++) {
                int N = in.nextInt();
                int mini = 1 << 30;
                for (int k = 2; k <= 36; k++) {
                    mini = Math.min(mini, get(N, k, B));
                }
                out.printf("Cheapest base(s) for number %d:", N);
                for (int k = 2; k <= 36; k++) {
                    if (mini == get(N, k, B))
                        out.printf(" %d", k);
                }
                out.println();
            }
            if(i+1<T)out.println();
        }

    }
}

class InputReader {

    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }


}

