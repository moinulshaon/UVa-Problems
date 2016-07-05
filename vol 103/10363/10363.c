#include <stdio.h>

int breakcondition(char board[][4])
{
	int i,j,sum1,sum2,gamex=0,gamey=0;
	for (i=0;i<3;++i)
	{
		sum1=0;
		sum2=0;
		for (j=0;j<3;++j)
		{
			sum1+=board[i][j];
			sum2+=board[j][i];
		}
		if (sum1==3*'X'|| sum2==3*'X')
			gamex=1;
		if (sum1==3*'O'|| sum2==3*'O')
			gamey=1;

	}
	/*sum1=board[0][0]+board[1][1]+board[2][2];
	sum2=board[0][2]+board[1][1]+board[2][0];
	if (sum1==3*'X'|| sum2==3*'X')
			gamex=1;
	if (sum1==3*'O'|| sum2==3*'O')
			gamey=1;*/
	if (gamex && gamey)
		return (1);
	else
		return (0);
}

int main()
{
	char board[3][4];

	int test,i,j,x,o;

	scanf("%d",&test);

	while (test--)
	{
		o=x=0;
		scanf("%s",board[0]);
		scanf("%s",board[1]);
		scanf("%s",board[2]);
		for (i=0;i<3;++i)
			for (j=0;j<3;++j)
			{
				if (board[i][j]=='X')
					++x;
				else if (board[i][j]=='O')
					++o;
			}
		if (!(o-x==0 || x-o==1))
		{
			printf("no1\n");

		}
		else if (breakcondition(board))
		{
			printf("no2\n");

		}
		else
			printf("yes\n");

	}

}