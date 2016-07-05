#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){

    freopen("in.txt","r",stdin);

    string str;

    int hour,min,second,h,m,s;
    double distance=0;
    double speed=0;
    char ca,cb;




    while (getline(cin,str) ){
        stringstream sstr(str);
        //cout<<str<<endl;
        if ( str.length()< 10 ){
            sstr>>h>>ca>>m>>cb>>s;
            distance+=( (h-hour)*3600+(m-min)*60+(s-second) )*speed;
            hour=h;
            min=m;
            second=s;

            printf("%s %.2lf km\n",str.c_str(),distance);

        }else{

            sstr>>h>>ca>>m>>cb>>s;
            distance+=( (h-hour)*3600+(m-min)*60+(s-second) )*speed;
            hour=h;
            min=m;
            second=s;

            sstr>>speed;
            speed/=3600;

        }

    }
    return 0;

}
