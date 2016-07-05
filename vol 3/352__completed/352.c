#include <stdio.h>

#define maxm 30

char arr[maxm][maxm];

void process(int i,int j)
{
	
	
	arr[i][j]='0';

	if (arr[i][j+1]=='1' )
		process(i,j+1);
	
	if (arr[i+1][j+1]=='1')
		process(i+1,j+1);
	

	if (arr[i+1][j]=='1')
		process(i+1,j);
	
	
	if (arr[i+1][j-1]=='1')
		process(i+1,j-1);
	

	if (arr[i][j-1]=='1')
		process(i,j-1);
	

	if (arr[i-1][j-1]=='1')
		process(i-1,j-1);
	
	
	if (arr[i-1][j]=='1')
		process(i-1,j);
	
	if (arr[i-1][j+1]=='1')
		process(i-1,j+1);
	
	
	
}

int main()
{
	int i,j,a,result,k;


	for (k=1;scanf("%d",&a)==1;++k)
	{	

				
		getchar();

		for (i=1;i<=a;++i)
		{
			for (j=1;j<=a;++j)
				scanf("%c",&arr[i][j]);
			getchar();
		}
		

		result=0;
		

		for (i=1;i<=a;++i)
		{
			arr[i][a+1]='0';
			arr[a+1][i]='0';
		}
		
		for (i=1;i<=a;++i)
		{
			for (j=1;j<=a;++j)
			{	

				//printf("%c",arr[i][j]);
				if (arr[i][j]== '1')
				{
					process(i,j);
					++result;
				}
			}
			//printf("\n");
		}

		printf("Image number %d contains %d war eagles.\n",k,result);
	}

	
	return 0;

}