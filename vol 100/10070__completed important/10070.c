#include <stdio.h>
#include <string.h>

int divisible4(char *ptr,int len)
{
	int last2digit;
	last2digit=ptr[len-1]-'0'+10*(ptr[len-2]-'0');
	if (last2digit%4)
		return (0);
	else 
		return (1);
}
int divisible3(char *ptr,int len)
{
	int i,digitsum=0;
	for (i=0;i<len;++i)
		digitsum+=ptr[i]-'0';
	if (digitsum%3)
		return 0;
	else 
		return 1;

}
int divisible11(char *ptr,int len)
{
	int i,sum=0;
	for (i=0;i<len;++i)
	{
		if (i%2)
			sum+=ptr[i]-'0';
		else
			sum-=ptr[i]-'0';
	}
	if (sum%11)
		return (0);
	else 
		return (1);
}

int main()
{
	char year[2001];

	int var4,var100,var400,var5,var3,var11,len,temp,flag,leapyear,first=1;

	while (scanf("%s",year)==1)
	{
		leapyear=0;
		flag=1;
		len=strlen(year);

		var400=0;
		var4=divisible4(year,len);
		var100=(year[len-1]=='0' && year[len-2]=='0')?1:0;
		if (var100)
		{
			temp=year[len-3]-'0'+10*(year[len-4]-'0');
			var400=(temp%4)?0:1;
		}

		if ((var4 && !var100) || var400)
		{
			if (flag && !first)
				printf("\n");
			printf("This is leap year.\n");
			flag=0;
			leapyear=1;
		}

		var5=(year[len-1]=='0'||year[len-1]=='5')?1:0;
		var3=divisible3(year,len);
		var11=divisible11(year,len);
		if (var3 && var5)
		{
			if (flag && !first)
				printf("\n");
			printf("This is huluculu festival year.\n");
			flag=0;
		}
		if (var5 && var11 && leapyear)
		{
			if (flag && !first)
				printf("\n");
			printf("This is bulukulu festival year.\n");
			flag=0;
		}
		if (flag)
		{
			if (!first)
				printf("\n");
			printf("This is an ordinary year.\n");
		}
		first=0;

	}
	return (0);
}