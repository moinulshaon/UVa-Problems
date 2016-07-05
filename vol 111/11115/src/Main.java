import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input=new Scanner(System.in);
		
		while (true){
			String a=input.next();
			int b=input.nextInt();
			if (a.equals("0") && b==0)
				break;
			BigInteger n1=new BigInteger(a);
			
			n1=n1.pow(b);
			System.out.println(n1);
		}
		
	}

}
