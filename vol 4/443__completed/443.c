#include <stdio.h>
#include <string.h>
#define size 5843


int arr[size];

int main()
{
	int input;


	int count,x,y,z,w,ptr2,ptr3,ptr5,ptr7,rem;

	char temp[5];
	arr[0]=1;
	ptr2=ptr3=ptr5=ptr7=0;

	for (count=1;count<size;++count)
	{
		x=2*arr[ptr2];
		y=3*arr[ptr3];
		z=5*arr[ptr5];
		w=7*arr[ptr7];

		if (x<y && x<z && x<w)
		{
			arr[count]=x;
			++ptr2;
		}
		else if (y<x && y<z && y<w)
		{
			arr[count]=y;
			++ptr3;
		}
		else if (z<x && z<y && y<w)
		{
			arr[count]=z;
			++ptr5;
		}
		else if (w<x && w<y && w<z)
		{
			arr[count]=w;
			++ptr7;
			
		}
		else if (x==w)
		{
			arr[count]=x;
			++ptr7;
			--count;
		}
		else if (y==w)
		{
			arr[count]=y;
			++ptr7;
			--count;
		}
		else if (z==w)
		{
			arr[count]=z;
			++ptr7;
			--count;
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

	while (1)
	{
		scanf("%d",&input);

		if (!input)
			return 0;
		rem=input%10;
		if ((input%100 - rem) == 10)
			strcpy(temp,"th");
		else if (rem==1)
			strcpy(temp,"st");
		else if (rem==2)
			strcpy(temp,"nd");
		else if (rem==3)
			strcpy(temp,"rd");
		else
			strcpy(temp,"th");

		printf("The %d%s humble number is %d.\n",input,temp,arr[input-1]);
	}
	
}