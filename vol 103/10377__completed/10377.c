#include <stdio.h>
#define  size 65

char arr[size][size];

int main()
{
	int i,test,dir,row,column,posr,posc,k;

	char c;


	scanf("%d",&test);
	getchar();



	for (k=0;k<test;++k)
	{
		getchar();
		
		if (k)
			printf("\n");

		scanf("%d %d",&row,&column);
		getchar();
		for (i=0;i<row;++i)
			gets(arr[i]);

		scanf("%d %d",&posr,&posc);
		getchar();

		dir=100000;
		while ((c=getchar())!='Q')
		{
			if (c=='R')
				++dir;
			else if (c=='L')
				--dir;
			else if (c=='F')
			{
				if (dir%4==0  && arr[posr-1-1][posc-1]!='*')
					--posr;
				else if (dir%4==2 && arr[posr+1-1][posc-1]!='*')
					++posr;
				else if (dir%4==1 && arr[posr-1][posc+1-1]!='*')
					++posc;
				else if (dir%4==3 && arr[posr-1][posc-1-1]!='*')
					--posc;
				
			}
			else if (c=='Q')
				break;


			
			
		}

		switch(dir%4)
		{
		case 0:printf("%d %d N\n",posr,posc);break;
		case 1:printf("%d %d E\n",posr,posc);break;
		case 2:printf("%d %d S\n",posr,posc);break;
		case 3:printf("%d %d W\n",posr,posc);break;
		}
	}
	return 0;
}