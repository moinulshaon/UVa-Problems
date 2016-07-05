#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
int rowm,colm,dimm;
bool vis[35][35][35];
char arr[35][35][35];

struct node
{
    int row,col,dim,val;
}c[35][35][35],start,des,temp;

queue <node> q;

void func()
{
    for (int i=0;i<35;++i)
        for (int j=0;j<35;++j)
            for (int k=0;k<35;++k)
                vis[i][j][k]=false;
}

void calc()
{
    int x=temp.dim,y=temp.row,z=temp.col;
    if (temp.col>0)
    {
        if (arr[x][y][z-1]!='#' && !vis[x][y][z-1])
        {
            c[x][y][z-1]=temp;
            c[x][y][z-1].val=temp.val+1;
            c[x][y][z-1].col=temp.col-1;
            vis[x][y][z-1]=true;
            q.push(c[x][y][z-1]);
        }
    }
    if (temp.col<colm-1)
    {
        if (arr[x][y][z+1]!='#' && !vis[x][y][z+1])
        {
            c[x][y][z+1]=temp;
            c[x][y][z+1].col=temp.col+1;
            c[x][y][z+1].val=temp.val+1;
            vis[x][y][z+1]=true;
            q.push(c[x][y][z+1]);
        }
    }

    if (temp.row>0)
    {
        if (arr[x][y-1][z]!='#' && !vis[x][y-1][z])
        {
            c[x][y-1][z]=temp;
            c[x][y-1][z].val=temp.val+1;
            c[x][y-1][z].row=temp.row-1;
            vis[x][y-1][z]=true;
            q.push(c[x][y-1][z]);

        }
    }
    if (temp.row<rowm-1)
    {
        if (arr[x][y+1][z]!='#' && !vis[x][y+1][z])
        {
            c[x][y+1][z]=temp;
            c[x][y+1][z].row=temp.row+1;
            c[x][y+1][z].val=temp.val+1;
            vis[x][y+1][z]=true;
            q.push(c[x][y+1][z]);

        }
    }

    if (temp.dim>0)
    {
        if (arr[x-1][y][z]!='#' && !vis[x-1][y][z])
        {
            c[x-1][y][z]=temp;
            c[x-1][y][z].dim=temp.dim-1;
            c[x-1][y][z].val=temp.val+1;
            vis[x-1][y][z]=true;
            q.push(c[x-1][y][z]);

        }
    }
    if (temp.dim<dimm-1)
    {
        if (arr[x+1][y][z]!='#' && !vis[x+1][y][z])
        {
            c[x+1][y][z]=temp;
            c[x+1][y][z].dim=temp.dim+1;
            c[x+1][y][z].val=temp.val+1;
            vis[x+1][y][z]=true;
            q.push(c[x+1][y][z]);
        }
    }

}


int main()
{

    int i,j,k;

    while (1)
    {


        scanf("%d %d %d",&dimm,&rowm,&colm);



        if (!dimm && !rowm && !colm)return 0;

        func();

        for (i=0;i<dimm;++i)
            for (j=0;j<rowm;++j)
                scanf("%s",arr[i][j]);

        for ( i=0;i<dimm;++i)
         {

            for (j=0;j<rowm;++j)
            {


                for (k=0;k<colm;++k)
                {
                    if (arr[i][j][k]=='E')
                    {

                        des.dim=i;
                        des.row=j;
                        des.col=k;
                        des.val=0;
                    }
                    else if (arr[i][j][k]=='S')
                    {

                        start.dim=i;
                        start.row=j;
                        start.col=k;
                        start.val=0;
                    }
                }
            }
         }

        vis[start.dim][start.row][start.col]=1;
        q.push(start);

        while(!q.empty())
        {
            temp=q.front();

            q.pop();
            calc();

        }
        if (vis[des.dim][des.row][des.col])
            printf("Escaped in %d minute(s).\n",c[des.dim][des.row][des.col].val);
        else
            printf("Trapped!\n");


    }
}
