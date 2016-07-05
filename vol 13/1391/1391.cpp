#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

#define SIZE 100100

struct PP{
    int age;
    bool a,b,c;
    vector<int> out;
}people[SIZE];
int n;



int main(){
    int m,u,v;
    while (scanf("%d %d",&n,&m)==2){
        if ( !n && !m )return 0;
        int avr=0;
        for (int i=0;i<n;++i){
            scanf("%d",&people[i].age);
            avr += people[i].age;
        }
        avr= int ( ceil( double(avr)/n  ) +1e-6 ) ;
        for (int i=0;i<n;++i){
            if ( people[i].age<avr ){
                people[i].a=false;
                people[i].b=true;
            }else{
                people[i].a=true;
                people[i].b=false;
            }
            people[i].c=true;
        }

        while (m--){
            scanf("%d %d",&u,&v);
            people[u-1].out.push_back(v-1);
            people[v-1].out.push_back(u-1);
        }


    }
}
