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

map<string,int> mp;

int ans [10];

queue<int> q[10];

string arr[]={"","Ja","Sam","Sha","Sid","Tan"};

int main(){

    int kase;
    scanf("%d",&kase);

    mp[ "Ja" ] = 1;
    mp[ "Sam" ] = 2;
    mp[ "Sha" ] = 3;
    mp[ "Sid" ] = 4;
    mp[ "Tan" ] = 5;


    for (int kk=1;kase--;++kk){
        int m,n;
        string str;

        scanf("%d %d",&m,&n);
        cin>>str;
        int now = mp[str];

        for (int i=0;i<10;++i){
            ans[i] = 0;
            while ( q[i].size() )
                q[i].pop();
        }

        int xx ;
        for (int i=1;i<=5;++i){
            scanf("%d",&xx);
            while ( xx-- ){
                cin>>str;
                q[i].push( mp[str] );
            }
        }

        int cnt = 0;
        for (int i=1;i<=n;++i){
            ans[now]++;
            cnt++;
            if ( cnt == m ){
                int tmp= q[ now ].front();
                q[now].pop();
                q[now].push( tmp );
                now = tmp;
                cnt = 0;
                i+= 2;
            }
        }

        printf("Case %d:\n",kk);
        for (int i=1;i<=5;++i){
            cout<<arr[i]<<" "<<ans[i]<<endl;
        }


    }


    return 0;
}
