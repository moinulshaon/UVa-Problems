#include <stdio.h>
#include <string.h>

#define maxm 28

char arr[maxm][maxm];

int process(int i,int j)
{
	int result=1;
	
	arr[i][j]='0';

	if (arr[i][j+1]=='1')
		result+=process(i,j+1);
	

	
	if (arr[i+1][j+1]=='1')
		result+=process(i+1,j+1);
	

	if (arr[i+1][j]=='1')
		result+=process(i+1,j);
	
	
	if (arr[i+1][j-1]=='1')
		result+=process(i+1,j-1);
	

	if (arr[i][j-1]=='1')
		result+=process(i,j-1);
	

	if (arr[i-1][j-1]=='1')
		result+=process(i-1,j-1);
	
	
	if (arr[i-1][j]=='1')
		result+=process(i-1,j);
	
	if (arr[i-1][j+1]=='1')
		result+=process(i-1,j+1);
	
	
	return result;
	
}

int main()
{
	int i,j,test,len,line,temp,max,k;


	scanf("%d",&test);
	getchar();
	getchar();

	for (k=0;k<test;++k)
	{
		if (k)
			printf("\n");
		

		for (i=1;gets(&arr[i][1]);i++)
			if (!arr[i][1])
				break;
		len=strlen(&arr[1][1]);
		line=i;
		max=0;

		for (i=1;i<line;++i)
		{
			for (j=1;j<=len;++j)
			{
				if (arr[i][j]=='1')
				{
					temp=process(i,j);
					if (temp>max)
						max=temp;
					
				}
			}
		}

		printf("%d\n",max);

	}
	return 0;

}