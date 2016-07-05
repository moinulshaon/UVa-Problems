#include <stdio.h>

int arr[101]={1};

int main()
{
	
	int n,k,i,temp;
	long prv,result;

	while (1)
	{
		scanf("%d %d",&n,&k);

		if (!n && !k)
			return 0;

		prv=1;

		result=1;

		temp=(n & 1)?1:0;

		for (i=1;i<k;++i)
		{
			if (i<=n/2+temp)
			{
				result+=prv*(n+i-1)/i;
				arr[i]=prv=prv*(n+i-1)/i;
			}
			else
			{
				result+=arr[n-i];
			}

			if (result>1000000)
				result%=1000000;
			
		}

		printf("%lld\n",result%1000000);

	}
}