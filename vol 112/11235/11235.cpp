#include <cstdio>

struct NODE
{
    int val;
    int frequency;
    int start;
    int finish;
}arr[300000];

struct tt
{
    int val;
    int start;
    int finish;
} tree[300000];

int totalNode,a,b,totaltree;

void build(int node,int l,int r)
{
    if (l==r)
    {
        tree[node].val=arr[l].frequency;
        tree[node].start=arr[l].start;
        tree[node].finish=arr[l].finish;
        if (node>totaltree)totaltree=node;
    }
    else
    {
        build(2*node,l,(l+r)/2);
        build(2*node+1,(l+r)/2+1,r);

        if ( tree[2*node].val > tree[2*node+1].val )
        {
            tree[node].val=tree[2*node].val;

        }
        else
        {
            tree[node].val=tree[2*node+1].val;
        }
        tree[node].start=tree[2*node].start;
        tree[node].finish=tree[2*node+1].finish;
    }
}

int query(int node)
{

    if (tree[node].finish<a || tree[node].start>b)
    {
        return 0;
    }
    else if ( tree[node].start>=a && tree[node].finish<=b )
    {
        return tree[node].val;
    }
    else if (2*node>totaltree )
    {
        if ( tree[node].start<=a && tree[node].finish<b)
            return tree[node].finish-a+1;
        else if (tree[node].start>a && tree[node].finish>=b )
            return b-tree[node].start+1;
        else
            return b-a+1;
    }
    else
    {
        int x=0,y=0;
        if (2*node<=totaltree)
        {
            x=query(2*node);
        }

        if (2*node+1<=totaltree)
        {
            y=query( 2*node+1 );
        }

        return (x>y)?x:y;
    }
}

int main()
{
    int total,queryNumber;
    while (true)
    {
        scanf("%d",&total);
        if (!total)return 0;
        scanf("%d",&queryNumber);

        scanf("%d",&arr[1].val);
        arr[1].frequency=1;
        arr[1].start=1;
        int tmp;
        totalNode=1;
        int i;
        for (i=2;i<=total;++i)
        {
            scanf("%d",&tmp);
            if (tmp==arr[totalNode].val)
                arr[totalNode].frequency++;
            else
            {
                arr[totalNode].finish=i-1;
                ++totalNode;
                arr[totalNode].val=tmp;
                arr[totalNode].frequency=1;
                arr[totalNode].start=i;
            }
        }
        arr[totalNode].finish=i-1;
        totaltree=0;
        build(1,1,totalNode);

        int L,R;
        while(queryNumber--)
        {

            scanf("%d %d",&a,&b);
            printf("%d\n",query( 1 ) );
        }
    }
    return 0;
}
