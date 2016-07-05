#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;

long mystrtol(char *str, int b) {
  long result = 0;
  for(int i=0; i<strlen(str); i++) {
    result = result * b + str[i]-'0';
  }
  return result;
}
int main()
{
  char str[100];
  char *end;
  long a, i, max;
  scanf("%s", str);
  while( str[0] != '0' ) {
    max = 0;
    for(i = strlen(str)-1; i>=0; i--)
      if( str[i] - '0' > max)
        max = str[i] - '0';
    for(i=max+1; i<100; i++) {
      a = mystrtol(str, i);
      if( (long)sqrt( a ) * (long)sqrt( a ) == a)
        break;
    }
    printf("%ld\n", i);
    scanf("%s", str);
  }
  return 0;
}
