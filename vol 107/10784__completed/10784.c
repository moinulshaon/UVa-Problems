#include <stdio.h>
#include <math.h>

int main()
{
	int i;
	long input,result;
	

	for (i=1;;++i)
	{
		scanf("%ld",&input);
		if (!input)
			return 0;
		
		result=ceil((3+sqrt(9+8*input))/2);

		printf("Case %d: %ld\n",i,result);
	}
}