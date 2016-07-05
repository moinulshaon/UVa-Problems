#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;


char map[310][310];


struct node
{
    int row,col,step,val;
}arr[310][310],start,exit;


int main()
{
    int cases;

    freopen("input.txt","r",stdin);

    scanf("%d",&cases);
    getchar();

    int row,col;
    while(cases--)
    {

        scanf("%d %d",&row,&col);
        getchar();

        for (int i=0;i<row;++i)
            gets(map[i]);


        for (int i=0;i<row;++i)
            for (int j=0;j<col;++j)
                if (map[i][j]=='S')
                {
                    start.row=i;
                    start.col=j;
                    start.step=1;
                    start.val=0;
                }
                else if (map[i][j]=='E')
                {
                    exit.row=i;
                    exit.col=j;
                }
        bool vis[310][310][4]={false};

        queue <node> q;

        q.push(start);
        vis[start.row][start.col][3]=true;

        while (!(vis[exit.row][exit.col][1] || vis[exit.row][exit.col][2] || vis[exit.row][exit.col][3] )  && !q.empty())
        {
            node temp=q.front();
            q.pop();


            if (temp.step==1 )
            {
                if (temp.col+1<col && map[temp.row][temp.col+1]!='#' && !vis[temp.row][temp.col+1][1])
                {
                    vis[temp.row][temp.col+1][1]=true;
                    arr[temp.row][temp.col+1].col=temp.col+1;
                    arr[temp.row][temp.col+1].row=temp.row;
                    arr[temp.row][temp.col+1].step=2;
                    arr[temp.row][temp.col+1].val=temp.val+1;
                    q.push(arr[temp.row][temp.col+1]);
                }

                if (temp.row+1<row && map[temp.row+1][temp.col]!='#' && !vis[temp.row+1][temp.col][1])
                {
                    vis[temp.row+1][temp.col][1]=true;
                    arr[temp.row+1][temp.col].col=temp.col;
                    arr[temp.row+1][temp.col].row=temp.row+1;
                    arr[temp.row+1][temp.col].step=2;
                    arr[temp.row+1][temp.col].val=temp.val+1;
                    q.push(arr[temp.row+1][temp.col]);
                }
                if (temp.col-1>=0 && map[temp.row][temp.col-1]!='#' && !vis[temp.row][temp.col-1][1])
                {
                    vis[temp.row][temp.col-1][1]=true;
                    arr[temp.row][temp.col-1].col=temp.col-1;
                    arr[temp.row][temp.col-1].row=temp.row;
                    arr[temp.row][temp.col-1].step=2;
                    arr[temp.row][temp.col-1].val=temp.val+1;
                    q.push(arr[temp.row][temp.col-1]);
                }
                if (temp.row-1>=0 && map[temp.row-1][temp.col]!='#' && !vis[temp.row-1][temp.col][1])
                {
                    vis[temp.row-1][temp.col][1]=true;
                    arr[temp.row-1][temp.col].col=temp.col;
                    arr[temp.row-1][temp.col].row=temp.row-1;
                    arr[temp.row-1][temp.col].step=2;
                    arr[temp.row-1][temp.col].val=temp.val+1;
                    q.push(arr[temp.row-1][temp.col]);
                }
            }

            else if (temp.step==2 )
            {
                if (temp.col+2<col && map[temp.row][temp.col+1]!='#'  && map[temp.row][temp.col+2]!='#' && !vis[temp.row][temp.col+2][2])
                {
                    vis[temp.row][temp.col+2][2]=true;
                    arr[temp.row][temp.col+2].col=temp.col+2;
                    arr[temp.row][temp.col+2].row=temp.row;
                    arr[temp.row][temp.col+2].step=3;
                    arr[temp.row][temp.col+2].val=temp.val+1;
                    q.push(arr[temp.row][temp.col+2]);
                }

                if (temp.row+2<row && map[temp.row+1][temp.col]!='#' && map[temp.row+2][temp.col]!='#' && !vis[temp.row+2][temp.col][2])
                {
                    vis[temp.row+2][temp.col][2]=true;
                    arr[temp.row+2][temp.col].col=temp.col;
                    arr[temp.row+2][temp.col].row=temp.row+2;
                    arr[temp.row+2][temp.col].step=3;
                    arr[temp.row+2][temp.col].val=temp.val+1;
                    q.push(arr[temp.row+2][temp.col]);
                }
                if (temp.col-2>=0 && map[temp.row][temp.col-1]!='#' && map[temp.row][temp.col-2]!='#' &&  !vis[temp.row][temp.col-2][2])
                {
                    vis[temp.row][temp.col-2][2]=true;
                    arr[temp.row][temp.col-2].col=temp.col-2;
                    arr[temp.row][temp.col-2].row=temp.row;
                    arr[temp.row][temp.col-2].step=3;
                    arr[temp.row][temp.col-2].val=temp.val+1;
                    q.push(arr[temp.row][temp.col-2]);
                }
                if (temp.row-2>=0 && map[temp.row-1][temp.col]!='#'&& map[temp.row-2][temp.col]!='#' && !vis[temp.row-2][temp.col][2])
                {
                    vis[temp.row-2][temp.col][2]=true;
                    arr[temp.row-2][temp.col].col=temp.col;
                    arr[temp.row-2][temp.col].row=temp.row-2;
                    arr[temp.row-2][temp.col].step=3;
                    arr[temp.row-2][temp.col].val=temp.val+1;
                    q.push(arr[temp.row-2][temp.col]);
                }
            }
            else if (temp.step==3 )
            {
                if (temp.col+3<col && map[temp.row][temp.col+1]!='#'  && map[temp.row][temp.col+2]!='#' && map[temp.row][temp.col+3]!='#'  && !vis[temp.row][temp.col+3][3])
                {
                    vis[temp.row][temp.col+3][3]=true;
                    arr[temp.row][temp.col+3].col=temp.col+3;
                    arr[temp.row][temp.col+3].row=temp.row;
                    arr[temp.row][temp.col+3].step=1;
                    arr[temp.row][temp.col+3].val=temp.val+1;
                    q.push(arr[temp.row][temp.col+3]);
                }

                if (temp.row+3<row && map[temp.row+1][temp.col]!='#' && map[temp.row+2][temp.col]!='#' && map[temp.row+3][temp.col]!='#' && !vis[temp.row+3][temp.col][3])
                {
                    vis[temp.row+3][temp.col][3]=true;
                    arr[temp.row+3][temp.col].col=temp.col;
                    arr[temp.row+3][temp.col].row=temp.row+3;
                    arr[temp.row+3][temp.col].step=1;
                    arr[temp.row+3][temp.col].val=temp.val+1;
                    q.push(arr[temp.row+3][temp.col]);
                }
                if (temp.col-3>=0 && map[temp.row][temp.col-1]!='#' && map[temp.row][temp.col-2]!='#' && map[temp.row][temp.col-3]!='#' && !vis[temp.row][temp.col-3][3])
                {
                    vis[temp.row][temp.col-3][3]=true;
                    arr[temp.row][temp.col-3].col=temp.col-3;
                    arr[temp.row][temp.col-3].row=temp.row;
                    arr[temp.row][temp.col-3].step=1;
                    arr[temp.row][temp.col-3].val=temp.val+1;
                    q.push(arr[temp.row][temp.col-3]);
                }
                if (temp.row-3>=0 && map[temp.row-1][temp.col]!='#' && map[temp.row-2][temp.col]!='#' && map[temp.row-3][temp.col]!='#' && !vis[temp.row-3][temp.col][3] )
                {
                    vis[temp.row-3][temp.col][3]=true;
                    arr[temp.row-3][temp.col].col=temp.col;
                    arr[temp.row-3][temp.col].row=temp.row-3;
                    arr[temp.row-3][temp.col].step=1;
                    arr[temp.row-3][temp.col].val=temp.val+1;
                    q.push(arr[temp.row-3][temp.col]);
                }
            }
        }

        if (vis[exit.row][exit.col][1] || vis[exit.row][exit.col][2] || vis[exit.row][exit.col][3])
            printf("%d\n",arr[exit.row][exit.col].val);
        else
            printf("NO\n");
    }
    return 0;
}
