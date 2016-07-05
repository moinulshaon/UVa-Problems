import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner input=new Scanner(System.in);
		
		BigInteger fact[]=new BigInteger[1001];
		
		fact[0]=BigInteger.ONE;
		for (int i=1;i<1001;++i)
			fact[i]=fact[i-1].multiply( new BigInteger( i+"" ));
		
		String str[]=new String[1001] ;
		int cnt[]=new int[1001];
		
		
		
		for (int i=0;i<1001;++i)
			str[i]=fact[i].toString();
		for (int i=0;i<1001;++i)
		{
			for (int j=0; j<str[i].length(); ++j)
			{
				cnt[i]+=Character.getNumericValue( str[i].charAt(j) );
			}
		}
		
		while (input.hasNext())
		{
			int n=input.nextInt();
			
			System.out.println(cnt[n]);
		}
		
	}
}
