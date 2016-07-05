#include <cstdio>
#include <cmath>

using namespace std;




struct mathv{
    int x,y;
}points[210000],circle1,circle2;

int pointsTotal;

double distance2DPointAndPoint(mathv& v1, mathv& v2){
    return sqrt((v2.x - v1.x) * (v2.x - v1.x)+ (v2.y - v1.y) * (v2.y - v1.y));
}

int tree[30000];
int save[30000];
int total;
int ql,qr;
void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=save[l];

    }
    else
    {
        build(2*node,l,(l+r)/2);
        build(2*node+1,(l+r)/2+1,r);

        tree[node]=tree[2*node]+tree[2*node+1];
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



int tree2[30000];
int save2[30000];
int total2;
int ql2,qr2;
void build2(int node,int l,int r)
{
    if(l==r)
    {
        tree2[node]=save2[l];

    }
    else
    {
        build2(2*node,l,(l+r)/2);
        build2(2*node+1,(l+r)/2+1,r);

        tree2[node]=tree2[2*node]+tree2[2*node+1];
    }
}

int query2(int node,int l,int r)
{
    if (r<ql2 || l>qr2)return 0;
    else if (l>=ql2 && r<=qr2)return tree2[node];
    else
    {
        return query2(2*node,l,(l+r)/2)+query2(2*node+1,(l+r)/2+1,r);
    }
}


int main()
{

    freopen("in.txt","r",stdin);

    int leaf=13001;
    int numberofquery;

    for (int kk=1;;++kk)
    {
        scanf("%d",&pointsTotal);
        if (!pointsTotal)return 0;

        for (int i=0;i<pointsTotal;++i){
            scanf("%d %d",&points[i].x,&points[i].y);
        }

        scanf("%d %d %d %d %d",&circle1.x,&circle1.y,&circle2.x,&circle2.y,&numberofquery);

        for (int i=0;i<=leaf;++i){
            save[i]=0;
            save2[i]=0;
        }

        total=total2=2*leaf-1;

        for (int i=0;i<pointsTotal;++i){
            int tmp=int ( ceil( distance2DPointAndPoint( points[i],circle1 ) ) );

            if (tmp<13001){
                save[tmp]++;
            }
        }

        for (int i=0;i<pointsTotal;++i){

            int tmp=int ( ceil( distance2DPointAndPoint( points[i],circle2 ) ) );

            if (tmp<13001){
                save2[tmp]++;
            }
        }


        build(1,1,leaf);
        build2(1,1,leaf);

        printf("Case %d:\n",kk);

        while (numberofquery--){
            scanf("%d %d",&qr,&qr2);
            ql=ql2=0;
            //printf("%d\n",query(1,1,leaf));
            //printf("%d\n",query2(1,1,leaf));
            int tmp=pointsTotal-query(1,1,leaf)-query2(1,1,leaf);
            if (tmp<0)tmp=0;

            printf("%d\n",tmp);
        }

    }
}
