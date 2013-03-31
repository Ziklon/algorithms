import java.io.File;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		int n, k;
		BigInteger f1, f2, f3;
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		k = in.nextInt();
		f1 = new BigInteger(k - 1 + "");
		f2 = f1.multiply(new BigInteger(k+""));
		for(int i=3;i<n;i++){
			f3=(f1.add(f2)).multiply(new BigInteger(k-1+""));
			f1=f2;
			f2=f3;			
		}
		System.out.println(f2);
	}

}
