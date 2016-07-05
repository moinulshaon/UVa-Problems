#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    int n;
    int cc=1;
    while(scanf("%d",&n)==1 && n){
        int sum=0,tmp;
        for (int i=0;i<n;++i){
            scanf("%d",&tmp);
            sum+=tmp;
        }

        bool neg=false;
        if ( sum<0 ){
            neg=true;
        }

        int a=abs(sum/n);
        int b=abs(sum%n);
        int c=n;
        //printf("%d %d %d\n",a,b,c);




        printf("Case %d:\n",cc++);
        if ( b==0 ){
            if ( neg ){
                printf("- %d\n",a);
            }else{
                printf("%d\n",a);
            }
        }else{

            int dd=__gcd(b,c);
            b/=dd;
            c/=dd;


            char line[20];
            sprintf(line,"%d",c );
            int lenc=strlen(line);
            sprintf(line,"%d",b );
            int lenb=strlen(line);
            sprintf(line,"%d",a );
            int lena=strlen(line);

            if ( a==0 )lena=0;


            if ( neg ){
                printf("  ");
            }

            for (int i=0;i<lena;++i){
                printf(" ");
            }
            for (int i=0;i<lenc-lenb;++i){
                printf(" ");
            }
            printf("%d\n",b );


            //seconeline
            if ( neg ){
                printf("- ");
            }
            if ( a )
                printf("%d",a );
            for (int i=0;i<lenc;++i){
                printf("-");
            }
            printf("\n");

            //thirdline
            if ( neg ){
                printf("  ");
            }
            for (int i=0;i<lena;++i){
                printf(" ");
            }
            printf("%d\n",c );
        }
    }
    return 0;
}
