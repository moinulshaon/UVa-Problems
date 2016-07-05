#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);


#define SIZE 110
#define X first
#define Y second

pair<double,double> point[SIZE][SIZE];
vector< pair<double,double> > v;

double root2=1/sqrt(2);
double root3=sqrt(3)/2;
double dist( pair<double,double> a,pair<double,double> b ){
    return sqrt( (a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y) );
}

int main(){
    freopen("out.txt","w",stdout);
    point[0][0].X=0;
    point[0][0].Y=0;

    for (int j=1;j<SIZE;++j){
        point[0][j].X=point[0][j-1].X+.5;
        point[0][j].Y=point[0][j-1].Y-root3;
    }

    for (int i=1;i<SIZE;++i){
        for (int j=0;j<SIZE;++j){

            point[i][j].X=point[i-1][j].X-.5;
            point[i][j].Y=point[i-1][j].Y-root3;

        }
    }





    for (int dim=2;dim<=100;++dim){
        v.clear();
        for (int i=0;i<dim;++i){
            for (int j=0;j<dim-i;++j){
                v.push_back( point[i][j] );
                //cout<<point[i][j].X<<' '<<point[i][j].Y<<endl;
            }
        }
        //printf("%d\n\n",v.size());
        int ans=0;
        for (int i=0;i<v.size();++i){
            for (int j=i+1;j<v.size();++j){
                for (int k=j+1;k<v.size();++k){

                    if( fabs( dist( v[i],v[j] )-dist( v[i],v[k] ) ) <1e-6 &&
                        fabs( dist( v[i],v[j] )-dist( v[j],v[k] ) ) <1e-6 ){
                            ++ans;
                            //cout<<i<<' '<<j<<' '<<k<<endl;
                    }
                    //cout<<i<<' '<<j<<' '<<k<<' ';
                    //cout<<fabs( dist( v[i],v[j] )-dist( v[i],v[k] ) )<<' '<<fabs( dist( v[i],v[j] )-dist( v[j],v[k] ) )<<endl;
                }
            }
        }
        printf("%d\n",ans);
    }

}





