#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	long long  test,k,arr[3];

	scanf("%lld",&test);

	for (k=1;k<=test;++k)
	{
		scanf("%lld %lld %lld",&arr[0],&arr[1],&arr[2]);

		sort(arr,arr+3);

		if (arr[0]+arr[1]<=arr[2])
			printf("Case %lld: Invalid\n",k);
		else if (arr[0]==arr[1] && arr[0]==arr[2])
			printf("Case %lld: Equilateral\n",k);
		else if ( arr[0]==arr[1] || arr[1]==arr[2] || arr[0]==arr[2] )
			printf("Case %lld: Isosceles\n",k);
		else
			printf("Case %lld: Scalene\n",k);

	}
	return 0;
}
