#include <stdio.h>
#define size 10100

int m,result,arr1[size],arr2[size];
char fallen[size];

void process(int n)
{
	int i;
	for (i=0;i<m;++i)
	{
		if (arr1[i]==n)
		{
			if (!fallen[arr2[i]])
			{
				++result;
				fallen[arr2[i]]=1;
				process(arr2[i]);
				
			}
		}
	}
}


int main()
{

	int fall,test,i,temp,total;

	freopen("input.txt","r",stdin);

	scanf("%d",&test);

	while (test--)
	{
		scanf("%d %d %d",&total,&m,&fall);

		result=0;

		for (i=0;i<m;++i)
			scanf("%d %d",&arr1[i],&arr2[i]);

		for (i=0;i<total;++i)
			fallen[i]=0;

		for (i=0;i<fall;++i)
		{
			scanf("%d",&temp);

			if (!fallen[temp])
			{
				++result;
				fallen[temp]=1;
				process(temp);
				
			}

		}
		printf("%d\n",result);
	}
	return 0;
}