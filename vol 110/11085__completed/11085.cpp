#include <cstdio>
#include <iostream>
#include <cstring>


using namespace std;

bool row[10];
bool rightdiag[20];
bool leftdiag[20];
char sol[100][10];
char temp[10];
int arr[10];

int totalsolution=0;

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
int absol(int i,int j)
{
    if (i>j)
        return i-j;
    else
        return j-i;
}

int func(int n)
{
    int result=0;
    for (int i=0;i<8;++i)
        if (arr[i]!=(sol[n][i]-'0'))
            ++result;
    return result;
}

int main()
{
    memset(row,true,sizeof(row));
    memset(rightdiag,true,sizeof(rightdiag));
    memset(leftdiag,true,sizeof(leftdiag));

    solution(0);

    freopen("in.txt","r",stdin);

    for (int k=1;scanf("%d",&arr[0])==1;++k)
    {
        for (int i=1;i<8;++i)
            scanf("%d",&arr[i]);
        int diff=10000,mini=10000;
        for (int i=0;i<totalsolution;++i)
        {
            diff=func(i);
            if (diff<mini)
                mini=diff;
        }
        printf("Case %d: %d\n",k,mini);
    }

    return 0;

}

