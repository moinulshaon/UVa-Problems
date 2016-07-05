#include <cstdio>
#include <cmath>
using namespace std;


int arr[]={0,9,180,2700,36000,450000,5400000,63000000,720000000};


int func( int n,int d ){


    int tmp=int( pow(10,d-1) )+n/d;
    int lsb=d-n%d-1;
    //printf("%d\n",tmp);
    //printf("%d %d %d %d %d\n",n,d,tmp,lsb,tmp/int( pow(10 , lsb ) ));
    return ( tmp/int( pow(10 , lsb ) ) ) %10;
}

int main()
{
    freopen("in.txt","r",stdin);
    int n;

    while (scanf("%d",&n)==1){

        if ( !n ){
            printf("%d\n",0);
            continue;
        }
        int sum=0;

        int d;
        for (d=0;sum<n;++d){
            sum+=arr[d];
            //printf("%d\n",sum);
        }
        //printf("%d %d\n",n-sum+arr[d-1]-1,d-1);
        //printf("shaon %d %d %d\n",sum,n-sum+arr[d-1],d-1);
        printf("%d\n",func(n-sum+arr[d-1]-1,d-1));

    }
    return 0;


}
