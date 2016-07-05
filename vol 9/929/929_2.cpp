#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
struct koltseg {
	int x, y;
	int cost;
};
bool v[1000][1000];
int g[1000][1000], idx= 0;
int main() {
	int n, a, b;
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		queue<koltseg> s[10];
		scanf("%d %d",&a,&b);
		for(int j = 0; j < a; j++) {
			for(int k = 0; k < b; k++) {
				scanf("%d",&g[j][k]);
				v[j][k] = false;
			}
		}
		koltseg e, e2;
		e.x = 0;
		e.y = 0;
		e.cost = g[0][0];
		s[idx].push(e);
		while(true) {
			while(s[idx].empty()) idx = (idx + 1) % 10;
			if(v[s[idx].front().x][s[idx].front().y]) { s[idx].pop(); continue; }
			cout<<idx<<" "<<s[idx].front().x<<" "<<s[idx].front().y<<" "<<s[idx].front().cost<<endl;
			if(s[idx].front().x == a - 1 && s[idx].front().y == b - 1) {
				printf("%d\n",s[idx].front().cost);
				break;
			}
			e = s[idx].front();
			v[e.x][e.y] = true;
			s[idx].front();
			if(e.x + 1 < a) {
				e2.x = e.x + 1;
				e2.y = e.y;
				e2.cost = e.cost + g[e2.x][e2.y];
				if(!v[e2.x][e2.y]) s[(idx+g[e2.x][e2.y])%10].push(e2);
			}
			if(e.y + 1 < b) {
				e2.x = e.x;
				e2.y = e.y + 1;
				e2.cost = e.cost + g[e2.x][e2.y];
				if(!v[e2.x][e2.y]) s[(idx+g[e2.x][e2.y])%10].push(e2);
			}
			if(e.x - 1 >= 0) {
				e2.x = e.x - 1;
				e2.y = e.y;
				e2.cost = e.cost + g[e2.x][e2.y];
				if(!v[e2.x][e2.y]) s[(idx+g[e2.x][e2.y])%10].push(e2);
			}
			if(e.y - 1 >= 0) {
				e2.x = e.x;
				e2.y = e.y - 1;
				e2.cost = e.cost + g[e2.x][e2.y];
				if(!v[e2.x][e2.y]) s[(idx+g[e2.x][e2.y])%10].push(e2);
			}
		}
	}
	return 0;
}
