#include <cstdio>
#include <cstring>

#define sz 15

using namespace std;

struct tttt{
    int row, col;
}arr[sz];

int a[sz][sz], p[sz][sz];

void showResult(int left, int right){
    if(left < right){
        printf("(");
        showResult(left, p[left][right]);
        printf(" x ");
        showResult(p[left][right] + 1, right);
        printf(")");
    }
    else if(left == right){
        printf("A%d", left);
    }
}

int main()
{
    int n, cas = 0;
    for (int kk=1;scanf("%d",&n)==1 &&  n;++kk){

        for(int i=1; i<=n; i++)
            scanf("%d %d",&arr[i].row,&arr[i].col);

        memset(a, 127, sizeof(a));
        memset(p, 0, sizeof(p));
        for(int i=1; i<=n; i++)
            a[i][i] = 0;
        for(int i=2; i<=n; i++){
            a[i-1][i]=arr[i - 1].row*arr[i].row*arr[i].col;
            p[i-1][i]=i-1;
        }

        for(int i=3; i<=n; i++)
            for(int j=i - 2; j ;j--)
                for(int k=j; k<i;k++){
                    int t = a[j][k] + a[k + 1][i] + arr[j].row * arr[k].col * arr[i].col;
                    if(a[j][i] > t){
                        a[j][i] = t;
                        p[j][i] = k;
                    }
                }
        printf("Case %d: ", kk);
        showResult(1, n);
        printf("\n");
    }
    return 0;
}
