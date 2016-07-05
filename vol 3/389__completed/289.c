#include <stdio.h>
#include <math.h>
#include <string.h>

long maxlimit[17]={0,0,127,2186,16383,78124,279935,823542,2097151,4782968,9999999,19487170,35831807,62748516,105413503,170859374,268435455};

int main()
{
	char arr[10],result[10];

	int len,i,basei,basen,temp;
	long input;


	while (scanf("%s %d %d",arr,&basei,&basen)!=EOF)
	{

		input=0;

		len=strlen(arr);

		for (i=len-1;i>=0;--i)
		{
			if (arr[i]>='A')
				input+=(arr[i]-'A'+10)*(long)pow(basei,len-1-i);
			else
				input+=(arr[i]-'0')*(long)pow(basei,len-1-i);
		}

		if (input>maxlimit[basen])
		{
			printf("  ERROR\n");
		}
		else if (!input)
		{
			printf("      0\n");
		}
		else if (basen==10)
		{
			printf("%7d\n",input);
		}
		else
		{
			for (i=6;i>=0;--i)
			{
				temp=input%basen;

				if (temp>9)
					result[i]='A'+temp-10;
				else if (!input)
					result[i]=' ';
				else 
					result[i]=temp+'0';

				input/=basen;
			}
			result[7]='\0';
			printf("%s\n",result);
		}	

	}
	return 0;
}