#include <stdio.h>

#define size 201

char arr[size];


int main()
{
	int test,k,i,len,count;

	freopen("input.txt","r",stdin);

	scanf("%d",&test);
	getchar();

	for (k=1;k<=test;++k)
	{
		scanf("%d",&len);
		getchar();
		gets(arr);


		count=0;

		for (i=0;i<len;i+=3)
		{
			while (arr[i]=='#')
				i++;
			if (i>=len)
				break;
			count+=1;

		}


		printf("Case %d: %d\n",k,count);

	}
	return 0;

}
