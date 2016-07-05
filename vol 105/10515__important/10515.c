#include <stdio.h>
#include <string.h>

int main()
{
    char num1[110],num2[110];
    int power,number,len1,len2,i,temp;

    while(1)
    {
        scanf("%s %s",num1,num2);
        if (!strcmp(num1,"0") && !strcmp(num2,"0"))
            return (0);
        len1=strlen(num1);
        len2=strlen(num2);

        number=num1[len1-1]-'0';
        if (len2>1)
        {
            power=(num2[len2-1]-'0')+10*(num2[len2-2]-'0');
            if (num2[len2-1]=='0' && num2[len2-2]=='0')
                power=4;
        }
        else
            power=num2[len2-1]-'0';
        if (power==0)
            number=1;
        temp=number;
        for (i=1;i<power;++i)
        {
            number=temp*number;
            number=number%10;
        }
        printf("%d\n",number);
    }


}
