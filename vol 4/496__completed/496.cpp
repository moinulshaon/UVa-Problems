#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

bool check(set<int> &a,set<int> &b){
    set<int>::iterator it;

    for (it=a.begin();it!=a.end();++it){
        if (b.find(*it)==b.end())
            return false;
    }
    return true;

}
bool checkDisjoint(set<int> &a,set<int> &b){
    set<int>::iterator it;

    for (it=a.begin();it!=a.end();++it){
        if (b.find(*it)!=b.end())
            return false;
    }
    return true;
}

int main(){

    int x;
    string str;

    while (getline(cin,str)){

        stringstream sstr(str);

        set<int> a,b;


        while (sstr>>x){
            a.insert(x);
        }
        getline(cin,str);

        stringstream sstr2(str);

        while (sstr2>>x){
            b.insert(x);
        }

        if (a==b){
            cout<<"A equals B\n";
        }else if (check(a,b)){
            cout<<"A is a proper subset of B\n";
        }else if (check(b,a)){
            cout<<"B is a proper subset of A\n";
        }else if (checkDisjoint(a,b)){
            cout<<"A and B are disjoint\n";
        }
        else{
            cout<<"I'm confused!\n";
        }

    }
    return 0;

}
