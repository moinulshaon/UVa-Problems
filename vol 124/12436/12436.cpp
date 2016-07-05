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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;


#define SIZE 250001

struct node{
    LL val,sum;
    int left,right;
}tree[7*SIZE];
int arr[SIZE];


node merge( node x,node y ){
    node tmp;
    tmp.val=x.val+y.val+( x.right-x.left+1 )*y.sum;
    tmp.sum=x.sum+y.sum;
    tmp.left=x.left;
    tmp.right=y.right;
    return tmp;
}

void build( int num ,int le,int ri){
    //printf("%d\n",num);
    tree[num].left=le;
    tree[num].right=ri;
    if ( le==ri ){
        tree[num].val=tree[num].sum=arr[le];
    }else{
        build(2*num,le,(le+ri)/2);
        build(2*num+1, (le+ri)/2+1,ri);
        tree[num]=merge(tree[2*num],tree[2*num+1]);
    }
}

LL lazy1[7*SIZE];

void change1(int x){
    LL width=(tree[x].right-tree[x].left+1);
    tree[x].sum+=width*lazy[x];
    tree[x].val+= width*(width+1)/2*lazy[x];
}

node query( int num,int ql,int qr ){
    //printf("%d %d %d\n",num,tree[num].left,tree[num].right);
    if ( lazy[num] ){
        lazy[2*num]+= lazy[num] ;
        lazy[2*num+1]+= lazy[num] ;
        change(num);
        lazy[num]=0;
    }


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

void update1(int num,int ul,int ur,int vv){
    //printf("%d %d %d %d %d %d\n",l,r,lazy[node],tree[node].zero,tree[node].one,tree[node].two);
    if ( lazy1[num] ){
        lazy1[2*num]+= lazy1[num] ;
        lazy1[2*num+1]+= lazy1[num]+( tree[2*num].right- tree[2*num].left+1 ) + 1 ;
        change1(num);
        lazy1[num]=0;
    }

    if (tree[num].right  <ul || tree[num].left>ur)return ;
    else if (tree[num].left>=ul && tree[num].right <=ur){
        lazy1[num]=vv;
        change1(num);
        lazy1[num]=0;
        lazy1[2*num]+= vv ;
        lazy1[2*num+1]+= vv+( tree[2*num].right- tree[2*num].left+1 ) + 1 ;
    }else{
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

        while (num){
            tree[num]=merge( tree[2*num],tree[2*num+1] );
            num/=2;
        }

    }
}


int main(){
    FRO
    int len;
    int kase;
    while ( scanf("%d",&kase)==1 ){
        CLR(lazy);
        CLR(arr);

        build(1,1,len);

        char ssss[10];

        while( kase--  ){
            int left,right,id,vv;

            scanf("%s",ssss);

            if ( ssss[0]== 'A' ){
                scanf("%d %d",&left,&right);
                update1( 1,left,right,1 )
            }else {
                scanf("%d %d",&left,&right);
                printf("%lld\n",query(1,left,right).val);
            }
        }
    }

    return 0;
}

