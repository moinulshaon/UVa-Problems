#include <cstdio>
using namespace std;

const int MAX_N = 10001;
int pars[2*MAX_N];
void init(int n){for(int i=0;i<n;i++)pars[i]=i;}
int getRoot(int x){return x==pars[x]?x:(pars[x]=getRoot(pars[x]));}
bool isSame(int x, int y){return getRoot(x)==getRoot(y);}
void merge(int x, int y){pars[getRoot(x)]=getRoot(y);}

int main(){

    freopen("input.txt","r",stdin);

	int N;
	scanf("%d", &N);
	init(2*N+2);
	int c, x, y;
	while(scanf("%d%d%d",&c, &x, &y), c){
		if(c == 1){ //set friends
			if( isSame(2*x, 2*y+1) || isSame(2*x+1, 2*y) ){
				puts("-1");
			}
			else{
				merge(2*x, 2*y);
				merge(2*x+1, 2*y+1);
			}
		}
		else if(c == 2){ //set enemy
			if( isSame(2*x, 2*y) || isSame(2*x+1, 2*y+1) ){
				puts("-1");
			}
			else{
				merge(2*x+1, 2*y);
				merge(2*x, 2*y+1);
			}
		}
		else if(c == 3){ //friends?
			puts((isSame(2*x, 2*y) || isSame(2*x+1, 2*y+1)) ? "1" : "0");
		}
		else if(c == 4){ //enemy?
			puts((isSame(2*x, 2*y+1) || isSame(2*x+1, 2*y)) ? "1" : "0");
		}
	}

	return 0;
}
