#include <stdio.h>
#include <math.h>

int main()
{
	unsigned time,row,column,root,var;
	int even;

	while (1)
	{
		scanf("%u",&time);
		if (time==0)
			break;
		root=(unsigned)sqrt(time-1);
		if (root%2)
			even=0;
		else 
			even=1;
		var=(root+1)*(root+1)-root;
		if (even)
		{

			if (time>=var)
			{
				row=root+1;
				column=root+1-(time-var);
			}
			else
			{
				row=root+1-(var-time);
				column=root+1;
			}	
		}
		else
		{
			if (time<=var)
			{
				row=root+1;
				column=root+1-(var-time);
			}
			else
			{
				row=root+1-(time-var);
				column=root+1;
			}
		}
		printf("%u %u\n",column,row);
	}
	return (0);
}