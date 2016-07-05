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
    int len;
    int left,right;
}tree[7*SIZE];

int mark[SIZE];
LL prime;
LL power[SIZE];

node merge( node x,node y ){
    node tmp;

    tmp.val= ( y.val +  x.val * power[ y.len ] )%prime ;

    tmp.left=x.left;
    tmp.right=y.right;

    tmp.len = x.len + y.len;

    return tmp;
}

void build( int num ,int le,int ri){

    tree[num].left=le;
    tree[num].right=ri;
    if ( le==ri ){
        mark[le]=num;
        tree[num].val=0;
        tree[num].len = 1;
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
void update(int pos,int val){
    int pp=mark[pos];

    tree[pp].val=val%prime;

    pp/=2;

    while (pp){
        tree[pp]=merge(tree[2*pp],tree[2*pp+1]);
        pp/=2;
    }
}


int main(){

    FRO

    LL b;
    int n;
    int qq;

    while ( scanf("%lld %lld %d %d",&b,&prime,&n,&qq) == 4 ){
        if ( b+prime+n+qq == 0 )break;

        power[0] = 1;
        for (int i=1;i<=n;++i){
            power[i] = ( power[i-1]* b )%prime;
        }

        build(1,1,n);


        char tmp[5];
        int x,y;
        while ( qq-- ){
            scanf("%s %d %d",tmp,&x,&y);
            if ( tmp[0] == 'E' ){
                update( x,y );
            }else{
                printf("%lld\n",query(1,x,y).val%prime);
            }
        }
        printf("-\n");
    }


    return 0;
}
