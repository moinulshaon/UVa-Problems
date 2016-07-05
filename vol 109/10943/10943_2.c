#include<stdio.h>

#define MAXD 210
#define D 1000000
int N, K;
int C[MAXD][MAXD];

int main()
{
    int i, j;

    for(i = 0; i <= 200; i ++)
        C[i][0] = 1;
    for(i = 1; i <= 200; i ++)
        for(j = 1; j <= i; j ++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % D;
    while (1)
    {
        scanf("%d%d", &N, &K);
        if(!N && !K)
            return 0;;
        printf("%d\n", C[N + K - 1][K - 1]);
    }
    
}