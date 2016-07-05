#include <stdio.h>

int main()
{
	int input,k;

	for (k=1;;++k)
	{
		scanf("%d",&input);
		if (!input)return 0;

		printf("Case %d: %d\n",k,input>>1);
	}
}