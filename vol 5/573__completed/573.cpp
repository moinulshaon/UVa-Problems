#include <cstdio>


using namespace std;

int main()
{
    int h,u,d,f,i;
    double sum,temp;

    while (true)
    {
        scanf("%d %d %d %d",&h,&u,&d,&f);

        if (!h && !u && !d && !f)return 0;

        sum=0;

        i=0;
        do
        {
            temp=1-i*double(f)/100;
            if (temp<=0)
                ;
            else
                sum+=u*temp;


            ++i;
            if (sum>h)
                break;
            else
                sum-=d;
        }while(sum<h && sum>=0);

        if (sum>h)
        printf("success on day %d\n",i);
        else printf("failure on day %d\n",i);
    }
}
