#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define SIZE 10010
#define EPS (1e-7)


struct tt{
    double left,right;
}line[SIZE];
int n;
double func( double r,double w ){
    return sqrt( r*r-w*w/4 );
}
bool cmp(const tt&a,const tt&b){
    if ( fabs(a.left-b.left)>EPS ){
        return a.left<b.left;
    }else{
        return a.right>b.right;
    }
}
int main(){
    freopen("in.txt","r",stdin);
    double len,width,x,r;

    while (scanf("%d %lf %lf",&n,&len,&width)==3){

        for (int i=0;i<n;++i){
            scanf("%lf %lf",&x,&r);
            if ( 4*r*r-width*width<EPS){
                --i;
                --n;
                continue;
            }
            line[i].left=x-func(r,width);
            if ( line[i].left<0 )line[i].left=0;
            if ( line[i].left>len ){
                --i;--n;
                continue;
            }
            line[i].right=x+func(r,width);
            if ( line[i].right>len )line[i].right=len;
            if ( line[i].right<0){
                --i;
                --n;
                continue;
            }
        }
        //printf("%d\n",n);
        sort(line,line+n,cmp);



        bool pos=true;
        if ( line[0].left>EPS ){
            pos=false;
            //printf("here\n");
        }
        double left=0,right=line[0].right;
        int ans=1;
        for (int i=1;i<n && pos ;++i){
            if ( line[i].left>right ){
                //printf("here %d\n",i);
                pos=false;
            }
            double save=right;
            while (i<n && line[i].left<save+EPS  ){
                right=max(right,line[i].right);
                ++i;
            }
            --i;
            if ( fabs(save-right)>EPS )
                ++ans;
            //printf("right %lf\n",right);
        }
        if ( pos && fabs(right-len)<EPS )printf("%d\n",ans);
        else printf("-1\n");

    }
    return 0;
}
