#include <cstdio>
#include <iostream>
#include <cmath>
#define min(m,n) ((m)<(n))?(m):(n)

using namespace std;

int main()
{
	int test,row,column,result;
	char piece;

	
	scanf("%d",&test);
	while (test--)
	{
		cin>>piece>>row>>column;

		if (piece=='r')
			printf("%d\n",min(row,column));
		else if (piece=='Q')
			printf("%d\n",min(row,column));
		else if (piece=='k')
		{
			result=ceil(row*column/2.0);
			printf("%d\n",result);
		}
		else if (piece=='K')
		{
			result=ceil((double)(row)/2);
			result*=ceil((double)(column)/2);
			printf("%d\n",result);
		}
	}
	return 0;

}