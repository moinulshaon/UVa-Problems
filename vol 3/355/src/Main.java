import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	
	public static void main(String []args)
	{
		Scanner input=new Scanner(System.in);
		
		while (input.hasNext())
		{
			int nowBase=input.nextInt();
			int toBase=input.nextInt();;
			String num=input.next();
			
			String result=new String("0");
			
			boolean can=true;
			
			try
			{
				long tmp=Long.valueOf(num, nowBase);
				result=new String(Long.toString(tmp, toBase));
			}
			catch  ( NumberFormatException e)
			{
				can=false;
			}
			
			num=num.toUpperCase();
			result=result.toUpperCase();
			
			if (can)
				System.out.printf("%s base %d = %s base %d\n",num,nowBase,result,toBase);
			else 
				System.out.printf("%s is an illegal base %d number\n",num,nowBase);	
		}
	}
	
}
