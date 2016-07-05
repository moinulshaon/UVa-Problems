#include <stdio.h>
#include <string.h>
int MinExp(char *s, int len);
int main()
{
    int T;
    char str[10001];
    scanf("%d", &T);
    getchar();
    while(T--){
        gets(str);
        printf("%d\n", MinExp(str, strlen(str))+1);
    }
    return 0;
}
int MinExp(char *s, int len){
    int i = 0, j = 1, k = 0, x, y;
    while(i < len && j < len && k < len){
        x = i+k;
        y = j+k;
        if(x >= len)    x -= len;
        if(y >= len)    y -= len;
        if(s[x] == s[y])  k++;
        else{
            if(s[x] > s[y])  i += k+1;
            else    j += k+1;
            if(i == j)  j++;
            k = 0;
        }
    }
    return i;
}
