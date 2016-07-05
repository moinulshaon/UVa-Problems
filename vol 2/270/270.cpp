#include <cstdio>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <map>

using namespace std;

typedef pair<int,int> vmath;

vmath point[800];

int main(){

    int kase,a,b,n;
    cin>>kase;
    getchar();
    getchar();

    string str;

    while (kase--){

        map<vmath,int> myp;

        for(n=0; getline(cin,str) && str.length() ;++n){
            stringstream sstr(str);

            sstr>>a>>b;

            point[n]=make_pair(a,b);

        }

        for ( int i=0;i<n;++i ){
            for (int j=i+1 ; j<n ;++j){
                vmath tmp( point[i].first-point[j].first, point[i].second-point[j].second );

                int val=dot(point[i],point[j]);

                if (myp.find(tmp)==myp.end()){
                    myp[tmp]=0;
                }
                else{
                    myp[tmp]++;
                }
            }
        }

    }

}
