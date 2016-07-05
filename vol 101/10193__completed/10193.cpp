#include <cstdio>
#include <iostream>
#include <bitset>
#include <cstring>

using namespace std;



int gcd(unsigned long  a,unsigned long b)
{
    unsigned long temp;
    if (b>a)
    {
        temp=b;
        b=a;
        a=temp;
    }
    temp=a;
    while (b!=0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return temp;

}


int main()
{

    freopen("in.txt","r",stdin);

    int cases;
    scanf("%d",&cases);
    getchar();

    bitset <64> num1;
    bitset <64> num2;
    char arr[35];
    for (int m=1;m<=cases;++m)
    {
        num1.reset();
        num2.reset();

        gets(arr);

        int cnt=0;
        for (int i=strlen(arr)-1;i>=0;--i)
            num1[cnt++]=arr[i]-'0';


        gets(arr);

        cnt=0;
        for (int i=strlen(arr)-1;i>=0;--i)
            num2[cnt++]=arr[i]-'0';
        if (gcd(num1.to_ulong(),num2.to_ulong())!=1)
            printf("Pair #%d: All you need is love!\n",m);
        else
            printf("Pair #%d: Love is not all you need!\n",m);
    }
    return 0;
}
