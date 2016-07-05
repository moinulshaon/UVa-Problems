#include <cstdio>
#include <algorithm>

using namespace std;
int x,y;
char mat[55][55];
bool vis[55][55];

struct result
{
    char c;
    int number;
}arr[3000];

bool cmp(result a,result b)
{
    if (a.number<b.number)
        return false;
    else if (a.number==b.number)
    {
        if (a.c>b.c)return false;
        else return true;
    }
    return true;
}


int dfs(int i,int j)
{
    if (i<0 || j<0 || i>=x || j>=y || vis[i][j])
        return 0;
    vis[i][j]=true;

    int temp=1;
    if (mat[i][j+1]==mat[i][j])
        temp +=dfs(i,j+1);
    if (mat[i][j-1]==mat[i][j])
        temp +=dfs(i,j-1);
    if (mat[i+1][j]==mat[i][j])
        temp +=dfs(i+1,j);
    if (mat[i-1][j]==mat[i][j])
        temp +=dfs(i-1,j);

    return temp;
}


int main()
{

    //freopen("in.txt","r",stdin);

    for (int m=1;;++m)
    {
        scanf("%d %d",&x,&y);

        if (!x && !y)return 0;

        for (int i=0;i<x;++i)
            scanf("%s",mat[i]);


        for (int i=0;i<x;++i)
            for (int j=0;j<y;++j)
                vis[i][j]=false;

        int cnt=0;
        for (int i=0;i<x;++i)
            for (int j=0;j<y;++j)
                if (!vis[i][j] && mat[i][j]!='.')
                {
                    arr[cnt].c=mat[i][j];
                    arr[cnt].number=dfs(i,j);
                    ++cnt;
                }
        printf("Problem %d:\n",m);
        stable_sort(arr,arr+cnt,cmp);

        for (int i=0;i<cnt;++i)
            printf("%c %d\n",arr[i].c,arr[i].number);
    }
}
