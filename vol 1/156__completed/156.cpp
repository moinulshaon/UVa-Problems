#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cctype>


using namespace std;



int main(){

    freopen("in.txt","r",stdin);

    string str,s2;

    while (cin>>str){

        map<string,string> myp;

        s2="";
        for (int i=0;i<str.size();++i){
            s2+=tolower(str[i]);
        }

        sort(s2.begin(),s2.end());

        myp[s2]=str;

        set<string> s;

        while  (cin>>str && str!="#"){

            s2="";
            for (int i=0;i<str.size();++i){
                s2+=tolower(str[i]);
            }

            sort(s2.begin(),s2.end());

            if (myp.find(s2)==myp.end()){
                myp[s2]=str;
            }else{
                s.insert(s2);
                //cout<<s2<<endl;
            }
        }

        vector<string> v;
        map<string,string>::iterator it;

        for (it=myp.begin() ;it!=myp.end(); ++it){

            if (s.find(it->first)==s.end())
                v.push_back(it->second);

        }

        sort(v.begin(),v.end());

        for (int i=0;i<v.size();++i){
            cout<<v[i]<<endl;
        }

    }
    return 0;

}
