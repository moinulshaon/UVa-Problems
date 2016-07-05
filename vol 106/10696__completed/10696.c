#include <stdio.h>

unsigned f91(unsigned number)
{
	if (number>101)
		return (number-10);
	else
		return (91);
}

int main()
{
	unsigned number;

	while (1)
	{
		scanf("%u",&number);
		if (number==0)
			break;

		printf("f91(%u) = %u\n",number,f91(number));
	}
	return (0);
}