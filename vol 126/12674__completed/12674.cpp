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
#include <stack>

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
    int val;
    int left,right;
}tree[7*SIZE];
int arr[SIZE];


node merge( node x,node y ){
    node tmp;
    tmp.val = min( x.val, y.val );

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

int n;
int toLeft[SIZE],toRight[SIZE];


void calcLeft(){
    arr[0] = INT_MAX;
    stack<int> stk;
    stk.push( 0 );

    for (int i=1;i<=n;++i){
        while ( arr[stk.top()] <= arr[i]  ){
            stk.pop();
        }
        toLeft[i] = stk.top();
        stk.push(i);
    }
}

void calcRight(){
    arr[n+1] = INT_MAX;
    stack<int> stk;
    stk.push( n+1 );

    for (int i=n;i>0;--i){
        while ( arr[stk.top()] <= arr[i]  ){
            stk.pop();
        }
        toRight[i] = stk.top();
        stk.push(i);
    }
}


int lim =150000;

int main(){

    FRO

    while ( scanf("%d",&n)==1 ){
        for (int i=1;i<=n;++i){
            scanf("%d",&arr[i]);
        }

        build(1,1,n);

        calcLeft();
        calcRight();

        vector<int> ans;
        for (int i=1;i<=n;++i){
            if ( toLeft[i] == 0 && toRight[i] == n+1 ){
                if ( arr[i]>= lim  ){
                    ans.PB( i );
                }
                continue;
            }

            int tmp = INT_MAX;
            if ( toLeft[i] != 0 ){
                tmp = min( tmp , arr[i]-query(1,toLeft[i]+1,i).val );
            }
            if ( toRight[i] != n+1 ){
                tmp = min( tmp , arr[i]-query(1,i,toRight[i]-1).val );
            }
            if ( tmp>= lim  ){
                ans.PB( i );
            }
        }
/*
        for (int i=0;i<ans.size();++i){
            if ( i )printf(" ");
            printf("%d",ans[i]);
        }printf("\n");*/

    }

    return 0;
}
