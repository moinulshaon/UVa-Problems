#include <stdio.h>

int main()
{
	int test,min,max,ant,input,len,i;

	scanf("%d",&test);

	while (test--)
	{
		scanf("%d %d",&len,&ant);

		min=0;
		max=0;
		for (i=0;i<ant;++i)
		{
			scanf("%d",&input);

			if (input<=len/2)
			{
				if (input>min)
					min=input;
				if (len-input>max)
					max=len-input;
			}
			else
			{	
				if (len-input>min)
					min=len-input;
				if (input>max)
					max=input;
			}
		}
		printf("%d %d\n",min,max);
	}
	return (0);
}