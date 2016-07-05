#include <cstdio>
#include <cstring>

using namespace std;

#define sz 4500000


int tree[sz];
char save[sz];
int mark[sz];
char lazy[sz];


const char LAZYONE=1;
const char LAZYZERO=2;
const char LAZYINVERSE=3;

void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=save[l]-'0';
        mark[l]=node;
    }
    else
    {
        build(2*node,l,(l+r)/2);
        build(2*node+1,(l+r)/2+1,r);

        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

int undoLazy( int node ,int l,int r){

    if ( lazy[node] ){

        if (lazy[node]==LAZYZERO){
            tree[node]=0;
            lazy[2*node]=LAZYZERO;
            lazy[2*node+1]=LAZYZERO;
        }else if (lazy[node]==LAZYONE){
            tree[node]=r-l+1;
            lazy[2*node]=LAZYONE;
            lazy[2*node+1]=LAZYONE;
        }else if ( lazy[node] == LAZYINVERSE ){
            tree[node]= r-l+1-tree[node];
            if ( lazy[2*node] == LAZYZERO )lazy[2*node]=LAZYONE;
            else if ( lazy[2*node] == LAZYONE )lazy[2*node]=LAZYZERO;
            else if ( lazy[2*node] == LAZYINVERSE )lazy[2*node]=0;
            else lazy[2*node]=LAZYINVERSE;

            if (lazy[2*node+1] == LAZYZERO)lazy[2*node+1]=LAZYONE;
            else if (lazy[2*node+1] == LAZYONE)lazy[2*node+1]=LAZYZERO;
            else if ( lazy[2*node+1] == LAZYINVERSE )lazy[2*node+1]=0;
            else lazy[2*node+1]=LAZYINVERSE;
        }
        lazy[node]=0;
    }

}



int ql,qr;
int query(int node,int l,int r)
{
    undoLazy(node,l,r);

    if (r<ql || l>qr)return 0;
    else if (l>=ql && r<=qr)return tree[node];
    else
    {
        return tree[node]=query(2*node,l,(l+r)/2)+query(2*node+1,(l+r)/2+1,r);
    }
}



int ul,ur;
void update(int node,int l,int r,char option)
{
    //printf("BEG %d %d %d %d %d\n",node,tree[node],l,r,option);

    undoLazy(node,l,r);

    if (r<ul || l>ur)return ;
    else if (l>=ul && r<=ur){
        if ( option==LAZYZERO ){
            lazy[node]=LAZYZERO;
            undoLazy(node,l,r);
        }else if ( option==LAZYONE ){
            lazy[node]=LAZYONE;
            //printf("%d %d %d\n",node,l,r);
            undoLazy(node,l,r);
        }else if ( option==LAZYINVERSE ){
            lazy[node]=LAZYINVERSE;
            undoLazy(node,l,r);
        }

    }
    else{
        update(2*node,l,(l+r)/2,option);
        update(2*node+1,(l+r)/2+1,r,option);

        tree[node]=tree[2*node]+tree[2*node+1];

    }
    //printf("END %d %d %d %d %d\n",node,tree[node],l,r,lazy[node]);

}


int main()
{

    //freopen("in.txt","r",stdin);

    int leaf;
    int kase,a,b;
    char ttt[100];
    scanf("%d",&kase);
    for (int kk=1;kase--;++kk){

        printf("Case %d:\n",kk);

        int leaf=0;

        scanf("%d",&a);
        while (a--){
            scanf("%d %s",&b,ttt);
            int tmp=strlen(ttt);
            for(int k = 0; k < b; ++k)
                for(int n = 0; n < tmp; ++n)
                    save[++leaf] = ttt[n];
        }

        save[leaf+1]='\0';

        //printf("%s\n",&save[1]);

        memset(lazy,0,sizeof(lazy));

        build(1,1,leaf);

        char str[3];
        scanf("%d",&a);
        for (int mm=1;a--;)
        {
            scanf("%s",str);
            if ( str[0]=='F' ){
                scanf("%d %d",&ul,&ur);
                ul++;ur++;
                update(1,1,leaf,LAZYONE);
            }else if (str[0]=='E'){
                scanf("%d %d",&ul,&ur);
                ul++;ur++;
                update(1,1,leaf,LAZYZERO);
            }else if (str[0]=='I'){
                scanf("%d %d",&ul,&ur);
                ul++;ur++;
                update(1,1,leaf,LAZYINVERSE);
            }else{
                scanf("%d %d",&ql,&qr);
                ql++;qr++;
                printf("Q%d: %d\n",mm++,query(1,1,leaf));
            }

        }
    }
    return 0;
}
