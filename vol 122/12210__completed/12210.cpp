#include<stdio.h>
int main()
{
    int B,S,min,i,j,k,l=1,a[10000],c[10000];
    while(1){
        scanf("%d %d",&B,&S);
        if(B==0&&S==0)break;
        else{
            for(i=0;i<B;i++){
                scanf("%d",&a[i]);

            }
            for(j=0;j<S;j++){
                scanf("%d",&c[j]);
            }
            if(B==S){
                printf("Case %d: 0\n",l++);
            }
            else if(B>S){
                for(i=0,min=100;i<B;i++){
                    if(a[i]<min){
                        min=a[i];
                    }
                }
                printf("Case %d: %d %d\n",l++,B-S,min);
            }
            else if(B<S){
                printf("Case %d: 0\n",l++);
            }
        }
    }
    return 0;
}
