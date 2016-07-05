#include <cstdio>
#include <algorithm>

using namespace std;
int arr[5];
bool on;

void recursion(int taken,int sum)
{
    if (on)return ;

    if (taken==5)
    {
        if (sum==23)on=true;
        return ;
    }

    recursion(taken+1,sum+arr[taken]);
    recursion(taken+1,sum-arr[taken]);
    recursion(taken+1,sum*arr[taken]);
}


int main()
{
    while (true)
    {
        for (int i=0;i<5;++i)
            scanf("%d",&arr[i]);
        if (!arr[0] && !arr[1] &&!arr[2] &&!arr[3] &&!arr[4] )return 0;

        on=false;

        sort(arr,arr+5);
        do{
            recursion(1,arr[0]);
        } while(!on && next_permutation(arr,arr+5));


        if (on)
            printf("Possible\n");
        else
            printf("Impossible\n");

    }
}
