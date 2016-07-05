import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	
	public static BigInteger gcd(BigInteger a,BigInteger b)
	{
	    BigInteger temp=new BigInteger(a.toString());
	    while (!b.equals(BigInteger.ZERO))
	    {
	        temp=b;
	        b=a.mod(b);
	        a=temp;
	    }
	    return temp;

	}

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int kase;
		String cc;
		Scanner input=new Scanner(System.in);
		kase=input.nextInt();
		
		for (int i=0;i<kase;++i){
			BigInteger a=input.nextBigInteger();
			cc=input.next();
			BigInteger b=input.nextBigInteger();
			
			BigInteger d=gcd(a,b);
			
			System.out.println(a.divide(d)+" / "+b.divide(d));
		}
	}

}
