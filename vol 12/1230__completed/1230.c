#include <stdio.h>

int square(int k)
{
    return k * k;
}

int BigMod(int a, int n, int p)
{
    if(n == 1)  return a % p;
    else if(n % 2 == 0)  return square(BigMod(a, n/2, p)) % p;
    else return ((square(BigMod(a, n/2, p))%p)*(a % p)) % p;
}


int main()
{
    int kase,x,y,n;
    scanf("%d",&kase);
    while (kase--)
    {
        scanf("%d %d %d",&x,&y,&n);
        printf("%d\n",BigMod(x,y,n));
    }
    return 0;

}
