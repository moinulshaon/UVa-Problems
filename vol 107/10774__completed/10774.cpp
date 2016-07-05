#include <cstdio>
#include <cmath>

using namespace std;

int result[30001];

int main()
{
    //freopen("in.txt","r",stdin);

    int m,n=0;
    for (int i=0;n<=30000;++i)
    {
        m=1<<i;
        n=1<<(i+1);
        for (int j=0;j<n-m && m+j<=30000;++j)
            result[m+j]=2*j+1;
    }

    int input,cases;
    scanf("%d",&cases);
    for (int m=1;cases--;++m)
    {
        scanf("%d",&input);
        int cnt=0;
        while (result[input]!=input)
        {
            ++cnt;
            input=result[input];
        }
        printf("Case %d: %d %d\n",m,cnt,result[input]);
    }
    return 0;

}
