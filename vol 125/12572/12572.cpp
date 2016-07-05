#include <cstdio>
#include <algorithm>

using namespace std;

int tree[100001];
char save[100001];
int total;
int ql,qr;

void build(int node,int l,int r)
{
    if(l==r){
        tree[node]=save[l]-'0';
    }
    else{
        build(2*node,l,(l+r)/2);
        build(2*node+1,(l+r)/2+1,r);

        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}

int query(int node,int l,int r)
{
    if (r<ql || l>qr)return 0;
    else if (l>=ql && r<=qr)return tree[node];
    else
    {
        return query(2*node,l,(l+r)/2)+query(2*node+1,(l+r)/2+1,r);
    }
}


int main(){
    freopen("in.txt","r",stdin);

    int leaf;
    while (scanf("%d",&leaf)==1){
        total=2*leaf-1;


    }
}
