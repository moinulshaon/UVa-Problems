#include <stdio.h>
#include <string.h>
#define limit 102
int main()
{
	int i,len,flag,j;
	char number[limit];
	char sum[limit];
	for (i=0;i<limit;++i)
		sum[i]='0';

	while (1)
	{
		scanf("%s",number);
		if (strcmp(number,"0")==0)
			break;
		len=strlen(number);
		for (i=0;i<len;++i)
		{
			sum[i]+=number[len-i-1]-'0';
			j=i;
			
			while (sum[j]>'9')
			{

				sum[j]-=10;
				++j;
				sum[j]+=1;
		
			}
		}
	

	}
	flag=0;
	for (i=0;i<limit;++i)
	{
		if (flag==0 && sum[limit-1-i]!='0')
		{
			printf("%c",sum[limit-1-i]);
			flag=1;
			continue;
		}
		if (flag)
			printf("%c",sum[limit-1-i]);

	}
	printf("\n");
	return (0);
	
}