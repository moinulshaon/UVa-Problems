#include <stdio.h>

int main()
{
	int fromY,toY,fromX,toX,i,j,board[8][8],step,m,n;

	char temp,temp2;

	freopen("input.txt","r",stdin);

	while (scanf("%c%d %c%d",&temp,&fromY,&temp2,&toY)==4)
	{
		getchar();
		fromX=temp-'a';
		--fromY;
		toX=temp2-'a';
		--toY;
		step=1;

		for (i=0;i<8;++i)
			for (j=0;j<8;++j)
				board[i][j]=0;

		board[fromX][fromY]=1;

		while (board[toX][toY]==0)
		{
			for (i=0;i<8;++i)
			{
				for (j=0;j<8;++j)
				{
					if (board[i][j]==step)
					{
						if (i+1<8)
						{
							if (j+2<8)
								if (!board[i+1][j+2])
									board[i+1][j+2]=step+1;
							if (j-2>=0)
								if (!board[i+1][j-2])
									board[i+1][j-2]=step+1;


							if (i+2<8)
							{
								if (j+1<8)
									if (!board[i+2][j+1])
										board[i+2][j+1]=step+1;
								if (j-1>=0)
									if (!board[i+2][j-1])
										board[i+2][j-1]=step+1;
							}
						}
						if (i-1>=0)
						{
							if (j+2<8)
								if (!board[i-1][j+2])
									board[i-1][j+2]=step+1;
							if (j-2>=0)
								if (!board[i-1][j-2])
									board[i-1][j-2]=step+1;
							if (i-2>=0)
							{
								if (j+1<8)
									if (!board[i-2][j+1])
										board[i-2][j+1]=step+1;
								if (j-1>=0)
									if (!board[i-2][j-1])
										board[i-2][j-1]=step+1;
							}
						}
					}
				}
            }

			/*printf("Board\n");
			for (m=0;m<8;++m)
			{
				for (n=0;n<8;++n)
				{
					printf("%d ",board[m][n]);
				}
				printf("\n");
			}
			getchar();*/
			++step;
			

        }
        printf("To get from %c%d to %c%d takes %d knight moves.\n",fromX+'a',fromY+1,toX+'a',toY+1,step-1);
    }
	return (0);
}
