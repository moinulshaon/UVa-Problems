#include <cstdio>




using namespace std;

char mat[100][100];

void dfs(int i,int j)
{
    mat[i][j]='#';
    if (mat[i][j+1]==' ')
        dfs(i,j+1);
    if (mat[i][j-1]==' ')
        dfs(i,j-1);
    if (mat[i+1][j]==' ')
        dfs(i+1,j);
    if (mat[i-1][j]==' ')
        dfs(i-1,j);
}


int main()
{

    freopen("in.txt","r",stdin);

    int test;
    scanf("%d",&test);
    getchar();

    while (test--)
    {
        int line=0;
        for (line=0;gets(mat[line]) && mat[line][0]!='_';++line)
            ;
        for (int i=0;i<line;++i)
            for (int j=0;mat[i][j];++j)
                if (mat[i][j]=='*')
                    dfs(i,j);

        for (int i=0;i<=line;++i)
            printf("%s\n",mat[i]);

    }
    return 0;
}
