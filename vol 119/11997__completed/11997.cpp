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

#define SIZE 800

vector<int> arr,tmp;

int n;

struct node{
    int ind , val;
    node(int x=0,int y=0){
        ind= x,val=y;
    }
    bool operator<(const node&a)const{
        return val>a.val;
    }
};

int main(){
    FRO


    while ( scanf("%d",&n)==1  ){


        arr.clear();
        arr.resize(n);

        tmp.clear();
        tmp.resize(n);

        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }

        sort( arr.begin(),arr.end() );

        for (int i=1;i<n;++i){

            for (int j=0;j<n;++j){
                scanf("%d",&tmp[j]);
            }
            sort( tmp.begin(),tmp.end() );

            //cout<<"shaon "<<tmp[0]<<endl;

            priority_queue<node> q;

            for (int j=0;j<n;++j){
                q.push( node( 0,arr[j]+tmp[0] ) );
            }

            vector<int> shaon;
            for (int j=0;j<n;++j){
                node x = q.top();q.pop();

                //cout<<x.val<<endl;

                shaon.PB( x.val );

                if ( x.ind+1<n ){
                    q.push( node( x.ind+1 ,x.val - tmp[x.ind] + tmp[x.ind+1] ) );
                }
            }
            for (int j=0;j<n;++j){
                arr[j]= shaon[j];
            }
        }

        for (int i=0;i<n;++i){
            if ( i )printf(" ");
            printf("%d",arr[i]);
        }printf("\n");


    }


    return 0;
}
