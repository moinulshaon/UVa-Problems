#include <cstdio>
#include <cstring>

using namespace std;

int tree[60000100];
bool poster[10000100];

int ql,qr;
void query(int node,int l,int r){
    //printf("%d %d %d %d\n",node,tree[node],l,r);
    //getchar();
    if (r<ql || l>qr  )return ;
    else{
        if ( tree[node] ){
            poster[ tree[node] ]=true;
            return ;
        }
        if ( (l+r)/2 != r )
            query(2*node,l,(l+r)/2);
        if ( (l+r)/2+1 != l )
            query(2*node+1,(l+r)/2+1,r);
    }
}

int ul,ur;
void update(int node,int l,int r,int color){
    //printf("%d %d %d %d\n",node,tree[node],l,r);
    if (r<ul || l>ur)return ;
    else if (l>=ul && r<=ur){
        tree[node]=color;
        //printf("%d %d %d %d\n",node,tree[node],l,r);
    }
    else {
        if ( tree[node] ){
            tree[2*node]=tree[node];
            tree[2*node+1]=tree[node];
            tree[node]=0;
        }



        update(2*node,l,(l+r)/2,color);
        update(2*node+1,(l+r)/2+1,r,color);
    }
}

int main(){


    int kase,leaf=10000000;;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){


        int n;
        scanf("%d",&n);
        memset(poster,false,sizeof(poster));
        memset(tree,0,sizeof(tree));

        for (int i=1;i <= n ;i++){
            scanf("%d %d",&ul,&ur);
            update(1,1,leaf,i);
            //printf("%d %d %d\n",tree[16],tree[8],tree[4]);
            //printf("\n");
        }
        ql=1;
        qr=leaf;
        query(1,1,leaf);
        leaf>>=1;
        int ans=0;
        for (int i=1;i<=leaf;++i ){
            if ( poster[i] ){
                //printf("%d\n",i);
                ++ans;
            }
        }
        printf("Case %d: %d\n",kk,ans);

    }
    return 0;
}
