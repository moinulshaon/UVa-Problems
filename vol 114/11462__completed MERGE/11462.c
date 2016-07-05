#include <stdio.h>
#define sz 2000010  
#define inf 1000000  
int a[sz+2],L[sz+2],R[sz+2];   

void merge(int p,int q,int r)
{    
	int i,j,k,ind1,ind2;    
  
	for(i = p,ind1 = 1;i <= q;i++)
	{
		L[ind1++] = a[i];    
	}    
	L[ind1] = inf;    
  
	for(i = q+1,ind2 = 1;i <= r;i++)
	{    
		R[ind2++] = a[i];    
	}    
	R[ind2] = inf;    
  
	i = j = 1;    
  
	for(k = p;k <= r;k++)
	{    
		if(L[i] > R[j])
		{        
			a[k] = R[j];    
			j++;    
		}    
		else
		{    
			 a[k] = L[i];    
			 i++;    
		}    
	}    
}    
  
void mergeSort(int p,int r)
{    
	if(p < r)
	{    
		int q = (p+r)/2;    
		mergeSort(p,q);    
		mergeSort(q+1,r);    
		merge(p,q,r);    
	}    
}    
  
int main(){    
	int i,n;    
  
	while(scanf("%d",&n) == 1)
	{   
		
		if (!n)return 0;

		for(i = 1;i <= n; i++)
		{    
			scanf("%d",&a[i]);    
		}    
		mergeSort(1,n);
		printf("%d",a[1]);
		for (i=2;i<=n;++i)
			printf(" %d",a[i]);
		printf("\n");
	}    
  
	return 0;    
}  