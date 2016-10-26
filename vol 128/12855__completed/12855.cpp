#include<bits/stdc++.h>

using namespace std;

#define SIZE 5100

typedef long long LL;

char str[SIZE];
LL a,b;

LL suma[SIZE];
LL sumb[SIZE];

LL pre[SIZE];

LL func(int st,int en){

    while ( st<=en && str[st] == 'B' ){
        st++;
    }
    while ( en>=st && str[en] == 'W' ){
        en--;
    }
    //now st has W and en has B
    if ( st>en )return 0;

    LL ret = ( pre[en] - pre[st-1] ) - (  sumb[en]-sumb[st-1]  ) * ( suma[st-1] ) * (a-b);
    ret = min( ret , a+func(st+1,en-1) );

    return ret;
}


int main(){

    //freopen("in.txt","r",stdin);

    while ( scanf("%d %d",&a,&b) == 2 ){
        scanf("%s",&str[1]);

        int n = strlen(&str[1]);

        for (int i=1;i<=n;++i){
            suma[i] = suma[i-1];
            if ( str[i] == 'W' )suma[i]++;
        }
        for (int i=1;i<=n;++i){
            sumb[i] = sumb[i-1];
            if ( str[i] == 'B' )sumb[i]++;
        }

        LL ans = 0;
        for (int i=1;i<=n;++i){
            if ( str[i] == 'B' ){
                ans += suma[i]*(a-b);
            }
            pre[i] = ans;
        }
        //cout<<ans<<endl;

        ans = min( ans,func(1,n) );

        printf("%lld\n",ans);
    }


    return 0;
}
