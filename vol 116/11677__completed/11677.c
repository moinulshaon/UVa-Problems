#include <stdio.h>




int main()
{
	int h1,m1,h2,m2,result;

	while (1)
	{
		scanf("%d %d %d %d",&h1,&m1,&h2,&m2);

		if (!h1 && !m1 && !h2 && !m2)
			return 0;

		m1=h1*60+m1;
		m2=h2*60+m2;

		result=m2-m1;

		if (result<0)
			result=24*60+result;

		printf("%d\n",result);


	}
}

