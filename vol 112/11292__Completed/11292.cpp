#include <cstdio>
#define inf 100000000

using namespace std;

int marr[20002];
int narr[20002];

int L[20001+2],R[20001+2];

void merge(int a[],int p,int q,int r)
{
	int i,j,k,ind1,ind2;

	for(i = p,ind1 = 1;i <= q;i++)
	{
		L[ind1++] = a[i];
	}
	L[ind1] = inf;

	for(i = q+1,ind2 = 1;i <= r;i++){
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

void mergeSort(int a[],int p,int r)
{
	if(p < r)
	{
		int q = (p+r)/2;
		mergeSort(a,p,q);
		mergeSort(a,q+1,r);
		merge(a,p,q,r);
	}
}


int main()
{
    int m,n;

    while (true)
    {
        scanf("%d %d",&m,&n);

        if (!m && !n)return 0;

        for (int i=1;i<=m;++i)
            scanf("%d",&marr[i]);
        for (int i=1;i<=n;++i)
            scanf("%d",&narr[i]);

        mergeSort(marr,1,m);
        mergeSort(narr,1,n);

        int cnt=0,pointer=1;
        for (int i=1;i<=n && pointer<=m;++i)
        {
            if (narr[i]>=marr[pointer])
            {
                cnt+=narr[i];
                pointer++;
            }
        }
        if (pointer==m+1)
            printf("%d\n",cnt);
        else
            printf("Loowater is doomed!\n");
    }

}
