#include <stdio.h>


int arr[100];
int main()
{
	register i,j;
	int input,step,temp,count;

	while (1)
	{
		scanf("%d",&input);

		if (!input)
			return 0;
		
		for (i=1;;++i)
		{
			for (j=1;j<=input;++j)
				arr[j]=1;
			step=1;
			count=0;
			temp=1;
			arr[1]=0;
			while (arr[13])
			{
				count=0;
				while (count<i)
				{
					if (temp>input)
						temp=1;
					if (arr[temp])
						++count;
					++temp;
					
				}
				--temp;
				arr[temp]=0;
				++step;
				
			}
			if (step==input)
				break;
		}
		printf("%d\n",i);
	}

}