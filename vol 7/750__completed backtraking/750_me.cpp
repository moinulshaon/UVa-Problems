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

    freopen("input.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while (cases--)
    {
        int r,c;
        scanf("%d %d",&r,&c);

        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");

        int toprint=1;

        for (int i=0;i<totalsolution;++i)
        {
            if (sol[i][c-1]=='0'+r)
            {
                printf("%2d     ",toprint++);
                for (int j=0;j<8;++j)
                    printf(" %d",sol[i][j]-'0');
                printf("\n");
            }

        }


        if (cases)printf("\n");
    }
    return 0;

}

