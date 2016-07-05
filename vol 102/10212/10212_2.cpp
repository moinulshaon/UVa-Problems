#include<cstdio>

int getx(int n,int x)
{
    if(n==0)  return 0;
    return n/x+getx(n/x,x);
}

int g(int n,int x)
{
    if(n==0)  return 0;
    return n/10+(n%10>=x)+g(n/5,x);
}

int get(int n,int x)
{
    if(n==0)  return 0;
    return get(n/2,x)+g(n,x);
}

int table[4][4] =
{
    6,2,4,8,//2
    1,3,9,7,//3
    1,7,9,3,//7
    1,9,1,9,//9
};//3，7，9
int main()
{
    //freopen("in.in","r",stdin);
    //freopen("out2.in","w",stdout);
    int n,m;
    int num2,num3,num5,num7,num9;
    while(scanf("%d%d",&n,&m)!=EOF)//n!/(n-m)!
    {
        num2=getx(n,2)-getx(n-m,2);
        num3=get(n,3)-get(n-m,3);
        num5=getx(n,5)-getx(n-m,5);
        num7=get(n,7)-get(n-m,7);
        num9=get(n,9)-get(n-m,9);
        int res=1;
        if(num5>num2)
        {
            printf("5\n");
            continue;
        }
        else
        {
            if(num2!=num5)
            {
                res*=table[0][(num2-num5)%4];
                res=res%10;
            }
            res*=table[1][num3%4];
            res%=10;
            res*=table[2][num7%4];
            res%=10;
            res*=table[3][num9%4];
            res%=10;
        }
        printf("%d\n",res);
    }
    return 0;
}
