#include <stdio.h>

int main()
{
    int number,limit,step,i,temp,flag;

    for(i=1;1;++i)
    {
        scanf("%d %d",&number,&limit);
        temp=number;
        step=1;
        flag=0;
        if (number<0 && limit<0)
            return (0);
        while (number!=1)
        {
            if (number%2)
            {
                if((limit-1)/3<number)
                {
                    flag=1;
                    break;
                }
                else
                    number=3*number+1;
            }
            else
                number/=2;
            if (flag)
                break;
            ++step;
        }
        printf("Case %d: A = %d, limit = %d, number of terms = %d\n",i,temp,limit,step);
    }
}
