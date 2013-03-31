

/**
 *
 * @author Ziklon
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Double.*;
import static java.util.Collections.*;

public class WastedTime implements Runnable {
    private void solve() throws IOException {
      int n,k,x,y,a,b;
      
      n=nextInt();
      k=nextInt();
      x=nextInt();
	  y=nextInt();
	  double dis=0;
      for(int i=1;i<n;i++){
    	 a=nextInt();
    	 b=nextInt();
    	 dis+=hypot(x-a, y-b);
    	 x=a;
    	 y=b;
      }
      dis=(dis*k)/50.0;
      writer.println(String.format("%.9f", dis));
    }

    public static void main(String[] args) {
        new WastedTime().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}
