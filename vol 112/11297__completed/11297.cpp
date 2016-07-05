#include <cstdio>
#include <climits>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int,int> ppi;

ppi treemain[501][3100];
int savemain[501][501];
int markmain[501][501];
int total;

int row,col;

int ql,qr;

void build(ppi tree[],int save[],int mark[],int node,int l,int r)
{
    if(l==r){
        tree[node]=make_pair( save[l] ,save[l] );
        mark[l]=node;
    }
    else{
        build(tree,save,mark,2*node,l,(l+r)/2);
        build(tree,save,mark,2*node+1,(l+r)/2+1,r);

        tree[node].first=max( tree[2*node].first ,tree[2*node+1].first );
        tree[node].second=min( tree[2*node].second ,tree[2*node+1].second );
    }
}

ppi zero=make_pair( INT_MIN,INT_MAX );

ppi query(ppi tree[],int node,int l,int r)
{
    if (r<ql || l>qr)return zero;
    else if (l>=ql && r<=qr)return tree[node];
    else
    {
        ppi xx=query(tree,2*node,l,(l+r)/2),yy=query(tree,2*node+1,(l+r)/2+1,r);
        return make_pair( max( xx.first ,yy.first ) ,min( xx.second ,yy.second )  ) ;
    }
}
void update(ppi tree[],int mark[],int pos,int val){
    int node=mark[pos];

    tree[node]=make_pair(val,val);
    node/=2;

    while (node)
    {
        tree[node].first=max( tree[2*node].first, tree[2*node+1].first) ;
        tree[node].second=min( tree[2*node].second, tree[2*node+1].second) ;
        node/=2;
    }
}


int main()
{

    freopen("in.txt","r",stdin);

    while (scanf("%d %d",&row,&col)==2){


        for (int i=1;i<=row;++i)
            for (int j=1;j<=col;++j)
                scanf("%d",&savemain[i][j]);
        for (int i=1;i<=row;++i)
            build(treemain[i],savemain[i], markmain[i], 1,1,col);

        char str[3];
        int qqq,r1,r2;
        scanf("%d",&qqq);
        while (qqq--){
            scanf("%s",str);

            if (str[0]=='q'){
                scanf("%d %d %d %d",&r1,&ql,&r2,&qr);
                ppi tmp,rr=make_pair( INT_MIN,INT_MAX );
                for (int i=r1;i<=r2;++i){
                    tmp=query( treemain[i], 1,1,col );
                    rr.first=max( rr.first ,tmp.first );
                    rr.second=min( rr.second ,tmp.second );
                }
                printf("%d %d\n",rr.first,rr.second);
            }
            else{
                int xx,yy,v;
                scanf("%d %d %d",&xx,&yy,&v);
                update(treemain[xx],markmain[xx],yy,v);
            }
        }
    }
    return 0;
}
