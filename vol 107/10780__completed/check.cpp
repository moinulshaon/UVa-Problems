#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){

    ifstream me("out1.txt",ios::in);
    ifstream him("out2.txt",ios::in);

    string a,b;
    for(int kk=1; getline(me,a) && getline(him,b);++kk ){
        if ( a!=b )cout<<a<<' '<<b<<endl;
    }
}
