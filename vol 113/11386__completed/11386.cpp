#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<LL,int> pint;
typedef map<int,int> mint;

#define SIZE 5010



pint arr[SIZE];
LL save[SIZE];


int main(){
    FRO

    int n;

    while ( scanf("%d",&n)==1 ){


        LL tmp;
        for (int i=1;i<=n;++i){
            scanf("%lld",&save[i]);
        }
        sort( save+1,save+n+1 );

        int len=0;
        for (int i=1;i<=n;++i){
            if ( arr[len].first  != save[i] ){
                arr[++len].first=save[i];
                arr[len].second=1;
            }else{
                arr[len].second++;
            }
        }
        /*
        for (int i=1;i<=len;++i){
            printf("%lld %d\n",arr[i].first,arr[i].second);
        }
        */
        LL ans=0;

        for (int i=1;i<=len;++i){
            int left=1,right=i+1;

            while ( right <=len && left<=i ){
                if ( arr[right].first-arr[left].first == arr[i].first ){
                    if ( left!= i )
                        ans+= arr[right].second*arr[left].second*arr[i].second ;
                    else
                        ans+= arr[right].second*( arr[left].second)*( arr[i].second -1 )/2;
                    right++;
                }else if ( arr[right].first-arr[left].first >arr[i].first ){
                    left++;
                }else{
                    right++;
                }
            }
            //printf("%d %lld\n",i,ans);
        }



        printf("%lld\n",ans);
    }

    return 0;
}
