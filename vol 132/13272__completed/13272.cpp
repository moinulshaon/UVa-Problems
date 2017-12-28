#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long LL;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
//find_by_order
//order_of_key

#define FO(i,a,b) for (int i = (a); i < (b); i++)

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

#define SIZE 100100

bool isLower(char c) {
    switch (c) {
        case '(':
        case '{':
        case '[':
        case '<':
            return true;
        default:
            return false;
    }
}

char getAlter(char c) {
    switch(c) {
        case '(':
        case ')':
            return '(' + ')' - c;
        case '{':
        case '}':
            return '{' + '}' - c;
        case '[':
        case ']':
            return '[' + ']' - c;
        case '<':
        case '>':
            return '<' + '>' - c;
        default:
            return c;
    }
}

char str[SIZE];
int dp[SIZE];



int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk) {
        scanf("%s",str);
        int n=strlen(str);

        dp[n] = dp[n-1] = 0;
        for (int i=n-2;i>=0;--i) {
            dp[i] = 0;
            if (!isLower(str[i]))continue;
            if (getAlter(str[i]) == str[i+1]) dp[i] = 2;

            if ( getAlter(str[i]) == str[ i+1 + dp[i+1] ]) {
                dp[i] = dp[i+1]+2;
            }

            if (dp[i]) {
                dp[i] += dp[i + dp[i]];
            }

        }

        printf("Case %d:\n",kk);
        FO(i,0,n)printf("%d\n", dp[i]);

    }

    return 0;
}
