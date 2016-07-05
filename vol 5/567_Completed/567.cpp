#include <cstdio>
#define min(a,b) ((a)<(b))?(a):(b)
#define INF 1000000


using namespace std;

int mat[21][21];


int main()
{

    freopen("input.txt","r",stdin);

    for (int m=1;;++m)
    {

        for (int i=0;i<20;++i)
            for (int j=0;j<20;++j)
                mat[i][j]=INF;


        int temp,a,b;
        for (int i=0;i<19;++i)
        {

            if (scanf("%d",&temp)!=1)return 0;
            while (temp--)
            {
                scanf("%d",&a);
                mat[a-1][i]=mat[i][a-1]=1;
            }
        }



        for (int  k = 0; k < 20; k++ )
            for (int  i = 0; i< 20; i++ )
                for (int j = 0; j < 20; j++ )
                    mat [i] [j] = min (mat [i] [j],  mat [i] [k]+ mat [k] [j]);




        scanf("%d",&temp);



        printf("Test Set #%d\n",m);
        while (temp--)
        {
            scanf("%d %d",&a,&b);
            printf("%2d to %2d: %d\n",a,b,mat[b-1][a-1]);
        }
        printf("\n");

    }

}
