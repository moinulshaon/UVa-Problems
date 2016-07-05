#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){

    int kase;
    scanf("%d",&kase);
    char str[10];
    int num;
    while( kase-- ){
        scanf("%4s%d",str,&num);
        int len=3;
        int sum=0;
        for (int i=0;i<len;++i){
            sum+= (str[len-1-i]-'A')*int( pow(26,i)+1e-6 );
        }
        //printf("%d %d %s\n",num,sum,str);
        if ( abs(sum-num)<=100 ){
            printf("nice\n");
        }else{
            printf("not nice\n");
        }
    }
    return 0;
}
