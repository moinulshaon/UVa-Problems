#include <bits/stdc++.h>

using namespace std;

#define SIZE 200100

int tree[5*SIZE];
int save[SIZE];
int mark[SIZE];
int ql,qr;

void build(int node,int l,int r){
    if(l==r){
        tree[node]=save[l];
        mark[l]=node;
    }
    else{
        build(2*node,l,(l+r)/2);
        build(2*node+1,(l+r)/2+1,r);

        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

int query(int node,int l,int r){
    if (r<ql || l>qr)return 0;
    else if (l>=ql && r<=qr)return tree[node];
    else{
        return query(2*node,l,(l+r)/2)+query(2*node+1,(l+r)/2+1,r);
    }
}
void update(int pos,int val){
    int node=mark[pos];

    tree[node]=val;
    node/=2;

    while (node>0){
        tree[node]=tree[2*node]+tree[2*node+1];
        node/=2;
    }
}


int main(){

    int n;
    for (int kk=1;;++kk){

        scanf("%d",&n);
        if (!n)return 0;

        if (kk==1)
            printf("Case %d:\n",kk);
        else
            printf("\nCase %d:\n",kk);


        for (int i=1;i<=n;++i)
            scanf("%d",&save[i]);

        build(1,1,n);

        char str[5];
        while (true){
            scanf("%s",str);
            if (str[0]=='E')
                break;
            else if (str[0]=='M'){
                scanf("%d %d",&ql,&qr);
                printf("%d\n",query(1,1,n));
            }
            else{
                int s,v;
                scanf("%d %d",&s,&v);
                update(s,v);
            }
        }


    }

    return 0;
}
