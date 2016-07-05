#include <cstdio>
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main()
{

    freopen("in.txt","r",stdin);

    int input;

    while (scanf("%d",&input)==1)
    {
        bitset <32> mybit,result;

        int save=input;

        for (int i=0;i<32;++i)
        {
            mybit[i]=input&1;
            input>>=1;
        }


        for (int i=0;i<8;++i)
            result[i]=mybit[24+i];
        for (int i=8;i<16;++i)
            result[i]=mybit[16+i-8];
        for (int i=16;i<24;++i)
            result[i]=mybit[8+i-16];
        for (int i=24;i<32;++i)
            result[i]=mybit[i-24];


        printf("%d converts to %d\n",save,int(result.to_ulong()));
    }
    return 0;

}
