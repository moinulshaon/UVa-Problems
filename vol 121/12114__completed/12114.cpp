#include<stdio.h>
int main()
{
    long long int b,s;
    int i=1;
    while(scanf("%lld %lld",&b,&s))
    {
        if(b==0 && s==0)
            break;
        if ( s>b )s=b;
        if ( b== 1 ){
            printf("Case %d: :-\\\n",i);
        }else if(b*(s-1)== s*(b-1))
            printf("Case %d: :-|\n",i);
        else if(b*(s-1)<s*(b-1))
            printf("Case %d: :-(\n",i);
        else
            printf("Case %d: :-)\n",i); // this will never happen

        i++;
    }
    return 0;
}
