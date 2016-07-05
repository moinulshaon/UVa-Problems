#include <stdio.h>
#define size 10000001

char prime[size];
int count,arr[4];

void process2(int num)
{
	int i;


	for (i=1;;i++)
	{
		if (!prime[i] && !prime[num-i])
		{
			arr[count]=i;
			arr[count+1]=num-i;
			count+=2;
			return ;
		}
	}
}




int main()
{
	int i,j,input;


	prime[0]=prime[1]=1;

	for (i=2;i<=3162;++i)
		if (prime[i]==0)
			for (j=2*i;j<size;j+=i)
				prime[j]=1;


	while (scanf("%d",&input)==1)
	{


		count=0;

		
		if (input<8)
			printf("Impossible.\n");
		else if (input%2)
		{
			process2(input-5);
			printf("%d %d %d %d\n",2,3,arr[0],arr[1]);
		}
		else
		{
			if ((input/2)%2)
			{
				process2(input/2-1);
				process2(input/2+1);
				printf("%d %d %d %d\n",arr[0],arr[1],arr[2],arr[3]);

				
			}
			else
			{
				process2(input/2);
				printf("%d %d %d %d\n",arr[0],arr[0],arr[1],arr[1]);
				
			}
				
			
		}
		
		
	}
	return 0;
}
