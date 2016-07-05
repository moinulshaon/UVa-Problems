import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input=new Scanner(System.in);
		
		BigInteger result[][]=new BigInteger[16][151];
		
		
		for (int i=0;i<16;++i)
			result[i][1]=new BigInteger( i+"");
		for (int i=0;i<16;++i)
		{
			for (int j=2;j<151;++j)
			{
				result[i][j]= result[i][j-1].add(  (result[i][1].pow( j ) ).multiply(new BigInteger(j+"") ) );
			}
		}
		
		while (input.hasNext())
		{
			int n=input.nextInt();
			int a=input.nextInt();
			
			System.out.println( result[a][n] );
		}
		
	}

}
