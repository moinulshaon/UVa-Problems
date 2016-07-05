#include <stdio.h>


int path,arr1[25],arr2[25],result,des;
char fallen[25];

void process(int n)
{
	int i;

	if (n==des)
	{
		++result;
		return ;
	}
	for (i=0;i<=path;++i)
	{
		if (arr1[i]==n)
		{
			if (!fallen[arr2[i]])
			{
				fallen[arr2[i]]=1;
				process(arr2[i]);
				
			}

		}
		else if (arr2[i]==n)
		{
			if (!fallen[arr1[i]])
			{
				fallen[arr1[i]]=1;
				process(arr1[i]);
			}
		}
	}
}


int main()
{

	int i;



	while (scanf("%d",&des)==1)
	{
		
		for(path=0;;++path)
		{
			scanf("%d %d",&arr1[path],&arr2[path]);
			if (!arr1[path] && !arr2[path])
				break;
		}

		for (i=0;i<25;++i)
			fallen[i]=0;


		result=0;
		for (i=0;i<=path;++i)
		{
			if (!fallen[i])
			{
				fallen[i]=1;
				process(i);
			}
		}
		printf("%d\n",result);

	}
	return 0;
}