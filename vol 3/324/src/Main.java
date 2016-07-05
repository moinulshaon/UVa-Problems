import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner input=new Scanner(System.in);
		
		BigInteger [] x=new BigInteger[367];
		
		x[0]=new BigInteger("1");
		
		
		for (int i=1;i<367;++i)
			x[i]=new BigInteger("0");
		
		for (int i=1;i<367;++i)
			for (int j=0;j<i;++j)
				x[i]=x[i].add(x[i-1]);
		
		while (true)
		{
			int n=input.nextInt();
			if (n==0)break;
			
			String str=x[n].toString();
			int cnt[]={0,0,0,0,0,0,0,0,0,0};
			
			for (int i=0;i<str.length();++i)
			{
				++cnt[ Character.digit(str.charAt(i), 10) ];
			}
			System.out.printf("%d! --\n", n);
			for (int i=0;i<5;++i)
			{
				System.out.printf("   (%d)%5d", i,cnt[i]);
			}
			System.out.println();
			for (int i=5;i<10;++i)
			{
				System.out.printf("   (%d)%5d", i,cnt[i]);
			}
			System.out.println();
		}
		
	}

}
