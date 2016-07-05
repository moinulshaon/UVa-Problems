#include <cstdio>

using namespace std;

char mat[85][85];
bool vis[85][85];
int line;


void dfs(int i,int j,char c)
{
    vis[i][j]=true;
    mat[i][j]=c;
    if (mat[i][j+1]==' ')
        dfs(i,j+1,c);
    if (j-1>=0 && mat[i][j-1]==' ')
        dfs(i,j-1,c);
    if (i+1<line  && mat[i+1][j]==' ')
        dfs(i+1,j,c);
    if (i-1>=0 && mat[i-1][j]==' ')
        dfs(i-1,j,c);
}


int main()
{
    freopen("in.txt","r",stdin);

    char boundary;
    bool firstchar;

    while (gets(mat[0]))
    {
        for (line=1;mat[line-1][0]!='_';++line)
            gets(mat[line]);

        boundary=' ';
        for (int i=0;i<line;++i)
            for (int j=0;mat[i][j];++j)
                if (mat[i][j]!=' ')
                {
                    boundary=mat[i][j];
                    i=line;
                    break;
                }

        for (int i=0;i<line;++i)
            for (int j=0;mat[i][j];++j)
                vis[i][j]=false;

        for (int i=0;i<line-1;++i)
            for (int j=0;mat[i][j];++j)
                if (mat[i][j]!=boundary && mat[i][j]!=' ' && !vis[i][j])
                    dfs(i,j,mat[i][j]);

        for (int i=0;i<line;++i)
            puts(mat[i]);
    }
    return 0;
}
