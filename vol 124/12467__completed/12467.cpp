#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

int failure[1000100];

int Morris_Pratt(string& t, string& p){

    for (int i=1, j=failure[0]= -1; i<p.size(); ++i){
        while (j >= 0 && p[j+1] != p[i])
            j = failure[j];
        if (p[j+1] == p[i]) j++;
        failure[i] = j;
    }

    int ans=0;
    for (int i=0, j=-1; i<t.size(); ++i){
        while (j >= 0 && p[j+1] != t[i])
            j = failure[j];
        if (p[j+1] == t[i]) j++;


        if (j >ans){
            ans=j;
            //j = failure[j];
        }
    }
    return ans;
}

int main(){
    //freopen("in.txt","r",stdin);
    string str;
    int kase;
    cin>>kase;
    while(kase--){
        cin>>str;
        string ss=str;
        reverse(ss.begin(),ss.end());
        string rr=str.substr(0,Morris_Pratt(ss,str)+1);
        reverse( rr.begin(),rr.end() );
        cout<<rr<<endl;
    }
    return 0;
}
