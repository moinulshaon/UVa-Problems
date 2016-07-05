#include <stdio.h>


char mat[85][85];
char vis[85][85];
int line;


void dfs(int i,int j,char c)
{
    vis[i][j]=1;
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

	char boundary;
	int i,j;

    freopen("in.txt","r",stdin);

    

    while (gets(mat[0]))
    {
        for (line=1;mat[line-1][0]!='_';++line)
            gets(mat[line]);

        boundary=' ';
        for (i=0;i<line;++i)
            for ( j=0;mat[i][j];++j)
                if (mat[i][j]!=' ')
                {
                    boundary=mat[i][j];
                    i=line;
                    break;
                }

        for (i=0;i<line;++i)
            for (j=0;mat[i][j];++j)
                vis[i][j]=0;

        for (i=0;i<line-1;++i)
            for (j=0;mat[i][j];++j)
                if (mat[i][j]!=boundary && mat[i][j]!=' ' && !vis[i][j])
                    dfs(i,j,mat[i][j]);

        for ( i=0;i<line;++i)
            puts(mat[i]);
    }
    return 0;
}
