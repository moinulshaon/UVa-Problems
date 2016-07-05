#include <stdio.h>
#include <math.h>

int main()
{
	int x,y,row,column,scentFlag[55][55]={0},lost,temp,dir,i;
	char finalDir,dirFirst,commands[200]; 

	scanf("%d %d",&column,&row);
	++column;
	++row;

	while (scanf("%d %d %c",&x,&y,&dirFirst)==3)
	{
		lost=0;

		if (dirFirst=='E')
			dir=0;
		else if (dirFirst=='N')
			dir=1;
		else if (dirFirst=='W')
			dir=2;
		else if (dirFirst=='S')
			dir=3;
		getchar();
		gets(commands);
		for (i=0;commands[i]!='\0' && !lost;++i)
		{
			if (commands[i]=='L')
				++dir;
			else if (commands[i]=='R')
				--dir;
			else if (commands[i]=='F')
			{
				temp=dir%4;
				if (temp<0)
					temp=4+temp;
				if (temp==0)
					++x;
				else if (temp==1)
					++y;
				else if (temp==2)
					--x;
				else
					--y;
				if (x<0 || x>=column || y<0 || y>=row)
				{
					lost=1;
					if (temp==0)
						--x;
					else if (temp==1)
						--y;
					else if (temp==2)
						++x;
					else
						++y;
					if (scentFlag[x][y])
						lost=0;
				}
				
			}
			
		}
		temp=dir%4;
		if (temp<0)
			temp=4+temp;
		if (temp==0)
			finalDir='E';
		else if (temp==1)
			finalDir='N';
		else if (temp==2)
			finalDir='W';
		else
			finalDir='S';
		if (lost)
		{	
			scentFlag[x][y]=1;
			printf("%d %d %c LOST\n",x,y,finalDir);
		}
		else 
			printf("%d %d %c\n",x,y,finalDir);
	}
	return 0;
}