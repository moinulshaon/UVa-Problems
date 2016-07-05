#include <stdio.h>
#include <string.h>

#define maxm 110

char arr[maxm][maxm];
int len,line;

int process(int i,int j)
{
	int result;

	if (arr[i][j]=='W')
		result=1;
	else
		return 0;
	
	arr[i][j]='C';

	if (arr[i][j+1]=='W' && j+1<=len)
		result+=process(i,j+1);
	
	if (arr[i+1][j+1]=='W' && i+1<line && j+1<=len)
		result+=process(i+1,j+1);
	

	if (arr[i+1][j]=='W'  && i+1<line)
		result+=process(i+1,j);
	
	
	if (arr[i+1][j-1]=='W'  && i+1<line)
		result+=process(i+1,j-1);
	

	if (arr[i][j-1]=='W')
		result+=process(i,j-1);
	

	if (arr[i-1][j-1]=='W')
		result+=process(i-1,j-1);
	
	
	if (arr[i-1][j]=='W')
		result+=process(i-1,j);
	
	if (arr[i-1][j+1]=='W' && j+1<=len )
		result+=process(i-1,j+1);
	
	
	return result;
	
}

int main()
{
	int i,j,test,k,a,b;


	scanf("%d",&test);
	getchar();

	for (k=0;k<test;++k)
	{
		if (k)
			printf("\n");
		


		for (i=1;scanf("%d %d",&a,&b)!=2;i++)
				gets(&arr[i][1]);
		line=i;
		len=strlen(&arr[1][1]);

		

		getchar();
		do 
		{
			if (a<line && b<=len)
				printf("%d\n",process(a,b));
			else
				printf("0\n");
		
			for (i=1;i<line;++i)
			{
				for (j=1;j<=len+1;++j)
				{	

					if (arr[i][j]== 'C')
						arr[i][j]='W';
				}
			}
		}
		while (scanf("%d %d",&a,&b)==2);

	}
	return 0;

}