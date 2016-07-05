#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define X first
#define Y second
#define MP make_pair

pint win[100100];

pint mm[100100];

struct tt{
    int ind,num;
    int ans ;
}ans[ 100100 ];

bool cmp ( const tt&a,const tt&b ){
    return a.ind<b.ind;
}
int n,m;
int cnt ;

int score(int x,int ind){

    //cout<<cnt<<" "<<x<<" "<<ind<<' '<<mm[x].X<<' '<<mm[x].Y<<endl;

    if ( x>=cnt ){
        return INT_MIN;
    }else if ( ind>=mm[x].X && ind<=mm[x].Y ){
        //cout<<"shaon\n";
        return min( ind - mm[x].X,mm[x].Y - ind );
    }else{
        return 0;
    }

}

bool ccc ( const tt&a,const tt&b ){
    return a.num<b.num;
}
bool sss ( const pint&a,const pint&b ){
    if ( a.X != b.X ) return a.X<b.X;
    else return a.Y>b.Y;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for ( int kk=1;kase--;++kk ){


        scanf("%d %d",&n,&m);

        for (int i=0;i<n;++i){
            scanf("%d %d",&win[i].X,&win[i].Y);
        }
        for (int i=0;i<m;++i){
            scanf("%d",&ans[i].ind);
            ans[i].num= i;
            ans[i].ans = 0;
        }


        sort( win,win+n, sss );

        cnt = 0;
        int lim = win[0].Y;
        mm[ cnt++ ] = win[0];
        for (int i=0;i<n;++i){
            if ( win[i].Y > lim ){
                mm[ cnt++ ] = win[i];
                lim=win[i].Y;
            }
        }

        sort( ans,ans+m  , cmp );

        //cout<<score( 1,9 )<<endl;


        int le = 0,save;
        for (int i=0;i<m;){
            //cout<<le<<' '<<i<<' '<<score( le,ans[i].ind )<<endl;
            save=score( le,ans[i].ind );
            if (  save == 0 ){
                if ( mm[le].Y < ans[i].ind && le+1<cnt ){
                    le++;
                    continue;
                }
            }

            if ( score( le+1,ans[i].ind ) > save ){
                le++;
            }else{
                ans[ i ].ans = save;
                //cout<<ans[i].ind<<' '<<ans[i].ans<<' '<<le<<endl;;
                i++;
            }

        }

        sort( ans,ans+m, ccc  );
        printf("Case %d:\n",kk);
        for (int i=0;i<m;++i){
            printf("%d\n",ans[i].ans);
        }

    }


    return 0;
}
