#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MaxVal=110;

int tree[MaxVal+5];
int val[MaxVal+5];

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

int arr[1001001];



int sz,mod;
void gene( int x ){
    if ( x<=3 ){
        arr[x]=x;
    }else{
        arr[x] = ( arr[x-1]+arr[x-2]+arr[x-3] )%mod+1;
    }
}

int main(){
    freopen("in.txt","r",stdin);
    int kase;

    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int total,k;
        memset(tree,0,sizeof(tree));
        memset(val,0,sizeof(val));

        scanf("%d %d %d",&total,&mod,&k);

        arr[1]=1;
        val[1]=1;
        update( 1,1 );

        int left=1,right=1;
        int ans= (1<<29);
        while( right<=total ){
            //printf("%d\n",read(k));
            if ( read( k ) == k ){
                ans=min( ans,right-left+1 );
                if ( arr[left]<=k ){
                    val[ arr[left] ]--;
                    if ( !val[ arr[left] ]  ){
                        update( arr[left], -1 );
                    }
                }
                left++;
            }else{
                gene( ++right );
                if ( arr[right]<=k ){
                    val[ arr[right] ]++;
                    if ( val[ arr[right] ] == 1  ){
                        update( arr[right], 1 );
                    }
                }
            }
        }

        if ( ans== (1<<29) ){
            printf("Case %d: sequence nai\n",kk);
        }else{
            printf("Case %d: %d\n",kk,ans);
        }
    }
    return 0;
}
