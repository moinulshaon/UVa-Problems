#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

bool cmp(const char &a,const char &b){
    return a>b;
}

int main(){

    string str,str2,str3;

    for (bool on=false;cin>>str && str!="0" ;on=true){


        int x;
        ostringstream ostr;
        ostr<<atoi(str.c_str());

        str=ostr.str();

        printf("Original number was %s\n",str.c_str());

        set<int> sset;



        for (int chain=0;true;++chain){
            str2=str3=str;

            sort(str2.begin(),str2.end());
            sort(str3.begin(),str3.end(),cmp);

            int a=atoi(str3.c_str());
            int b=atoi(str2.c_str());
            int c=a-b;
            printf("%d - %d = %d\n",a,b,c);
            if (sset.find(c)!=sset.end()){
                printf("Chain length %d\n\n",chain+1);
                break;
            }else{

                sset.insert(c);

                ostringstream ostr2;
                ostr2<<c;

                str=ostr2.str();

            }
        }
    }
    return 0;

}
