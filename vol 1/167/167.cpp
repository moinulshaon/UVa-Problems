#include <cstdio>
#include <iostream>
#include <cstring>


using namespace std;

bool row[10];
bool rightdiag[20];
bool leftdiag[20];
char sol[100][10];
char temp[10];

int totalsolution=0;
int board[10][10];

void solution(int n)
{
    if (n==8)
    {
        temp[8]='\0';
        strcpy(sol[totalsolution++],temp);
        return ;
    }

    for (int i=0;i<8;++i)
    {
        if (row[i] && rightdiag[n-i+8] && leftdiag[n+i])
        {
            row[i]=rightdiag[n-i+8] =leftdiag[n+i]=false;
            temp[n]=i+'1';
            solution(n+1);
            row[i]=rightdiag[n-i+8] =leftdiag[n+i]=true;;
        }
    }
}

int main()
{
    memset(row,true,sizeof(row));
    memset(rightdiag,true,sizeof(rightdiag));
    memset(leftdiag,true,sizeof(leftdiag));

    solution(0);

    int cases;
    scanf("%d",&cases);
    while (cases--)
    {
        for (int i=0;i<8;++i)
            for (int j=0;j<8;++j)
                scanf("%d",&board[i][j]);
        int maxx=0;
        for (int i=0;i<totalsolution;++i)
        {
            int tmp=0;
            for (int j=0;j<8;++j)
                tmp+=board[ j ][ sol[i][j]-'1' ];
            if (tmp>maxx)
                maxx=tmp;
        }
        printf("%5d\n",maxx);
    }
    return 0;

}

