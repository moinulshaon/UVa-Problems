#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int mat[1100][1100];

int main()
{
    string a,b;

    int kase;
    scanf("%d",&kase);
    getchar();
    while ( kase-- )
    {
        getline(cin,a);
        b="";
        int length_a=a.length();
        for (int i=0;i<length_a;++i)
            b+= a[length_a-i-1] ;
        int length_b=b.length();

        for (int i=0;i<=length_a;++i)
            mat[i][0]=0;
        for (int i=0;i<=length_b;++i)
            mat[0][i]=0;

        for (int i=1;i<=length_b;++i)
        {
            for (int j=1;j<=length_a;++j)
            {
                if (b[i-1]==a[j-1])
                {
                    mat[i][j]=1+mat[i-1][j-1];
                }
                else
                    mat[i][j]=max( mat[i-1][j],mat[i][j-1] );
            }
        }
        printf("%d\n",mat[length_b][length_a]);
    }
    return 0;
}
