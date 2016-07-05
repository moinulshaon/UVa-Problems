import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input=new Scanner(System.in);
		
		while (input.hasNext())
		{
			String str=input.next();
			int base;
			for (base=2;base<=64;++base)
			{
				try{
					int k=Integer.parseInt(str, base);
					//System.out.println(k);
					if ( k%(base-1)==0)
					break;
				}
				catch (NumberFormatException e) {
					;
					// TODO: handle exception
				}
				
			}
			if (base<=64)
				System.out.printf("%d\n", base);
			else
				System.out.printf("such number is impossible!\n");
			
		}
	}

}
