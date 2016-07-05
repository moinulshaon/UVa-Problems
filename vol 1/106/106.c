#include <stdio.h>
int cd(int a,int b)
{
	int temp;
	while (1)
	{
		temp=b%a;
		if (temp==0)
			break;
		b=a;
		a=temp;
	}
	if (a==1)
		return (1);
	else 
		return (0);
}

int main()
{
	int i,j,k,num,count;
	while (scanf("%d",&num))
	{
		count=0;
		for (i=1;i<=num;++i)
		{
			for (j=i+1;j<=num;++j)
			{
				if (cd(i,j))
				{
					for (k=j+1;k<=num;++k)
					{
						if (i*i+j*j==k*k)
						{
							++count;
							//printf("%d %d\n",i,j);
							/*if (cd(i,j))
							{	//printf("\n%d %d\n\n",i,j);
								//printf("%d\n",count++);
								++count;
							}*/
						}
					}
				}
			}
		//	printf("%d\n",i);
		}
		printf("%d\n",count);
	}
}