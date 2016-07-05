#include <stdio.h>

int main()
{
	int test,arr[10],i,temp,number;

	scanf("%d",&test);

	while (test--)
	{
		for (i=0;i<10;++i)
			arr[i]=0;
		scanf("%d",&number);

		temp=number;
		while (temp!=0)
		{
			number=temp--;
			while (number!=0)
			{
				++arr[number%10];
				number/=10;
			}
		}

		for (i=0;i<9;++i)
			printf("%d ",arr[i]);
		printf("%d",arr[9]);
		printf("\n");
		


	}
	return (0);
}