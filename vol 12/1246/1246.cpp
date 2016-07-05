#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

bool prime[150];
vector <int> v;

int div(int input)
{
	int  result=1,count=0;
	for (int i=0; i<v.size()  && v[i]*v[i]<=input;++i)
	{
        count=0;
        while (input%v[i]==0)
        {
            input/=v[i];
            ++count;
        }
        result*=(count+1);
	}

	if (input!=1)
		return result*2;
	else
		return result;
}

int main()
{
	register int i,j,k;
	for (i=2;i<150;++i)
        prime[i]=true;
    for (i=2;i<=12;++i)
        if (prime[i])
            for (j=i*2;j<150;j+=i)
                prime[j]=false;
    for (i=2;i<150;++i)
        if (prime[i])
            v.push_back(i);

    int l,h,test;
    scanf("%d",&test);
	while(test--)
    {
        bool on=false;
        scanf("%d %d",&l,&h);
        for (i=l;i<=h;++i)
            if (prime[div(i)])
            {
                if (on)
                    printf(" %d",i);
                else
                {
                    printf("%d",i);
                    on=true;
                }
            }
        if (!on)
            printf("-1");
        printf("\n");
    }
	return 0;
}
