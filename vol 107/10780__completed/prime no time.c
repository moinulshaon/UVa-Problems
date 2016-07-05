#include <stdio.h>
#include <math.h>
int s[110100],r[110100],t[110100],f[110100];
void sieve()
{
    int a=110000,c,d;
    s[0]=1;
    s[1]=1;
    for(c=2;c*c<=a;c=c+1){
        if(s[c]==0){
            for(d=c*c;d<=a;d=d+c){
                s[d]=1;
            }
        }
    }
    d=0;
    for(c=0;c<=a;c=c+1){
        if(s[c]!=1){
            r[d]=c;
            d=d+1;
        }
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out2.txt","w",stdout);
    int a,b,c,d,k,y,final,temp,m,n,h,M,p,S,max;
    sieve();
    int T;
    a=1;
    scanf("%d",&T);
    while(a<=T){
        scanf("%d %d",&m,&n);
        printf("%d %d ",m,n);
        S=2;
        int f[110100]={0};
        int t[110100]={0};
        M=m;
        c=0;
        y=0;
        while(r[c]<=n){
            k=r[c];
            final=0;
            for(d=1;d<=30;d=d+1){
                temp=(n)/pow(k,d);
                final=final+temp;
            }
            t[y]=final;
            y=y+1;
            c=c+1;
        }
        c=0;
        y=0;
        while(r[c]<=(sqrt(m))){
            h=r[c];

            if(m%h==0){
                f[y]=f[y]+1;
                m=m/h;
            }
            else{
                y=y+1;
                c=c+1;
            }
        }
        for(c=0;c<n;c=c+1){
            if(m==r[c]){
                b=c;
                break;
            }
        }
        f[b]=f[b]+1;
        max=100000;
        for(c=0;c<M;c=c+1){
            if(f[c]!=0){
                p=t[c]/f[c];
                if(p==0){
                    S=-2;
                    break;
                }
                else{
                if(p<max){
                    max=p;
                }
                }
            }
        }
        if(S!=-2){
            printf("Case %d:%d\n",a,max);
        }
        else{
            printf("Case %d:Impossible to divide\n",a);
        }
        a=a+1;
    }
    return 0;
}



