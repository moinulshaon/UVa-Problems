#include <cstdio>
#include <cmath>
#define size 100010042


using namespace std;

bool prime[size];

int main()
{
    freopen("out.out","w",stdout);



    for (int i=2;i<size;++i)
        prime[i]=true;
    for (int i=0;i<=10000;++i)
        if (prime[i])
            for (int j=i*2;j<size;j+=i)
                prime[j]=false;

    for (int i=0;i<=10000;++i)
        if (prime[i*i+i+41])
            printf("1,");
        else
            printf("0,");


    /*int a,b,count;

    while (scanf("%d %d",&a,&b)==2)
    {
        count=0;
        for (int i=a;i<=b;++i)
            if (result[i])
                ++count;
        printf("%.2lf\n",double(count)/(b-a+1)*100);
    }*/
    return 0;


}
