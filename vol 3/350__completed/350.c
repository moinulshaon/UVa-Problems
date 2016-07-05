#include <stdio.h>

char arr[1000000];
int main()
{
	register j;
	int z,l,i,m,step,k;

	for (k=1;;++k)
	{
		scanf("%d %d %d %d",&z,&i,&m,&l);
		if (z==0 && i==0 && m==0 && l==0)
			return 0;

		for (j=0;j<1000000;++j)
			arr[j]=0;
		step=0;
		while (1)
		{	
			l=(z*l+i)%m;
			if (arr[l])break;
			arr[l]=1;
			++step;
		}
		printf("Case %d: %d\n",k,step);
	}
}