#include <stdio.h>

char arr[100];
void recursion(int i)
{
    int number;
    if (arr[i]!='\0')
        recursion(i+1);
    else
        return ;
    number=(int)arr[i];
    //printf("%d\n",number);
    while(number)
    {
        printf("%d",number%10);
        number/=10;
    }

    return ;
}

int main()
{
    int i;
    while (gets(arr))
    {
        if (arr[0]>='0' && arr[0]<='9')
        {
            for (f=0;arr[i]!='\0';++i)
            {
                number=
            }
        }

        else
            recursion(0);
    }
    return (0);
}
