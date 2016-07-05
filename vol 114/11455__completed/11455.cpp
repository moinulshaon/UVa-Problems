#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int arr[4],test;

	scanf("%d",&test);

	while (test--)
	{
		scanf("%d %d %d %d",&arr[0],&arr[1],&arr[2],&arr[3]);

		if (arr[0]==arr[1] && arr[0]==arr[1] && arr[0]==arr[1] && arr[0]==arr[3])
			printf("square\n");
		else 
		{
			sort(arr,arr+4);

			if (arr[0]==arr[1] && arr[2]==arr[3])
				printf("rectangle\n");
			else if (arr[0]+arr[1]+arr[2]>arr[3])
				printf("quadrangle\n");
			else
				printf("banana\n");
		}
	}
	return 0;
}