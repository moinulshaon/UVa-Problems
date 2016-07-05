#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main(){

    string total,a,b;

    map<string,string> myp;

    while (getline(cin,total) && total.length() ){
        stringstream sstr(total);

        sstr>>a>>b;
        myp[b]=a;

    }

    while (getline(cin,total)){
        if (myp.find(total)==myp.end()){
            cout<<"eh"<<endl;
        }else{
            cout<<myp[total]<<endl;
        }
    }
    return 0;

}
