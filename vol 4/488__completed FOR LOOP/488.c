#include <stdio.h>

int main()
{
	int amp,freq;
	int test,i,j,k,var,flag,x;

	scanf("%d",&test);

	for (i=0;i<test;++i)
	{
		scanf("%d",&amp);
		scanf("%d",&freq);
		var=1;
		for (j=0;j<freq;++j)
		{
			var=1;
			flag=0;
			for (k=0;k<2*amp-1;++k)
			{
				
				for (x=0;x<var;++x)
				{
					printf("%d",var);
				}
				printf("\n");
				if (var==amp)
					flag=1;
				if (flag)
					--var;
				else
					++var;
			}
			if (j!=freq-1)
				printf("\n");

		}
		if (i!=test-1)
			printf("\n");
	}
	
	return (0);
}