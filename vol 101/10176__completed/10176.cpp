#include <cstdio>
#include <cstring>


int ans[17];
char line[11000];
int main(){
    //freopen("in.txt","r",stdin);

    ans[0]=1;
    for (int i=1;i<17;++i){
        ans[i]=2*ans[i-1];
    }
    int sum;
    char c=getchar();
    while ( true ){

        int len=0;
        while( c!='#' ){
            if ( c=='0' || c=='1' )
                line[len++]=c;
            c=getchar();
        }

        sum=0;
        for (int i=len-1;i>=0;--i){
            if ( line[i]=='1' ){
                sum=( sum+ans[i%17] )%131071;
            }
        }
        //printf("%d\n",sum);
        if ( sum ){
            printf("NO\n");
        }else{
            printf("YES\n");
        }

        while ( true ){
            c=getchar();
            if ( c==EOF )return 0;
            else if ( c=='1' || c=='0'||c=='#' )break;
        }
    }
    return 0;
}
