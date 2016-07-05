import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input=new Scanner(System.in ); 
		BigInteger[] x=new BigInteger[1001];
		
		x[0]=new BigInteger("1");
		for (int i=1;i<=1000;++i)
			x[i]=new BigInteger("0");
		
		for (int i=1;i<=1000;++i)
			for (int j=0;j<i;++j)
				x[i]=x[i].add(  x[i-1]  );
		
		
		while (input.hasNext() )
		{
			int n=input.nextInt();
			System.out.printf("%d!\n",n);
			System.out.println(x[n]);
		}
	}

}
