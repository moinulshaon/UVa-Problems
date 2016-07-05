#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;

int gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}
int main() {

	int n;
	int t = 1;
	while(1)
	{
	    scanf("%d",&n);
	    if (!n)return 0;
		printf("Case %d: ",t++);
		if(n == 1) {
			printf("2\n");
			continue;
		}
		if(n == 2147483647) {
			printf("2147483648\n");
			continue;
		}
		int m = sqrt((float)n);
		int ans = 0;
		int tmpn = n;
		int count = 0;
		for(int i = 2; i <= m; i++) {
			if(tmpn % i == 0) {
				count++;
				int tmp = 1;
				while(tmpn % i == 0) {
					tmp *= i;
					tmpn /= i;
				}
				ans += tmp;
			}
		}
		if(tmpn == n) printf("%d\n",1+n);
		else {
			if(tmpn != 1) ans += tmpn;
			else if(count == 1) ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}
