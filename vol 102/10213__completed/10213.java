import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;



public class Main{

	public static void main(String []args) {

		Scanner input=new Scanner(System.in);

		int kase=input.nextInt();

		while(  kase-- != 0 ){
			BigInteger n=new BigInteger( input.next() );

			System.out.println(
					BigInteger.ONE.add(
						n.multiply(
							n.subtract(BigInteger.ONE)
						).multiply(
							n.multiply( n ).
							subtract(
								n.multiply( new BigInteger("5")  ) ).add(new BigInteger("18")  ) ) .divide(
													new BigInteger("24")
										)
							)
					);

		}

	}

}
