#include <stdio.h>

int main()
{
	unsigned long number,temp;

	while (1)
	{
		scanf("%lu",&number);

		if (number==0)
			break;
		while (number>9)
		{
			temp=number;
			number=0;
			while (temp!=0)
			{
				number+=temp%10;
				temp/=10;
			}
		}
		printf("%lu\n",number);
	}
	return (0);
}
