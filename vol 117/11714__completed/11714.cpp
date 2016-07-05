#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
   long n;
   while (scanf("%ld",&n)==1)
   {
      --n;
      printf("%ld\n",n+long ( log2( n )));
   }
   return 0;
}
