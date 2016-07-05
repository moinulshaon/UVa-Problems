#include <stdio.h>

int main()
{
	int numbers[1001],count,i,j,flip,temp,flipcount;

	while (scanf("%d",&count)!=EOF)
	{
		for (i=0;i<count;++i)
			scanf("%d",&numbers[i]);
		flip=0;
		for (i=0;i<count;++i)
		{
			flipcount=flip;
			for (j=0;j<count-i-1;++j)
			{
				if (numbers[j+1]<numbers[j])
				{
					temp=numbers[j+1];
					numbers[j+1]=numbers[j];
					numbers[j]=temp;
					++flip;
				}
			}
			if (flipcount==flip)
				break;
		}
		printf("Minimum exchange operations : %d\n",flip);
	}
	return (0);
}