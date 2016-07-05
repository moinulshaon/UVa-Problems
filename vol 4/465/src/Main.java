import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Main {

    public static void main(String[] args) {
    	
    	int lim = 1001;
        int ans[] = new int[lim];
    	BigInteger now = new BigInteger("1");
        ans[0] = 1;
    	for (int i=1;i<lim;++i){
            now = now.multiply( new BigInteger( Integer.toString(i) ) );
            String tmp = now.toString();
            for (int j=0;j<tmp.length();++j){
            	ans[i] += (int) ( tmp.charAt(j)-'0' );
            }
        }
        
        Scanner in = new Scanner(System.in);
        int kase= in . nextInt();
        while ( kase-- >0 ){
        	int n = in.nextInt();
        	System.out.println(ans[n]);
        }
        
    }
}