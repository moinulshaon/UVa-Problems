#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int MaxVal= 2000010;

int tree[MaxVal+1];
vector<int> isLucky;
bool is[MaxVal+1];

int read(int idx){
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val){
	while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
    }
}

int binarySearch(int ind){
    int low=1,high=MaxVal,mid,tmp;
    bool found;
    while ( low<=high ){
        mid=(low+high)/2;
        found=false;
        while (mid>0 && read(mid)==ind ){
            --mid;
            found=true;
        }
        if ( found )return mid+1;
        tmp=read(mid);
        if ( tmp<ind )low=mid+1;
        else if ( tmp>ind )high=mid-1;
    }
    return -1;
}
int BB(int n){
    int low=1,high=isLucky.size()-1,mid,tmp;
    while ( low<=high ){
        mid=(low+high)/2;
        if ( isLucky[mid]==n )return mid+3;
        else if ( isLucky[mid]<n )low=mid+1;
        else if ( isLucky[mid]>n )high=mid-1;
    }
    return mid+3;
}

int main(){
    int kase,a,b,tmp;

    for (int i=1;i<=MaxVal;i+=2){
        update(i,1);
    }


    for (int i=2;i<=MaxVal;i++){
        a=binarySearch(i);
        if ( a== -1 )break;

        for (int j=a;j<=MaxVal;j+=a-1){
            b=binarySearch(j);
            if ( b== -1 )break;
            update(b,-1);
        }
    }
    for (int i=1;i<=MaxVal;i++){
        a=binarySearch(i);
        if ( a==-1 )break;
        isLucky.push_back( a );
        is[a]=true;
    }

    int n;
    while ( scanf("%d",&n)==1 ){

        if ( n&1 ){
            printf("%d is not the sum of two luckies!\n",n);
            continue;
        }
        bool pos=false;
        tmp=n>>1;
        a=BB(tmp);
        for (int i=a ;i>=0;--i){

            if (i<isLucky.size() &&  isLucky[i]<=n-isLucky[i] && is[ n-isLucky[i] ] ){
                pos=true;
                printf("%d is the sum of %d and %d.\n",n,isLucky[i],n-isLucky[i]);
                break;
            }
        }
        if ( !pos )printf("%d is not the sum of two luckies!\n",n);
    }
    return 0;
}
