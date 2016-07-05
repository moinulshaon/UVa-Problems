#include <cstdio>


using namespace std;

template<class T>
    inline T fastIn() {
    register char c=0;
    register T a=0;
    bool neg=false;
    while ( c<33 ) c=getchar();
    while ( c>33 ) {
        if ( c=='-' ) {
            neg=true;
        } else {
            a= ( a*10 ) + ( c-'0' );
        }
        c=getchar();
    }
    return neg?-a:a;
}

int arr[40];

int main(){
    int kase=fastIn<int>();

    for (int kk=1;kase--;++kk){
        int n=fastIn<int>();

        for (int i=0;i<n;++i){
            arr[i]=fastIn<int>();
        }

        int mx=0;
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                if ( (arr[i] & arr[j]) >mx ){
                    mx=(arr[i] & arr[j]);
                }
            }
        }
        printf("Case %d: %d\n",kk,mx);
    }
    return 0;
}
