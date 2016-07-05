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

#define SIZE 4010

int n;
int a[SIZE],b[SIZE],c[SIZE],d[SIZE];
int up[SIZE*SIZE];
int down[SIZE*SIZE];

pint rr1[SIZE*SIZE];
pint rr2[SIZE*SIZE];

int main(){

    //FRO

    int kase;
    scanf("%d",&kase);

    while (kase--){
        scanf("%d",&n);

        for (int i=0;i<n;++i){
            scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
        }

        int len1=0;
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                up[len1++]= a[i]+b[j];
            }
        }


        int len2=0;
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                down[len2++]= -c[i]-d[j];
            }
        }

        sort( up,up+len1 );
        sort( down,down+len2 );

        int xx=0;
        for (int i=0;i<len1;++i){
            if ( i==0 ){
                rr1[ xx ].first=up[ i ];
                rr1[ xx++ ].second= 1;
            }else{
                if ( up[i] == up[i-1] ){
                    rr1[ xx-1 ].second++;
                }else{
                    rr1[ xx ].first=up[ i ];
                    rr1[ xx++ ].second= 1;
                }
            }
        }

        int yy = 0;
        for (int i=0;i<len2;++i){
            if ( i==0 ){
                rr2[ yy ].first=down[ i ];
                rr2[ yy++ ].second= 1;
            }else{
                if ( down[i] == down[i-1] ){
                    rr2[ yy-1 ].second++;
                }else{
                    rr2[ yy ].first=down[ i ];
                    rr2[ yy++ ].second= 1;
                }
            }
        }

        //cout<<xx<<' '<<yy<<endl;

        int p1=0,p2=0;
        LL ans=0;
        while ( p1<xx && p2<yy  ){
            if ( rr1[p1].first == rr2[p2].first ){
                ans+= rr1[p1].second * rr2[p2].second;
                p1++;
            }else if ( rr1[p1].first > rr2[p2].first ){
                p2++;
            }else{
                p1++;
            }
            //cout<<rr1[p1].first<<' '<<rr2[p2].first<<endl;
        }

        printf("%lld\n",ans);

        if ( kase )printf("\n");
    }


    return 0;
}
