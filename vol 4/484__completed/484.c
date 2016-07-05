#include <stdio.h>

int nnum=0,occ[10000];
int num[10000];

void isin(int l)
{
	int i;
	for( i=0;i<nnum;i++)
		if(num[i]==l)
		{
			occ[i]++;
			return ;
		}
	num[nnum]=l;
	occ[nnum]++;
	nnum++;
	return ;
}
int main()
{
	int nm,nn;
	while(scanf("%d",&nm)==1)
		isin(nm);
	

	for(nn=0 ;nn<nnum ;nn++)
		printf("%d %d\n",num[nn],occ[nn]);
	
	return 0;
}