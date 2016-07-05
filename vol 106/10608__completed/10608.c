#include <stdio.h>


int m,result,arr1[500001],arr2[500001];
char fallen[30001];

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
		else if (arr2[i]==n)
		{
			if (!fallen[arr1[i]])
			{
				++result;
				fallen[arr1[i]]=1;
				process(arr1[i]);
			}
		}
	}
}


int main()
{

	int test,i,max,total;

	freopen("input.txt","r",stdin);

	scanf("%d",&test);


	while (test--)
	{
		scanf("%d %d",&total,&m);

		

		for (i=0;i<m;++i)
			scanf("%d %d",&arr1[i],&arr2[i]);

		for (i=1;i<=total;++i)
			fallen[i]=0;


		max=0;
		for (i=1;i<=total;++i)
		{
			result=0;
			if (!fallen[i])
			{
				++result;
				fallen[i]=1;
				process(i);
			}
			if (result>max)max=result;
		}
		printf("%d\n",max);

	}
	return 0;
}