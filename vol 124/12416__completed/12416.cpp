#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

char str[1000100];

int func(int x){

    if ( x==0||x==1 )return 0;
    else if ( x==2 )return 1;
    else return int( ceil( log2(x)-1e-6 )+1e-6 ) ;

}

int main(){

    //freopen("in.txt","r",stdin);

    while ( gets(str) ){
        int len=strlen(str);
        int ans=0,cnt=0;
        for (int i=0;i<len;++i){

            if ( str[i]==' ' ){
                ++cnt;
            }else{
                ans=max( ans,func(cnt) );
                cnt=0;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
