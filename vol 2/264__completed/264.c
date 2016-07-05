#include <stdio.h>
#define size 2300

int arr[size];

int main()
{
	int i,temp=5,test,row,column,temp2;

	arr[0]=1;
	for (i=1;i<2300;++i)
	{
		arr[i]=arr[i-1]+temp;
		temp+=4;
	}

	

	while (scanf("%d",&test)==1)
	{
		for (i=0;arr[i]<test;++i)
			;

		temp=arr[i]-test;
		if (temp<2*i+1)
		{
			column=2*i+1-temp;
			row=temp+1;
		}
		else
		{
			temp2=arr[i]-2*i-1;
			temp=temp2-test;
			column=temp+1;
			row=2*i-temp;
		}

		printf("TERM %d IS %d/%d\n",test,row,column);
	}
	return 0;

}