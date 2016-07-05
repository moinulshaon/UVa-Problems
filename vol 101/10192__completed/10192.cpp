#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int mat[105][105];

int main()
{
    string a,b;

    for (int m=1;getline(cin,a) && a!="#";++m)
    {
        getline(cin,b);
        int length_a=a.length();
        int length_b=b.length();

        for (int i=0;i<length_a;++i)
            mat[i][0]=0;
        for (int i=0;i<length_b;++i)
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
        printf("Case #%d: you can visit at most %d cities.\n",m,mat[length_b][length_a]);
    }
    return 0;
}
