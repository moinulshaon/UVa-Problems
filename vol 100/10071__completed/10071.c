#include <stdio.h>

int main()
{
	int time,velocity;

	while (scanf("%d %d",&time,&velocity)!=EOF)
	{
		printf("%d\n",2*time*velocity);
	}
	return (0);
}