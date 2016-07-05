import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	
	public static int face,sum,thr;
	
	public static BigInteger[][] dp;
	
	
	public static BigInteger DFS(int diceNo,int s){
		if (s==sum && diceNo==thr+1){
	        return BigInteger.ONE;
	    }else if (s>sum || diceNo>thr+1)return BigInteger.ZERO;
	    if ( dp[diceNo][s] != null){
	        return dp[diceNo][s];
	    }
	    BigInteger tmp=new BigInteger("0");
	    for (int i=1;i<=face;++i){
	        if (diceNo!=0)
	            tmp=tmp.add(  DFS(diceNo+1,s+i) );
	        else{
	            tmp=DFS(diceNo+1,s) ;
	            break;
	        }
	    }
	    return dp[diceNo][s]=tmp;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input=new Scanner(System.in);
		
		while (input.hasNext()){
			face=input.nextInt();
			thr=input.nextInt();
			sum=input.nextInt();
			
			dp=new BigInteger[60][4100];
			
			
			System.out.println(DFS(0,0)+"/"+new BigInteger(face+"").pow(thr));
		}
	}

}
