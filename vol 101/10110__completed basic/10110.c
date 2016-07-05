#include <stdio.h>
#include <math.h>

int main()
{
	unsigned bulb,root;

	while (1)
	{
		scanf("%u",&bulb);
		if (!bulb)
			break;

		root=(unsigned)sqrt(bulb);

		if (root*root==bulb)
			printf("yes\n");
		else
			printf("no\n");
	}
	return (0);
}