#include<stdio.h>

int main()
{
   unsigned long long N,B;
   while(scanf("%llu",&N)==1)
   {
      if(!N)
         return 0;
      B = N*10/9;
      if(N%9==0)
         printf("%llu %llu\n",B-1,B);
      else
         printf("%llu\n",B);
   }
}
