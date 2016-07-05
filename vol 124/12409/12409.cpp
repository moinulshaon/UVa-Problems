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



int main(){
    freopen("in.txt","r",stdin);
    int row,col,tmp,kase=fastIn<int>();

    for (int kk=1;kase--;++kk){
        row=fastIn<int>();
        col=fastIn<int>();

        int ans=0;
        for (int i=row-1;i>=0;--i){
            for (int j=col-1;j>=0;--j){
                tmp=fastIn<int>();
                if ( (i+j)%2 ){
                    ans^=tmp;
                }
            }
        }
        if ( ans ){
            printf("Case %d: win\n",kk);
        }else{
            printf("Case %d: lose\n",kk);
        }
    }
    return 0;
}
