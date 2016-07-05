#include <iostream>
#include <string>

using namespace std;

bool kmp(string t,string p){

    int len=p.length();

    for (int i=0, j=-1; i<t.size(); ++i){

        if (p[ (j+1)%len ] == t[i])
            j++;

        if (j == p.size()-1){
            return i-p.size()+2;
        }
    }
}

int main(){

    string str;
    while (cin>>str && str!="."){

        for (int i=1;i<str.length();++i){

            if (str.length()%i==0){

                if ( kmp(str,str.substr(0,i) ) ){
                    cout<<i<<endl;
                    //break;
                }

            }

        }

    }
    return 0;

}
