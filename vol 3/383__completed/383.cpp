#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <cstdio>
#define INF 1000000
#define min(a,b) ((a)<(b))?(a):(b)

using namespace std;


int main()
{
    int test;

    freopen("input.txt","r",stdin);

    scanf("%d",&test);
    printf("SHIPPING ROUTES OUTPUT\n");

    for (int cases=1;cases<=test;++cases)
    {
        printf("\nDATA SET  %d\n\n",cases);
        int warehouse,leg,testcase;
        scanf("%d %d %d",&warehouse,&leg,&testcase);

        map <string,int> myindex;

        string a,b;
        int nodeNumber=0;
        int mat[35][35];

        for (int i=0;i<35;++i)
            for (int j=0;j<35;++j)
                mat[i][j]=INF;

        for (int i=0;i<warehouse;++i)
        {
            cin>>a;

            if (!myindex[a])myindex[a]=nodeNumber++;


        }
        for (int i=0;i<leg;++i)
        {
            cin>>a>>b;
            mat[myindex[a]][myindex[b]]=mat[myindex[b]][myindex[a]]=1;
        }


         for (int  k = 0; k < nodeNumber; k++ )
            for (int  i = 0; i < nodeNumber; i++ )
                for (int  j = 0; j < nodeNumber; j++ )
                mat [i] [j] = min (mat [i] [j],  mat [i] [k]+ mat [k] [j]);

        int cost;
        for (int i=0;i<testcase;++i)
        {
            cin>>cost>>a>>b;

            if (mat[myindex[a]][myindex[b]]!=INF)
            {
                cost*=mat[myindex[a]][myindex[b]]*100;
                printf("$%d\n",cost);
            }
            else
                printf("NO SHIPMENT POSSIBLE\n");
        }
    }
    printf("\nEND OF OUTPUT\n");
    return 0;
}


