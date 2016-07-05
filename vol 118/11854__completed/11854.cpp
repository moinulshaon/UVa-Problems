#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int arr[3];

	while (1)
	{
		scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);

		if (!arr[0] && !arr[1] && !arr[2])
			return 0;

		sort(arr,arr+3);

		if (arr[0]*arr[0]+arr[1]*arr[1]==arr[2]*arr[2])
			printf("right\n");
		else
			printf("wrong\n");
	}
}