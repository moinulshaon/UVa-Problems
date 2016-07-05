#include <stdio.h>
#define size 7489


int arr[size+6]={1};

int main()
{

	int i,j,input;

	int coin[]={1,5,10,25,50};


	for (i=0;i<5;++i)
		for (j=0;j<=size;++j)
			if (j-coin[i]>=0)
				arr[j]+=arr[j-coin[i]];

	while (scanf("%d",&input)==1)
		printf("%d\n",arr[input]);
	
	
	return 0;

	
}