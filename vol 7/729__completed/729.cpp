#include <cstdio>
#include <cstring>

using namespace std;

char temp[20];
int n,k;

void printdiff(int m,int p)
{
    if (m==n)
    {
        temp[n]='\0';
        printf("%s\n",temp);
        return ;
    }


    if (m>=n-p)
    {
        temp[m]='1';
        printdiff(m+1,p);
    }
    else
    {
        temp[m]='0';
        printdiff(m+1,p);

        if (p-1>=0)
        {
            temp[m]='1';

            printdiff(m+1,p-1);
        }


    }





}



int main()
{
    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&n,&k);

        printdiff(0,k);


        if (cases)printf("\n");
    }
}
