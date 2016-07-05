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

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 51000

int arr[SIZE];
int mp[SIZE];
int cnt;
int n;

int bsearch(int x){
    int low=1,high=cnt;
    while ( low<=high ){
        int mid=(low+high)/2;
        if ( x>=arr[mid] )low=mid+1;
        else high= mid-1;
    }

    return cnt+1-low;
}

int shaonsearch(int pos){
    int low=1,high=pos;
    while ( low<=high ){
        int mid=(low+high)/2;
        //printf("%d %d\n",mid, bsearch( mid ));
        if ( mid+ bsearch( mid )< pos ){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int qq;
        scanf("%d %d %d",&n,&cnt,&qq);


        for (int i=1;i<=cnt;++i){
            scanf("%d",&arr[i]);
            mp[ i ]= arr[i];
        }

        //arr[cnt+1]= (1<<30);

        sort( arr+1,arr+cnt+1 );

        printf("Case %d:\n",kk);
        int x;
        while ( qq-- ){
            scanf("%d",&x);

            if ( x <=cnt ){
                printf("%d\n",mp[x]);
            }else{
                printf("%d\n",shaonsearch(x));
            }
        }

    }

    return 0;
}
