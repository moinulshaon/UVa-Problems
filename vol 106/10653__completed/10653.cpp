#include <cstdio>
#include <queue>

using namespace std;

bool mat[1010][1010];
bool vis[1010][1010];
struct node
{
    int row,col,val;
};
struct node pos,arr[1010][1010],des;


int main()
{
    int mrow,mcolumn;

    freopen("input.txt","r",stdin);

    while(scanf("%d %d",&mrow,&mcolumn)==2)
    {
        if (!mrow && !mcolumn)return 0;



        for (int i=0;i<mrow;++i)
            for (int j=0;j<mcolumn;++j)
                mat[i][j]=true;


        int test;
        scanf("%d",&test);
        while(test--)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            while(b--)
            {
                int k;
                scanf("%d",&k);
                mat[a][k]=false;
            }

        }




        scanf("%d %d",&pos.row,&pos.col);
        pos.val=0;

        for (int i=0;i<mrow;++i)
            for (int j=0;j<mcolumn;++j)
                vis[i][j]=false;


        queue <node> q;
        q.push (pos);

        vis[pos.row][pos.col]=true;

        scanf("%d %d",&des.row,&des.col);


        while(!vis[des.row][des.col])
        {
            node temp=q.front();
            q.pop();


            if ( temp.col+1<mcolumn && !vis[temp.row][temp.col+1] && mat[temp.row][temp.col+1])
            {
               vis[temp.row][temp.col+1]=true;
               arr[temp.row][temp.col+1].val=1+temp.val;
               arr[temp.row][temp.col+1].row=temp.row;
               arr[temp.row][temp.col+1].col=temp.col+1;
               q.push(arr[temp.row][temp.col+1]);
            }
            if (temp.col-1>=0 && !vis[temp.row][temp.col-1] && mat[temp.row][temp.col-1])
            {
               vis[temp.row][temp.col-1]=true;
               arr[temp.row][temp.col-1].val=1+temp.val;
               arr[temp.row][temp.col-1].row=temp.row;
               arr[temp.row][temp.col-1].col=temp.col-1;
               q.push(arr[temp.row][temp.col-1]);
            }
            if (temp.row+1<mrow && !vis[temp.row+1][temp.col] && mat[temp.row+1][temp.col])
            {
                vis[temp.row+1][temp.col]=true;
                arr[temp.row+1][temp.col].val=1+temp.val;
                arr[temp.row+1][temp.col].row=temp.row+1;
                arr[temp.row+1][temp.col].col=temp.col;
                q.push(arr[temp.row+1][temp.col]);

            }
            if (temp.row-1>=0 && !vis[temp.row-1][temp.col] && mat[temp.row-1][temp.col])
            {
                vis[temp.row-1][temp.col]=true;
                arr[temp.row-1][temp.col].val=1+temp.val;
                arr[temp.row-1][temp.col].row=temp.row-1;
                arr[temp.row-1][temp.col].col=temp.col;
                q.push(arr[temp.row-1][temp.col]);

            }

        }
        printf("%d\n",arr[des.row][des.col].val);


    }
    return 0;

}
