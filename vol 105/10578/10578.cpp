#include <iostream>
#include <string>
#include <cstring>
using namespace std;


int arr[7];


bool win(int n){

    if (n==31)return true;

    for (int i=1;i<=6;++i){

        if ( arr[i]>0 ){

            arr[i]--;
            if ( n+i<=31 && !win( n+i ) )
                return true;
            arr[i]++;
        }

    }
    return false;

}

int main(){


    string str;

    while (getline(cin,str)){

        for (int i=1;i<=6;++i){
            arr[i]=4;
        }
        int sum=0;
        for (int i=0;i<str.length();++i){
            sum+=str[i]-'0';
            arr[ str[i]-'0' ]--;
        }

        cout<<str<<' ';
        for (int i=0;i<32;++i){
            cout<<i<<' '<<win(i)<<endl;
        }

        /*bool w=false;
        if ( win(sum) ){
            w=true;
        }
        if ( str.length()%2==0 ){
            if (w){
                cout<<"A\n";
            }else{
                cout<<"B\n";
            }
        }else{
            if (!w){
                cout<<"A\n";
            }else{
                cout<<"B\n";
            }
        }*/


    }
    return 0;

}
