#include <cstdio>
#include <iostream>
#include <cstring>


using namespace std;

bool row[20];
bool rightdiag[40];
bool leftdiag[40];
char sol[20][400000][40];
char temp[20];
char board[20][20];
bool pos[20][20];

int totalsolution[20];
int rc;

void solution(int n)
{
    if (n==rc)
    {
        temp[rc]='\0';

        for (int i=0;i<rc;++i)
            sol[rc][ totalsolution[rc] ][i]=temp[i];
        totalsolution[rc]++;

        return ;
    }

    for (int i=0;i<rc;++i)
    {
        if (row[i] && rightdiag[n-i+rc] && leftdiag[n+i])
        {
            row[i]=rightdiag[n-i+rc] =leftdiag[n+i]=false;
            temp[n]=i;
            solution(n+1);
            row[i]=rightdiag[n-i+rc] =leftdiag[n+i]=true;;
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);

    for (rc=4;rc<15;++rc)
    {
        memset(row,true,sizeof(row));
        memset(rightdiag,true,sizeof(rightdiag));
        memset(leftdiag,true,sizeof(leftdiag));
        totalsolution[rc]=0;
        solution(0);
    }

    for (int kase=1;true;++kase)
    {
        scanf("%d",&rc);
        if (!rc)return 0;

        for (int i=0;i<rc;++i)
            scanf("%s",board[i]);

        memset(pos,true,sizeof(pos));
        for (int i=0;i<rc;++i)
            for (int j=0;j<rc;++j)
                if (board[i][j]=='*')
                    pos[i][j]=false;


        int result=0;
        bool on;
        for (int i=0;i<totalsolution[rc];++i)
        {
            on =true;
            for (int j=0;j<rc;++j)
            {
                if (! pos  [ sol[rc][i][j] ] [j] )
                {
                    on=false;
                    break;
                }
            }
            if (on)
                ++result;
        }


        printf("Case %d: %d\n",kase,result);
    }

    return 0;

}

