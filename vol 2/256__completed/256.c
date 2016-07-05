#include <stdio.h>
#include <math.h>

int checkQuirk(int number,int digit)
{
	int a,b,c;
	c=(int)pow(10,digit/2);
	a=number/c;
	b=number%c;
	if ((a+b)*(a+b)==number)
		return (1);
	else 
		return (0);
}

int main()
{
	int squres[10000],i,count=0,result[4][100],a=0,b=0,c=0,d=0,test;

	for (i=0;i<=9999;++i)
		squres[i]=i*i;

	for (i=0;i<=9999;++i)
	{
		if (checkQuirk(squres[i],8))
			result[3][d++]=squres[i];
		if (squres[i]<=999999)
		{
			if (checkQuirk(squres[i],6))
				result[2][c++]=squres[i];
			if (squres[i]<=9999)
			{
				if (checkQuirk(squres[i],4))
					result[1][b++]=squres[i];
				if (squres[i]<=99)
				{
					if (checkQuirk(squres[i],2))
						result[0][a++]=squres[i];
				}
			}
		}
		
	}

	while (scanf("%d",&test)==1)
	{
		if (test==2)
		{
			for (i=0;i<a;++i)
				printf("%02d\n",result[0][i]);
		}
		else if (test==4)
		{
			for (i=0;i<b;++i)
				printf("%04d\n",result[1][i]);
		}
		else if (test==6)
		{
			for (i=0;i<c;++i)
				printf("%06d\n",result[2][i]);
		}
		else if (test==8)
		{
			for (i=0;i<d;++i)
				printf("%08d\n",result[3][i]);
		}
	}
	return (0);



	

}