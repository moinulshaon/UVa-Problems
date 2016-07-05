this #include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()

#define X first
#define Y second
#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;

void show() {cout<<'\n';}
template<typename T,typename... Args>
void show(T a, Args... args) { cout<<a<<" "; show(args...); }
template<typename T>
void show_c(T& a) { for ( auto &x:a ){ cout<<x<<" ";}cout<<endl;  }


#define SIZE 200010
#define LIM 450

int tree[LIM][LIM];
int max_x=LIM-1;
int max_y=LIM-1;

int read(int x , int y ){
    x+=2,y+=2;

    int val=0;
	int y1;
	while (x > 0 ){
		y1 = y;
		while (y1>0){
			val+=tree[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return val;
}

void update(int x , int y , int val){
    x+=2,y+=2;

	int y1;
	while (x <= max_x){
		y1 = y;
		while (y1 <= max_y){
			tree[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

int arr[SIZE];
int pos[SIZE];

bool valid_x[SIZE];
bool valid_y[SIZE];

int srt;


int query(int x,int y){

    int ret = read(x/srt-1,y/srt-1);

    int indx = ( x/srt )*srt;
    while ( indx <= x ){
        if ( valid_x[indx] && arr[indx] < (y/srt)*srt ){
            ret++;
        }
        indx++;
    }

    int indy = ( y/srt )*srt;

    while ( indy < y ){
        if ( valid_y[indy] && pos[indy] <= x ){
            ret++;
        }
        indy++;
    }

    return ret;
}


int MaxVal=SIZE-1;
struct BIT{
    int tree[SIZE];
    int read(int idx){
        idx++;
        int sum = 0;
        while (idx > 0){
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

    void update(int idx ,int val){
        idx++;
        while (idx <= MaxVal){
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }
}base;

int main(){

    //FRO

    int n,m;
    while ( scanf("%d %d",&n,&m)==2 ){

        CLR(tree);
        CLR(base.tree);

        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
            arr[i]--;

            pos[ arr[i] ] = i;

            valid_x[i] = true;
            valid_y[i] = true;
        }

        srt = sqrt( n )+1e-6;

        LL ans = 0;

        for (int i=0;i<n;++i){
            update( i/srt,arr[i]/srt,1 );

            ans += base.read( n )-base.read( arr[i] );
            base.update( arr[i],1 );
        }

        CLR(base.tree);
        for (int i=0;i<n;++i){
            base.update( i,1 );
        }

        int v;
        while ( m-- ){

            printf("%lld\n",ans);

            scanf("%d",&v);
            v--;

            int tmp = query( pos[v],v );
            ans -= query( n-1,v ) -tmp;

            ans -= base.read(pos[v]-1) - tmp;

            base.update(pos[v],-1);

            update( pos[v]/srt,v/srt ,-1 );

            valid_x[ pos[v] ] = false;
            valid_y[v] = false;


            pos[v] = n+100;
        }

    }

    return 0;
}
