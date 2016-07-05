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

vector <int> edge[100];

struct node{
    int val,city;
    bool operator < (const node & p)const{return val<p.val;}
};


int func( char c ){
    if ( islower(c) )return c-'a';
    else return c-'A'+26;
}

int ff( int now,int city ){
    if ( city>=26 )return int( ceil( double(now)/20 )+1e-6 );
    else return 1;
}

int lim;
bool dijkstra(int s,int f,int cc){

    bool vis[100]={false};

    node place,temp,u;
    place.val=cc;
    place.city=s;

    priority_queue<node> q;

    q.push(place);


    while (!q.empty()){
        temp=q.top();q.pop();

        //cout<<temp.city<<' '<<temp.val<<endl;

        if ( temp.val<lim )return false;

        if (temp.city==f)return temp.val>=lim;

        if (vis[temp.city])
            continue;
        vis[temp.city]=true;




        for (int i=0;i<edge[temp.city].size();++i){
            u.city=edge[temp.city][i];
            u.val=temp.val-ff( temp.val, u.city );

            if ( !vis[ u.city ] )
                q.push(u);
        }
    }
    return false;
}


int main(){

    FRO

    int ee;
    char ss[5],sss[5];

    for (int kk=1; scanf("%d",&ee) == 1 && ee != -1 ;++kk ){

        for (int i=0;i<100;++i){
            edge[i].clear();
        }


        while ( ee-- ){
            scanf("%s %s",ss,sss);

            edge[ func( ss[0] ) ].PB( func( sss[0] ) );
            edge[ func( sss[0] ) ].PB( func( ss[0] ) );
        }

        scanf("%d %s %s",&lim,ss,sss);

        //cout<<ss[0]<<sss[0]<<endl;

        int a=func( ss[0] );
        int b=func( sss[0] );



        int ans=-1 ,low=0,high=(1<<12);

        while ( low<=high ){
            int mid=(low+high)/2;
            if ( dijkstra( a,b,mid ) ){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        printf("Case %d: %d\n",kk,ans);

    }



    return 0;
}
