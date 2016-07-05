#include <cstdio>

using namespace std;

int main(){
    char arr[20];
    for(int kk=1;gets(arr) && arr[0]!='*';++kk){
        if ( arr[0]=='H' ){
            printf("Case %d: Hajj-e-Akbar\n",kk);
        }else{
            printf("Case %d: Hajj-e-Asghar\n",kk);
        }
    }
    return 0;
}
