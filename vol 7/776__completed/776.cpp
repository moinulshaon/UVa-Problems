#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#define mx 1000

using namespace std;

char mat[mx][mx];
string tmp;
bool vis[mx][mx];
int result[mx][mx];
int num;
int row,col;
int allign[mx];

void DFS(int i,int j)
{
    vis[i][j]=true;
    char tt=mat[i][j];
    result[i][j]=num;
    if (i+1<row &&  mat[i+1][j]==tt && !vis[i+1][j])
        DFS(i+1,j);
    if (i+1<row && j+1<col && mat[i+1][j+1]==tt && !vis[i+1][j+1])
        DFS(i+1,j+1);
    if (j+1<col && mat[i][j+1]==tt && !vis[i][j+1])
        DFS(i,j+1);
    if (i-1>=0 && j+1<col && mat[i-1][j+1]==tt && !vis[i-1][j+1])
        DFS(i-1,j+1);
    if (i-1>=0 && mat[i-1][j]==tt && !vis[i-1][j])
        DFS(i-1,j);
    if (i-1>=0 && j-1>=0 && mat[i-1][j-1]==tt && !vis[i-1][j-1])
        DFS(i-1,j-1);
    if (j-1>=0 && mat[i][j-1]==tt && !vis[i][j-1])
        DFS(i,j-1);
    if (i+1<row && j-1>=0 && mat[i+1][j-1]==tt && !vis[i+1][j-1])
        DFS(i+1,j-1);
}


int main()
{

    //freopen("in.txt","r",stdin);

    while (true)
    {

        bool off=false;
        for (row=0; ;++row)
        {

            if ( !getline(cin,tmp) )
            {
                off=true;
                break;
            }
            //cout<<tmp<<endl;
            istringstream sstr(tmp);

            if (tmp[0]=='%')
                break;

            for (col=0;sstr>>mat[row][col];++col)
                ;
        }
        for (int i=0;i<row;++i)
            for (int j=0;j<col;++j)
            {
                vis[i][j]=false;
                //cout<<mat[i][j];
            }
        //cout<<endl;
        num=0;
        for (int i=0;i<row;++i)
            for (int j=0;j<col;++j)
                if (!vis[i][j])
                {
                    ++num;
                    DFS(i,j);
                }

        for (int i=0;i<col;++i )
        {
            int min=0;
            for (int j=0;j<row;++j)
            {
                int digit=1,p=result[j][i];
                while (p/=10)
                    ++digit;

                if (digit>min)
                    min=digit;
            }
            allign[i]=min;
        }
        for (int i=0;i<row;++i)
        {
            for (int j=0;j<col;++j)
            {

                if (j)
                    cout<<' ';

                cout.width(allign[j]);

                cout<<result[i][j];
            }
            cout<<endl;
        }
        cout<<'%'<<endl;
        if (off)return 0;

    }

}
