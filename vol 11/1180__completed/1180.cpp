#include <cstdio>
#include <cmath>
#include <set>

using namespace std;

set<int> s;

int main(){


    s.insert(2);
    s.insert(3);
    s.insert(5);
    s.insert(7);
    s.insert(13);
    s.insert(17);
    s.insert(19);
    s.insert(31);
    s.insert(61);

    int n,input;
    while (scanf("%d",&n)==1){
        getchar();
        for (int i=0;i<n;++i){
            scanf("%d",&input);
            getchar();
            if (s.find(input)!=s.end()){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
    }
    return 0;
}
