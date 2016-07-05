#include <cstdio>
#include <cmath>

using namespace std;

bool prime[32001];
int result[32001];
int cnt=0;

int main()
{
    for (int i=2;i<32001;++i)
        prime[i]=true;
    for (int i=2;i<=178;++i)
        if (prime[i])
            for (int j=i*2;j<32001;j+=i)
                prime[j]=false;
    for (int i=2;i<32001;++i)
        if(prime[i])
            result[cnt++]=i;

    int a,b;


    while (true)
    {
        scanf("%d %d",&a,&b);
        if (!a && !b)return 0;

        if (b<a)
        {
            int temp=a;
            a=b;
            b=temp;
        }

        for (int i=0;i<cnt;++i)
        {
            if (result[i]>=a)
            {
                if (result[i]>b)
                    break;

                if (i<cnt-3)
                {
                    if (result[i+1]-result[i]==result[i+2]-result[i+1] && result[i+2]<=b)
                    {

                        if (i<cnt-4)
                        {
                            if (result[i+1]-result[i]==result[i+2]-result[i+1] && result[i+1]-result[i] == result[i+3]-result[i+2] )
                            {
                                if (result[i+3]<=b )
                                    printf("%d %d %d %d\n",result[i],result[i+1],result[i+2],result[i+3]);
                                i+=2;

                            }
                            else if (!(result[i+1]-result[i]==result[i+2]-result[i+1] && result[i+1]-result[i] == result[i]-result[i-1])
                                     && !(result[i+1]-result[i]==result[i]-result[i-1] && result[i]-result[i-1] == result[i]-result[i-2]))
                            {
                                printf("%d %d %d\n",result[i],result[i+1],result[i+2]);
                                i+=1;
                            }
                        }
                        else
                        {
                            printf("%d %d %d\n",result[i],result[i+1],result[i+2]);
                            i+=1;
                        }

                    }
                }
            }
        }
    }

}
