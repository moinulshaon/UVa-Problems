import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input=new Scanner( System.in );
		
		while (input.hasNext())
		{
			BigInteger t=new BigInteger( input.next() );
			int a=input.nextInt();
			int b=input.nextInt();
			
			BigInteger x=t.pow(a).subtract( BigInteger.ONE );
			BigInteger y=t.pow(b).subtract( BigInteger.ONE );
			
			String ss=x.divide(y).toString();
			if (x.mod(y).toString()=="0" && ss.length()<100)
			{
				System.out.printf("(%d^%d-1)/(%d^%d-1) %s\n", t,a,t,b,ss);
			}
			else
			{
				System.out.printf("(%d^%d-1)/(%d^%d-1) is not an integer with less than 100 digits.\n",t,a,t,b);
			}
		}
		
	}

}
