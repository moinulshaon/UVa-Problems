import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

/**
 * Created by moinulislam on 8/11/16.
 */
public class Main {

    public static void main( String[]args ){

       MyScanner input = new MyScanner();

        String str;
        while ( ( str=input.nextLine() )!= null && str.length() != 0 ){


            //System.out.println(str);

            long ans = 0;

            for ( int i=0;i<str.length();++i ){

                if ( !Character.isDigit( str.charAt(i) ) ){
                    continue;
                }

                int []cnt = new int[3];
                cnt[0]++;

                int j=i;
                int sum = 0;
                while ( j<str.length() && Character.isDigit( str.charAt(j) ) ){
                    int tmp = str.charAt(j) - '0';

                    sum += tmp;
                    sum %= 3;
                    ans += cnt[sum];

                    cnt[sum]++;
                    ++j;
                }
                i=j;

            }

            System.out.println(ans);
        }

    }
    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }
}

