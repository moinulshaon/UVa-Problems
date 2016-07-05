#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int test,k,arr[3];

	scanf("%d",&test);

	for (k=1;k<=test;++k)
	{
		scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);

		sort(arr,arr+3);
		
		printf("Case %d: %d\n",k,arr[1]);
		

	}
	return 0;
}