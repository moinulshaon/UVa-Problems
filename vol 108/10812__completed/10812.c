#include <stdio.h>

int main()
{
	long apb,amb,x,y;
	int test;

	scanf("%d",&test);

	while(test--)
	{
		scanf("%ld %ld",&apb,&amb);
		if (amb>apb || (apb+amb)%2!=0 || (apb-amb)%2!=0)
		{
			printf("impossible\n");
			continue;
		}
		
		x=(apb+amb)/2;
		y=apb-x;
		printf("%ld %ld\n",x,y);
	}
	return (0);
}