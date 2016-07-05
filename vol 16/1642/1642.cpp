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

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;
#define SIZE 100010

struct node{
    LL val;
    int left,right;
}tree[7*SIZE];
LL arr[SIZE];

node merge( node x,node y ){
    node tmp;
    tmp.val= __gcd( x.val, y.val );

    tmp.left=x.left;
    tmp.right=y.right;

    return tmp;
}

void build( int num ,int le,int ri){
    //printf("%d\n",num);
    tree[num].left=le;
    tree[num].right=ri;
    if ( le==ri ){
        tree[num].val=arr[le];
    }else{
        build(2*num,le,(le+ri)/2);
        build(2*num+1, (le+ri)/2+1,ri);
        tree[num]=merge(tree[2*num],tree[2*num+1]);
    }
}

node query( int num,int ql,int qr ){
    //printf("%d %d %d\n",num,tree[num].left,tree[num].right);
    if ( ql <= tree[num].left && qr >= tree[num].right  )return tree[num];
    else{
        bool lon=false,ron=false;
        if (  ql<= tree[2*num].right )
            lon=true;
        if ( qr>= tree[2*num+1].left  )
            ron=true;
        if ( lon && ron ){
            return merge(query(2*num,ql,qr),query(2*num+1,ql,qr));
        }else if ( lon ){
            return query(2*num,ql,qr);
        }else if ( ron ){
            return query(2*num+1,ql,qr);
        }
    }
}

int main(){

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;++i){
            scanf("%lld",&arr[i]);
        }
        build(1,1,n);

        int low = 1,high = 0;
        while ( low<=n ){

            if (  )

        }

    }


    return 0;
}
