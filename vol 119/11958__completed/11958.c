#include <stdio.h>

int main()
{
	int i,j,test,nowH,nowM,nowT,min,busH,busM,busT,busNo,time;

	scanf("%d",&test);
	
	for (i=1;i<=test;++i)
	{
		scanf("%d %d:%d",&busNo,&nowH,&nowM);

		nowT=nowH*60+nowM;
		min=5000;
		for (j=0;j<busNo;++j)
		{
			scanf("%d:%d %d",&busH,&busM,&time);
			
			busT=busH*60+busM;
			if (busT<nowT)
				busT=24*60+busT;

			if (busT-nowT+time<min)
				min=busT-nowT+time;
		}
		printf("Case %d: %d\n",i,min);
	}
	return 0;
	
}