#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct mathv{
    mathv(){x=0;y=0;}
    mathv(int a,int b){x=a;y=b;}
    int x,y;

    mathv operator + (mathv & p){
        mathv tmp( x+p.x,y+p.y );
        return tmp;
    }
    mathv operator - (mathv & p){
        mathv tmp( x-p.x,y-p.y );
        return tmp;
    }

};


int dot2D(mathv& v1, mathv& v2){
    return v1.x * v2.x + v1.y * v2.y;
}
int dot2D(mathv& o, mathv& a, mathv& b){
    return (a.x-o.x) * (b.x-o.x) - (a.y-o.y) * (b.y-o.y);
}
int cross2D(mathv v1, mathv v2){
    return v1.x * v2.y - v1.y * v2.x;
}
int cross2D(mathv& o, mathv& a, mathv& b){
    return (a.x-o.x) * (b.y-o.y) - (a.y-o.y) * (b.x-o.x);
}

double distance2DPointAndPoint(mathv& v1, mathv& v2){
    return sqrt((v2.x - v1.x) * (v2.x - v1.x)+ (v2.y - v1.y) * (v2.y - v1.y));
}

bool cmp(const mathv& a, const mathv& b){
    if ( a.y!=b.y ){
        return a.y<b.y;
    }else{
        return a.x<b.x;
    }
}
double convexHull(mathv points[],mathv convexPoints[],  int n){

    if ( n==1 ){
        return 0;
    }else if ( n==2 ){
        return 2*distance2DPointAndPoint( points[0],points[1] );
    }

    sort(points, points+n, cmp);
    int m = 0;
    for(int i = 0; i < n; i++){
        while(m >= 2 && cross2D(convexPoints[m-2]- convexPoints[m-1],convexPoints[m-2]- points[i]) <= 0)
            m--;
        convexPoints[m++] = points[i];
    }
    for(int i = n-2, t = m+1; i >= 0; i--){
        while(m >= t && cross2D(convexPoints[m-2]- convexPoints[m-1],convexPoints[m-2]- points[i]) <= 0)
            m--;
        convexPoints[m++] = points[i];
    }

    double sum=0;

    for (int i=0;i<m-1;++i){
        sum+= distance2DPointAndPoint( convexPoints[i],convexPoints[ (i+1)%(m-1) ] );
    }

    return sum;
}

int set(int N,int pos){
    return N=N | (1<<pos);
}
int reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool check(int N,int pos){
    return (bool)(N & (1<<pos));
}

int main(){

    freopen("in.txt","r",stdin);

    int node;
    int kase=1;
    mathv tree[20],ccc[20];
    int val[20],fence[20];

    while( scanf("%d",&node)==1 && node ){

        if ( kase!=1 )printf("\n");

        for (int i=0;i<node;++i){
            scanf("%d %d %d %d",&tree[i].x,&tree[i].y,&val[i],&fence[i]);
            //printf("%d %d\n",tree[i].x,tree[i].y);
        }

        int config=0,ans=(1<<29),prvnumber=100;
        double excess=0;
        mathv kept[20];
        for (int i=0;i<(1<<node)-1;++i){
            int n=0;
            int cutval=0;
            int number=0;
            int available=0;
            for (int j=0;j<node;++j){
                if ( check(i,j)==0 ){
                    kept[n++]=tree[j];
                }else{
                    number++;
                    cutval+= val[j];
                    available+= fence[j];
                }
            }

            if ( convexHull( kept,ccc,n )< available+1e-6 ){
                if ( cutval<ans ){
                    config=i;
                    ans=cutval;
                    prvnumber=number;
                    excess= available- convexHull( kept,ccc,n );
                }else if ( cutval==ans && number < prvnumber ){
                    config=i;
                    ans=cutval;
                    prvnumber=number;
                    excess= available- convexHull( kept,ccc,n );
                }
            }
        }
        //printf("VAL %d\n",ans);
        printf("Forest %d\nCut these trees:",kase++);

        for (int i=0;i<node;++i){
            if ( check( config,i )==1 ){
                printf(" %d",i+1);
            }
        }
        printf("\n");
        printf("Extra wood: %.2lf\n",excess);
    }
    return 0;
}
