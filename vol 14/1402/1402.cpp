#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct ttt{
    int zero,one,two;
    ttt operator + ( const ttt & b){
        ttt tmp;
        tmp.zero=zero+b.zero;
        tmp.one=one+b.one;
        tmp.two=two+b.two;
        return tmp;
    }
}tree[600001],zz;
int lazy[600001];

void build(int node,int l,int r){
    if(l==r){
        tree[node].zero=1;
        tree[node].one=0;
        tree[node].two=0;
    }
    else{
        build(2*node,l,(l+r)/2);
        build(2*node+1,(l+r)/2+1,r);

        tree[node].zero=tree[2*node].zero+tree[2*node+1].zero;
        tree[node].one=tree[node].two=0;
    }
}

void change(int x){
    swap( tree[x].zero,tree[x].one );
    swap( tree[x].zero,tree[x].two );
}


int ql,qr;
ttt query(int node,int l,int r){
    if (r<ql || l>qr)return zz;
    else if ( lazy[node] ){
        lazy[2*node]= (lazy[2*node]+lazy[node])%3 ;
        lazy[2*node+1]= (lazy[2*node+1]+lazy[node])%3 ;
        while ( lazy[node]-- )
            change(node);
        lazy[node]=0;
    }

    if (l>=ql && r<=qr)return tree[node];
    else{
        return query(2*node,l,(l+r)/2)+query(2*node+1,(l+r)/2+1,r);
    }
}

int ul,ur;
void update(int node,int l,int r){
    //printf("%d %d %d %d %d %d\n",l,r,lazy[node],tree[node].zero,tree[node].one,tree[node].two);
    if ( lazy[node] ){
        lazy[2*node]= (lazy[2*node]+lazy[node])%3 ;
        lazy[2*node+1]= (lazy[2*node+1]+lazy[node])%3 ;

        while ( lazy[node]-- )
            change(node);
        lazy[node]=0;
        //printf("now value %d %d %d %d %d\n",l,r,tree[node].zero,tree[node].one,tree[node].two);
    }

    if (r<ul || l>ur)return ;
    else if (l>=ul && r<=ur){
        change(node);
        lazy[2*node]= (lazy[2*node]+1)%3 ;
        lazy[2*node+1]= (lazy[2*node+1]+1)%3 ;
    }else{
        update(2*node,l,(l+r)/2);
        update(2*node+1,(l+r)/2+1,r);

        while (node){
            tree[node]=tree[2*node]+tree[2*node+1];
            node/=2;
        }

    }
}

int main(){
    freopen("in.txt","r",stdin);
    int kase,leaf,q,a,b,c;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&leaf,&q);

        memset(lazy,0,sizeof(lazy));
        memset(tree,0,sizeof(tree));

        build(1,1,leaf);

        printf("Case %d:\n",kk);
        while (q--){
            scanf("%d %d %d",&a,&b,&c);
            if ( a ){
                ql=b+1;
                qr=c+1;
                printf("%d\n",query(1,1,leaf).zero);
            }else{
                ul=b+1;
                ur=c+1;
                update(1,1,leaf);
            }
        }
    }
    return 0;
}

