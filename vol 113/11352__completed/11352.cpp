#include <cstdio>
#include <queue>

using namespace std;

char map[110][110];
struct node
{
    int row,col,val;
}start,des,arr[110][110];

int main()
{
    int cases;

    freopen("input.txt","r",stdin);

    scanf("%d",&cases);

    while(cases--)
    {

        int mrow,mcol;
        scanf("%d %d",&mrow,&mcol);

        for (int i=0;i<mrow;++i)
            scanf("%s",map[i]);

        bool vis[110][110]={false};
        des.row=des.col=-1;
        for (int i=0;i<mrow;++i)
        {
            for (int j=0;j<mcol;++j)
            {
                if (map[i][j]=='A')
                {
                    start.row=i;
                    start.col=j;
                    start.val=0;
                }

                else if (map[i][j]=='B')
                {
                    des.row=i;
                    des.col=j;
                    vis[i][j]=false;
                }
                else if (map[i][j]=='Z')
                {
                    if (!(i==des.row && j==des.col))
                        vis[i][j]=true;
                    if (i+1<mrow)
                    {
                        if (j-2>=0 && !(i+1==des.row && j-2==des.col))
                            vis[i+1][j-2]=true;
                        if (j+2<mcol && !(i+1==des.row && j+2==des.col))
                            vis[i+1][j+2]=true;
                        if (i+2<mrow)
                        {
                            if (j-1>=0 && !(i+2==des.row && j-1==des.col))
                                vis[i+2][j-1]=true;
                            if (j+1<mcol && !(i+2==des.row && j+1==des.col))
                                vis[i+2][j+1]=true;
                        }
                    }
                    if (i-1>=0)
                    {
                        if (j-2>=0 && !(i-1==des.row && j-2==des.col))
                            vis[i-1][j-2]=true;
                        if (j+2<mcol && !(i-1==des.row && j+2==des.col))
                            vis[i-1][j+2]=true;
                        if (i-2>=0)
                        {
                            if (j-1>=0 && !(i-2==des.row && j-1==des.col))
                                vis[i-2][j-1]=true;
                            if (j+1<mcol && !(i-2==des.row && j+1==des.col))
                                vis[i-2][j+1]=true;
                        }
                    }

                }
            }
        }



        queue <node> q;
        q.push(start);
        vis[start.row][start.col]=true;

        while (!vis[des.row][des.col] && !q.empty())
        {
            node temp=q.front();
            q.pop();
            if (temp.col+1<mcol && !vis[temp.row][temp.col+1])
            {

                vis[temp.row][temp.col+1]=true;
                arr[temp.row][temp.col+1].row=temp.row;
                arr[temp.row][temp.col+1].col=temp.col+1;
                arr[temp.row][temp.col+1].val=temp.val+1;
                q.push(arr[temp.row][temp.col+1]);

            }
            if (temp.col+1<mcol && temp.row+1<mrow && !vis[temp.row+1][temp.col+1] )
            {

                vis[temp.row+1][temp.col+1]=true;
                arr[temp.row+1][temp.col+1].row=temp.row+1;
                arr[temp.row+1][temp.col+1].col=temp.col+1;
                arr[temp.row+1][temp.col+1].val=temp.val+1;
                q.push(arr[temp.row+1][temp.col+1]);

            }
            if (temp.row+1<mrow && !vis[temp.row+1][temp.col] )
            {

                vis[temp.row+1][temp.col]=true;
                arr[temp.row+1][temp.col].row=temp.row+1;
                arr[temp.row+1][temp.col].col=temp.col;
                arr[temp.row+1][temp.col].val=temp.val+1;
                q.push(arr[temp.row+1][temp.col]);

            }
            if (temp.row+1<mrow && temp.col-1>=0 &&!vis[temp.row+1][temp.col-1] )
            {

                vis[temp.row+1][temp.col-1]=true;
                arr[temp.row+1][temp.col-1].row=temp.row+1;
                arr[temp.row+1][temp.col-1].col=temp.col-1;
                arr[temp.row+1][temp.col-1].val=temp.val+1;
                q.push(arr[temp.row+1][temp.col-1]);

            }
            if (temp.col-1>=0 && !vis[temp.row][temp.col-1] )
            {

                vis[temp.row][temp.col-1]=true;
                arr[temp.row][temp.col-1].row=temp.row;
                arr[temp.row][temp.col-1].col=temp.col-1;
                arr[temp.row][temp.col-1].val=temp.val+1;
                q.push(arr[temp.row][temp.col-1]);

            }
            if (temp.row-1>=0 && temp.col-1>=0 && !vis[temp.row-1][temp.col-1] )
            {

                vis[temp.row-1][temp.col-1]=true;
                arr[temp.row-1][temp.col-1].row=temp.row-1;
                arr[temp.row-1][temp.col-1].col=temp.col-1;
                arr[temp.row-1][temp.col-1].val=temp.val+1;
                q.push(arr[temp.row-1][temp.col-1]);

            }
            if (temp.row-1>=0 && !vis[temp.row-1][temp.col] )
            {
                vis[temp.row-1][temp.col]=true;
                arr[temp.row-1][temp.col].row=temp.row-1;
                arr[temp.row-1][temp.col].col=temp.col;
                arr[temp.row-1][temp.col].val=temp.val+1;
                q.push(arr[temp.row-1][temp.col]);

            }
            if (temp.row-1>=0 && temp.col+1<mcol && !vis[temp.row-1][temp.col+1] )
            {
                vis[temp.row-1][temp.col+1]=true;
                arr[temp.row-1][temp.col+1].row=temp.row-1;
                arr[temp.row-1][temp.col+1].col=temp.col+1;
                arr[temp.row-1][temp.col+1].val=temp.val+1;
                q.push(arr[temp.row-1][temp.col+1]);
            }

        }
        if (!vis[des.row][des.col])
            printf("King Peter, you can't go now!\n");
        else
            printf("Minimal possible length of a trip is %d\n",arr[des.row][des.col].val);


    }
    return 0;

}
