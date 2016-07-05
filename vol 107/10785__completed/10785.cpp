#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string arr[]={"J","S","B","K","T","C","L","D","M","V","N","W","F","X","G","P","Y","H","Q","Z","R"};

int main(){
    int kase,n;
    cin>>kase;
    freopen("out.txt","w",stdout);
    string vowel,consonent;

    for (int kk=1;kase--;++kk){
        cin>>n;

        vowel=consonent="";
        int ll;
        if (n%2==1)ll=n/2+1;
        else ll=n/2;


        for (int i=0;i<ll;++i){
            if (i<21){
                vowel+="A";
            }else if (i<42){
                vowel+="U";
            }else if (i<63){
                vowel+="E";
            }else if (i<84){
                vowel+="O";
            }else if (i<105){
                vowel+="I";
            }
        }

        ll=n/2;
        int j=0;
        for (int i=0;i*5<ll;++i){

            for (j=0;j<5 && j+i*5<ll;++j){
                consonent+= arr[i];
            }

        }

        //cout<<vowel<<' '<<consonent<<endl;
        sort(vowel.begin(),vowel.end());
        sort(consonent.begin(),consonent.end());
        printf("Case %d: ",kk);
        int a=0,b=0;
        for (int i=0;i<n;++i){
            if (i%2==0)
                cout<<vowel[a++];
            else
                cout<<consonent[b++];
        }
        cout<<endl;

    }
    return 0;
}
