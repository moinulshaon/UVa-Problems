#include <cstdio>
#include <cstring>

using namespace std;


int input;

int arr[20];
int count;

bool prime[100];
bool used[20];

void backtrack(int a)
{
    if (count==input-1)
    {
        for (int i=1;i<=input;++i)
        {
            if (prime[i+a] && prime[i+1] &&!used[i])
            {
                arr[count++]=i;
                used[i]=true;
                for (int k=0;k<input-1;++k)
                    printf("%d ",arr[k]);
                printf("%d\n",arr[input-1]);
                --count;
                used[i]=false;
            }
        }
    }

    for (int i=1;i<=input;++i)
    {
        if (prime[i+a] && !used[i])
        {
            arr[count++]=i;
            used[i]=true;
            backtrack(i);
            --count;
            used[i]=false;
        }
    }

}


int main()
{

    for (int i=2;i<100;++i)
        prime[i]=true;

    for (int i=2;i<=10;++i)
        if (prime[i])
            for (int j=i*2;j<100;j+=i)
                prime[j]=false;





    int p;
    for (int m=1;scanf("%d",&input)==1;++m)
    {
        if (m!=1)
            printf("\n");
        printf("Case %d:\n",m);
        count=1;
        memset(used,false,sizeof(used));
        used[1]=true;
        arr[0]=1;
        backtrack(1);

    }
    return 0;
}
