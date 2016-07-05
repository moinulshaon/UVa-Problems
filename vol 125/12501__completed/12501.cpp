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


#define SIZE 110010

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

LL lazy[7*SIZE];

void change(int x){
    LL width=(tree[x].right-tree[x].left+1);
    tree[x].sum+=width*lazy[x];
    tree[x].val+= width*(width+1)/2*lazy[x];
}

node query( int num,int ql,int qr ){
    //printf("%d %d %d\n",num,tree[num].left,tree[num].right);
    if ( lazy[num] != 0 ){
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

void update(int num,int ul,int ur,int vv){
    //printf("%d %d %d %d %d %d\n",l,r,lazy[node],tree[node].zero,tree[node].one,tree[node].two);
    if ( lazy[num]!= 0 ){
        lazy[2*num]+= lazy[num] ;
        lazy[2*num+1]+= lazy[num] ;
        change(num);
        lazy[num]=0;
    }

    if (tree[num].right  <ul || tree[num].left>ur)return ;
    else if (tree[num].left>=ul && tree[num].right <=ur){
        lazy[num]=vv;
        change(num);
        lazy[num]=0;
        lazy[2*num]+= vv;
        lazy[2*num+1]+= vv ;
    }else{
        update(2*num,ul,ur,vv);
        update(2*num+1,ul,ur,vv);

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
    scanf("%d",&kase);
    for(int kk=1;kase--;++kk  ){
        printf("Case %d:\n",kk);
        int qq;
        scanf("%d %d",&len,&qq);
        for (int i=1;i<=len;++i){
            arr[i]=100;
        }
        CLR(lazy);

        build(1,1,len);
        //printf("shaon\n");
        int left,right,id,vv;
        char ssss[10];
        while(qq--){
            scanf("%s",ssss);

            if ( ssss[0]=='q' ){
                scanf("%d %d",&left,&right);
                printf("%lld\n", query(1,left,right).val );
            }else{
                scanf("%d %d %d",&left,&right,&vv);
                update(1,left,right,vv);
            }
        }

    }
    return 0;
}

