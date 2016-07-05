#include <stdio.h>



int main()
{
	int arr[1500],count,x,y,z,ptr2,ptr3,ptr5;

	arr[0]=1;
	ptr2=ptr3=ptr5=0;

	for (count=1;count<1500;++count)
	{
		x=2*arr[ptr2];
		y=3*arr[ptr3];
		z=5*arr[ptr5];

		if (x<y && x<z)
		{
			arr[count]=x;
			++ptr2;
		}
		else if (y<x && y<z)
		{
			arr[count]=y;
			++ptr3;
		}
		else if (z<x && z<y)
		{
			arr[count]=z;
			++ptr5;
		}
		else if (x==y)
		{
			arr[count]=x;
			++ptr3;
			--count;
		}
		else if (y==z)
		{
			arr[count]=y;
			++ptr5;
			--count;
		}
		else if (x==z)
		{
			arr[count]=x;
			++ptr5;
			--count;
		}
	}
	printf("The 1500'th ugly number is %d.\n",arr[1499]);
	return (0);

}
