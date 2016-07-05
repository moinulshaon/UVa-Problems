#include <stdio.h>


int f(int m,int n){
	if (m==1)
		return n-1;
	else
		return n+f(m-1,n);
}

int main()
{
	int m,n;

	while (scanf("%d %d",&m,&n)==2)
	{
		if (m>n)
			printf("%d\n",f(m,n));
		else
			printf("%d\n",f(n,m));
	}
	return 0;
}
