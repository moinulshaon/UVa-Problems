#include <stdio.h>
#include <math.h>

int main()
{
	int tax,input,test,i;

	scanf("%d",&test);

	for (i=1;i<=test;++i)
	{
		scanf("%d",&input);

		if (input>1180000)
			tax=ceil(150000+(input-1180000)*.25);
		else if (input>880000)
			tax=ceil(90000+(input-880000)*.2);
		else if (input>480000)
			tax=ceil(30000+(input-480000)*.15);
		else if (input>180000)
			tax=ceil((input-180000)*.1);
		else
			tax=0;

		if (tax<2000 && tax)
			tax=2000;
		printf("Case %d: %d\n",i,tax);
	}
	return 0;
}