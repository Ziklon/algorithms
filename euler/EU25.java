import java.math.BigInteger;


public class EU25 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		BigInteger numeros[]=new BigInteger[3];
		numeros[0]=BigInteger.ONE;
		numeros[1]=BigInteger.ONE;
		int index=1,count=2;
		while(numeros[index].toString().length()<1000){
			index=(index+1)%3;
			numeros[index]=numeros[(index+2)%3].add(numeros[(index+1)%3]);
			count++;			
		}
		System.out.println(count);
		

	}

}
